#define P 300
#define N 100
#include "Nocurp.h"
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

int main()
{
    menu();
    return 0;
}
int msg()
{
    int op;
    printf("\tMENU\n1-Cargar\n2-Eliminar\n3-Buscar\n4-Ordenar\n5-Imprimir\n6-Archivo Texto\n0-Salir\n");
    op = validaInt(0,6,"Escoge una de la opcion\n","Error, no escogiste una de las opciones");
    return op;
}
void menu()
{
    Tkey reg[P];
    int op, band, tam;
    tam = 0;
    band = 0;

    do{
        op = msg();
        switch(op)
        {
            case 1:
                tam = agregarR(reg, tam);
                tam = agregarM(reg, tam);
                break;
            case 2:
                eliminarR(reg, tam);
                break;
            case 3:
                buscarR(reg, tam);
                break;
            case 4: 
                band = ordenarR(reg, tam, band);
                break;
            case 5:
                imprimirR(reg, tam);
                break;
            case 6:
                archivo(reg,tam);
                break;
            case 0:
                printf("Has escogido salir del menu");
                break;
        }
        
    }while (op != 0);
}