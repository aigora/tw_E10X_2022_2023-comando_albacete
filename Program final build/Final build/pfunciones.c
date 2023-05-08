//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//#include "bacano.h"
//#include <ctype.h>

//int main()
//{
//    FILE *archivo;
//    char linea[500], *token;
//    char fechas[25][20], energias[25][20];
//    int numfecha = 0, numenergia = 0, i, j;
//    setlocale(LC_ALL,"spanish");
//
//    archivo = fopen("generacion.txt", "r");
//
//    if (archivo != NULL) {
//
//        leer_fechas(archivo, fechas, &numfecha);
//
//    fgets(linea, 500, archivo);
//    token = strtok(linea, ",");
//    while (token != NULL && numenergia < 1000) {
//        // Reemplazar la coma por punto y coma
//        for (j = 0; j < strlen(token); j++) {
//            if (token[j] == ',' && isdigit(token[j-1]) && isdigit(token[j+1])) {
//                token[j] = ';';
//            }
//        }
//        strcpy(energias[numenergia], token);
//        numenergia++;
//        token = strtok(NULL, ",");
//    }
//    for(i=0;i<numenergia;i++)
//    printf("%s\t", energias[i]);
//
//}
//
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main()
{
    FILE *archivo;
    char linea[500], *token;
    char fechas[25][20], energias[25][20];
    int numfecha = 0, numenergia = 0, i, j;
    setlocale(LC_ALL,"spanish");

    archivo = fopen("generacion.txt", "r");

    if (archivo != NULL) {
        // Leer la línea de los nombres de las columnas y descartarla
        fgets(linea, 500, archivo);

        // Leer la línea de las energías
        fgets(linea, 500, archivo);
        token = strtok(linea, ",");
        while (token != NULL && numenergia < 1000) {
            // Extraer números dentro de las comillas
            int num1, num2;
            if (sscanf(token, "\"%d %d\"", &num1, &num2) == 2) {
                char num_str[20];
                sprintf(num_str, "%d,%d", num1, num2);
                strcpy(energias[numenergia], num_str);
                numenergia++;
            } else {
                printf("Error al extraer números de la cadena: %s\n", token);
            }
            token = strtok(NULL, ",");
        }

        for (i = 0; i < numenergia; i++) {
            printf("%s\t", energias[i]);
        }

    } else {
        printf("Error al abrir el archivo.\n");
    }

    return 0;
}
