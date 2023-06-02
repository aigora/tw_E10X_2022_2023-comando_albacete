#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <float.h>
#include<locale.h>
#include<stdbool.h>
#include"alejandria.h"


void compilar_fechas(char fila[], Datos informacion[]){
    // Esta funci�n se encarga de compilar las fechas en la estructura Datos
    int j=0,k = 0, mes = 0, anio = 0;
    char titulo[50], separador[] = ",/", *cad_aux;
    cad_aux = strtok(fila, separador); //se utiliza la funci�n strtok para dividir la cadena fila en tokens utilizando los caracteres de separaci�n.
    strcpy(titulo, cad_aux); //Copiamos el primer token con strcpy a la cadena titulo
    while (cad_aux != NULL){
        if (cad_aux != NULL){
            cad_aux = strtok(NULL, separador);
            mes = atoi(cad_aux); // se convierte el token a entero utilizando la funci�n atoi y se asigna a la variable mes
            informacion[k].fecha[j].mes = mes;
            cad_aux = strtok(NULL, separador);
            anio = atoi(cad_aux);
            informacion[k].fecha[j].anio = anio; //El siguiente token (correspondiente al a�o) y se convierte a entero, asign�ndolo a la variable anio
            j++;
            if ((j == 12)){
                k++;
                j = 0;
            }
            if (k != 0 && informacion[k-1].fecha[j].anio != atoi(cad_aux) && informacion[k-1].fecha[11].mes == 0){
                k++;   //comprobaci�n para ver si k no es igual a 0 y si el a�o de la fecha anterior
                j = 0;   //y si el mes de la �ltima fecha del bloque anterior es 0 se incrementa k y se reinicia j a 0.
            }
        }
    }
}

void compilar(char fila[], Datos informacion[], int num_anios, int num_fuentes, int meses[]){
    int i = 0, k = 0;
    char separador[] = {'"',','}, *cad_aux;
    // Separar la cadena en tokens usando el separador ","
    cad_aux = strtok(fila, separador);
    // Comprobar si el primer token es diferente de NULL
    if (cad_aux != NULL){
    // Recorrer todos los tokens restantes
        while (cad_aux != NULL){
            // Obtener el siguiente token
            cad_aux = strtok(NULL, separador);
            // Comprobar si el token actual no es NULL
            if (cad_aux != NULL){
            // Convertir el token en un valor flotante y guardarlo en la estructura informacion
                informacion[k].datos[num_fuentes].cantidad[i] = atof(cad_aux);
                i++;
                if (i == meses[k]){
                // Comprobar si se han procesado todos los meses del a�o actual
                    k++;
                    i = 0; //Pasar al a�o siguiente y reiniciar contador de mes
                }
            }
        }
    }
}

void titulos(char fila[], Datos informacion[], int num_anio, int num_fuente){
    char *cad_aux, separador[] = ",";
    //separar la cadena en tokens usando como separador ","
    cad_aux = strtok(fila, separador);
    //copiar el primer token a la estructura informaci�n
    strcpy(informacion[num_anio].datos[num_fuente].energia, cad_aux);
}

void print_energy_type(Datos informacion[], int num_anios) {
    setlocale(LC_CTYPE, "");
    int seleccionenergia, i ,j;
    printf("Introduzca el �ndice de energia (0-17): ");
    scanf("%d", &seleccionenergia);
    getchar(); // Consumir el car�cter de la nueva l�nea

    //Comprueba que el indice esta en el rango valido de energia.
    if (seleccionenergia >= 0 && seleccionenergia < 19) {
        printf("%s:\n", informacion[0].datos[seleccionenergia].energia);
        //recorre los a�os y meses para imprimir los datos correspondientes a la energia seleccionada.
        for (j = 0; j < num_anios; j++) {
            for ( i = 0; i < 12; i++) {
                // Comprobar si el mes es diferente de cero (indicando que hay datos disponibles)
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
    setlocale(LC_CTYPE, "");
    //Itera sobre los 18 tipos de energia que hay
    for (k = 0; k < 18; k++) {
        printf("%s:\n", valor_energia[0].datos[k].energia);
        //Recorre cada a�o
        for (i = 0; i < num_anio; i++) {
        //Recorre todos los meses del a�o en el que estamos
            for (j = 0; j < num_mes_por_anio[i]; j++) {
            //Imprime toda la informaci�n
                printf("%i/%i: %.15f\n", valor_energia[i].fecha[j].mes, valor_energia[i].fecha[j].anio, valor_energia[i].datos[k].cantidad[j]);
            }
        }

        printf("\n");
        system("pause");
        system("cls");
    }
}

void mostrarMenu(Datos *valor_energia, int num_anio, int *num_mes_por_anio, Datos informacion[], int num_anios) {
    int selecciona;
    setlocale(LC_CTYPE, "");
    printf("Bienvenido a Electric.Camps de Camps.code\n");
    printf("�lvaro Campos Coria\n Alumno del E-105");
    printf("\n");
    printf("Creador de todo el c�digo, arregl� el programa :) .\n");
    system("pause");
    system("cls");
    printf("Se recomienda al usuario hacer uso de la consulta de �ndices de energia\n");
    system("pause");
    system("cls");
    printf("Perdone si algunos car�cteres del idioma espa�ol no aparecen en pantalla de la manera adecuada\n");
    system("pause");
    system("cls");
    printf("Todas las cantidades de energ�a generada est�n en GWh\n");
    system("pause");
    system("cls");
    do {

        printf("1. Consultar indices de energias\n");
        printf("2. Imprimir todos los valores\n");
        printf("3. Imprimir un valor en concreto de energ�a\n");
        printf("4. Calcular media\n");
        printf("5. Maximo y minimo de energias\n");
        printf("6. Miscelanea de datos\n");
        printf("7. Creaci�n de archivo con datos personalizados\n");
        printf("8. Salir\n");
        printf("Ingrese su opci�n: ");
        scanf("%d", &selecciona);

        switch (selecciona) {
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
                imprimirIndices(*informacion);
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
                darlachapa();
                break;
            case 7:
                archivoBacano(informacion,num_anios);
                system("pause");
                system("cls");
                break;
            case 8:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci�n inv�lida. Por favor, ingrese una opci�n v�lida.\n");
                system("pause");
                system("cls");
                break;
        }
    } while (selecciona != 8);
}


void imprimirIndices(Datos informacion) {
    int i;
    setlocale(LC_CTYPE, "");
    //Recorre la estructura informaci�n
    for (i = 0; i < 18; i++) {
        //Imprime los indices de todas las energias
        printf("%d. %s\n", i , informacion.datos[i].energia);
    }
}

void calcularMedia(Datos *informacion, int num_anios) {
    int indice, i, k;
    setlocale(LC_CTYPE, "");
    printf("Ingrese el �ndice de la energ�a (0-16): ");
    scanf("%d", &indice);
    //Verifica que el indice esta dentro del rango v�lido.
    if (indice < 0 || indice > 16) {
        printf("�ndice inv�lido.\n");
        return;
    }
    //Recorremos todos los a�os
    for (i = 0; i < num_anios-1; i++) {
        printf("A�o: %d\n", informacion[i].fecha[0].anio);
        double sum = 0;
        //Calculamos la suma de los valores de energ�a de para el tipo de energ�a y a�o actual
        for (k = 0; k < 12; k++) {
            sum += informacion[i].datos[indice].cantidad[k];
        }
        //C�lculo final de la media de ese a�o
        double media = sum / 12;
        printf("%s: %.5f\n", informacion[i].datos[indice].energia, media);
    }
}

void calcularMinimoMaximo(Datos *informacion, int num_anios) {
    int indice;
    setlocale(LC_CTYPE, "");
    //Solicita al usuario el �ndice de energ�a
    printf("Ingrese el �ndice de la energ�a (0-16): ");
    scanf("%d", &indice);
    //Verficamos si el indice est� dentro del rango
    if (indice < 0 || indice > 16) {
        printf("�ndice inv�lido.\n");
        return;
    }
    //Bucle para recorrer cada a�o
    for (int i = 0; i < num_anios-1; i++) {
        printf("a�o: %d\n", informacion[i].fecha[0].anio);
        double min = informacion[i].datos[indice].cantidad[0];
        double max = informacion[i].datos[indice].cantidad[0];
        int min_mes = 0;
        int max_mes = 0;
        // Encontrar el valor m�nimo y m�ximo de energ�a y sus respectivos meses
        for (int k = 1; k < 12; k++) {
            if (informacion[i].datos[indice].cantidad[k] < min) {
                min = informacion[i].datos[indice].cantidad[k];
                min_mes = k;
            }
            if (informacion[i].datos[indice].cantidad[k] > max) {
                max = informacion[i].datos[indice].cantidad[k];
                max_mes = k;
            }
        }
        // Imprimir los resultados
        printf("%s\n", informacion[i].datos[indice].energia);
        printf("M�nimo: %.2f (Mes: %d)\n", min, min_mes + 1);
        printf("M�ximo: %.2f (Mes: %d)\n", max, max_mes + 1);
    }
}

void miscelanea(Datos *informacion, int num_anios) {
    setlocale(LC_CTYPE, "");
    double max_total = 0;
    int max_anio = 0;
    int max_mes = 0;
    int max_fuente = 0;
    // Encontrar el valor m�ximo de energ�a en toda la informaci�n
    for (int i = 0; i < num_anios-1; i++) {
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
    // Imprimir el valor m�ximo y su informaci�n relacionada
    printf("Producci�n m�xima: %.2f (Energia: %s, Mes: %d, A�o: %d)\n", max_total, informacion[max_anio].datos[max_fuente].energia, max_mes + 1, informacion[max_anio].fecha[0].anio);
    // Calcular y mostrar las medias m�xima y m�nima de energ�a por a�o
    for (int i = 0; i < num_anios; i++) {
        double max_media = 0;
        double min_media = DBL_MAX; //La constante DBL_MAX representa el valor m�ximo finito representable de tipo double. Utilizada para establecer un valor inicial alto para min_media
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
        printf("A�o: %d\n", informacion[i].fecha[0].anio);
        printf("Maxima media: %.2f (Energia: %s)\n", max_media, informacion[i].datos[max_fuente_media].energia);
        printf("Minima media: %.2f (Energia: %s)\n", min_media, informacion[i].datos[min_fuente_media].energia);
    }
}

void darlachapa() {
    setlocale(LC_ALL, "spanish");
    int i=0;
    char *archivos[] = {"muchachapa.txt", "muchisimachapa.txt", "chapafinal.txt"};
    char *nombres[] = {"Energ�a E�lica", "Ciclo combinado", "Conclusiones sobre ambas energ�as"};
    // Iterar sobre cada archivo y nombre correspondiente
    for ( i = 0; i < 3; i++) {
        printf("�Desea ver el archivo %d: %s? (s/n): ", i+1, nombres[i]);
        char respuesta;
        scanf(" %c", &respuesta);
        // Verificar la respuesta del usuario
        if (respuesta == 's' || respuesta == 'S') {
            printf("Archivo: %s\n", nombres[i]);
            FILE *fp = fopen(archivos[i], "r");
            // Verificar si se pudo abrir el archivo correctamente
            if (fp == NULL) {
                printf("Error al abrir el archivo.\n");
                continue;
            }
            char c;
            // Leer y mostrar el contenido del archivo
            while ((c = fgetc(fp)) != EOF) {
                putchar(c);
            }
            fclose(fp);
            system("pause");
            system("cls");
        }
        system("pause");
        system("cls");
    }
}


void archivoBacano(Datos *informacion, int num_anios) {
    int indice;
    setlocale(LC_CTYPE, "");
    // Solicitar al usuario el �ndice de la energ�a
    printf("Ingrese el �ndice de la energ�a (0-16): ");
    scanf("%d", &indice);
    // Verificar si el �ndice es v�lido
    if (indice < 0 || indice > 16) {
        printf("�ndice inv�lido.\n");
        return;
    }
    char opcion;
    // Preguntar al usuario si desea calcular la media de esta energ�a
    printf("�Desea calcular la media de esta energ�a? %s (s/n): ",informacion[indice].datos[indice].energia);
    scanf(" %c", &opcion);
    bool calcularMedia = false;
    // Preguntar al usuario si desea calcular el m�nimo y m�ximo de esta energ�a
    if (opcion == 's' || opcion == 'S') {
        calcularMedia = true;
    }
    printf("�Desea calcular el m�nimo y m�ximo de esta energ�a? (s/n): ");
    // Preguntar al usuario si desea borrar los datos antiguos del archivo
    scanf(" %c", &opcion);
    bool calcularMinimoMaximo = false;
    if (opcion == 's' || opcion == 'S') {
        calcularMinimoMaximo = true;
    }
    if (calcularMedia || calcularMinimoMaximo) {
        printf("�Desea borrar los datos antiguos del archivo? (s/n): ");
        scanf(" %c", &opcion);
        FILE *fp;
        // Abrir el archivo en modo de escritura o anexado seg�n la respuesta del usuario
        if (opcion == 's' || opcion == 'S') {
            fp = fopen("EsMiEnergia.txt", "w");
        } else {
            fp = fopen("EsMiEnergia.txt", "a");
        }
        // Verificar si se pudo abrir el archivo correctamente
        if (fp == NULL) {
            printf("No se pudo abrir el archivo\n");
            return;
        }
        // Calcular la media, m�nimo y m�ximo de la energ�a para cada a�o
        for (int i = 0; i < num_anios; i++) {
            fprintf(fp,"A�o: %d\n", informacion[i].fecha[0].anio);
            double min = informacion[i].datos[indice].cantidad[0];
            double max = informacion[i].datos[indice].cantidad[0];
            int min_mes = 0;
            int max_mes = 0;
            double sum = 0;
            // Calcular la suma, m�nimo y m�ximo de la energ�a para cada mes
            for (int k = 0; k < 12; k++) {
                sum += informacion[i].datos[indice].cantidad[k];
                if (informacion[i].datos[indice].cantidad[k] < min) {
                    min = informacion[i].datos[indice].cantidad[k];
                    min_mes = k;
                }
                if (informacion[i].datos[indice].cantidad[k] > max) {
                    max = informacion[i].datos[indice].cantidad[k];
                    max_mes = k;
                }
            }
            fprintf(fp,"%s\n", informacion[i].datos[indice].energia);
            if (calcularMedia) {
                double media = sum / 12;
                fprintf(fp,"Media: %.5f\n", media);
            }
            if (calcularMinimoMaximo) {
                fprintf(fp,"M�nimo: %.2f (Mes: %d)\n", min, min_mes + 1);
                fprintf(fp,"M�ximo: %.2f (Mes: %d)\n", max, max_mes + 1);
            }
        }
        //Se cierra el archivo una vez terminado todos los procesos.
        fclose(fp);
    }
}
