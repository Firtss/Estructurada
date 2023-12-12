#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;
int offset = 75;

bool gameOver = false;
double currentTime = 0;
bool restartRequested = false;

double lastUpdateTime = 0;

bool ElementInDeque(Vector2 element, deque<Vector2> deque)
{
    for (unsigned int i = 0; i < deque.size(); i++)
    {
        if (Vector2Equals(deque[i], element))
        {
            return true;
        }
    }
    return false;
}

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Snake
{
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool addSegment = false;

    void Draw()
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    void Update()
    {
        body.push_front(Vector2Add(body[0], direction));
        if (addSegment == true)
        {
            addSegment = false;
        }
        else
        {
            body.pop_back();
        }
    }

    void Reset()
    {
        body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
        direction = {1, 0};
    }
};

class Food
{

public:
    Vector2 position;
    Texture2D texture;

    Food(deque<Vector2> snakeBody)
    {
        Image image = LoadImage("Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        position = GenerateRandomPos(snakeBody);
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    void Draw()
    {
        DrawTexture(texture, offset + position.x * cellSize, offset + position.y * cellSize, WHITE);
    }

    Vector2 GenerateRandomCell()
    {
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }

    Vector2 GenerateRandomPos(deque<Vector2> snakeBody)
    {
        Vector2 position = GenerateRandomCell();
        while (ElementInDeque(position, snakeBody))
        {
            position = GenerateRandomCell();
        }
        return position;
    }
};

class Game
{
public:
    Snake snake = Snake();
    Food food = Food(snake.body);
    bool running = true;
    int score = 0;
    Sound eatSound;
    Sound wallSound;

    // Añade una textura de renderizado como miembro de la clase
    RenderTexture2D renderTexture;

    Game() {
        InitAudioDevice();
        eatSound = LoadSound("Sounds/eat.mp3");
        wallSound = LoadSound("Sounds/wall.mp3");
    }

    ~Game()
    {
        UnloadSound(eatSound);
        UnloadSound(wallSound);
        CloseAudioDevice();
    }

    void Draw()
    {
        food.Draw();
        snake.Draw();
    }

    void Update()
    {
        if (running)
        {
            snake.Update();
            CheckCollisionWithFood();
            CheckCollisionWithEdges();
            CheckCollisionWithTail();
        }
    }

    void CheckCollisionWithFood()
    {
        if (Vector2Equals(snake.body[0], food.position))
        {
            food.position = food.GenerateRandomPos(snake.body);
            snake.addSegment = true;
            score++;
            PlaySound(eatSound);
        }
    }

    void CheckCollisionWithEdges()
    {
        if (snake.body[0].x == cellCount || snake.body[0].x == -1)
        {
            snake.direction = {0, 0}; // Detener el movimiento en el eje X
            GameOver();
        }
        if (snake.body[0].y == cellCount || snake.body[0].y == -1)
        {
            snake.direction = {0, 0}; // Detener el movimiento en el eje Y
            GameOver();
        }
    }

    void GameOver()
    {
        snake.Reset();
        food.position = food.GenerateRandomPos(snake.body);
        running = false;
        score = 0;
        PlaySound(wallSound);
    }

    void CheckCollisionWithTail()
    {
        deque<Vector2> headlessBody = snake.body;
        headlessBody.pop_front();
        if (ElementInDeque(snake.body[0], headlessBody))
        {
            snake.direction = {0, 0}; // Detener el movimiento
            GameOver();
        }
    }
};

void updateGame(Game& game, double& lastUpdateTime, double& currentTime)
{
    const double interval = 0.1; // Intervalo de tiempo para el movimiento de la serpiente

    currentTime = GetTime();
    if (game.running && currentTime - lastUpdateTime >= interval)
    {
        if (IsKeyDown(KEY_UP) && game.snake.direction.y != 1)
        {
            game.snake.direction = {0, -1};
        }
        else if (IsKeyDown(KEY_DOWN) && game.snake.direction.y != -1)
        {
            game.snake.direction = {0, 1};
        }
        else if (IsKeyDown(KEY_LEFT) && game.snake.direction.x != 1)
        {
            game.snake.direction = {-1, 0};
        }
        else if (IsKeyDown(KEY_RIGHT) && game.snake.direction.x != -1)
        {
            game.snake.direction = {1, 0};
        }

        game.snake.Update();
        game.CheckCollisionWithFood();
        game.CheckCollisionWithEdges();
        game.CheckCollisionWithTail();

        lastUpdateTime = currentTime;
    }

    game.Draw();
}

void drawGame(Game& game, bool gameOver) {
    ClearBackground(green);
    DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5, darkGreen);
    DrawText("Retro Snake", offset - 5, 20, 40, darkGreen);
    DrawText(TextFormat("%i", game.score), offset - 5, offset + cellSize * cellCount + 10, 40, darkGreen);

    if (!gameOver) {
        game.Draw();
    }
}

void playGame(Game &game) 
{
    double lastUpdateTime = 0;
    double currentTime = 0;
    bool gameOver = false;
    

    while (!WindowShouldClose()) {
        if (!gameOver) {
            updateGame(game, lastUpdateTime, currentTime);
            drawGame(game, gameOver);
            if (!game.running) {
                gameOver = true;
                restartRequested = true;
            }
        } else {
            // Dibujar pantalla de Game Over
            ClearBackground(green);
            DrawText("Game Over", GetScreenWidth() / 2 - MeasureText("Game Over", 40) / 2, GetScreenHeight() / 2 - 50, 40, WHITE);
            DrawText("Press Enter to restart", GetScreenWidth() / 2 - MeasureText("Press Enter to restart", 20) / 2, GetScreenHeight() / 2 + 50, 20, WHITE);

            // Reiniciar el juego si se presiona Enter
            if (IsKeyPressed(KEY_ENTER)) {
                game.running = true;
                gameOver = false;
                game.score = 0;
                game.snake.Reset();
                game.food.position = game.food.GenerateRandomPos(game.snake.body);
            }
        }

        EndDrawing();
    }
    
}

enum GameState {
    MENU_PRINCIPAL,
    EN_JUEGO,
    CREDITOS,
    EXIT
};
// Estructura para los botones
struct Button {
    Rectangle bounds;
    Color color;
    Color textColor;
    const char* text;
};
// Función para determinar si el ratón está sobre un área rectangular
bool isMouseOver(Rectangle bounds) {
    Vector2 mouse = GetMousePosition();
    return (mouse.x >= bounds.x && mouse.x <= (bounds.x + bounds.width) &&
            mouse.y >= bounds.y && mouse.y <= (bounds.y + bounds.height));
}
// Función para dibujar un botón y manejar clics
bool drawButton(const Button& button) {
    bool clicked = false;

    if (isMouseOver(button.bounds)) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            clicked = true;
        }
        DrawRectangleRec(button.bounds, button.color);
        DrawText(button.text, static_cast<int>(button.bounds.x) + 10, static_cast<int>(button.bounds.y) + 10, 20, button.textColor);
    } else {
        DrawRectangleLinesEx(button.bounds, 2, button.color);
        DrawText(button.text, static_cast<int>(button.bounds.x) + 10, static_cast<int>(button.bounds.y) + 10, 20, button.textColor);
    }

    return clicked;
}
// Función para mostrar el menú principal
void showMainMenu(GameState& gameState) {
    Texture2D fondo = LoadTexture("Serpentin2.png");
    DrawTexture(fondo, 0,0,WHITE);
    // Definir los botones personalizados
    Button buttonJugar{ Rectangle{ 350, 260, 200, 50 }, BLUE, WHITE, "JUGAR" };
    Button buttonCreditos{ Rectangle{ 350, 350, 200, 50 }, BLUE, WHITE, "CREDITOS" };
    Button buttonSalir{ Rectangle{ 350, 450, 200, 50 }, BLUE, WHITE, "SALIR" };

    // Lógica para dibujar los botones y manejar clics
    if (drawButton(buttonJugar)) {
        gameState = GameState::EN_JUEGO;
    }

    if (drawButton(buttonCreditos)) {
        gameState = GameState::CREDITOS;
    }

    if (drawButton(buttonSalir)) {
        gameState = GameState::EXIT;
    }
}
// Función para mostrar los créditos
void showCredits(GameState& gameState) {
    ClearBackground(green);
    // Lógica para mostrar los créditos
    // Aquí carga la textura del fondo y cualquier otra imagen necesaria

    // Botón para regresar al menú principal
    Button buttonRegresar{ Rectangle{ 300, 440, 200, 50 }, BLUE, WHITE, "REGRESAR" };
    if (drawButton(buttonRegresar)) {
        gameState = GameState::MENU_PRINCIPAL;
    }

    DrawText("Desarolladores", 220, 300, 60, BLACK);
    DrawText("Martin Santos ", 300, 350, 40, BLACK);
    DrawText("Miguel Portillo ", 300, 390, 40, BLACK);
}

int main()
{
    cout << "Starting the game..." << endl;
    InitWindow(2 * offset + cellSize * cellCount, 2 * offset + cellSize * cellCount, "Retro Snake");
    SetTargetFPS(60);

    Game game = Game();
    GameState gameState = MENU_PRINCIPAL;
    
    

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        //ClearBackground(green);
        Music music = LoadMusicStream("fondo.mp3");
        PlayMusicStream(music);

        switch (gameState) 
        {
            case MENU_PRINCIPAL:
                showMainMenu(gameState);
                break;
            case EN_JUEGO:
                playGame(game);
                gameState = GameState::MENU_PRINCIPAL;
                break;
            case CREDITOS:
                showCredits(gameState);
                break;
            case EXIT:
                CloseWindow();
                break;
        }

        EndDrawing();
        UnloadMusicStream(music); // Detén la música cuando salgas del loop
        CloseAudioDevice();
    }
    
    CloseWindow();
    return 0;
}