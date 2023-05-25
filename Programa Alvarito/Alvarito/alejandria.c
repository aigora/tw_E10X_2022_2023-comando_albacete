#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <float.h>

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


void compilar_fechas(char fila[], Datos informacion[]){
    int i = 0, j = 0, k = 0, mes = 0, anio = 0;
    char titulo[50], separador[] = ",/", *cad_aux;
    cad_aux = strtok(fila, separador);
    strcpy(titulo, cad_aux);
    while (cad_aux != NULL){
        if (cad_aux != NULL){
            cad_aux = strtok(NULL, separador);
            mes = atoi(cad_aux);
            informacion[k].fecha[j].mes = mes;
            cad_aux = strtok(NULL, separador);
            anio = atoi(cad_aux);
            informacion[k].fecha[j].anio = anio;
            j++;
            if ((j == 12)){
                k++;
                j = 0;
            }
            if (k != 0 && informacion[k-1].fecha[j].anio != atoi(cad_aux) && informacion[k-1].fecha[11].mes == 0){
                k++;
                j = 0;
            }
        }
    }
}

void compilar_datos2(char fila[], Datos informacion[], int num_anios, int num_fuentes, int meses[]){
    int i = 0, j = 0, k = 0;
    char separador[] = {'"',','}, *cad_aux;
    //puts(fila);
    cad_aux = strtok(fila, separador);
    if (cad_aux != NULL){
        while (cad_aux != NULL){
            cad_aux = strtok(NULL, separador);
            if (cad_aux != NULL){
                informacion[k].datos[num_fuentes].cantidad[i] = atof(cad_aux);
                i++;
                if (i == meses[k]){
                    k++;
                    i = 0;
                }
            }
        }
    }
}

void leer_titulo(char fila[], Datos informacion[], int num_anio, int num_fuente){
    char *cad_aux, separador[] = ",";
    int i = 0;
    //puts(fila);
    cad_aux = strtok(fila, separador);
    strcpy(informacion[num_anio].datos[num_fuente].energia, cad_aux);
}

void print_energy_type(Datos informacion[], int num_anios) {
    int seleccionenergia;
    printf("Introduzca el indice de energia (0-17): ");
    scanf("%d", &seleccionenergia);
    getchar(); // Consume the newline character

    // Check if the energy type index is within the valid range
    if (seleccionenergia >= 0 && seleccionenergia < 19) {
        printf("%s:\n", informacion[0].datos[seleccionenergia].energia);
        for (int j = 0; j < num_anios; j++) {
            for (int i = 0; i < 12; i++) {
                if (informacion[j].fecha[i].mes != 0) {
                    printf("%d/%d: %.15f\n", informacion[j].fecha[i].mes, informacion[j].fecha[i].anio, informacion[j].datos[seleccionenergia].cantidad[i]);
                }
            }
        }
    } else {
        printf("Seleccione una opcion valida.\n");
    }
}

void imprimirTodo(Datos *valor_energia, int num_anio, int *num_mes_por_anio) {
    int i, j, k;

    for (k = 0; k < 18; k++) {
        printf("%s:\n", valor_energia[0].datos[k].energia);

        for (i = 0; i < num_anio; i++) {
            for (j = 0; j < num_mes_por_anio[i]; j++) {
                printf("%i/%i: %.15f\n", valor_energia[i].fecha[j].mes, valor_energia[i].fecha[j].anio, valor_energia[i].datos[k].cantidad[j]);
            }
        }

        printf("\n");
        system("pause");
        system("cls");
    }
}

void mostrarMenu(Datos *valor_energia, int num_anio, int *num_mes_por_anio, Datos informacion[], int num_anios) {
    int choice, tam=10;

    printf("Bienvenido a Electric.Camps de Camps.code\n");
    printf("Alvaro Campos Coria\n Alumno del E-105");
    printf("\n");
    system("pause");
    system("cls");
    printf("Se recomienda al usuario hacer uso de la consulta de indices de energia\n");
    system("pause");
    system("cls");
    do {

        printf("1. Consultar indices de energias\n");
        printf("2. Imprimir todos los valores\n");
        printf("3. Imprimir un valor en concreto de energ�a\n");
        printf("4. Calcular media\n");
        printf("5. Maximo y minimo de energias\n");
        printf("6. Miscelanea de datos\n");
        printf("7. Salir\n");
        printf("Ingrese su opci�n: ");
        scanf("%d", &choice);

        switch (choice) {
            case 2:
                imprimirTodo(valor_energia, num_anio, num_mes_por_anio);
                system("pause");
                system("cls");
                break;
            case 3:
                print_energy_type(informacion, num_anios);
                system("pause");
                system("cls");
                break;
            case 1:
                imprimirIndices(informacion);
                system("pause");
                system("cls");
                break;
            case 4:
                calcularMedia(informacion,num_anio);
                system("pause");
                system("cls");
                break;
            case 5:
                calcularMinimoMaximo(informacion, num_anios);
                system("pause");
                system("cls");
                break;
            case 6:
                miscelanea(informacion, num_anios);
                system("pause");
                system("cls");
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci�n inv�lida. Por favor, ingrese una opci�n v�lida.\n");
                system("pause");
                system("cls");
                break;
        }
    } while (choice != 7);
}


void imprimirIndices(Datos informacion) {
    int i;

    for (i = 0; i < 18; i++) {
        printf("%d. %s\n", i , informacion.datos[i].energia);
    }
}

void calcularMedia(Datos *informacion, int num_anios) {
    int index;
    printf("Ingrese el �ndice de la energ�a (0-16): ");
    scanf("%d", &index);
    if (index < 0 || index > 16) {
        printf("�ndice inv�lido.\n");
        return;
    }
    for (int i = 0; i < num_anios-1; i++) {
        printf("Anio: %d\n", informacion[i].fecha[0].anio);
        double sum = 0;
        for (int k = 0; k < 12; k++) {
            sum += informacion[i].datos[index].cantidad[k];
        }
        double media = sum / 12;
        printf("%s: %.5f\n", informacion[i].datos[index].energia, media);
    }
}

void calcularMinimoMaximo(Datos *informacion, int num_anios) {
    int index;
    printf("Ingrese el �ndice de la energ�a (0-16): ");
    scanf("%d", &index);
    if (index < 0 || index > 16) {
        printf("�ndice inv�lido.\n");
        return;
    }
    for (int i = 0; i < num_anios-1; i++) {
        printf("anio: %d\n", informacion[i].fecha[0].anio);
        double min = informacion[i].datos[index].cantidad[0];
        double max = informacion[i].datos[index].cantidad[0];
        int min_mes = 0;
        int max_mes = 0;
        for (int k = 1; k < 12; k++) {
            if (informacion[i].datos[index].cantidad[k] < min) {
                min = informacion[i].datos[index].cantidad[k];
                min_mes = k;
            }
            if (informacion[i].datos[index].cantidad[k] > max) {
                max = informacion[i].datos[index].cantidad[k];
                max_mes = k;
            }
        }
        printf("%s\n", informacion[i].datos[index].energia);
        printf("Minimo: %.2f (Mes: %d)\n", min, min_mes + 1);
        printf("Maximo: %.2f (Mes: %d)\n", max, max_mes + 1);
    }
}

void miscelanea(Datos *informacion, int num_anios) {
    double max_total = 0;
    int max_anio = 0;
    int max_mes = 0;
    int max_fuente = 0;
    for (int i = 0; i < num_anios; i++) {
        for (int j = 0; j < 17; j++) {
            for (int k = 0; k < 12; k++) {
                if (informacion[i].datos[j].cantidad[k] > max_total) {
                    max_total = informacion[i].datos[j].cantidad[k];
                    max_anio = i;
                    max_mes = k;
                    max_fuente = j;
                }
            }
        }
    }
    printf("Produccion maxima: %.2f (Energia: %s, Mes: %d, Anio: %d)\n", max_total, informacion[max_anio].datos[max_fuente].energia, max_mes + 1, informacion[max_anio].fecha[0].anio);

    for (int i = 0; i < num_anios-1; i++) {
        double max_media = 0;
        double min_media = DBL_MAX;
        int max_fuente_media = 0;
        int min_fuente_media = 0;
        for (int j = 0; j < 17; j++) {
            double sum = 0;
            for (int k = 0; k < 12; k++) {
                sum += informacion[i].datos[j].cantidad[k];
            }
            double media = sum / 12;
            if (media > max_media) {
                max_media = media;
                max_fuente_media = j;
            }
            if (media < min_media) {
                min_media = media;
                min_fuente_media = j;
            }
        }
        printf("Anio: %d\n", informacion[i].fecha[0].anio);
        printf("Maxima media: %.2f (Energia: %s)\n", max_media, informacion[i].datos[max_fuente_media].energia);
        printf("Minima media: %.2f (Energia: %s)\n", min_media, informacion[i].datos[min_fuente_media].energia);
    }
}
