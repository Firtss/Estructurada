//Santos Tirado Martin 00369705
//25 de agosto del 2023
/*Algoritmo que sirva para desplegar el Total de una llamada telefónica donde se pide
como datos de entrada los ​ minutos​ y el ​ tipo de llamada​ , se cobra de la siguiente manera:
1.- Llamada Loca​ l $3.00 sin límite de tiempo
2.-​ ​ Llamada Nacional​ $7.00 por los 3 primeros minutos y $2.00 minuto adicional
3.-​ ​ Llamada Internacional​ $9.00 por los 2 primeros minutos y $4.00 minutoadicional
Desplegar, ​ Subtotal​ ,​ Iva​ (16%) y ​ Tota​l.*/
#include <stdio.h>

int main()
{
    int llamada,minutos,cobro,min_3,tres_min,total;
    float iva;
    printf("Cuantos minutos estuvo en su llamada?");
    scanf("%d",&minutos);
    printf("Que tipo de llamada era?\n 1-Local \t 2-Nacional \t 3-Internacional \n ");
    scanf("%d",&llamada);

    if (llamada==1)
    {
        cobro= minutos * 3;
    }
    if (llamada==2)
    {
        min_3= minutos - 3;
        tres_min=21;
        if (minutos>3)
        {
            cobro = (min_3 *2) + tres_min;
        }
        else
        {
            cobro=tres_min;
        }
    }
    if (llamada==3)
    {
        min_3= minutos - 2;
        tres_min=18;
        if (minutos>3)
        {
            cobro = (min_3 *4) + tres_min;
        }
        else
        {
            cobro=tres_min;
        }
    }
    iva= cobro*0.16;
    total=cobro + iva;
    printf("\nSubtotal: %d\n",cobro);
    printf("\nIVA(16%): %f\n",iva);
    printf("\nTotal: %d\n",total);

    return 0;
}