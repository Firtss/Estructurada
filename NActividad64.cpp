//Martin Santos Tirado
//00369705
//15 de septiembre de 2023
//En los cabos la embarcación finisterra que tiene fondo de cristal, solo sale a navegar con un máximo de 10 turistas o un máximo de 700 kilos de pasajeros. 
//(preguntar el peso a cada turista) con un máximo de 15% de sobrepeso. desplegar el promedio de peso de los turistas y cual de los 2 condiciones se cumplió.
#include <stdio.h>
#include <stdlib.h>
void peso(void);
void peso()
{
    int pesoxpersona,i,sum,max,total;
    for ( i = 0; i < 10; i++)
    {
        printf("\nCual es tu peso turista %d\n",i+1);
        scanf("%d",&pesoxpersona);
        sum= sum + pesoxpersona;
        if (pesoxpersona >= 105 )
        {
            printf("Usted abarca el 15 porciento del peso maximo de la embarcacion");
            max = max + 1;
        }
    }
    if (sum > 700)
    {
        printf("Es demasiado peso para que la embarcacion salga");
    }
    else
    {
        printf("La embarcacion esta bien");
    }

}
int main ()
{
    peso();
    return 0;
}
