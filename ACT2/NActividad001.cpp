#include <stdio.h>
//Martin Santos Tirado 00369705
//08/25/23
/*Algoritmo que lea 4 calificaciones de un alumno, 
calcular y desplegar el promedio acompañado de la leyenda APROBADO o REPROBADO*/
//NActividad001
int main(){
    int cal1,cal2,cal3,cal4;
    int prom;
    printf("Dame tus 4 calificaciones\n");
    scanf("%d",&cal1);
    scanf("%d",&cal2);
    scanf("%d",&cal3);
    scanf("%d",&cal4);
    prom = (cal1+cal2+cal3+cal4)/4;
    printf("Tu promedio es de: %d\n",prom);

    if (prom >= 60)
    {
        printf("APROBASTE\n");
    }
    if (prom<60)
    {
        printf("REPROBASTE\n");
    }
    return 0;
}