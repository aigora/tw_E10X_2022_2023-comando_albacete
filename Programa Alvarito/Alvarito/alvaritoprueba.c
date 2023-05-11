#include "stdio.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

typedef struct
{
    int mes;
    int anio;
}fechas;

typedef struct
{
    char energia[50];
    double cantidad[12];

}Energias;

typedef struct
{
    fechas fecha[12];
    Energias datos[18];
}Datos;

void compilar_fechas(char fila[], Datos informacion[]);

void compilar_datos2(char fila[], Datos informacion[], int num_anios, int num_fuentes, int meses[]);

void leer_titulo(char fila[], Datos informacion[], int num_anio, int num_fuente);

int main(){

    int i = 0, j = 0, k = 0, t = 0, num_datos = 0, num_anio = 0, m = 0, num_mes_por_anio[15], num_mes = 0;
    FILE *archivo;
    char* fila = malloc(10000 * sizeof(char));
        char** filas = malloc(23 * sizeof(char*));

    for (int i = 0; i < 23; i++)
        filas[i] = malloc(10000 * sizeof(char));  //Asignación diamica de memoria para albergar la información del archivo
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

// Versión 2, el bucle estará en el codigo principal, se limitará a leer datos de un solo año y devolverlos, el titulo se leerá en el codigo principal

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

//Leé el titulo de la fuente y lo aplica al año dado

void leer_titulo(char fila[], Datos informacion[], int num_anio, int num_fuente){
    char *cad_aux, separador[] = ",";
    int i = 0;
    //puts(fila);
    cad_aux = strtok(fila, separador);
    strcpy(informacion[num_anio].datos[num_fuente].energia, cad_aux);
}
