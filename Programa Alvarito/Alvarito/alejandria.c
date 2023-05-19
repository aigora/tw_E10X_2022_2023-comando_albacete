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



