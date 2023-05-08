#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main()
{
    FILE *archivo;
    char linea[500], *token;
    char fechas[25][20], energias[25][20];
    int numfecha = 0, numenergia = 0, i;
    setlocale(LC_ALL,"spanish");

    archivo = fopen("generacion.txt", "r");

    if (archivo != NULL) {
        // Leer la quinta l�nea (fecha)
        for (i = 0; i < 4; i++) {
            fgets(linea, 500, archivo);
        }
        fgets(linea, 500, archivo);
        token = strtok(linea, ",");
        while (token != NULL && numfecha < 25) {
            strcpy(fechas[numfecha], token);
            numfecha++;
            token = strtok(NULL, ",");
        }

        // Leer la sexta l�nea (energ�a)
        fgets(linea, 500, archivo);
        token = strtok(linea, ",");
        while (token != NULL && numenergia < 25) {
            size_t len = strcspn(token, "\r\n"); // buscar la posici�n del primer salto de l�nea o retorno de carro
            token[len] = '\0'; // reemplazar el salto de l�nea o retorno de carro por un car�cter nulo
            strcpy(energias[numenergia], token);
            numenergia++;
            token = strtok(NULL, ",");
        }

        // Imprimir las fechas y energ�as
        for (i = 0; i < numfecha; i++) {
            printf("%s\t%s\n", fechas[i], energias[i]);
        }

        fclose(archivo);
    } else {
        printf("Error al abrir el archivo.\n");
    }

    return 0;
}


