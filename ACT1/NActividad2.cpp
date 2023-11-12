#include <stdio.h>
#include <math.h>
//Santos Tirado Martin 00369705
//8 de agosto del 2023
// Se tiene un terreno rectangular y se desea saber el costo de sembrar pasto en el considerando que cada metro cuadrado cuesta $35.40. 
// Además se pide determinar qué Cantidad de alambre se necesitará para cercarlo sin tomar en cuenta la altura de la cerca. 
// Elaborar un programa que muestre tales totales.


int main ()
{
    int largo,ancho;
    float siembra,alambre,area;
    printf("\nDe cuantos metros es de largo su terreno?\n");
    scanf("%d",&largo);
    printf("\nDe cuantos metros es de ancho su terreno?\n");
    scanf("%d",&ancho);
    area= largo*ancho;
    siembra= area * 35.40;
    printf("\nEl costo para sembrar en su terreno es de: %f\n",siembra);
    alambre= 2*largo+2*ancho;
    printf("\nLos metros de alambre que ocupara para alambrar su terreno es de: %f\n",alambre);

    return 0;
}