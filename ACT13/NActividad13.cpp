#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Nocurp3_0.h"

#define MAX 2500

int msgs();
void menu();

void agg_autom(Talum vect[], int *n, int max);
void edit_datos(Talum vect[], int n, int band);
void elim_datos(Talum vect[], int n, int band);
void busq_datos(Talum vect[], int n, int band);
void ord_datos(Talum vect[], int n, int *band);
void imp_datos(Talum vect[], int n);
void crear_arch_txt(Talum vect[], int n);
void ver_arch_txt(Talum vect[], int n);
void crear_arch_bin(Talum vect[], int n);
void cargar_arch_bin(Talum vect[], int *n, int max, int *band);

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}

int msgs()
{
    int opc;
    system("cls");
    printf("------Menu------\n");
    printf("1.-  Agregar registros\n");
    printf("2.-  Editar registro\n");
    printf("3.-  Eliminar registro\n");
    printf("4.-  Buscar registro\n");
    printf("5.-  Ordenar registros\n");
    printf("6.-  Imprimir registros\n");
    printf("7.-  Generar archivo de texto\n");
    printf("8.-  Ver archivo de texto\n");
    printf("9.-  Generar archivo binario\n");
    printf("10.- Cargar archivo binario\n");
    printf("0.- Salir\n");
    opc = vali_int(0, 10, "Seleccione una opcion: ", "Opcion invalida");
    return opc;
}

void menu()
{
    Talum alumnos[MAX];
    int opc, i, band_ord, band_carg;
    FILE *arch;
    i = 0;
    band_ord = 0;
    band_carg = 0;

    do{
        opc = msgs();
        switch(opc)
        {
            case 1:
                agg_autom(alumnos, &i, MAX);
                break;
            case 2:
                edit_datos(alumnos, i, band_ord);
                break;
            case 3:
                elim_datos(alumnos, i, band_ord);
                break;
            case 4: 
                busq_datos(alumnos, i, band_ord);
                break;
            case 5:
                ord_datos(alumnos, i, &band_ord);
                break;
            case 6:
                imp_datos(alumnos, i);
                break;
            case 7:
                crear_arch_txt(alumnos, i);
                break;
            case 8:
                ver_arch_txt(alumnos, i);
                break;
            case 9:
                crear_arch_bin(alumnos, i);
                break;
            case 10:
                cargar_arch_bin(alumnos, &i, MAX, &band_carg);
                break;
        }
    }while (opc != 0);
}

void agg_autom(Talum vect[], int *n, int max)
{
    int i, j;
    
    i = (*n);
    for(j=0; j < 2300; j++)
    {
        system("cls");
        vect[i] = datos_autom(vect, i);
        i++;
    }
    for(j=0; j < 200; j++)
    {
        system("cls");
        vect[i] = datos_autom_inac(vect, i);
        i++;

    }
    printf("Se han generado 100 datos aleatorios correctamente\n");
    system("pause");

    (*n) =  i;
}

void edit_datos(Talum vect[], int n, int band)
{
    long mat;
    int posi, temp_int, correct = 0;
    char *estatus, *sexo, temp_char[35];
    Talum reg;

    system("cls");
    if(n > 0)
    {
        mat = vali_long(300000, 399999, "Ingrese la matricula a editar: ", "Matricula invalida");
        if(band == 0)
        {   
            posi = busq_sec_talum(vect, n, mat);
        }
        else
        {
            posi = busq_bin_talum(vect, n, mat);
        }
        if(posi != -1)
        {
            system("cls");
            reg = vect[posi];

            if(reg.genero == 0)
            {
                sexo = "MASCULINO";
            }
            else
            {
                sexo = "FEMENINO";
            }
            /*
            if(reg.estatus == 0)
            {
                estatus = "INACTIVO";
            }
            else
            {
                estatus = "ACTIVO";
            }

            do
            {
                printf("Estado actual: %s", estatus);
                temp_int = vali_int(0, 1, "0.- Inactivo \n1.- Activo \nIngrese el nuevo dato: ", "Valor invalido");
                correct = vali_int(0, 1, "0.- No \n1.- Si \nEs correcto: ", "Valor invalido");
                system("cls");
            }while(correct == 0);
            reg.estatus = temp_int;
           */

            if(reg.estatus != 0)
            {
                do
                {
                    printf("Matricula actual: %d\n", reg.mat);
                    temp_int = vali_int(300000, 399999, "Ingrese el nuevo dato: ", "Valor invalido");
                    correct = vali_int(0, 1, "\n0.- No \n1.- Si \nEs correcto: ", "Valor invalido");
                    system("cls");
                    if(existe_talum_matri(temp_int, vect, n) == 1)
                    {
                        printf("El valor ingresado ya se encuentra registrado\n");
                        system("pause");
                        system("cls");
                    }
                }while(correct == 0 || existe_talum_matri(temp_int, vect, n) == 1);
                reg.mat = temp_int;

                do
                {
                    printf("Apellido paterno actual: %s\n", reg.ap_pat);
                    vali_cad_obg(temp_char, "Ingrese el nuevo dato: ");
                    correct = vali_int(0, 1, "\n0.- No \n1.- Si \nEs correcto: ", "Valor invalido");
                    system("cls");
                }while(correct == 0);
                strcpy(reg.ap_pat, temp_char);

                do
                {
                    printf("Apellido materno actual: %s\n", reg.ap_mat);
                    vali_cad_obg(temp_char, "Ingrese el nuevo dato: ");
                    correct = vali_int(0, 1, "\n0.- No \n1.- Si \nEs correcto: ", "Valor invalido");
                    system("cls");
                }while(correct == 0);
                strcpy(reg.ap_mat, temp_char);

                do
                {
                    printf("Nombre actual: %s\n", reg.nombre);
                    vali_cad_obg(temp_char, "Ingrese el nuevo dato: ");
                    correct = vali_int(0, 1, "\n0.- No \n1.- Si \nEs correcto: ", "Valor invalido");
                    system("cls");
                }while(correct == 0);
                strcpy(reg.nombre, temp_char);

                do
                {
                    printf("Edad actual: %d\n", reg.edad);
                    temp_int = vali_int(17, 65, "Ingrese el nuevo dato: ", "Valor invalido");
                    correct = vali_int(0, 1, "\n0.- No \n1.- Si \nEs correcto: ", "Valor invalido");
                    system("cls");
                }while(correct == 0);
                reg.edad = temp_int;

                do
                {
                    printf("Genero actual: %s\n", sexo);
                    temp_int = vali_int(0, 1, "0.- Masculino \n1.- Femenino \nIngrese el nuevo dato: ", "Valor invalido");
                    correct = vali_int(0, 1, "\n0.- No \n1.- Si \nEs correcto: ", "Valor invalido");
                    system("cls");
                }while(correct == 0);
                reg.genero = temp_int;

                vect[posi] = reg;
            }
            else
            {
                printf("La matricula que busco no se encuentra registrada\n");
                system("pause");
            }
        }
        else
        {
            printf("La matricula que busco no se encuentra registrada\n");
            system("pause");
        }
    }
    else
    {
        printf("Cargue o agregue datos antes de editar\n");
        system("pause");
    }
}

void elim_datos(Talum vect[], int i, int band)
{
    long mat;
    int posi, del;
    char *sexo, *estatus;

    system("cls");

    mat = vali_long(300000, 399999, "Ingrese la matricula a eliminar: ", "Matricula invalida");
    if(band == 0)
    {   
        posi = busq_sec_talum(vect, i, mat);
    }
    else
    {
        posi = busq_bin_talum(vect, i, mat);
    }
    if(posi != -1)
    {
        system("cls");
        if(vect[posi].estatus == 0)
        {
            printf("La matricula que busco ya fue eliminada\n");
            system("pause");
            return;
        }
        else
        { 
            
            if(vect[posi].genero == 0)
            {
                sexo = "HOMBRE";
            }
            else
            {
                sexo = "MUJER";
            }
            if(vect[posi].estatus == 0)
            {
                estatus = "INACTIVO";
            }
            else
            {
                estatus = "ACTIVO";
            }

            if(vect[posi].estatus != 0)
            {
                printf("%-10s %-10s %-20s %-20s %-20s %-5s %-10s\n", "Estatus", "Matricula", "Apellido paterno", "Apellido materno", "Nombre", "Edad", "Genero");
                printf("%-10s %-10ld %-20s %-20s %-20s %-5d %-10s\n", estatus, vect[posi].mat, vect[posi].ap_pat, vect[posi].ap_mat, vect[posi].nombre, vect[posi].edad, sexo);
                del = vali_int(0, 1, "1.- Eliminar registro \n0.- No eliminar \nSeleccione una opcion: ", "Opcion invalida");
                if(del == 1)
                {
                    vect[posi].estatus = 0;
                    printf("Registro eliminado existosamente\n");
                    system("pause");
                }
            }
            else
            {
                printf("La matricula que busco no se encuentra registrada\n");
                system("pause");
            }
        }
    }
    else
    {
        printf("La matricula que busco no se encuentra registrada\n");
        system("pause");
    }
}

void busq_datos(Talum vect[], int n, int band)
{
    long mat;
    int posi;
    char *estatus, *sexo;

    system("cls");
    if(n > 0)
    {
        mat = vali_long(300000, 399999, "Ingrese la matricula a buscar: ", "Matricula invalida");
        if(band == 0)
        {   
            posi = busq_sec_talum(vect, n, mat);
        }
        else
        {
            posi = busq_bin_talum(vect, n, mat);
        }
        if(posi != -1)
        {
            system("cls");
            if(vect[posi].genero == 0)
            {
                sexo = "MASCULINO";
            }
            else
            {
                sexo = "FEMENINO";
            }
            if(vect[posi].estatus == 0)
            {
                estatus = "INACTIVO";
            }
            else
            {
                estatus = "ACTIVO";
            }
            
            if(vect[posi].estatus != 0)
            {
                printf("%-10s %-10s %-20s %-20s %-20s %-5s %-10s\n", "Estatus", "Matricula", "Apellido paterno", "Apellido materno", "Nombre", "Edad", "Genero");
                printf("%-10s %-10ld %-20s %-20s %-20s %-5d %-10s\n", estatus, vect[posi].mat, vect[posi].ap_pat, vect[posi].ap_mat, vect[posi].nombre, vect[posi].edad, sexo);
                system("pause");
            }
            else
            {
                printf("La matricula que busco no se encuentra registrada\n");
                system("pause");
            }
        }
        else
        {
            printf("La matricula que busco no se encuentra registrada\n");
            system("pause");
        }
    }
    else
    {
        printf("Cargue o agregue datos antes de buscar\n");
        system("pause");
    }
}

void ord_datos(Talum vect[], int n, int *band)
{
    int bande;
    bande = (*band);

    system("cls");
    if(n > 0)
    {
        if(bande == 0)
        {
            ord_quicksort(vect, 0, n-1);
            bande = 1;
        }
        else
        {
            ord_burb(vect, n);
        }
        printf("Datos ordenados correctamente\n");
        system("pause");
    }
    else
    {
        printf("Cargue o agregue datos antes de ordenarlos\n");
        system("pause");
    }

    (*band) = bande;
}

void imp_datos(Talum vect[], int n)
{
    int j, k;
    char *sexo;

    system("cls");

    if(n > 0)
    {
        j = 0;
        while(j < n)
        {
            printf("%-7s %-10s %-20s %-20s %-20s %-5s %-10s\n","Indice", "Matricula", "Apellido paterno", "Apellido materno", "Nombre", "Edad", "Genero");
            for(k = 0; k < 40; k++)
            {
                if(vect[j].genero == 0)
                {
                    sexo = "MASCULINO";
                }
                else
                {
                    sexo = "FEMENINO";
                }
                printf("%-7d %-10ld %-20s %-20s %-20s %-5d %-10s\n", j, vect[j].mat, vect[j].ap_pat, vect[j].ap_mat, vect[j].nombre, vect[j].edad, sexo);
                j++;
            }
            system("pause");
            system("cls");
        }
    }
    else
    {
        printf("Ingrese datos antes de imprimir\n");
        system("pause");
    }
}

void crear_arch_txt(Talum vect[], int n)
{
    int j;
    char *sexo, *estatus, nombre[25], txt[5];
    Talum reg;
    FILE *arch;

    system("cls");

    if(n > 0)
    {
        vali_cad_obg(nombre, "Ingrese el nombre para el archivo: ");
        strlwr(nombre);
        txt[0] = '.'; txt[1] = 't'; txt[2] = 'x'; txt[3] = 't'; txt[4] = '\0';

        strcat(nombre, txt);

        arch = fopen(nombre, "w");
        if (arch)
        {
            system("cls");

            if (arch == NULL)
            {
                printf ("Este archivo no existe!");
                return;
            }

            fprintf(arch, "%-7s %-10s %-10s %-20s %-20s %-20s %-5s %-10s\n","Indice", "Estatus", "Matricula", "Apellido paterno", "Apellido materno", "Nombre", "Edad", "Genero");
            for(j=0; j < 2500; j++)
            {
                reg = vect[j];
                if(reg.genero == 0)
                {
                    sexo = "HOMBRE";
                }
                else
                {
                    sexo = "MUJER";
                }
                if(vect[j].estatus == 0)
                {
                    estatus = "INACTIVO";
                }
                else
                {
                    estatus = "ACTIVO";
                }
                if(vect[j].estatus != 2)
                {
                    fprintf(arch, "%-7d %-10s %-10ld %-20s %-20s %-20s %-5d %-10s\n", j, estatus, reg.mat, reg.ap_pat, reg.ap_mat, reg.nombre, reg.edad, sexo);
                }
            }    
            fclose(arch);
            printf("Archivo generado exitosamente!\n");
            system("pause");
        }
    }
    else
    {
        printf("Ingrese datos antes de generar un archivo\n");
        system("pause");
    }
}

void ver_arch_txt(Talum vect[], int n)
{
    Talum reg;
    FILE *arch;
    char caractr, nombre[25], txt[5];
    long i;
    
    i = 1;
    system("cls");
    vali_cad_obg(nombre, "Ingrese el nombre del archivo a ver: ");
    strlwr(nombre);
    txt[0] = '.'; txt[1] = 't'; txt[2] = 'x'; txt[3] = 't'; txt[4] = '\0';
    strcat(nombre, txt);

    arch = fopen(nombre, "r");
    if(arch)
	{
		while(!feof(arch))
		{
                caractr = fgetc(arch);
		        fprintf(stdout,"%c", caractr);
                i++;
                if(i >= 4400)
                {
                    i = 1;
                    printf("\n");
                    system("pause");
                    system("cls");
                    printf("%-7s %-10s %-10s %-20s %-20s %-20s %-5s %-10s\n","Indice", "Estatus", "Matricula", "Apellido paterno", "Apellido materno", "Nombre", "Edad", "Genero");
                }
		}
		fclose(arch);        
        system("pause");

	}
    else
    {
        printf("El archivo no existe\n");

    }

}

void crear_arch_bin(Talum vect[], int n)
{
    int j;
    char nombre[25], bin[5];
    Talum reg;
    FILE *arch;

    system("cls");

    if(n > 0)
    {
        vali_cad_obg(nombre, "Ingrese el nombre para el archivo: ");
        strlwr(nombre);
        bin[0] = '.'; bin[1] = 'd'; bin[2] = 'a'; bin[3] = 't'; bin[4] = '\0';
        strcat(nombre, bin);

        arch = fopen(nombre, "wb");
        if (arch)
        {
            system("cls");

            if (arch == NULL)
            {
                printf ("Este archivo no existe!");
                return;
            }

            for(j=0; j < 2500; j++)
            {
                reg = vect[j];
                fwrite(&reg, sizeof(Talum), 1, arch);
            }    
            fclose(arch);
            printf("Archivo generado exitosamente!\n");
            system("pause");
        }
    }
    else
    {
        printf("Ingrese datos antes de generar un archivo\n");
        system("pause");
    }
}

void cargar_arch_bin(Talum vect[], int *n, int max, int *band)
{
    int i , bande;
    FILE *arch;
    Talum reg;
    char basura[30], nombre[25], bin[5], *estatus;

    system("cls");

    i = (*n);
    bande = (*band);

    vali_cad_obg(nombre, "Ingrese el nombre del archivo a abrir: ");
    strlwr(nombre);
    bin[0] = '.'; bin[1] = 'd'; bin[2] = 'a'; bin[3] = 't'; bin[4] = '\0';
    strcat(nombre, bin);

    if (bande == 0)
    {

        arch = fopen(nombre, "rb");

        if (arch)
        {
            while(fread(&reg, sizeof(Talum), 1, arch))
            {
                
                vect[i] = reg;
                i++;
                if(i == max)
                {
                    printf("No fue posible agregar mas datos");
                    system("pause");
                    return;
                }
            }
            fclose(arch);
            bande = 1;

            printf("Los datos fueron cargados correctamente\n");
            system("pause");
        }
        else
        {
            printf("No se encontro el archivo a abrir\n");
            system("pause");
        }
    }
    else
    {
        if (bande == 1)
        {
            printf("Los datos ya fueron cargaron\n");
            system("pause");
        }
        else
        {
            printf("No fue posible agregar mas datos\n");
            system("pause");
        }
    }

    (*n) = i;
    (*band) = bande;
}

