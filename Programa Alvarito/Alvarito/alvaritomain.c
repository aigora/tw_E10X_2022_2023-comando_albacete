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
////    for (int i = 5; i < 23; i++) {
////        printf("%s: ", data[i].name);
////        for (int j = 0; j < data[i].num_values; j++) {
////            printf("%f ", data[i].values[j]);
////        }
////        printf("\n");
////    }


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//
//typedef struct {
//    char name[20];
//    double values[26];
//    int num_values;
//} Energias;
//
//int main() {
//    FILE *file = fopen("generacion.txt", "r");
//    if (file == NULL) {
//        printf("Error al abrir el archivo\n");
//        return 1;
//    }
//
//    Energias data[100];
//    int num_lines = 0;
//
//    char line[1000];
//    while (fgets(line, 1000, file) != NULL) {
//        // Separa la línea por comas
//        char *token = strtok(line, ",");
//        int token_num = 0;
//
//        // Guarda el nombre de la energía
//        strcpy(data[num_lines].name, token);
//
//        // Guarda los valores como doubles
//        while (token != NULL) {
//            token = strtok(NULL, ",");
//            if (token != NULL) {
//                data[num_lines].values[token_num] = strtod(token + (*token == '"'), NULL);
//                token_num++;
//            }
//        }
//
//        // Guarda el número de valores en la estructura
//        data[num_lines].num_values = token_num;
//
//        // Incrementa el contador de líneas
//        num_lines++;
//    }
//
//    // Cierra el archivo
//    fclose(file);
//
//    char input_name[100];
//    printf("Ingrese el nombre de la energía que desea buscar: ");
//    fgets(input_name, 100, stdin);
//    // Elimina el salto de línea final de la entrada
//    input_name[strcspn(input_name, "\n")] = '\0';
//
//    // Limpiar y normalizar la cadena de entrada
//    char input_name_clean[100];
//    char *token = strtok(input_name, " ");
//    int i = 0;
//    while (token != NULL) {
//        for (int j = 0; j < strlen(token); j++) {
//            if (isalnum(token[j])) {
//                input_name_clean[i] = tolower(token[j]);
//                i++;
//            }
//        }
//        token = strtok(NULL, " ");
//    }
//    input_name_clean[i] = '\0';
//
//    // Busca la coincidencia y muestra los valores correspondientes
//    int found = 0;
//    for (int i = 0; i < num_lines; i++) {
//        // Limpiar y normalizar el nombre almacenado en la estructura
//        char name_clean[20];
//        int j = 0;
//        for (int k = 0; k < strlen(data[i].name); k++) {
//            if (isalnum(data[i].name[k])) {
//                name_clean[j] = tolower(data[i].name[k]);
//                j++;
//            }
//        }
//        name_clean[j] = '\0';
//
//        // Comparar las cadenas normalizadas
//        if (strcmp(name_clean, input_name_clean) == 0) {
//            found = 1;
//            printf("%s: ", data[i].name);
//            for (int j = 0; j < data[i].num_values; j++) {
//                printf("%f ", data[i].values[j]);
//            }
//            printf("\n");
//            break;
//        }
//    }
//
//    if (!found) {
//        printf("No se encontró la energía ingresada\n");
//    }
//
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//
//typedef struct {
//    char name[20];
//    double values[26];
//    int num_values;
//} Energias;
//
//void convertir_caracteres_especiales(char *cadena);
//
//int main() {
//    FILE *file = fopen("generacion.txt", "r");
//    if (file == NULL) {
//        printf("Error al abrir el archivo\n");
//        return 1;
//    }
//
//    Energias data[100];
//    int num_lines = 0;
//
//    char line[1000];
//    while (fgets(line, 1000, file) != NULL) {
//        // Separa la línea por comas
//        char *token = strtok(line, ",");
//        int token_num = 0;
//
//        // Guarda el nombre de la energía
//        strcpy(data[num_lines].name, token);
//
//        // Guarda los valores como doubles
//        while (token != NULL) {
//            token = strtok(NULL, ",");
//            if (token != NULL) {
//                data[num_lines].values[token_num] = strtod(token + (*token == '"'), NULL);
//                token_num++;
//            }
//        }
//
//        // Guarda el número de valores en la estructura
//        data[num_lines].num_values = token_num;
//
//        // Incrementa el contador de líneas
//        num_lines++;
//    }
//
//    // Cierra el archivo
//    fclose(file);
//
//    char input_name[100];
//    printf("Ingrese el nombre de la energía que desea buscar: ");
//    fgets(input_name, 100, stdin);
//    // Elimina el salto de línea final de la entrada
//    input_name[strcspn(input_name, "\n")] = '\0';
//
//    // Limpiar y normalizar la cadena de entrada
//    char input_name_clean[100];
//    strcpy(input_name_clean, input_name);
//    convertir_caracteres_especiales(input_name_clean);
//    for (int i = 0; i < strlen(input_name_clean); i++) {
//        input_name_clean[i] = tolower(input_name_clean[i]);
//    }
//
//    // Busca la coincidencia y muestra los valores correspondientes
//    int found = 0;
//    for (int i = 0; i < num_lines; i++) {
//        // Limpiar y normalizar el nombre almacenado en la estructura
//        char name_clean[20];
//        strcpy(name_clean, data[i].name);
//        convertir_caracteres_especiales(name_clean);
//        for (int j = 0; j < strlen(name_clean); j++) {
//            name_clean[j] = tolower(name_clean[j]);
//        }
//
//        // Comparar las cadenas normalizadas
//        if (strcmp(name_clean, input_name_clean) == 0) {
//            found = 1;
//            printf("%s: ", data[i].name);
//            for (int j = 0; j < data[i].num_values; j++) {
//                printf("%f ", data[i].values[j]);
//            }
//            printf("\n");
//            break;
//        }
//    }
//
//    if (!found) {
//        printf("No se encontró la energía ingresada\n");
//    }
//
//    return 0;
//}
//
//void convertir_caracteres_especiales(char *cadena) {
//    char origen[] = {'á', 'é', 'í', 'ó', 'ú', 'ñ', 'ü'};
//    char destino[] = {'a', 'e', 'i', 'o', 'u', 'n', 'u'};
//    for (int i = 0; i < strlen(cadena); i++) {
//        for (int j = 0; j < sizeof(origen); j++) {
//            if (cadena[i] == origen[j]) {
//                cadena[i] = destino[j];
//            }
//        }
//    }
//}
//
//

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include"alejandria.h"
//
//int main() {
//    int num_lines;
//    Energias* data = leer_archivo("generacion.txt", &num_lines);
//    if (data == NULL) {
//        return 1;
//    }
//
//
//    Energias* leer_archivo(char* filename, int* num_lines);
//    fecha* leer_fechas(char* filename, int* num_lines);
//
//    char input_name[100];
//    printf("Ingrese el nombre de la energía que desea buscar: ");
//    fgets(input_name, 100, stdin);
//    // Elimina el salto de línea final de la entrada
//    input_name[strcspn(input_name, "\n")] = '\0';
//
//    // Limpiar y normalizar la cadena de entrada
//    char input_name_clean[100];
//    strcpy(input_name_clean, input_name);
//    convertir_caracteres_especiales(input_name_clean);
//    for (int i = 0; i < strlen(input_name_clean); i++) {
//        input_name_clean[i] = tolower(input_name_clean[i]);
//    }
//
//    // Busca la coincidencia y muestra los valores correspondientes
//    int found = 0;
//    for (int i = 0; i < num_lines; i++) {
//        // Limpiar y normalizar el nombre almacenado en la estructura
//        char name_clean[20];
//        strcpy(name_clean, data[i].name);
//        convertir_caracteres_especiales(name_clean);
//        for (int j = 0; j < strlen(name_clean); j++) {
//            name_clean[j] = tolower(name_clean[j]);
//        }
//
//        // Comparar las cadenas normalizadas
//        if (strcmp(name_clean, input_name_clean) == 0) {
//            found = 1;
//            printf("%s: ", data[i].name);
//            for (int j = 0; j < data[i].num_values; j++) {
//                printf("%f ", data[i].values[j]);
//            }
//            printf("\n");
//            break;
//        }
//    }
//
//    if (!found) {
//        printf("No se encontró la energía ingresada\n");
//    }
//
//    return 0;
//}
//
//
//
//
//
