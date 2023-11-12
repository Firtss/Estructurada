#include "libreria.h"
void funcion1(char cad[]);
void funcion2(char cad[]);
void funcion3(char cad[]);
void funcion4(char cad[]);
void funcion5(char cad[]);
void funcion6(char cad[]);
void funcion7(char cad[]);
void funcion8(char cad[]);
void funcion9(char cad[]);
int main()
{
    system("CLS");
    char cad[30];
    int tam, i, j;
    printf("Dame una palabra: ");
    fflush(stdin);
    gets(cad);
    tam = tam_cad(cad);

    funcion1(cad);
    funcion2(cad);
    funcion3(cad);
    funcion4(cad);
    funcion5(cad);
    funcion6(cad);
    funcion7(cad);
    funcion8(cad);
    funcion9(cad);

    return 0;
}
void funcion1(char cad[])
{
    printf("MAYUSCULAS\n");
    mayusculas(cad);
    puts(cad);
    printf("\n");
}
void funcion2(char cad[])
{
    printf("minusculas\n");
    minusculas(cad);
    puts(cad);
    printf("\n");
}
void funcion3(char cad[])
{
    printf("Capital\n");
    capital(cad);
    puts(cad);
    printf("\n");
}
void funcion4(char cad[])
{
    int i;
    printf("Cantidad de caracteres\n");
    for (i = 0; cad[i] != '\0'; i++);
    printf("Tiene un total de ",i);
    printf(" caracteres\n");
    printf("\n");
}
void funcion5(char cad[])
{
    printf("Palabra al reves\n");
    reves(cad,cad);
    puts(cad); 
    printf("\n");
}
void funcion6(char cad[])
{
    printf("Palabrassinespacio\n");
    sinespacios(cad);
    puts(cad);
    printf("\n");
}
void funcion7(char cad[])
{  
    printf("S0l0 L3tr4s\n");
    solo_az(cad);
    puts(cad);
    printf("\n");
}
void funcion8(char cad[])
{
    printf("De ToDO\n");
    combo(cad);
    puts(cad);
    printf("\n");
}
void funcion9(char cad[])
{
    printf("Es un palindromo?\n");
    palindromo(cad,cad);
    printf("\n");
}