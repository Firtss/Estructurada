//Santos Tirado Martin 00369705
//1 de septiembre del 2023
//9.- Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y la computadora, (usar selección múltiple)
#include <stdio.h>
int main ()
{
    int mano;

    printf("Jugemos piedra,papel y tijera!! Yo comienzo: Escogo piedra");
    printf("\nPara jugar, utiliza este menu!!\n1=piedra\n2=papel\n3=tijera\n");
    scanf("%d",&mano);

   switch (mano)
   {
    case 1:
    printf("Uy!! es un empate... otra vez?");
        break;
    case 2:
    printf("No puede ser... me ganaste!, otra vez?");
        break;
    case 3:
    printf("Si!! gane!!, quieres la revancha?");
        break;
   default:
        printf("No escogiste ninguna de las opciones asi que gane, Tehe :p");
    break;
   }
    
    return 0;
}