#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 6737;

int main()
{
   FILE  *archivo;
   char contenido[6737];
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

    if(archivo!=NULL)
    {
      while (fgets(contenido, 6737, archivo))
        printf("%s", contenido);
    }
    fclose(archivo);

   return 0;
}
