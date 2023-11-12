//Martin Santos Tirado
//00369705
//06 de octubre de 2023
/*1.- LLENAR VECTOR .-  Llenar vector con 15 números, los números generados aleatoriamente, los números entre el rango de 100 al 200 (no repetidos)
2.- LLENAR MATRIZ .- Llenar la matriz de 4x4 con con números generados aleatoriamente, números entre el rango de 1 al 16  (no repetidos)
3.- IMPRIMIR VECTOR .- Imprime el vector que se envíe, donde la función recibe como parámetro el vector,tamaño, nombre del vector.
4.- IMPRIMIR MATRIZ.-  Imprime la matriz sin importar el tamaño de la matriz recibiendo como parámetros la matriz,
la cantidad de renglones y columnas, así como nombre que se le dará a la matriz
5.- ORDENAR VECTOR.- Usar función que ordene el vector por el método de ordenación de la Burbuja mejorada.  
6.- BUSCAR VALOR EN VECTOR.-  Buscar un valor en el vector usando el método de búsqueda secuencial.
0.- SALIR */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

bool vect1_filled = false;
bool vect2_filled = false;

void llenar_vector(int v1[]);
void imprvector(int v1[]);
void llenar_matriz4x4(int m[][4]);
void impr_matriz(int m[][4]);
bool sinrepetir(int v1[],int n);
void ordenar_vect(int v1[],int tam);
bool sinrepetir_m(int m[][4],int i,int j,int n);
void buscar_valor(int v1[],int tam);
int validaInt(int ri, int rf,const char msg[],const char msgError[]);
void menu();

int main()
{
    menu();
    return 0;
}
void menu()
{
    int v1[15];
    int op,i;
    int m[4][4];
    int tam;
    system("CLS");
    do{ 
    printf("\tMENU\n1-Llenar 15 numeros en el vector\n2-Llenar matriz del 1 al 16\n3-Imprimir vector\n4-Imprimir matriz\n5-Ordenar Vector\n6-Buscar valor en vector\n7-Salir\n");
    op = validaInt(1,7,"Escoge una opcion","No escogiste una de las opciones");
        switch (op)
        {
        case 1: 
            llenar_vector(v1);
            break;
        case 2: 
            llenar_matriz4x4(m);
            break;
        case 3:
            if (vect1_filled == true)
            {
                imprvector(v1);
            }
            else
            {
                printf("Primero necesitar llenar el vector.\n");
            }
            
            break;
        case 4: 
            if (vect2_filled == true)
            {
                impr_matriz(m);
            }
            else
            {
                printf("Primero necesitas llenar la matriz.\n");
            }
            
            break;
        case 5: 
            if (vect1_filled == true)
            {
                ordenar_vect(v1,tam);
            }
            else
            {
                printf("Primero necesitar llenar el vector.\n");
            }
            
            break;
        case 6: 
            if (vect1_filled == true)
            {
                buscar_valor(v1,tam);
            }
            else
            {
                printf("Primero necesitar llenar el vector.\n");
            }
            break;
        case 7:
            printf("Saliendo del programa\n");
            break;
        }

    } while (op!=0); 
}
int validaInt(int ri, int rf,const char msg[],const char msgError[])
{
    int num;
    char xnum[30];
    do
    {
        puts(msg);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);

        if (num < ri || num > rf)
        {
            printf("%s", msgError);
            printf("\n");
        }
    } while (num < ri || num > rf);

    return num;
}
void llenar_vector(int v1[])
{
    int i,num;
    system("CLS");
    srand(time(NULL));
    printf("Escogiste llenar vector aleatoriamente\n");
    for (i=0;i<15;i++)
    {   
        do
        {
            num=100+rand()%(201-100); 
        } while (sinrepetir(v1,num));
        v1[i]=num;              
    } 
    vect1_filled = true; 
    system("PAUSE");
}
bool sinrepetir(int v1[],int n)
{
    int i;
    for (i = 0; i <15; i++)
    {
        if (n == v1[i])
        {
            return true;
        }            
    }
    return false;
}
void  imprvector(int v1[])
{
    int i;
    system("CLS");
    for(i=0;i<15;i++)
    {
        printf("%2d:[%3d]\n",i+1,v1[i]);  //i+1 es para que no se vea el cero 
    }
    system("PAUSE");
}
bool sinrepetir_m(int m[][4],int i,int j,int num)
{
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            if(num == m[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
void llenar_matriz4x4(int m[][4])
{
    int i,j,k;
    system("CLS");
    srand(time(NULL));
    int num;
    printf("Escogiste matriz de 4x4\n");
    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            do
            {
                num = 1+rand()%(17-1);
            } while (sinrepetir_m(m,4,4,num )== false);
            m[i][j] = num;
            
        }
        printf("\n");   
    }
    vect2_filled = true;
    system("PAUSE");
}
void impr_matriz(int m[][4])
{
    int i,j;
    system("CLS");
    printf("Escogiste imprimir matriz\n");
    for (i = 0; i < 4; i++)
    {
        printf("%2d: ",i);
        for (j = 0; j < 4; j++)
        {
            printf("[%3d]",m[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}
void ordenar_vect(int v1[],int tam)
{
    system("CLS");
    printf("Escogiste ordenar vector\n");
    int i, j,temp;
    for(i = 0; i < 15; i++)
    {
        for(j = 0; j < 15; j++)
        {
            if (v1[j] > v1[j+1])
            {
                temp = v1[j+1];
                v1[j+1] = v1[j];
                v1[j] = temp;            
            }
        }
    }
    for( i = 0 ; i < 15 ; i++)
    {
        printf("%2d:[%3d]\n",i+1,v1[i]);  //i+1 es para que no se vea el cero 
    }
    system("PAUSE");

}
void buscar_valor(int v1[],int tam)
{
    system("CLS");
    int i,dato;
    char band = 'F';
    i = 0;
    printf("Que numero deseas buscar?\n");
    scanf("%d",&dato);
    while (band == 'F' && i < 15)
    {
        if (v1[i] == dato)
        {
            band = 'V';
        }
        i ++;
    }
    if (band == 'F')
    {
        printf("El numero a buscar no existe en el vector\n");
    }
    else if (band == 'V')
    {
        printf("El numero a sido encontrado en la posicion: %d\n",i);
    }
    system("PAUSE");
}