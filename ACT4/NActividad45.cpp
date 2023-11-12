//Santos Tirado Martin 00369705
//1 de septiembre del 2023
/*6.- Programa en C que sirva para calcular el Total a pagar por consumo de agua, 
donde el dato de entrada son los M3 de agua consumidos, 
Tomar en cuenta que se cobra escalonada de la Siguiente manera:
Rango1: 0 al 4 M3 $50 x facturación sin importar cuánto consumió en este rango
Rango2: 5 a 15 M3 $8.00 x M3
Rango3: 16 a 50 M3 $10.00 x M3
Rango4: 51 M3 en adelante $11.00 x M3
Nota: Desplegar SubTotal, Iva(16%), y Total a pagar.*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m3,consumo,iva,total;
    printf("Dame la cantidad de M3 de agua consumidos para darte el total a pagar");
    scanf("%d",&m3);
    if (m3 <= 15)
    {
        consumo = (m3 * 8);
        iva = consumo * 0.16;
        total = consumo + iva;
        printf("El total a pagar es de\nSubtotal: %d\nIva: %d\nTotal: %d",consumo,iva,total);
        if (m3 <= 4)
        {
            consumo = (m3 * 50);
            iva = consumo * 0.16;
            total = consumo + iva;
            printf("El total a pagar es de\nSubtotal: %d\nIva: %d\nTotal: %d",consumo,iva,total);
        }
        
    }
    else
    {
        if (m3 >= 51)
        {
            consumo = (m3 * 11);
            iva = consumo * 0.16;
            total = consumo + iva;
            printf("El total a pagar es de\nSubtotal: %d\nIva: %d\nTotal: %d",consumo,iva,total);
        }
        else
        {
            consumo = (m3 * 10);
            iva = consumo * 0.16;
            total = consumo + iva;
            printf("El total a pagar es de\nSubtotal: %d\nIva: %d\nTotal: %d",consumo,iva,total);
        }
        
    }
    
    return 0;
}