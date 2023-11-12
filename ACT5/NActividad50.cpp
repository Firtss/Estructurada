//Martin Santos Tirado
//00369705
//8 de septiembre de 2023
/*1.- Función en C que pida al usuario el valor de n, y 
desplegar todos los números enteros positivos menores de n en orden descendente. 
2.- Función en "C" que genere 40 números aleatorios entre el 0 y 200, desplegar los números 
y la leyenda de cada número si es par o impar , la cantidad de los números pares e impares así como la suma de los números pares o impares.
3.- Función en "C" que genere N (35) cantidad de números (100 -200), desplegar al final el número mayor y el número menor. 
4.- Función en "C" que despliegue la tabla de multiplicar de un número dado (número entre el 1 y 20).*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu(void);
void orden_descendente(void);
void multiplicacion(void);
void par_impar(void);
void numero_mayor_a_menor(void);
int main()
{
    menu();
    return 0;
}
void menu()
{
    int op;
    do
    {
        system("CLS");
        printf("\tMENU\n\t1-Orden descendente los numeros a partir de n\n\t2-Par o Impar\n\t3-Mayor a menor de 100 num\n\t4-Tabla de multiplicar\n\t0-SALIR\n");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            orden_descendente();
            break;
        case 2:
            par_impar();
            break;
        case 3:
            numero_mayor_a_menor();
            break;
        case 4:
            multiplicacion();
            break;
        case 0:
            printf("Escogiste la opcion salir");
            printf("...");
            break;
        default:
            printf("No escribiste una de las opciones");
            break;
        }
    } while (op != 0);
}
void orden_descendente()
{
    system("CLS");
    int num;
    int i;
    printf("Dame un numero entero positivo y te dare sus numeros debaje de el\n");
    scanf("%d",&num);
    i = num;
    printf("Tu numero es: %d\nAqui los numeros menores a el---\n",num);
    do
    {
        printf("%d\n",num--);
        i = i - 1;
    } while (i != 0);
    
    system("PAUSE");
}
void par_impar()
{
    system("CLS");
    int i,num,cont1,cont2,sum1,sum2,resu,res;
    cont1=0;
    cont2=0;
    sum1=0;
    sum2=0;
    for (i=0; i <40; i++)
    {
        num= (rand()%201)+40;
        res= num % 2;
        if (res== 1)
        {
            printf("\nEl numero %d es impar\n",num);
            cont1= cont1 + 1;
            sum1=sum1 + num;
        }
        else
        {
            printf("\nEl numero %d es par\n",num);
            cont2= cont2 + 1;
            sum2= sum2 + num;
        }

    }
    resu= sum1 + sum2;
    printf("\nEl total de pares es de: %d\n",cont2);
    printf("\nEl total de impares es de: %d\n",cont1);
    printf("\nEl total en suma es de: %d\n",resu);
    system("PAUSE");
}
void numero_mayor_a_menor(void)
{
    system("CLS");
    int mayor,menor,num,i;
    mayor=0;
    menor=0;
    for(i=0 ; i < 35 ; i++)
    {
        num= (rand()%201-100)+35;
        printf("%d\n",num);
        if (num > mayor)
        {
            mayor = num;
        }
        else
        {
            menor = num;
        }
    }
    printf("\nEl numero mayor es: %d\n",mayor);
    printf("\nEl numero menor es: %d\n",menor);
    system("PAUSE");
}
void multiplicacion()
{
    system("CLS");
    int num,i,res;
    srand(time(NULL));
    num=1+rand()%(20-1+1);
    printf("\nTabla del: %d\n",num);
    for ( i = 1; i < 11; i++)
    {
        res= num * i;
        printf("\n%d X %d = %d\n",num,i,res);
    }
    system("PAUSE");
}