#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct
{
    char energia[50];
    double cantidad[12];

}Energias;

typedef struct
{
    int mes;
    int anio;
}fechas;

typedef struct
{
    fechas fecha[12];
    Energias datos[18];
}Datos;



//Energias* leer_archivo(char* filename, int* num_lines) {
//    FILE *file = fopen(filename, "r");
//    if (file == NULL) {
//        printf("Error al abrir el archivo\n");
//        return NULL;
//    }
//
//    Energias* data = (Energias*) malloc(sizeof(Energias) * 100);
//    int n = 0;
//
//    char line[1000];
//    while (fgets(line, 1000, file) != NULL) {
//        // Separa la línea por comas
//        char *token = strtok(line, ",");
//        int token_num = 0;
//
//        // Guarda el nombre de la energía
//        strcpy(data[n].name, token);
//
//        // Guarda los valores como doubles
//        while (token != NULL) {
//            token = strtok(NULL, ",");
//            if (token != NULL) {
//                data[n].values[token_num] = strtod(token + (*token == '"'), NULL);
//                token_num++;
//            }
//        }
//
//        // Guarda el número de valores en la estructura
//        data[n].num_values = token_num;
//
//        // Incrementa el contador de líneas
//        n++;
//    }
//
//    // Cierra el archivo
//    fclose(file);
//
//    // Actualiza el número de líneas
//    *num_lines = n;
//
//    return data;
//}


void convertir_caracteres_especiales(char *cadena) {
    char origen[] = {'á', 'é', 'í', 'ó', 'ú', 'ñ', 'ü'};
    char destino[] = {'a', 'e', 'i', 'o', 'u', 'n', 'u'};
    for (int i = 0; i < strlen(cadena); i++) {
        for (int j = 0; j < sizeof(origen); j++) {
            if (cadena[i] == origen[j]) {
                cadena[i] = destino[j];
            }
        }
    }
}



