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

    printf("Linea, Total o Fechas?(L),(T) o (F)\n");
    scanf("%c", &opcion);
    switch(opcion)
    {
    case 'T':
    case 't':
            if(archivo!=NULL)
            {
          while (fgets(contenido, 6737, archivo))
            printf("%s", contenido);
            }
            fclose(archivo);
            break;
    case'L':
    case'l':
        printf("Linea?");
        scanf("%d", &numlin);
        if(archivo!=NULL)
        {
        while (fgets(linea,500,archivo))
            {
            contadorlinea++;
            if (contadorlinea == numlin)
            printf("%s\n", linea);
            }
        }
        else if(numlin>=23)
        printf("Límite de líneas alcanzado\n");
        break;
    case 'F':
    case 'f':
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
        printf("Opción no valida");
    }
    fclose(archivo);
   return 0;
}

