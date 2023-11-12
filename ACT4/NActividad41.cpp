//Santos Tirado Martin 00369705
//1 de septiembre del 2023
/*2.- Programa en C que use un menú para realizar conversiones de unidades de medida, 
donde el usuario selecciona una opción y realizará la opción según sea su selección del menú.
MENÚ
1.- cm a pulgadas
2.- cm a pies
3.- Km a millas
4.- Pulgadas a cm
5.- pies a cm
6.- millas a Km*/
#include <stdio.h>
int main ()
{
    int menu;
    float resul,medida;
    printf("\nMENU\n");
    printf("\n1.-cm a pulgadas\n");
    printf("\n2.-cm a pies\n");
    printf("\n3.-km a millas\n");
    printf("\n4.-pulgadas a cm\n");
    printf("\n5.-pies a cm\n");
    printf("\n6.-millas a km\n");
    printf("\n7.-salir del menu\n");
    printf("\nEscoge una de las opciones con numero\n");
    scanf("%d",&menu);

    switch (menu)
        {
        case 1:
            printf("Escogiste cm a pulgadas, dame la medida para convertir\n");
            scanf("\t%f\n",&medida);
            resul= medida * 0.39370;
            printf("\nLa mediad en pulgadas es de: %f\n",resul);
            break;
        case 2:
            printf("Escogiste cm a pies, dame la medida para convertir\n");
            scanf("\t%f\n",&medida);
            resul= medida * 0.0328084;
            printf("\nLa mediad en pies es de: %f\n",resul);
            break;
        case 3:
            printf("Escogiste km a millas, dame la medida para convertir\n");
            scanf("\t%f\n",&medida);
            resul= medida * 0.621371;
            printf("\nLa mediad en millas es de: %f\n",resul);
            break;
        case 4:
            printf("Escogiste pulgadas a cm, dame la medida para convertir\n");
            scanf("\t%f\n",&medida);
            resul= medida * 2.54;
            printf("\nLa mediad en cm es de: %f\n",resul);
            break;
        case 5:
            printf("Escogiste pies a cm, dame la medida para convertir\n");
            scanf("\t%f\n",&medida);
            resul= medida * 30.48;
            printf("\nLa mediad en cm es de: %f\n",resul);
            break;
        case 6:
            printf("Escogiste millas a km, dame la medida para convertir\n");
            scanf("\t%f\n",&medida);
            resul= medida * 1.60934;
            printf("\nLa mediad en km es de: %f\n",resul);
            break;
        case 7:
            printf("Escogiste salir del menu!!\n");
            break;
        default:
            printf("\nNo seleccionas ninguna de las opciones!!\n");
            break;
        }
    return 0;
}