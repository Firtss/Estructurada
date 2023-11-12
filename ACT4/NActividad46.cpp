//Santos Tirado Martin 00369705
//1 de septiembre del 2023
/*7- En la materia programación estructurada se aplican 5 exámenes, 
calcular el promedio final de la materia donde la calificación 
menor de los exámenes se anula y el promedio se calcula en base a 4 exámenes.
Desplegar el promedio final.*/
#include <stdio.h>
int main()
{
    int prom,mayor,menor;
    int E1,E2,E3,E4,E5;
    printf("Dame las calificaciones de los 5 examenes\n");
    printf("Examen 1:");
    scanf("%d",&E1);
    printf("Examen 2:");
    scanf("%d",&E2);
    printf("Examen 3:");
    scanf("%d",&E3);
    printf("Examen 4:");
    scanf("%d",&E4);
    printf("Examen 5:");
    scanf("%d",&E5); 
    if (E1 > E2)
    {
        menor = E2;
        if (menor > E3)
        {
            menor = E3;
            if (menor > E4)
            {
                menor = E4
                if (menor > E5)
                {
                    menor = E5;
                    prom = (E1 + E2 + E3 + E4)/4;
                    printf("El examen que se anulo fue el examen 5");
                    printf("El promedio es de: %d",prom);
                }
            }
        }
        else
        {
            menor = E2;
            if (menor > 4)
            {
                
            }
            
        }
    }
    else
    {
        menor = E1
        if (menor > E3)
        {
            menor = E3;
            if (menor > E4)
            {
                menor = E4;
                if (menor > E5)
                {
                    menor = E5;
                }
                else
                {

                }
                
            }
            else
            {

            }
            
        }
        else
        {

        }
        
    }
    
    
}