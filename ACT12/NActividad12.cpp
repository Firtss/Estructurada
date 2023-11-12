#define P 150
#define MAX 500
#include "Nocurp2.h"
int msg();
void menu();
int validaL(long ri, long rf, const char msg[], const char msgError[]);
int validaInt(int ri, int rf, const char msg[], const char msgError[]);
int busqSec(Tkey *vect, int tam, long matricula);
int ordenarR(Tkey registros[], int tam, int band);
int agregarR(Tkey registros[], int tam);
int agregarM(Tkey registros[], int tam);
int eliminarEsp(char cadena[]);
int soloLetras(char cadena[]);
int existeTkey(long mat, Tkey *reg, int tam);
Tkey datosR(Tkey registros[], int tam);
Tkey datosM(Tkey registros[], int tam);
void validaCad(char cadena[], const char *msg);
void burbuja(Tkey vect[], int tam);
void quickSort(Tkey registros[], int limIzq, int limDer);
void buscarR(Tkey registros[], int tam);
void imprimirR(Tkey vect[], int tam);
void eliminarR(Tkey registros[], int tam);
void archivo(Tkey vect[],int tam);
int cargartxt(Tkey vect[],int tam);

int main()
{
    menu();
    return 0;
}
int msg()
{
    int op;
    printf("\tMENU\n");
    printf("1-Cargar Archivo\n");
    printf("2-Agregar\n");
    printf("3-Eliminar\n");
    printf("4-Buscar\n");
    printf("5-Ordenar\n");
    printf("6-Mostrar Todo\n");
    printf("7-Generar archivo\n");
    printf("0-Salir\n");
    op = validaInt(0,7,"Escoge una de la opcion\n","Error, no escogiste una de las opciones");
    return op;
}
void menu()
{
    Tkey reg[P];
    int op, band, tam,i;
    tam = 0;
    band = 0;
    int opcion;
    Tkey vect[MAX];
    
    do{
        op = msg();
        switch(op)
        {
            case 1:
                tam = cargartxt(vect, tam);
                break;
            case 2:
                tam = agregarR(reg, tam);
                tam = agregarM(reg, tam);
                break;
            case 3:
                eliminarR(reg, tam);
                break;
            case 4: 
                buscarR(reg, tam);
                break;
            case 5:
                band = ordenarR(reg, tam, band);
                break;
            case 6:  
                imprimirR(reg, tam);
                break;
            case 7:
                archivo(reg,tam);
                break;
            case 0:
                printf("Has escogido salir del menu");
                break;
        }
        
    }while (op != 0);
}