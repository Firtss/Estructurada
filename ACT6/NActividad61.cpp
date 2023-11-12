//Martin Santos Tirado
//00369705
//15 de septiembre de 2023
//El profesor de una materia desea conocer la cantidad de sus alumnos que no tienen derecho al examen de nivelación.
//Diseñe un programa en C que lea las calificaciones obtenidas en las 5 unidades por cada uno de los 40 alumnos 
//y escriba la cantidad de ellos que no tienen derecho al examen de nivelación 
//( Los promedios menores de 50 no tiene derecho a examen de nivelación) .
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu(void);
int unidades(int no1,int no2,int no3,int no4,int no5);
int promedio(int no1,int no2,int no3,int no4,int no5);
int msg(int n);
int main ()
{
    menu();
    return 0;
}
int msg(int n)
{
    system("CLS");
    printf("\t  MENU\n\t1-Unidades\n\t2-Promedio\n\t 0-Salir\n");
    scanf("%d",&n);
    return n;
}
void menu()
{
    int op,n;
    int no1,no2,no3,no4,no5;
    do
    {
        op = msg(n);
        switch (op)
        {
        case 1:
            unidades(no1,no2,no3,no4,no5);
            break;
        case 2:
            promedio(no1,no2,no3,no4,no5);
            break;
        case 0:
            printf("\nEscogiste salir\n");
            break;
        default:
            printf("\nNo escogiste una de las opciones\n");
            break;
        }
    } while (op != 0);
}
int unidades(int no1,int no2,int no3,int no4,int no5)
{
    system("CLS");
    srand(time(NULL));
    int calificacion;
    for (int i = 0; i < 40; i++)
    {
        calificacion = rand()%100;
        printf("Calificacion %d: %d\n",i+1,calificacion);
        if (calificacion < 50)
        {
            no1 = no1 + 1;
            no2 = no2 + 1;
            no3 = no3 + 1;
            no4 = no4 + 1;
            no5 = no5 + 1;
        }

    }
    return no1;
    return no2;
    return no3;
    return no4;
    return no5;
    system("PAUSE");
}

int promedio(int no1,int no2,int no3,int no4,int no5)
{
    system("CLS");
    printf("La cantidad de reprobados en la Unidad 1 es de: %d\n",no1);
    printf("La cantidad de reprobados en la Unidad 2 es de: %d\n",no2);
    printf("La cantidad de reprobados en la Unidad 3 es de: %d\n",no3);
    printf("La cantidad de reprobados en la Unidad 4 es de: %d\n",no4);
    printf("La cantidad de reprobados en la Unidad 5 es de: %d\n",no5);
    system("PAUSE");
    return 0;
}