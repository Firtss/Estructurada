#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct Tkey
{
    long matri;
    char nombre[31];
    char apellidoP[31];
    char apellidoM[31];
    int status;
    int genero;
    int edad;
     
}Tkey;
int validaL(long ri, long rf,const char msg[],const char msgError[])
{
    long num;
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
int busqSec(Tkey *registros, int tam, long matricula)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        if(registros[i].matri == matricula)
        {
            return i;
        }
    }

    return -1;
}
void burbuja(Tkey vect[], int tam)
{
    system("CLS");
    int i, j;
    Tkey burbuja;
    for(i = 0; i < tam - 1; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            if (vect[j].matri < vect[i].matri)
            {
                burbuja = vect[j];
                vect[j] = vect[i];
                vect[i] = burbuja;            
            }
        }
    }

    system("PAUSE");
}
void quickSort(Tkey registros[], int limIzq, int limDer)
{
    int izq, der, tem;
    Tkey central;

    izq = limIzq;
    der = limDer;
    central.matri = registros[(izq + der) / 2].matri;

    do{

        while(registros[izq].matri < central.matri && izq < limDer)
        {
            izq++;
        }
        
        while(central.matri < registros[der].matri && der > limIzq)
        {
            der--;
        }

        if ( izq <= der)
        {
            tem = registros[izq].matri;
            registros[izq].matri = registros[der].matri;
            registros[der].matri = tem;
            izq++;
            der--;
        }
    }while(izq <= der);

    if (limIzq < der)
    {
        quickSort(registros, limIzq, der);
    }

    if (limDer > izq)
    {    
        quickSort(registros, izq, limDer);
    }
}
int ordenarR(Tkey registros[], int tam, int band)
{
    system("cls");
    if(tam > 0)
    {
        if(band == 0)
        {
            burbuja(registros, tam);
            band = 1;
        }
        else
        {
            quickSort(registros, 0, tam);
        }
        
        printf("HAS ORDENADO LOS DATOS\n");
        system("PAUSE");
        return band;
    }
    else
    {
        printf("PRIMERO DEBE HABER DATOS\n");
        system("PAUSE");
        return 0;
    }
}
int eliminarEsp(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);

    if(cadena[0] == '\0')
    {
        return 0;
    }

    for(i = 0; i <= tam; i++)
    {
        if(cadena[i] == ' ' && cadena[i + 1] == ' ')
        {
            return -1;
        }
    }
    return 0;
}
int soloLetras(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);

    if(eliminarEsp(cadena) == 0)
    {
        return 0;
    }

    for(i =  0; i <= tam; i++)
    {
        if(cadena[i] < 'A' || cadena[i] > 'z')
        {
            return -1;
        }
        if(cadena[i] > 'Z' && cadena[i] < 'a')
        {
            return -1;
        }

        return 0;
    }
    return 0;
}
void validaCad(char cadena[], const char *msg)
{
    int tam, band;

    band = 1;
    do{

        printf("%s", msg);
        fflush(stdin);
        gets(cadena);
        
        if (soloLetras(cadena) == 0)
        {
            if(eliminarEsp(cadena) == -1)
            {
                printf("NO SE PERMITEN ESPACIOS\n");
                continue;
            }
        }
        else
        {
            if(cadena[0] == ' ')
            {
                printf("NO SE PERMITEN ESPACIOS\n");
                continue;
            }
            else
            {
                printf("INGRESA SOLO LETRAS\n");
                continue;
            }
        }

        strupr(cadena);
        band = 0;

    }while(band == 1);      
}
int existeTkey(long mat, Tkey *reg, int tam)
{
    int i;
    
    for(i = 0; i <= tam; i++)
    {
        if (mat == reg[i].matri)
        {
            return 1;
        }
    }
    return 0;
}
Tkey datosR(Tkey registros[], int tam)
{
    Tkey reg;
    long matri;
    char *nombre;
    char *apellido;
    int status;
    int sexo;
    int edad;

    matri = (rand() % 99999) + 300000;
    while(existeTkey(matri, registros, tam) == 1)
    {
        matri = (rand() % 99999) + 300000;
    }

    edad = (rand() % 60) + 17;
    status = rand() % 2;
    sexo = rand() % 2;
    
    reg.status = status;
    reg.matri = matri;
    reg.edad = edad;
    reg.genero = sexo;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    char nombresM[][31] = {"Juan", "Luis", "Carlos", "Pedro"};
    char nombresF[][31] = {"Maria", "Ana", "Laura", "Sofia"};
    char apellidosP[][31] = {"Garcia", "Rodriguez", "Martínez", "Lopez", "Perez", "Fernandez", "Gonzalez", "Hernandez"};
    char apellidosM[][31] = {"Sanchez", "Ramirez", "Torres", "Diaz", "Vargas", "Jimenez", "Ruiz", "Silva"};
    int apellidoPIndex = rand() % 8;
    int apellidoMIndex = rand() % 8;
    if (sexo == 1) 
    {
        // Genera un índice aleatorio para nombres masculinos
        int nombreIndex = rand() % 4;
        strcpy(reg.nombre, nombresM[nombreIndex]);
    } 
    else 
    {
        // Genera un índice aleatorio para nombres femeninos
        int nombreIndex = rand() % 4;
        strcpy(reg.nombre, nombresF[nombreIndex]);
    }

    /*strcpy(reg.nombre, nombres[nombreIndex]);*/
    strcpy(reg.apellidoP, apellidosP[apellidoPIndex]);
    strcpy(reg.apellidoM, apellidosM[apellidoMIndex]);
    
    return reg;
}
int agregarR(Tkey registros[], int tam)
{   
    system("CLS");
    int i;
    int band = 0;
    for(i = 0; i < 100; i++)
    {
        system("CLS");
        registros[tam] = datosR(registros, tam);
        system("CLS");
        tam++;
    }
    printf("HAS GENERADO 500 REGISTROS\n");
    system("PAUSE");

    return tam;
}
Tkey datosM(Tkey registros[], int tam)
{

    Tkey reg;
    long mat;
    char apPat[21], apMat[21], nombre[41];
    do{
        reg.status = validaInt(0, 1,"0) INACTIVO 1) ACTIVO","FUERA DE RANGO");
        mat = validaL(300000, 399999,"INGRESA TU MATRICULA: ","MATRICULA INVALIDA");
        if(existeTkey(mat, registros, tam) == 1)
        {
            printf("ESTA MATRICULA YA EXISTE \n INGRESE UNA MATRICULA VALIDA\n");
        }
    }while(existeTkey(mat, registros, tam) == 1);
    
    reg.matri = mat;

    validaCad(apPat, "INGRESA TU APELLIDO PATERNO: \n");
    strcpy(reg.apellidoP, apPat);

    validaCad(apMat, "INGRESA TU APELLIDO MATERNO: \n");
    strcpy(reg.apellidoM, apMat);

    validaCad(nombre, "INGRESA TU NOMBRE: \n");
    strcpy(reg.nombre, nombre);

    reg.edad = validaInt(17, 80,"INGRESA LA EDAD: ","EDAD FUERA DE RANGO");
    reg.genero = validaInt(1, 2,"INGRESE EL GENERO\n 1) HOMBRE\n 2) MUJER","OPCION FUERA DE RANGO"); 

    return reg;
}
int agregarM(Tkey registros[], int tam)
{   
    int op = 1;
    do{
        system("CLS");
        registros[tam] = datosM(registros, tam);
        system("CLS");
        tam++;
        op = validaInt(0, 1,"1.- AGREGAR DATOS \n0.- SALIR \n SELECCIONE UNA OPCION: ","OPCION FUERA DE RANGO");
    }while(op == 1);

    return tam;
}
void imprimirR(Tkey registros[], int tam)
{
    Tkey reg;
    int i;
    char *sexo;
    system("CLS");
    
    if (tam > 0)
    {
        printf("%-10s %-14s %-15s %-20s %-20s %-10s %-10s\n", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
        
        for (i = 0; i < tam; i++)
        {
            if(registros[i].genero == 1)
            {
                strcpy(sexo,"HOMBRE");;
            }
            else
            {
                strcpy(sexo,"MUJER");
            }

            if (registros[i].matri != -1 && registros[i].matri >= 300000 && registros[i].matri <= 399999)
            {
                printf("%-10d %-14ld %-15s %-20s %-20s %-10d %-10s\n", registros[i].status, registros[i].matri, registros[i].nombre, registros[i].apellidoP, registros[i].apellidoM, registros[i].edad, sexo);
            }
        }
    }
    else
    {
        printf("INGRESE DATOS PARA PODER IMPRIMIR\n");
    }

    printf("\n");
    system("PAUSE");
}
void buscarR(Tkey registros[], int tam)
{
    system("CLS");
    long mat;
    int pos, id, i;
    char *sexo;
    int band = 0;

    id = validaL(300000, 399999,"INGRESA LA MATRICULA QUE QUIERES ELIMINAR: ","MATRICULA INVALIDA");
    pos = busqSec(registros, tam, id);

    if (pos != -1)
    {
        system("CLS");
        printf("\nRESULTADOS ENCONTRADO.\n%-10s %-14s %-15s %-20s %-20s %-10s %-10s\n", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
        if(registros[pos].genero == 1)
        {
            strcpy(sexo,"HOMBRE");
        }
        else
        {
            strcpy(sexo,"MUJER");
        }

        if (registros[pos].matri != -1 && registros[pos].matri >= 300000 && registros[pos].matri <= 399999)
        {
            printf("%-10d %-14ld %-15s %-20s %-20s %-10d %-10s\n", registros[pos].status, registros[pos].matri, registros[pos].nombre, registros[pos].apellidoP, registros[pos].apellidoM, registros[pos].edad, sexo);
        }
    }
    else
    {
        printf("NO SE ENCONTRO LA MATRICULA\n");
    }

}
void eliminarR(Tkey registros[], int tam)
{
    system("CLS");

    long id;
    int pos, op;

    id = validaL(300000, 399999,"INGRESA LA MATRICULA QUE QUIERES ELIMINAR: ","MATRICULA INVALIDA");
    pos = busqSec(registros, tam, id);

    if (pos != -1)
    {
        imprimirR(registros, tam);
        op = validaInt(1, 2,"1) ELIMINAR\n 2) NO ELIMINAR\n","OPCION FUERA DE RANGO");

        if (op == 1)
        {
            registros[pos].status = 0;
        }    
    }
    else
    {
        printf("LA MATRICULA NO EXISTE\n");
    }
}
void archivo(Tkey registros[],int tam)
{
    system("CLS");
    Tkey reg;
    int i;
    char *sexo;
    FILE *arch;
    arch=fopen("archivo.txt","w");
    if (tam > 0)
    {
        fprintf(arch,"%-10s %-14s %-15s %-20s %-20s %-10s %-10s\n", "ESTATUS", "MATRICULA", "NOMBRE", "APELLIDO PATERNO", "APELLIDO MATERNO", "EDAD", "GENERO\n");
        
        for (i = 0; i < tam; i++)
        {
            if(registros[i].genero == 1)
            {
                strcpy(sexo,"HOMBRE");
            }
            else
            {
                strcpy(sexo,"MUJER");
            }

            if (registros[i].matri != -1 && registros[i].matri >= 300000 && registros[i].matri <= 399999)
            {
                fprintf(arch,"%-10d %-14ld %-15s %-20s %-20s %-10d %-10s\n", registros[i].status, registros[i].matri, registros[i].nombre, registros[i].apellidoP, registros[i].apellidoM, registros[i].edad, sexo);
            }
        }
        printf("Se han cargado los datos en el archivo");
        fclose(arch);
    }
    else
    {
        printf("INGRESE DATOS PARA PODER IMPRIMIR\n");
    }

    printf("\n");
    system("PAUSE");
}