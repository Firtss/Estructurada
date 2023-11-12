#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define NUM_COL 4

int vali_int(int ran_inf, int ran_sup, char *msg, char *msg_error)
{
    int num;
    char char_num[25];

    do{
        printf("%s", msg);
        fflush(stdin);
        gets(char_num);
        num = atoi(char_num);

        if (num < ran_inf || num > ran_sup)
        {
            printf("%s\n", msg_error);
        }
    }while(num < ran_inf || num > ran_sup);

    return num;
}

long vali_long(long ran_inf, long ran_sup, char *msg, char *msg_error)
{
    long num;
    char char_num[25];

    do{
        printf("%s", msg);
        fflush(stdin);
        gets(char_num);
        num = atoi(char_num);

        if (num < ran_inf || num > ran_sup)
        {
            printf("%s\n", msg_error);
        }
    }while(num < ran_inf || num > ran_sup);

    return num;
}

void vali_num_cad(char cadena[], int ran_inf, int ran_sup, int max, char *msg, char *msg_error)
{
    char xnum[max];
    int num;

    do{
        printf("%s", msg);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if((num < ran_inf || num > ran_sup) || strlen(xnum) > max)
        {
            printf("%s\n", msg_error);
        }
    }while((num < ran_inf || num > ran_sup) || strlen(xnum) > max);

    strcpy(cadena, xnum);

}

int busq_sec(int vect[], int len, int val)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(val == vect[i])
        {
            return i;
        }
    }
    return -1;
}

char busq_vocal(char cadena[])
{
    int tam, i;
    tam = strlen(cadena);

    for(i=1; i<tam; i++)
    {
        if(cadena[i]=='A' || cadena[i]=='E' || cadena[i]=='I' || cadena[i]=='O' || cadena[i]=='U')
        {
            return cadena[i];
        }
    }

    return 'X';
}

char busq_vocal_dela(char cadena[])
{
    int tam, i;
    tam = strlen(cadena);

    for(i=7; i<tam; i++)
    {
        if(cadena[i]=='A' || cadena[i]=='E' || cadena[i]=='I' || cadena[i]=='O' || cadena[i]=='U')
        {
            return cadena[i];
        }
    }

    return 'X';
}

char busq_vocal_del(char cadena[])
{
    int tam, i;
    tam = strlen(cadena);

    for(i=5; i<tam; i++)
    {
        if(cadena[i]=='A' || cadena[i]=='E' || cadena[i]=='I' || cadena[i]=='O' || cadena[i]=='U')
        {
            return cadena[i];
        }
    }

    return 'X';
}

char busq_cons(char cadena[])
{
    int tam, i;
    tam = strlen(cadena);

    for(i=1; i<tam; i++)
    {
        if(cadena[i]!='A' && cadena[i]!='E' && cadena[i]!='I' && cadena[i]!='O' && cadena[i]!='U')
        {
            return cadena[i];
        }
    }

    return 'X';
}

char busq_cons_dela(char cadena[])
{
    int tam, i;
    tam = strlen(cadena);

    for(i=7; i<tam; i++)
    {
        if(cadena[i]!='A' && cadena[i]!='E' && cadena[i]!='I' && cadena[i]!='O' && cadena[i]!='U')
        {
            return cadena[i];
        }
    }

    return 'X';
}

char busq_cons_del(char cadena[])
{
    int tam, i;
    tam = strlen(cadena);

    for(i=5; i<tam; i++)
    {
        if(cadena[i]!='A' && cadena[i]!='E' && cadena[i]!='I' && cadena[i]!='O' && cadena[i]!='U')
        {
            return cadena[i];
        }
    }

    return 'X';
}

int existe_vect(int num, int *vect, int len)
{
    int i;
    for(i=0; i <= len; i++)
    {
        if (num == vect[i])
        {
            return 1;
        }
    }
    return 0;
}

int existe_mat(int num, int mat[][NUM_COL], int len)
{
    int i, j;
    for(i=0; i <= len; i++)
    {
        for(j=0; j <= len; j++)
        {
            if (num == mat[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}

void uno_a_dos_digitos(char cadena[2])
{
    int xnum_temp;
    xnum_temp = atoi(cadena);

    if(xnum_temp < 10)
    {
        cadena[0] = '0';
        cadena[1] = xnum_temp + '0';
        cadena[2] = '\0';
    }
}

int comp_esp(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);
    if(cadena[0] == '\0')
            return 0;
    for(i = 1; i <= tam; i++)
    {
        if(cadena[i] == ' ' && cadena[i+1] == ' ')
            return -1;
    }
}

int solo_letras(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);
    if (comp_esp(cadena) == 0)
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
}

void vali_cad(char cadena[], char *msg)
{
    int tam, band;

    band = 1;
    do{

        printf("%s", msg);
        fflush(stdin);
        gets(cadena);

        if (solo_letras(cadena) == 0)
        {
            if (comp_esp(cadena) == -1)
            {
                printf("No se permite doble espacio\n");
                continue;
            }
        }
        else
        {
            if(cadena[0] == ' ')
            {
                printf("No se permiten espacios\n");
                continue;
            }
            else
            {
                printf("Solo puedes ingresar letras\n");
                continue;
            }
        }

        strupr(cadena);
        band = 0;

    }while(band == 1);      
}

int comp_esp_obg(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);
    for(i = 1; i <= tam; i++)
    {
        if(cadena[i] == ' ' && cadena[i+1] == ' ')
            return -1;
    }
}

int solo_letras_obg(char cadena[])
{
    int tam;
    int i;

    tam = strlen(cadena);
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
}

void vali_cad_obg(char cadena[], char *msg)
{
    int tam, band;

    band = 1;
    do{

        printf("%s", msg);
        fflush(stdin);
        gets(cadena);

        if (solo_letras_obg(cadena) == 0)
        {
            if (comp_esp_obg(cadena) == -1)
            {
                printf("No se permite doble espacio\n");
                continue;
            }
        }
        else
        {
            if(cadena[0] == ' ')
            {
                printf("No se permiten espacios\n");
                continue;
            }
            else
            {
                printf("Solo puedes ingresar letras\n");
                continue;
            }
        }

        strupr(cadena);
        band = 0;

    }while(band == 1);      
}

void enie(char cadena[])
{
    int i, len;

    len = strlen(cadena);

    for(i=0; i<len; i++)
    {
        if (cadena[i] == -92 || cadena[i] == -91)
		{
			cadena[i] = 'X';
		}
    }
}

void enie_mayus(char cadena[])
{
    int i, len;

    len = strlen(cadena);

    for(i=0; i<len; i++)
    {
        if (cadena[i] == -92)
		{
			cadena[i] = -91;
		}
    }
}

int dela_del(char ap[])
{
    if(ap[0] == 'D' && ap[1] == 'E' && ap[2] == ' ' && ap[3] == 'L' && ap[4] == 'A' && ap[5] == ' ')
    {
        return 2;
    }
    else
    {
        if(ap[0] == 'D' && ap[1] == 'E' && ap[2] == 'L' && ap[3] == ' ')
        {
            return 1;
        }
    }
    
    return 0;


}