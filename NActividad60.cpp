//Martin Santos Tirado
//00369705
//15 de septiembre de 2023
/*REALIZA LOS SIGUIENTES EJERCICIOS EN C SUBIR UN PROGRAMA QUE LLAME LOS 3 EJERCICIOS Y CON CADA UNA DE LAS SENTENCIAS.
MENÚ
1.- FIBONACCI
2.- FACTORIAL
3.- CANTIDAD DE DÍGITOS
1.- PROGRAMA QUE PREGUNTE LA CANTIDAD DE VECES QUE DESEA QUE SE REALICE EL PROGRAMA DE FIBONACCI
2.- PROGRAMA QUE PIDA UN NÚMERO Y DESPLEGAR LA SALIDA DE FACTORIAL DE UN NÚMERO DADO.
EJEMPLO
5 * 4 =20
20* 3 = 60
60*2 =120
FACTORIAL DE 5 = 120
3.- PROGRAMA QUE PIDA UN NÚMERO Y DESPLEGAR LA CANTIDAD DE DÍGITOS QUE TIENE EL NÚMERO.
EJEMPLO
25 TIENE 2 DÍGITOS 1
2578 TIENE 5 DÍGITOS*/

#include <stdio.h>
#include <stdlib.h>
#define N 10
int msges();
void menu();
void Fibonacci (void);
void Factorial (void);
void Digitos (void);
int main()
{
   menu();

	return 0;
}
int msges()
{ int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- FIBONACCI \n");
  printf("2.- FACTORIAL \n");
  printf("3.- DIGITOS \n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}
void menu()
{
  int op;
  do{
      op=msges();
      switch (op)
      {
        case 1:
              Fibonacci();
              break;
        case 2:
              Factorial();
              break;
        case 3:
              Digitos();
              break;

      }

    }while (op != 0);
}
void Fibonacci (void)
{
    system ("CLS");
    int i,ant,sig,res,cant;
    sig=1;
    ant=1;
    printf("\nDime cuantas quieres que se repita\n");
    scanf("%d",&cant);
    for(i=0;i<cant;i++)
    {
        res=ant+sig;
        ant=res;
        sig=res+1;
    } 
    system ("PAUSE");
}
void Factorial (void)
{
    system ("CLS");
    int i,num,ant,res,sig;
    printf("\nDame un numero\n");
    scanf("%d",&num);
    ant=num;
    sig= ant - 1;
    for (i=1;i<num;i++)
    {
        res=ant * sig;
        printf("\n%d * %d = %d\n",ant,sig,res);
        ant=res;
        sig--;
    }
    printf("\nEl factorial de %d es de = %d\n",num,res);
    system ("PAUSE");
}
void Digitos (void)
{ 
    system ("CLS");
    int numero, cociente, divisor, contador;
    cociente = 0;
    divisor = 1;
    contador = 0;

    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    while (cociente !=1)
    {
        contador++;
        divisor = divisor * 10;
        cociente = numero / divisor;

        if (cociente == 1)
        {
        printf("El numero tiene %d digitos\n", contador + 1);
        }

        if (cociente < 1)
        {
        printf("El numero tiene %d digitos\n", contador);
        cociente = 1;
        }

        if (numero < 10)
        {
        printf("Solo tiene un digito\n");
        }
  }
    system ("PAUSE");
}