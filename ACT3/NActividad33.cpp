//Santos Tirado Martin 00369705
//1 de SEPTIEMBRE del 2023
//Algoritmo que lea 3 números y desplegar los 3 números en orden ascendente
#include<stdio.h>
int main()
    {
        int num1, num2, num3;
        int mayor,medio,menor;
        printf("Dame 3 numeros enteros\n");
        scanf("%d",&num1);
        scanf("%d",&num2);
        scanf("%d",&num3);
        if (num1>num2)
        {
            if (num1>num3)
            {
                if (num2>num3)
                {
                    mayor=num1;
                    medio=num2;
                    menor=num3;
                }
                else
                {
                    mayor=num1;
                    medio=num3;
                    menor=num2;
                }
            }
            else
            {
                mayor=num3;
                medio=num1;
                menor=num2;
            }
        }
        else
        {
            if(num2>num3)
            {
                if(num1>num3)
                {
                     mayor=num2;
                     medio=num1;
                     menor=num3;
                }
                else
                {
                    mayor=num2;
                    medio=num3;
                    menor=num1;
                }
            }
            else
            {
                mayor=num3;
                medio=num2;
                menor=num1;
            }
        }


    printf("Tu numero mayor es: %d\t",mayor);
    printf("Tu numero medio es: %d\t",medio);
    printf("Tu numero menor es: %d\t",menor);

 return 0;
}