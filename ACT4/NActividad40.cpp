//Santos Tirado Martin 00369705
//1 de septiembre del 2023
//1.- Programa en C que use un menú para realizar 
//las 4 operaciones básicas, donde el usuario introduce 2 números enteros y 
//realizará la operación según sea su selección del menú.
//MENÚ
//1.- Suma
//2.- Resta
//3.- Multiplicación
//4.-División
#include <stdio.h>

int main()
{
    int num1,num2,resul,menu;
    float resul2;
        printf("\nMENU\n");
        printf("\n1.-Suma\n");
        printf("\n2.-Resta\n");
        printf("\n3.-Multiplicacion\n");
        printf("\n4.-Division\n");
        printf("\n5.-Salir\n");
        printf("\nEscoge una de las opciones con numero\n");
        scanf("%d",&menu);

        switch (menu)
        {
        case 1:
            printf("Escogiste suma, dame 2 numeros enteros\n");
            scanf("\t%d\n",&num1);
            scanf("\t%d\n",&num2);
            resul= num1 + num2;
            printf("\nLa suma de los 2 numeros es: %d\n",resul);
            break;
        case 2:
            printf("Escogiste resta, dame 2 numeros enteros\n");
            scanf("\t%d\n",&num1);
            scanf("\t%d\n",&num2);
            resul= num1 - num2;
            printf("\nLa resta de los 2 numeros es: %d\n",resul);
            break;
        case 3:
            printf("Escogiste multiplicacion, dame 2 numeros enteros\n");
            scanf("\t%d\n",&num1);
            scanf("\t%d\n",&num2);
            resul= num1 * num2;
            printf("\nLa multiplicacion de los 2 numeros es: %d\n",resul);
            break;
        case 4:
            printf("\nEscogiste division, dame 2 numeros enteros\n");
            scanf("\t%d\n",&num1);
            scanf("\t%d\n",&num2);
            resul2= num1 / num2;
            printf("\nLa division de los 2 numeros es: %d\n",resul2);
            break;
        case 5:
            printf("\nEscogiste salir del menu\n");
            break;
        default:
            printf("\nNo seleccionas ninguna de las opciones!!\n");
            break;
        }
    return 0;
}