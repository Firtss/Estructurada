//Santos Tirado Martin 00369705
//1 de septiembre del 2023
//Programa en C que lea 6 números, desplegar el valor del número mayor.
#include <stdio.h>
int main()
{
    int mayor,num1,num2,num3,num4,num5,num6;
    printf("\nDame 6 numeros enteros\n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    scanf("%d",&num3);
    scanf("%d",&num4);
    scanf("%d",&num5);
    scanf("%d",&num6);
    mayor= num1;
    if (num2>num1)
    {
        mayor=num2;
        if (num3>num2)
        {
            mayor=num3;
            if (num4>num3)
            {
                mayor=num4;
                if (num5>num4)
                {
                    mayor=num5;
                    if (num6>num5)
                    {
                        mayor=num6;
                    }
                    else
                    {
                        mayor=num5;
                    }
                }
                else
                {
                    mayor=num4;
                }
            }
            else
            {
                mayor=num3;
            }
        }
        else
        {
            mayor=num2;
        }
    }
    else
    {
        mayor=num1; 
        if (num2>num3)
        {
            mayor=num2;
            if (num3>num4)
            {
                mayor=num3;
                if (num4>num5)
                {
                    mayor=num4;
                    if (num5>num6)
                    {
                        mayor=num5;
                    }
                    else
                    {
                        mayor=num6;
                    }
                }
                else
                {
                    mayor=num5;
                }
            }
            else
            {
                mayor=num4;
            }
        }
        else
        {
            mayor=num3;
        } 
    }

    printf("El numero mayor es: %d",mayor);

    return 0;
}