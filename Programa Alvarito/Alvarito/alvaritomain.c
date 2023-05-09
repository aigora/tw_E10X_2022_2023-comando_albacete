//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct{
//    int anio;
//    int mes;
//}fecha;
//
//
//int main() {
//    FILE *archivo;
//    char linea[500];
//    char *token;
//    int i, *numfecha, aux = 0;
//    char fechas[25][20];
//
//    archivo = fopen("generacion.txt", "r");
//    if (archivo == NULL) {
//        printf("No se pudo abrir el archivo.");
//        exit(EXIT_FAILURE);
//    }
//
//    fseek(archivo, 0, SEEK_END);
//    long int tamano_archivo;
//    tamano_archivo = ftell(archivo);
//    rewind(archivo);
//
//    char *buffer;
//    buffer = (char*) malloc(tamano_archivo * sizeof(char));
//    if (buffer == NULL) {
//        printf("No se pudo asignar memoria para el buffer.");
//        exit(EXIT_FAILURE);
//    }
//
//    fread(buffer, sizeof(char), tamano_archivo, archivo);
//
//    fclose(archivo);
//    free(buffer);
//    archivo = fopen("generacion.txt", "r");
//    if (archivo == NULL)
//        printf("malito");
//
//    numfecha = &aux;
//    for (i = 0; i < 4; i++)
//        fgets(linea, 500, archivo);
//
//    fgets(linea, 500, archivo);
//
//    token = strtok(linea, ",");
//    while (token != NULL && *numfecha < 25)
//    {
//        strcpy(fechas[*numfecha], token);
//        (*numfecha)++;
//        token = strtok(NULL, ",");
//    }
//
//    for (i = 0; i < *numfecha; i++) {
//        printf("%s\n", fechas[i]);
//    }
//
//    return 0;
//}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int mes;
    int anio;
} Fecha;

int main() {
    FILE *archivo;
    char linea[500];
    char *token;
    int i, num_fechas = 0;
    Fecha fechas[25];

    archivo = fopen("generacion.txt", "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.");
        exit(EXIT_FAILURE);
    }

    // Saltar las primeras cuatro líneas
    for (i = 0; i < 4; i++) {
        fgets(linea, 500, archivo);
    }

    // Leer las fechas y almacenarlas en un vector de estructuras Fecha
    fgets(linea, 500, archivo);
    token = strtok(linea, ",");
    while (token != NULL && num_fechas < 25) {
        int mes = atoi(token);
        token = strtok(NULL, ",");
        int anio = atoi(token);
        if (mes >= 1 && mes <= 12 && (anio == 2021 || anio == 2022)) {
            fechas[num_fechas].mes = mes;
            fechas[num_fechas].anio = anio;
            num_fechas++;
        }
        token = strtok(NULL, ",");
    }

    fclose(archivo);

    // Imprimir las fechas almacenadas en el vector de estructuras Fecha
    for (i = 0; i < num_fechas; i++) {
        printf("Fecha %d: %02d/%04d\n", i+1, fechas[i].mes, fechas[i].anio);
    }

    return 0;
}
