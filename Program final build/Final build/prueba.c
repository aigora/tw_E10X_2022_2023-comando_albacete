#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>

// funci�n para convertir y redondear los datos de energ�a
void convertir_y_redondear_energia(char *energias[], int num_datos);

int main()
{
    FILE *archivo;
    char linea[500], *token;
    char **fechas, **energias;
    int numfecha = 0, numenergia = 0, numdatosenergia = 0, i;
    setlocale(LC_ALL,"spanish");

    // Asignar memoria para las matrices de fechas y energ�as
    fechas = (char **) malloc(5000 * sizeof(char *));
    for (i = 0; i < 5000; i++) {
        fechas[i] = (char *) malloc(20 * sizeof(char));
    }

    energias = (char **) malloc(5000 * sizeof(char *));
    for (i = 0; i < 5000; i++) {
        energias[i] = (char *) malloc(1000 * sizeof(char));
    }

    archivo = fopen("generacion.txt", "r");
    if (archivo != NULL) {
        // Leer la quinta l�nea (fecha)
        for (i = 0; i < 4; i++) {
            fgets(linea, 500, archivo);
        }
        fgets(linea, 500, archivo);
        token = strtok(linea, ",");
        while (token != NULL) {
            strcpy(fechas[numfecha], token);
            numfecha++;
            token = strtok(NULL, ",");
        }

        // Leer la sexta l�nea (energ�a)
        fgets(linea, 500, archivo);
        token = strtok(linea, ",");
        while (token != NULL) {
            if (numdatosenergia > 0) {
                strcpy(energias[numdatosenergia-1], token);
            }
            numdatosenergia++;
            token = strtok(NULL, ",");
        }
        energias[numdatosenergia-1][strlen(energias[numdatosenergia-1])-1] = '\0';

        // Convertir y redondear los datos de energ�a
        convertir_y_redondear_energia(energias, numdatosenergia-1);
        for (i = 0; i < numdatosenergia-1; i++) {
            numenergia++;
        }
        // Imprimir las fechas y energ�as
        for (i = 0; i < numfecha; i++) {
            printf("%s\t%s\n", fechas[i], energias[i]);
}


        fclose(archivo);

    return 0;
}


}

void convertir_y_redondear_energia(char *energias[], int num_datos) {
    for (int i = 0; i < num_datos; i++) {
        // convertir de cadena a punto flotante

        double energia = atof(energias[i]);

        // redondear al n�mero entero m�s cercano
        int energia_redondeada = (int) round(energia);

        // reemplazar el valor en la cadena original
        sprintf(energias[i], "%d", energia_redondeada);
    }
}

