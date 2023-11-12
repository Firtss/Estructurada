#include <stdio.h>
//Martin Santos Tirado 00369705
//08/25/23
/*Algoritmo que lea un número entero, y desplegar si el número es “PAR” o “IMPAR”*/

int main(){
    int num;
    int res;
    printf("Dame un numero y te dire si es impar o par\n");
    scanf("%d",&num);
    res = num % 2;
    if (res== 0)
    {
        printf("Tu numero es par");
    }
    if (res!=0)
    {
        printf("Tu numero es impar");
    }
    return 0;
}