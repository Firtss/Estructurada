//Santos Tirado Martin 00369705
//8 de agosto del 2023
//Como calcular un cilindro?
#include <stdio.h>
#include <math.h>

int main ()
{
    int altura;
    float radio,area_total;

    printf("Dame la altura y radio del cilindro ");
    printf("Altura: ");
    scanf("%d",&altura);
    printf("Radio: ");
    scanf("%f",&radio);

    area_total= (2*M_PI*(radio*radio)) + (2*M_PI*radio)*altura;

    printf("El area del cilindro es de: %f",area_total);


    return 0;
}