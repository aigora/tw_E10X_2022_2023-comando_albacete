#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void leer_fechas(FILE *archivo, char fechas[25][20], int *numfecha)
{
    char linea[500], *token;
    int i;

    // Leer la quinta línea (fecha)
    for (i = 0; i < 4; i++)
        fgets(linea, 500, archivo);
    fgets(linea, 500, archivo);
    token = strtok(linea, ",");
    while (token != NULL && *numfecha < 25)
    {
        strcpy(fechas[*numfecha], token);
        (*numfecha)++;
        token = strtok(NULL, ",");
    }
}

void imprimir(char vectorito[][20], int num_datos)
{
    for (int i = 0; i < num_datos; i++)
        printf("%s\n", vectorito[i]);
}
