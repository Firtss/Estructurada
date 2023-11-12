//Santos Tirado Martin 00369705
//1 de septiembre del 2023
//8.- Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y la computadora, (usar condición anidada)
#include <stdio.h>
int main ()
{
    int mano;

    printf("Jugemos piedra,papel y tijera!! Yo comienzo: Escogo piedra");
    printf("\nPara jugar, utiliza este menu!!\n1=piedra\n2=papel\n3=tijera\n");
    scanf("%d",&mano);

    if(mano==1)
    {
        printf("Uy!! es un empate... otra vez?");
    }
    else
    {
        if(mano==2)
        {
        printf("No puede ser... me ganaste!, otra vez?");
        }
        else
        {
            printf("Si!! gane!!, quieres la revancha?");
        }       

    }
    
    return 0;
}