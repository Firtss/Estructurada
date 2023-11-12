//Martin Santos Tirado
//00369705
//15 de septiembre de 2023
// Realiza una función en C que imprima las tablas de multiplicar del 1 al 10
#include <stdio.h>
#include <stdlib.h>
void multi(void);
int main()
{
    multi();
    return 0;
}
void multi()
{
    int num,resu,i;
    printf("\nDame un numero para darte su tabla\n");
    scanf("%d",&num);
    system("CLS");
    for ( i = 0; i < 10; i++)
    {
        resu=num*(i+1);
        printf("\n%d * %d = %d\n",num,i+1,resu);
    }
    system("PAUSE");
}