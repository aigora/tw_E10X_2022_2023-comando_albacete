#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define BUFFER_SIZE 6737

int main()
{
   FILE  *archivo;
   char contenido[6737];
   int contadorlinea=1, numlin; //Variable de contador para el buscador de l�nea.
   char linea[500];//Tama�o de linea, sudficiente como para leer una l�nea entera. La m�xima extensi�n de l�nea es de 429
   char opcion;
   long size;

   archivo = fopen("generacion.txt", "r");

   if(archivo==NULL)
      printf("error");
    else
        printf("Bacano\n");

    fseek(archivo,0,SEEK_END);
    size = ftell(archivo);
    printf("Tama�o del archivo = %ld\n", size);
    fclose(archivo);
    archivo = fopen("generacion.txt", "r");

    printf("Linea o Total?(L) O (T)\n");
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
        printf("L�mite de l�neas alcanzado\n");
        break;
    default:
        printf("Opci�n no valida");
    }

   return 0;
}

