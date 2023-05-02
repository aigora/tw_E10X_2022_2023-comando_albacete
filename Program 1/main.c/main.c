#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    char nombre[50];
    char mes[10];
    float cantidad;
}tecnologias;
typedef struct
{
    char mes[10];
    float cantidadtotal;
}sumatorio;

int main()
{
    FILE *archivo, *copiat;
    tecnologias tecnologia[408];//Vector de estructuras con el tamaño justo, 17 tecnologias a 24 meses cada una
    sumatorio totalmes[12]; //Vector estructuras que dará el total de cada mes
    char contenido[2500];
    int lectura=0, numerotecnologia=0;

    archivo = fopen("generacion_por_tecnologias_21_22.txt", "r");
    //Abre en modo lectura, comprueba que se abre el archivo.
    if(archivo == NULL)
    {
        printf("Error al abrir el atchivo\n");
        return 1;
    }
    //Si no abre, da mensaje de error y termina el programa.
    else
    {
        printf("Fichero abierto correctamente \n");
		fclose(archivo);
    }

    if(archivo !=NULL)
    {
        while (fgets(contenido, 2500, archivo))
        {
            printf("%s", contenido);
        }
    }
    //Si el archivo existe, esta parte del código lee el contenido del mismo y lo
    //imprime en pantalla


    copiat = fopen("copia.txt", "w");
    //Funcionalidad de copiar el archivo.
    if(copiat == NULL)
    {
        printf("Error al abrir el atchivo\n");
        return 1;
    }
    while ((copiat = fgets(contenido, 2500,archivo)!= EOF))
    {
        fputs(contenido[2500], copiat);
    }
    fclose(copiat);
    //reabro el archivo.
    fopen(archivo);
    //AUN NO SÉ COMO HACER LA LECTURA Y ALMACENAMIENTO ORDENADO DE DATOS.
//    do
//    {
//        lectura = fscanf(archivo, ",")
//
//    }while (!feof(archivo));


    return 0;
}
