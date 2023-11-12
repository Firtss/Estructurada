//Martin Santos Tirado
//00369705
//15 de septiembre de 2023
//Un alumno solo puede cursar la misma asignatura en un máximo de 3 veses, si el alumno reprueba durante sus intentos deberá repetir la materia, 
//y si en su tercera ocasión no aprueba se le dará de baja académica.
//Elabore una función donde basada en sus 3 exámenes parciales calcular el promedio y basado en su promedio final,
//se deberá enviar mensaje al alumno de repetir materia, aprobado o baja temporal. 
#include <stdio.h>
#include <stdlib.h>
void alumno(void);
void alumno()
{
    int exa1,exa2,exa3,sum,prom,repro,i;
    repro = 0;
    do 
    {
        printf("\nDeme su calificacion de los 3 examenes parciales\n");
        scanf("%d",&exa1);
        scanf("%d",&exa2);
        scanf("%d",&exa3);
        prom = (exa1+exa2+exa3)/3;
        if (prom < 60)
        {
            printf("\nHas reprobado\n");
            repro= repro + 1;
            printf("%d",repro);
        }  
    }while (repro<3 && prom < 60);
    
    if (prom > 60)
    {
        printf("\nHas aprobado felicidades!!\n");
    }
    if (repro == 3)
    {
        printf("\nEstas dado de baja por el motivo de que reprobaste 3 veces la misma materia\n");
    }
}
int main()
{
    alumno();
    return 0;
}