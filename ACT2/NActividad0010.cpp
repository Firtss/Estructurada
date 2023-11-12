//Santos Tirado Martin 00369705
//25 de agosto del 2023
/*Programa que sirva para calcular el salario semanal de un trabajador donde se obtiene
como dato de entrada las ​ horas semanales​ trabajadas, el ​ salario por hora​ .
El programa deberá calcular el ​ salario normal​ , ​ salario extra​ y ​ salario total​ , considerando
lo siguiente*/
#include <stdio.h>
#include <math.h>
int main()
{
    int horas,pago;
    float dobles,triples,extra,total;
  
        printf("Cuantas horas trabajaste?\n");
        scanf("%d",&horas);
        if (horas>40)
        {
            pago= horas * 250;
            printf("Tu salario normal es de: %d\n\n",pago);
            printf("Trabajaste horas extras \n\n favor de ingresar tus horas extras!:\n\n");
            scanf("%f",&extra);
           
                if(extra >8)
                {
                    dobles = 8;
                    triples = extra - dobles;
                    printf("Tus horas extras son:%.2f \n\n",extra);
                    total= (dobles*26)+(triples*39)+(pago*13);
                    printf("Tu paga total es de: %.2f \n\n",total);
                }
                if(extra <=8)
                {
                    printf("Tus horas extras son:%.2f \n\n",extra);
                    total= (extra*26)+(pago*13);
                    printf("Tu paga total es de: %.2f \n\n",total);
                }
        }
        else
        {
        printf("No trabajaste horas extras!\n\n");
        }
    

return 0;
}