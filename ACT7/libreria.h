#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void mayusculas(char cad[]);
void minusculas(char cad[]);
void capital(char cad[]);
int tam_cad(char cad[]);
void reves(char cad1[],char cad2[]);
void sinespacios(char cad[]);
void solo_az(char cad[]);
void combo(char cad[]);
void palindromo(char cad1[],char cad2[]);

void mayusculas(char cad[])
{
    int i, tam;
    tam = tam_cad(cad);
    for (i = 0; i < tam; i++)
    {
        if (cad[i] >= 'a' && cad[i] <= 'z')
        {
            cad[i] = cad[i] - ('a' - 'A');
        }
    }
}
void minusculas(char cad[])
{
    int i, tam;
    tam = tam_cad(cad);
    for (i = 0; i < tam; i++)
    {
        if (cad[i] >= 'A' && cad[i] <= 'Z')
        {
            cad[i] = cad[i] + ('a' - 'A');
        }
    }
}
void capital(char cad[])
{
    int i, tam;
    tam = tam_cad(cad);
    for (i = 0; i<tam; i++)
    {
        
        if (cad[i] != '\0')
        {
            if (cad[i] > cad[0])
            {
                if (cad[i] > '\0' && cad[i] >= 'A' && cad[i] <= 'Z');
                
                if (cad[i] >= 'A' && cad[i] <= 'Z')
                {
                    cad[i] = tolower(cad[i]);
                }
            }  
        }
        else
        {
            printf(" ");
        }
    }
}
int tam_cad(char cad[])
{
    int i;
    for (i = 0; cad[i] != '\0'; i++);
        
    return i;
}
void reves(char cad1[], char cad2[])
{
    int i, tam;
    tam = tam_cad(cad1);
    tam--;
    for (i = 0; i <= tam; i++)
    {
        cad2[i] = cad1[tam - i];
    }
}
void sinespacios(char cad[])
{
    int i,j;
    i=0;
    j=0;
    while (cad[i]!='\0') 
    {
        if(cad[i]!=' ')
        {
            cad[j]=cad[i];
            j++;
        }
        i++;
    }
}
void solo_az(char cad[])
{
}
void combo(char cad[])
{
    int i, j, tam;
    tam = tam_cad(cad);
    
    for (i = 0; i < tam; i++)
    {
        if (cad[i] >= 'a' && cad[i] <= 'z')
        {
            cad[i] = cad[i] - ('a' - 'A');
        }
    }
    for (i = 0; i < tam; i++)
    {
        if (cad[i] >= 'A' && cad[i] <= 'Z')
        {
            cad[i] = cad[i] + ('a' - 'A');
        }
    }
    i=0;
    j=0;
    while (cad[i]!='\0') 
    {
        if(cad[i]!=' ')
        {
            cad[j]=cad[i];
            j++;
        }
        i++;
    }
}
void palindromo(char cad1[], char cad2[])
{
    int i, j, tam, band;
    band=0;
    j=0;
    tam=tam_cad(cad1);
    reves(cad1, cad2);
    for (i=0; i<tam; i++)
    {
        if (cad1[i]==cad2[i])
        {
            j++;
        }
    }
    if (j==tam)
    {
        puts(cad1);
        printf(" es un palindromo\n");
    }
}