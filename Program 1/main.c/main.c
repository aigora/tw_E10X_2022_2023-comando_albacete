#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *archivo, *copiat;
    char contenido[2500];

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
    return 0;
}
