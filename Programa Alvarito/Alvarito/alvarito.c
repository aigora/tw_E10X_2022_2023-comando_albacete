#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "alejandria.h"
#include<locale.h>

int main(){

    setlocale(LC_CTYPE, "");

    int i = 0, j = 0, k = 0, t = 0, num_datos = 0, num_anio = 0, m = 0, num_mes_por_anio[15], num_mes = 0;
    FILE *archivo;
    char* fila = malloc(10000 * sizeof(char));  // Puntero para almacenar temporalmente cada l�nea del archivo
    char** filas = NULL;  // Arreglo de punteros para almacenar las l�neas del archivo
    int filas_size = 0;  // Tama�o actual del arreglo 'filas'
    char seleccionenergia[24];
    Datos valor_energia[15];  // Arreglo de estructuras para almacenar los datos energ�ticos

    archivo = fopen("generacion.txt","r");
    if (archivo == NULL){
        printf("No se ha podido abrir el archivo");  // Mensaje de error si no se puede abrir el archivo
        return 0;
    }
    else{
        printf("Archivo abierto correctamente\n");
        system("pause");
        system("cls");
    }

    for (i = 0; i < 23; i++){
        fgets(fila, 10000, archivo);  // Leer una l�nea del archivo y almacenarla en 'fila'
        filas_size++;
        filas = realloc(filas, filas_size * sizeof(char*));  // Realocar memoria para agregar una nueva l�nea a 'filas'
        if (filas == NULL) {
            printf("Error\n");  // Mensaje de error si falla la realocaci�n de memoria
            return -1;
        }
        filas[i] = malloc(10000 * sizeof(char));  // Asignar memoria para almacenar la l�nea en 'filas[i]'
        if (filas[i] == NULL) {
            printf("Error\n");  // Mensaje de error si falla la asignaci�n de memoria
            return -1;
        }
        strcpy(filas[i], fila);  // Copiar el contenido de 'fila' a 'filas[i]'
        memset(fila, 0, 10000);  // Reiniciar 'fila' para la siguiente lectura
    }

    for (i = 0; i < strlen(filas[3]); i++){
        if (filas[3][i] == ','){
            num_datos++;  // Contar la cantidad de comas en la cuarta l�nea del archivo
        }
    }

    compilar_fechas(filas[4], valor_energia);  // Llamar a la funci�n 'compilar_fechas' para procesar la fecha en la quinta l�nea del archivo

    for (i = 0; i < 15; i++){
        if (valor_energia[i].fecha[0].anio != 0){
            num_anio++;  // Contar la cantidad de a�os con datos en 'valor_energia'
        }
    }

    memset(num_mes_por_anio, 0, 15);  // Inicializar el arreglo 'num_mes_por_anio' con ceros

    for (i = 0; i < num_anio; i++){
        for (j = 0; j < 12; j++){
            if (valor_energia[i].fecha[j].mes != 0){
                num_mes_por_anio[i] = num_mes_por_anio[i] + 1;  // Contar la cantidad de meses con datos por cada a�o en 'valor_energia'
            }
        }
    }

    for (i = 0; i < 18; i++){
        m = i + 5;
        for (j = 0; j < num_anio; j++){
            memset(fila, 0, 10000);  // Reiniciar 'fila' para la siguiente lectura
            strcpy(fila, filas[m]);  // Copiar la l�nea correspondiente a 'fila'
            titulos(fila, valor_energia, j, i);  // Llamar a la funci�n 'titulos' para procesar los t�tulos en 'fila'
        }
        compilar(filas[m], valor_energia, num_anio, i, num_mes_por_anio);  // Llamar a la funci�n 'compilar' para procesar los datos en 'fila'
    }

    printf("Compilaci�n de datos terminada...\n");
    system("pause");
    system("cls");

    mostrarMenu(valor_energia,num_anio,num_mes_por_anio,valor_energia,num_anio);  // Llamar a la funci�n 'mostrarMenu' para mostrar el men� de opciones

    free(fila);  // Liberar la memoria asignada a 'fila'

    for (i = 0; i < filas_size; i++) {
        free(filas[i]);  // Liberar la memoria asignada a cada l�nea en 'filas'
    }

    free(filas);  // Liberar la memoria asignada a 'filas'

    return 0;
}
