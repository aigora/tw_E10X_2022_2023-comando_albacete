#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

#define BUFFER_SIZE 6737

int main()
{
   setlocale(LC_ALL, "spanish");
   FILE  *archivo;
   char contenido[6737];
   int contadorlinea=1, numlin, numfecha=0, i; //Variable de contador para el buscador de línea.
   char linea[500], fechas[25][10];//Tamaño de linea, sudficiente como para leer una línea entera. La máxima extensión de línea es de 429
   char opcion;
   char *fecha;
   long size;

   archivo = fopen("generacion.txt", "r");

   if(archivo==NULL)
      printf("error");
    else
        printf("Bacano\n");

    fseek(archivo,0,SEEK_END);
    size = ftell(archivo);
    printf("Tamaño del archivo = %ld\n", size);
    fclose(archivo);
    archivo = fopen("generacion.txt", "r");
    printf("Año 2021(1) o Año 2022(2) o Total(3):\n");
    scanf("%c", &opcion);
    switch(opcion)
    {
    case '1':
        if (archivo != NULL)
          {
            for (i = 0; i < 5; i++)
                { //Lee hasta la quinta linea;
                fgets(linea, 500, archivo);
                fecha = strtok(linea, ",");
                }
            while (fecha != NULL && numfecha < 25)
            {
                strcpy(fechas[numfecha], fecha);
                numfecha++;
                fecha = strtok(NULL, ",");
            }
            numfecha=13;
            for (i = 0; i < numfecha; i++) // Imprimir todas las fechas almacenadas
                printf("%s\n", fechas[i]);
          }
         break;
    case'2':
        if (archivo != NULL)
          {
            for (i = 0; i < 5; i++)
                { //Lee hasta la quinta linea;
                fgets(linea, 500, archivo);
                fecha = strtok(linea, ",");
                }
            while (fecha != NULL && numfecha < 25)
            {
                strcpy(fechas[numfecha], fecha);
                numfecha++;
                fecha = strtok(NULL, ",");
            }
            numfecha=25;
            printf("Fecha\n");
            for (i = 13; i < numfecha; i++) // Imprimir todas las fechas almacenadas
                printf("%s\n", fechas[i]);
          }
         break;
    case '3':
        if (archivo != NULL)
          {
            for (i = 0; i < 5; i++)
                { //Lee hasta la quinta linea;
                fgets(linea, 500, archivo);
                fecha = strtok(linea, ",");
                }
            while (fecha != NULL && numfecha < 25)
            {
                strcpy(fechas[numfecha], fecha);
                numfecha++;
                fecha = strtok(NULL, ",");
            }
            for (i = 0; i < numfecha; i++) // Imprimir todas las fechas almacenadas
                printf("%s\n", fechas[i]);
         }
         break;
    default:
        printf("No seas pelotudo\n");
    }
    fclose(archivo);
    return 0;
}

