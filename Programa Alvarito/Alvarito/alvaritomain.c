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


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct {
//    int mes;
//    int anio;
//} Fecha;
//
//int main() {
//    FILE *archivo;
//    char linea[500];
//    char *token;
//    int i, num_fechas = 0;
//    Fecha fechas[25];
//
//    archivo = fopen("generacion.txt", "r");
//    if (archivo == NULL) {
//        printf("No se pudo abrir el archivo.");
//        exit(EXIT_FAILURE);
//    }
//
//    // Saltar las primeras cuatro l�neas
//    for (i = 0; i < 4; i++) {
//        fgets(linea, 500, archivo);
//    }
//
//    // Leer las fechas y almacenarlas en un vector de estructuras Fecha
//    fgets(linea, 500, archivo);
//    token = strtok(linea, ",");
//    while (token != NULL && num_fechas < 25) {
//        int mes = atoi(token);
//        token = strtok(NULL, ",");
//        int anio = atoi(token);
//        if (mes >= 1 && mes <= 12 && (anio == 2021 || anio == 2022)) {
//            fechas[num_fechas].mes = mes;
//            fechas[num_fechas].anio = anio;
//            num_fechas++;
//        }
//        token = strtok(NULL, ",");
//    }
//
//    fclose(archivo);
//
//    // Imprimir las fechas almacenadas en el vector de estructuras Fecha
//    for (i = 0; i < num_fechas; i++) {
//        printf("Fecha %d: %02d/%04d\n", i+1, fechas[i].mes, fechas[i].anio);
//    }
//
//    return 0;
//}

//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_ENERGIAS 100
//
//typedef struct {
//    char tipo[50];
//    float cantidad;
//} Energia;
//
//int main() {
//    FILE *archivo;
//    char linea[500];
//    char *token;
//    int i, num_energias = 0;
//    Energia energias[MAX_ENERGIAS];
//
//    archivo = fopen("generacion.txt", "r");
//    if (archivo == NULL) {
//        printf("No se pudo abrir el archivo.");   //CON ESTO CONSIGO VECTOR PERO NO RELLENARLO.
//        exit(EXIT_FAILURE);
//    }
//
//    for (i = 0; i < 5; i++) {
//        fgets(linea, 500, archivo);
//    }
//
//    while (fgets(linea, 500, archivo)) {
//        token = strtok(linea, ",");
//        if (token != NULL) {
//            strcpy(energias[num_energias].tipo, token);
//            token = strtok(NULL, ",");
//            if (token != NULL) {
//                energias[num_energias].cantidad = atof(token);
//                num_energias++;
//                if (num_energias == MAX_ENERGIAS) {
//                    printf("Se ha alcanzado el m�ximo n�mero de energ�as permitidas.\n");
//                    break;
//                }
//            }
//        }
//    }
//
//    printf("Se han le�do %d energ�as.\n", num_energias);
//    printf("Energ�as le�das:\n");
//    for (i = 0; i < num_energias; i++) {
//        printf("%s: %.2f\n", energias[i].tipo, energias[i].cantidad);
//    }
//
//    fclose(archivo);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//
//
//typedef struct {
//    char tipo[50];
//    float cantidad;
//} Energia;
//
//int main() {
//    FILE *archivo;
//    char linea[500];
//    int i, num_energias = 0;
//    Energia energias[5000];
//
//    archivo = fopen("generacion.txt", "r");
//    if (archivo == NULL) {
//        printf("No se pudo abrir el archivo.");
//        exit(EXIT_FAILURE);
//    }
//
//    for (i = 0; i < 5; i++) {
//        fgets(linea, 500, archivo);
//    }
//
//    while (fgets(linea, 500, archivo)) {
//        if (sscanf(linea, "%[^,],%f", energias[5000].tipo, &energias[5000].cantidad) == 2) {
//            num_energias++;
//            if (num_energias == 5000) {
//                printf("Se ha alcanzado el m�ximo n�mero de energ�as permitidas.\n");
//                break;
//            }
//        } else {
//            printf("Error de formato en la l�nea: %s", linea);
//        }
//    }
//
//    printf("Se han le�do %d energ�as.\n", num_energias);
//    printf("Energ�as le�das:\n");
//    for (i = 0; i < num_energias; i++) {
//        printf("%s: %.2f\n", energias[i].tipo, energias[i].cantidad);
//    }
//    fclose(archivo);
//
//    return 0;
//}
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_VALUES 26 // N�mero m�ximo de valores por l�nea

// Estructura para guardar los datos de cada l�nea
struct EnergyData {
    char name[20];
    double values[MAX_VALUES];
    int num_values;
};

int main() {
    // Abre el archivo
    FILE *file = fopen("generacion.txt", "r");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Crea un vector de estructuras
    struct EnergyData data[100];
    int num_lines = 0;

    // Lee el archivo l�nea por l�nea
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        // Separa la l�nea por comas
        char *token = strtok(line, ",");
        int token_num = 0;

        // Guarda el nombre de la energ�a
        strcpy(data[num_lines].name, token);

        // Guarda los valores como doubles
        while (token != NULL) {
            token = strtok(NULL, ",");
            if (token != NULL) {
                data[num_lines].values[token_num] = strtod(token + (*token == '"'), NULL);
                token_num++;
            }
        }

        // Guarda el n�mero de valores en la estructura
        data[num_lines].num_values = token_num;

        // Incrementa el contador de l�neas
        num_lines++;
    }

    // Cierra el archivo
    fclose(file);

    // Imprime los datos para verificar que se leyeron correctamente
    for (int i = 5; i < 6; i++) {
        printf("%s: ", data[i].name);
        for (int j = 0; j < data[i].num_values; j++) {
            printf("%f ", data[i].values[j]);
        }
        printf("\n");
    }

    return 0;
}
