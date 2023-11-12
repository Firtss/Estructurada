//Martin Santos Tirado
//00369705
//30 de septiembre de 2023
/*Realiza programa en C el programa deberá tener el siguiente menú. 
MENÚ
1.- LLENAR VECTOR 1 (MANUALMENTE)
2.- LLENAR VECTOR 2 ALEATORIAMENTE
3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2)
4.- IMPRIMIR VECTORES
5.- LLENA MATRIZ 4 X 4
6.- IMPRIMIR MATRIZ
0.- SALIR
NOTA: EL PROGRAMA DEBERÁ REPETIRSE CUANTAS VECES LO DESEE EL USUARIO
NOTA 2: EL VECTOR 1 DE 10 POSICIONES, NÚMEROS DEL 30 AL 70 
NOTA 3: EL VECTOR 2 DE 10 POSICIONES CON NÚMEROS GENERADOS ALEATORIAMENTE DEL 1 AL 20 ( SIN REPETIR)
NOTA 4: EL VECTOR 3 DE 20 POSICIONES, CON LOS DATOS DEL ARREGLO1 Y ARREGLO2 
NOTA 5: MATRIZ 4 X 4 LLENARLA CON LOS DATOS DEL VECTOR1 Y VECTOR2, */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
bool vect1_filled = false;
bool vect2_filled = false;
bool vect3_filled = false;

void llenar_vector(int v1[]);
void llenar_vector2(int v2[]);
void llenar_vect12(int v1[],int v2[],int v3[]);
void imprvector(int v1[],int v2[],int v3[]);
void llenar_vector4x4(int v1[],int v2[],int v3[],int m[][4]);
void impr_matriz(int m[][4]);
bool sinrepetir(int v2[],int n);
int validaInt(int ri, int rf,const char msg[],const char msgError[]);
void menu();

int main()
{
    menu();
    return 0;
}
void menu()
{
    int v1[10],v2[10],v3[20];
    int op,i;
    int m[4][4];
    system("CLS");
    do{ 
    printf("\tMENU\n1-Llenar vector(Manualmente)\n2-Llenar vector(Aleatoriamente)\n3-Llenar con vector 1 y 2\n4-Imprimir vectores\n5-Llenar matriz 4x4\n6-Imprimir matriz\n0-Salir\n");
    op = validaInt(0,6,"Escoge una opcion","No escogiste una opcion");
        switch (op)
        {
        case 1: 
            llenar_vector(v1);
            break;
        case 2: 
            llenar_vector2(v2);
            break;
        case 3:
            if (vect1_filled && vect2_filled)
            {
                llenar_vect12(v1,v2,v3);
            }
            else
            {
                printf("Primero debes llenar Vector 1 y Vector 2.\n");
            }
            break;
        case 4: 
            if (vect1_filled && vect2_filled)
            {
                imprvector(v1,v2,v3);
            }
            else
            {
                printf("Primero debes llenar Vector 1 y Vector 2.\n");
            }
            break;
        case 5: 
            if (vect1_filled && vect2_filled && vect3_filled)
            {
                llenar_vector4x4(v1,v2,v3,m);
            }
            else
            {
                printf("Primero debes llenar los vectores 1,2 y 3.\n"); 
            }
            break;
        case 6: 
            if (vect1_filled && vect2_filled && vect3_filled)
            {
                impr_matriz(m);
            }
            else
            {
                printf("Primero debes de llenar los vectores 1,2 y 3\nademas de llenar la matriz con ellos.\n");
            } 
                
            break;
        case 0:
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
{int i,num;
    system("CLS");
    printf("Escogiste llenar vector manualmente\n");
    for(i=0;i<10;i++)
    {
        num = validaInt(10,70,"Dame un numero de 10 al 70\n","No pusiste un numero\n");
        if (num<=70 && num>=10)
        {
            v1[i]=num; 
        }
        else
        {
            printf("Tu numero no esta en el rango\n");
        }  
    }
    vect1_filled = true;  
    system("PAUSE");
}
bool sinrepetir(int v2[],int n)
{
    int i;
    for (i = 0; i <10; i++)
    {
        if (n == v2[i])
        {
            return true;
        }            
    }
    return false;
}
void llenar_vector2(int v2[])
{
    int i,num;
    system("CLS");
    srand(time(NULL));
    printf("Escogiste llenar vector aleatoriamente\n");
    for (i=0;i<10;i++)
    {   
        do
        {
            num=1+rand()%20; 
        } while (sinrepetir(v2,num));
        v2[i]=num;              
    }
    vect2_filled = true;
    system("PAUSE");
}
void llenar_vect12(int v1[],int v2[],int v3[])
{
    int i,num;
    system("CLS");
    printf("Escogiste llenar vecto con vector 1 y 2\n");
    for (i = 0; i <10; i++)
    {
        v3[i]= v1[i];
    }
    for (i = 0; i < 10; i++)
    {
        v3[i+10] = v2[i];
    }
    vect3_filled = true;
    system("PAUSE");
}
void  imprvector(int v1[],int v2[],int v3[])
{
    int ve,i,m,x;
    do{
        system("CLS");
        printf("Que vector deseas usuario\n Vector 1,Vector 2,Vector 3 para salir presione 0\n");
        scanf("%d",&ve);
        switch (ve)
        {
        case 1:
            printf("Escogiste el vector uno\n");
            m=10;
            for(i=0;i<m;i++)
            {
                printf("%2d:[%3d]\n",i+1,v1[i]);  //i+1 es para que no se vea el cero 
            }
            break;
        case 2:
            printf("Escogiste el vector dos\n");
            m=10;
            for(i=0;i<m;i++)
            {
                printf("%2d:[%3d]\n",i+1,v2[i]); //i+1 es para que no se vea el cero  
            }
            break;
        case 3:
            printf("Escogiste el vector tres\n");
            x=20;
            for(i=0;i<x;i++)
            {
                printf("%2d:[%3d]\n",i+1,v3[i]); //i+1 es para que no se vea el cero  
            }
            break;        
        default:
            printf("No pusiste una de las opciones\n");
            break;
        }
        system("PAUSE");
    }while(ve != 0);
}
void llenar_vector4x4(int v1[],int v2[],int v3[],int m[][4])
{
    int i,j,k;
    system("CLS");
    k = 0;
    printf("Escogiste matriz de 4x4\n");
    for (i=0;i<2;i++)
    {
        for (j=0;j<4;j++)
        {
            m[i][j] = v1[k];
            k++;
        }
        
    }
    k = 0;
    for (i=2;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            m[i][j] = v2[k];
            k++;
        }
        printf("\n");
    }
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
