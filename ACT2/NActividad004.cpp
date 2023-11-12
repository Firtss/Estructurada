//Santos Tirado Martin 00369705
//25 de agosto del 2023
/*Algoritmo que a través de opciones (1.- HOMBRE 2.- MUJER ) preguntar al usuario cual es
su SEXO y desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”*/
#include <stdio.h>
int main(){
    int sexo;
    printf("Eres Hombre o Mujer? \nPresione 1 para Hombre\nPresione 2 para Mujer\n");
    scanf("%d",&sexo);
    if (sexo == 1)
    {
        printf("Hola, eres un Hombre");
    }
    else
    {   
        if (sexo == 2)
        {
            printf("Hola, eres una Mujer");
        }
        else
        {
            printf("No escogite una de las opciones por lo que eres un tanque sovietico T-80");
        }   
    }
    return 0;
}