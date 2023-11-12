#include "libreria.h"

void funcion1(char cad[]);
void funcion2(char cad[],int tam,int i);
void funcion3(char cad[],int tam,int i);
void funcion4(char cad[],int tam,int i);
void funcion5(char cad[],int tam,int i,int j);
void funcion6(char cad[],int tam,int i,int j);
void funcion7(char cad[],int tam,int i,int j);
void funcion8(char cad[],int tam,int i,int j);
void funcion9(char cad[],int tam,int i);
void funcion10(char cad[],int tam,int i);

/////////////////////////////////////////////////////////

int main()
{
    system("CLS");
    char cad[30];
    int tam, i, j;
    printf("Dame una palabra: ");
    fflush(stdin);
    gets(cad);
    tam = tam_cad(cad);

    mayusculas(cad);

    funcion1(cad);
    funcion2(cad, tam, i);
    funcion3(cad, tam, i);
    funcion4(cad, tam, i);
    funcion5(cad, tam, i, j);
    funcion6(cad, tam, i, j);
    funcion7(cad, tam, i, j);
    funcion8(cad, tam, i, j);
    funcion9(cad, tam, i);
    funcion10(cad, tam, i);

    system("PAUSE");
    return 0;
}

///////////////////////////////////////////////////////////////

void funcion1(char cad[])
{
    printf("SALIDA 1:\n");
    puts(cad);
    printf("\n");
}

void funcion2(char cad[], int tam, int i)
{
    printf("SALIDA 2:\n");
    for (i = tam - 1; i >= 0; i--)
    {
        printf("%c", cad[i]);
    }
    printf("\n\n");
}

void funcion3(char cad[], int tam, int i)
{
    printf("SALIDA 3:\n");
    for (i = 0; i < tam; i++)
    {
        printf("%c\n", cad[i]);
    }
    printf("\n");
}

void funcion4(char cad[], int tam, int i)
{
    printf("SALIDA 4:\n");
    for (i = tam - 1; i >= 0; i--)
    {
        printf("%c\n", cad[i]);
    }
    printf("\n");
}

void funcion5(char cad[], int tam, int i, int j)
{
    printf("SALIDA 5:\n");
    for (j = tam - 1; j >= 0; j--)
    {
        for (i = 0; i <= j; i++)
        {
            printf("%c", cad[i]);
        }
        printf("\n");
    }
    printf("\n");
}

void funcion6(char cad[], int tam, int i, int j)
{
    printf("SALIDA 6:\n");
    for (j = 0; j <= tam - 1; j++)
    {
        for (i = tam - 1; i >= j; i--)
        {
            printf("%c", cad[i]);
        }
        printf("\n");
    }
    printf("\n");
}

void funcion7(char cad[], int tam, int i, int j)
{
    printf("SALIDA 7:\n");
    for (j = 0; j <= tam - 1; j++)
    {
        for (i = j; i <= tam - 1; i++)
        {
            printf("%c", cad[i]);
        }
        printf("\n");
    }
    printf("\n");
}

void funcion8(char cad[], int tam, int i, int j)
{
    printf("SALIDA 8:\n");
    for (j = tam - 1; j >= 0; j--)
    {
        for (i = j; i >= 0; i--)
        {
            printf("%c", cad[i]);
        }
        printf("\n");
    }
    printf("\n");
}

void funcion9(char cad[], int tam, int i)
{
    printf("SALIDA 9:\n");
    for (i = 0; i < tam; i++)
    {
        if (cad[i] != 'A' && cad[i] != 'E' && cad[i] != 'I' && cad[i] != 'O' && cad[i] != 'U')
        {
            printf("%c", cad[i]);
        }
    }
    printf("\n\n");
}

void funcion10(char cad[], int tam, int i)
{
    printf("SALIDA 10:\n");
    for (i = 0; i < tam; i++)
    {
        if (cad[i] == 'A' || cad[i] == 'E' || cad[i] == 'I' || cad[i] == 'O' || cad[i] == 'U')
        {
            printf("%c", cad[i]);
        }
    }
    printf("\n\n");
}