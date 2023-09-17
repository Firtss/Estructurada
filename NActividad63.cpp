//Martin Santos Tirado
//00369705
//15 de septiembre de 2023
//Realizar función en C para un programa 
//que sirva para leer n cantidad de números dentro de un rango dado por el usuario, 
//desplegar la suma de los números y la media aritmética de los números válidos dentro del rango.
#include <stdio.h>
#include <stdlib.h>
void num(void);
int main()
{
    num();
    return 0;
}
void num()
{
    int numero,i,sum,media;
    printf("\nDeme un numero entero y le contare los numero que haya en ese rango\n");
    scanf("%d",numero);

    for (i = 1; i < numero; i++)
    {
        sum= sum + i;
    }
    media = sum / numero;
    printf("\nLa suma de los numero del rango es de: %d\n",sum);
    printf("\nLa media del rango es de: %d\n",media);

}
