#include <stdio.h>
int main() {
    int cal1,cal2,cal3,prom;
    printf("Dame 3 calificaciones\n");
    scanf("%d",&cal1);
    scanf("%d",&cal2);
    scanf("%d",&cal3);
    prom = (cal1+cal2+cal3)/3;
    printf("Tu calificacion es de %d\n",prom);
    if (prom >= 80)
    {
        if (prom >= 90)
        {

            if (prom >= 98)
            {
                if (prom > 100)
                {
                    printf("Error");
                }
                else
                {
                    printf("Excelente");
                }
                
            }
            else
            {
                printf("Muy bien");
            }
            
        }
        else
        {
            printf("Bien");  
        }
        
    }
    else
    {
        if (prom >= 30)
        {
            if (prom >= 60)
            {
                if (prom >= 70)
                {
                    printf("Regular");
                }
                else
                {
                    printf("Suficiente");
                }
                
            }
            else
            {
                printf("Extraordinario");
            }
            
        }
        else
        {
            printf("Repetir");
        }
        
    }
}