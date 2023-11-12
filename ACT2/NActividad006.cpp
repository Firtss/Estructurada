//Santos Tirado Martin 00369705
//8 de agosto del 2023
// Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar: 
/* Si prom < 30 Repetir 
 Si prom >=30 y prom <60 extraordinario 
 Si prom >=60 y prom <70 suficiente 
 Si prom >=70 y prom <80 Regular 
 Si prom >=80 y prom <90 bien 
 Si prom >=90 y prom <98 muy bien 
 Si prom >=98 y prom <=100 excelente 
 Si prom >100 Error en promedio */
#include <stdio.h>

int main()
{

    int cali1,cali2,cali3,prom;
    printf("Dame tus 3 calificaciones\n");
    printf("Calificacion 1: ");
    scanf("%d",&cali1);
    printf("Calificacion 2: ");
    scanf("%d",&cali2);
    printf("Calificacion 3: ");
    scanf("%d",&cali3);

    prom=(cali1+cali2+cali3)/3;

        if (prom>=98)
        {
            printf("Excelente");
        }
        else
        {
            if(prom>=90)
            {
                printf("Muy bien");
                
            }
            else
            {
                if (prom>=80)
                {
                    printf("Bien");
                      
                }
                else
                {
                    if (prom>=70)
                    {
                        printf("Regular");
                    }
                    else
                    {
                        if (prom>=60)
                        {
                            printf("Suficiente");
                        }
                        else
                        {
                            if (prom>=30)
                            {
                                printf("Extraordinario");
                            }
                            else
                            {
                                printf("Repetir");
                            }
                            
                        }
                        
                    } 
                    
                }
            }
        
        }
    
    return 0;
}