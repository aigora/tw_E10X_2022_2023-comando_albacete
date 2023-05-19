#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"
#include"alejandria.h"


int main(){

    int i = 0, j = 0, k = 0, t = 0, num_datos = 0, num_anio = 0, m = 0, num_mes_por_anio[15], num_mes = 0;
    FILE *archivo;
    char* fila = malloc(10000 * sizeof(char));
        char** filas = malloc(23 * sizeof(char*));
    char seleccionenergia[24];
    for (int i = 0; i < 23; i++)
        filas[i] = malloc(10000 * sizeof(char));  //Asignaci�n diamica de memoria para albergar la informaci�n del archivo
    Datos valor_energia[15];


    archivo = fopen("generacion.txt","r");
    if (archivo == NULL){
        printf("No se ha podido abrir el archivo");
        return 0;
    }
    else{
        printf("Se ha abierto correctamente\n");
        system("pause");
        system("cls");
    }
    for (i = 0; i < 23; i++){
        fgets(fila, 10000, archivo);
        strcpy(filas[i], fila);
        memset(fila, 0, 10000);
    }

    for ( i = 0; i < strlen(filas[3]); i++){
        if (filas[3][i] == ','){
            num_datos++;
        }
    }

    compilar_fechas(filas[4], valor_energia);

    for ( i = 0; i < 15; i++){
        if (valor_energia[i].fecha[0].anio != 0){
            num_anio++;
        }
    }

    for ( i = 0; i < num_anio; i++){
        for ( j = 0; j < 12; j++){
            if (valor_energia[i].fecha[j].mes != 0){
                printf("%i/%i\n\n",valor_energia[i].fecha[j].mes, valor_energia[i].fecha[j].anio);
            }
        }
    }

    system("pause");
    system("cls");

    //Compilacion de datos 2.0

    memset(num_mes_por_anio, 0, 15);

    for ( i = 0; i < num_anio; i++){
        for ( j = 0; j < 12; j++){
            if (valor_energia[i].fecha[j].mes != 0){
                num_mes_por_anio[i] = num_mes_por_anio[i] + 1;
            }
        }
    }

    for ( i = 0; i < 18; i++){
        m = i + 5;
        for ( j = 0; j < num_anio; j++){
            memset(fila, 0, 10000);
            strcpy(fila, filas[m]);
            leer_titulo(fila, valor_energia, j, i);
        }
        compilar_datos2(filas[m], valor_energia, num_anio, i, num_mes_por_anio);
    }

    //Imprimir tabla:



    for ( k = 0; k < 18; k++){
        printf("%s:\n", valor_energia[0].datos[k].energia);
        for ( j = 0; j < num_anio; j++){
            for ( i = 0; i < num_mes_por_anio[j]; i++){
               printf("%i/%i: %.15f\n", valor_energia[j].fecha[i].mes, valor_energia[j].fecha[i].anio, valor_energia[j].datos[k].cantidad[i]);
            }
        }
        system("pause");
        system("cls");
    }

    free(fila);
    for (i = 0; i < 23; i++) {
        free(filas[i]);
    }
    free(filas);        //Liberamos la memoria.


    return 0;
}