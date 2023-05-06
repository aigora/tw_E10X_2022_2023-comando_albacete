#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {

    FILE *archivo;
    setlocale(LC_ALL, "spanish");
    char linea[500];
    char fechas[25][10];
    char energia[30][20];
    char *fecha;
    int i, numfecha = 0;
    char anio_str[5];
    int anio_deseado = 0;

    while (anio_deseado != 2021 && anio_deseado != 2022)
    {
        printf("Ingrese el año deseado (2021 o 2022): ");
        scanf("%s", anio_str);
        anio_deseado = atoi(anio_str);
        if (anio_deseado != 2021 && anio_deseado != 2022)
        {
            printf("Año inválido. Intente nuevamente.\n");
        }
    }

    archivo = fopen("generacion.txt", "r");
    if (archivo != NULL) {
        for (i = 0; i < 5; i++)
        { //Lee hasta la quinta linea;
            fgets(linea, 500, archivo);
        }
        fecha = strtok(linea, ",");
        while (fecha != NULL && numfecha < 25) // Validar que no se exceda el tamaño de fechas
        {
            // Extraer el año de la fecha
            char* mes_str = strtok(fecha, "/");
            char* anio_str = strtok(NULL, "/");
            int anio = atoi(anio_str);
            // Si el año coincide con el deseado, almacenar la fecha
            if (anio == anio_deseado)
            {
                sprintf(fechas[numfecha], "%s/%s", mes_str, anio_str);
                numfecha++;
            }
            fecha = strtok(NULL, ",");
        }
        for (i = 0; i < numfecha; i++) { // Imprimir todas las fechas almacenadas
            printf("%s\n", fechas[i]);
        }
        fclose(archivo);
    }
    else
    {
        printf("No se pudo abrir el archivo.\n");
    }

    return 0;
}

