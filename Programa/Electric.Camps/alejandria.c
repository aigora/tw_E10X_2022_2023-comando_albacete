#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <float.h>
#include<locale.h>
#include<stdbool.h>
#include"alejandria.h"


void compilar_fechas(char fila[], Datos informacion[]){
    // Esta función se encarga de compilar las fechas en la estructura Datos
    int j=0,k = 0, mes = 0, anio = 0;
    char titulo[50], separador[] = ",/", *cad_aux;
    cad_aux = strtok(fila, separador); //se utiliza la función strtok para dividir la cadena fila en tokens utilizando los caracteres de separación.
    strcpy(titulo, cad_aux); //Copiamos el primer token con strcpy a la cadena titulo
    while (cad_aux != NULL){
        if (cad_aux != NULL){
            cad_aux = strtok(NULL, separador);
            mes = atoi(cad_aux); // se convierte el token a entero utilizando la función atoi y se asigna a la variable mes
            informacion[k].fecha[j].mes = mes;
            cad_aux = strtok(NULL, separador);
            anio = atoi(cad_aux);
            informacion[k].fecha[j].anio = anio; //El siguiente token (correspondiente al año) y se convierte a entero, asignándolo a la variable anio
            j++;
            if ((j == 12)){
                k++;
                j = 0;
            }
            if (k != 0 && informacion[k-1].fecha[j].anio != atoi(cad_aux) && informacion[k-1].fecha[11].mes == 0){
                k++;   //comprobación para ver si k no es igual a 0 y si el año de la fecha anterior
                j = 0;   //y si el mes de la última fecha del bloque anterior es 0 se incrementa k y se reinicia j a 0.
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
                // Comprobar si se han procesado todos los meses del año actual
                    k++;
                    i = 0; //Pasar al año siguiente y reiniciar contador de mes
                }
            }
        }
    }
}

void titulos(char fila[], Datos informacion[], int num_anio, int num_fuente){
    char *cad_aux, separador[] = ",";
    //separar la cadena en tokens usando como separador ","
    cad_aux = strtok(fila, separador);
    //copiar el primer token a la estructura información
    strcpy(informacion[num_anio].datos[num_fuente].energia, cad_aux);
}

void print_energy_type(Datos informacion[], int num_anios) {
    setlocale(LC_CTYPE, "");
    int seleccionenergia, i ,j;
    printf("Introduzca el índice de energia (0-17): ");
    scanf("%d", &seleccionenergia);
    getchar(); // Consumir el carácter de la nueva línea

    //Comprueba que el indice esta en el rango valido de energia.
    if (seleccionenergia >= 0 && seleccionenergia < 19) {
        printf("%s:\n", informacion[0].datos[seleccionenergia].energia);
        //recorre los años y meses para imprimir los datos correspondientes a la energia seleccionada.
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
        //Recorre cada año
        for (i = 0; i < num_anio; i++) {
        //Recorre todos los meses del año en el que estamos
            for (j = 0; j < num_mes_por_anio[i]; j++) {
            //Imprime toda la información
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
    printf("Álvaro Campos Coria\n Alumno del E-105");
    printf("\n");
    printf("Creador de todo el código, arreglé el programa :) .\n");
    system("pause");
    system("cls");
    printf("Se recomienda al usuario hacer uso de la consulta de índices de energia\n");
    system("pause");
    system("cls");
    printf("Perdone si algunos carácteres del idioma español no aparecen en pantalla de la manera adecuada\n");
    system("pause");
    system("cls");
    printf("Todas las cantidades de energía generada están en GWh\n");
    system("pause");
    system("cls");
    do {

        printf("1. Consultar indices de energias\n");
        printf("2. Imprimir todos los valores\n");
        printf("3. Imprimir un valor en concreto de energía\n");
        printf("4. Calcular media\n");
        printf("5. Maximo y minimo de energias\n");
        printf("6. Miscelanea de datos\n");
        printf("7. Creación de archivo con datos personalizados\n");
        printf("8. Salir\n");
        printf("Ingrese su opción: ");
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
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                system("pause");
                system("cls");
                break;
        }
    } while (selecciona != 8);
}


void imprimirIndices(Datos informacion) {
    int i;
    setlocale(LC_CTYPE, "");
    //Recorre la estructura información
    for (i = 0; i < 18; i++) {
        //Imprime los indices de todas las energias
        printf("%d. %s\n", i , informacion.datos[i].energia);
    }
}

void calcularMedia(Datos *informacion, int num_anios) {
    int indice, i, k;
    setlocale(LC_CTYPE, "");
    printf("Ingrese el índice de la energía (0-16): ");
    scanf("%d", &indice);
    //Verifica que el indice esta dentro del rango válido.
    if (indice < 0 || indice > 16) {
        printf("Índice inválido.\n");
        return;
    }
    //Recorremos todos los años
    for (i = 0; i < num_anios-1; i++) {
        printf("Año: %d\n", informacion[i].fecha[0].anio);
        double sum = 0;
        //Calculamos la suma de los valores de energía de para el tipo de energía y año actual
        for (k = 0; k < 12; k++) {
            sum += informacion[i].datos[indice].cantidad[k];
        }
        //Cálculo final de la media de ese año
        double media = sum / 12;
        printf("%s: %.5f\n", informacion[i].datos[indice].energia, media);
    }
}

void calcularMinimoMaximo(Datos *informacion, int num_anios) {
    int indice;
    setlocale(LC_CTYPE, "");
    //Solicita al usuario el índice de energía
    printf("Ingrese el índice de la energía (0-16): ");
    scanf("%d", &indice);
    //Verficamos si el indice está dentro del rango
    if (indice < 0 || indice > 16) {
        printf("Índice inválido.\n");
        return;
    }
    //Bucle para recorrer cada año
    for (int i = 0; i < num_anios-1; i++) {
        printf("año: %d\n", informacion[i].fecha[0].anio);
        double min = informacion[i].datos[indice].cantidad[0];
        double max = informacion[i].datos[indice].cantidad[0];
        int min_mes = 0;
        int max_mes = 0;
        // Encontrar el valor mínimo y máximo de energía y sus respectivos meses
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
        printf("Mínimo: %.2f (Mes: %d)\n", min, min_mes + 1);
        printf("Máximo: %.2f (Mes: %d)\n", max, max_mes + 1);
    }
}

void miscelanea(Datos *informacion, int num_anios) {
    setlocale(LC_CTYPE, "");
    double max_total = 0;
    int max_anio = 0;
    int max_mes = 0;
    int max_fuente = 0;
    // Encontrar el valor máximo de energía en toda la información
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
    // Imprimir el valor máximo y su información relacionada
    printf("Producción máxima: %.2f (Energia: %s, Mes: %d, Año: %d)\n", max_total, informacion[max_anio].datos[max_fuente].energia, max_mes + 1, informacion[max_anio].fecha[0].anio);
    // Calcular y mostrar las medias máxima y mínima de energía por año
    for (int i = 0; i < num_anios; i++) {
        double max_media = 0;
        double min_media = DBL_MAX; //La constante DBL_MAX representa el valor máximo finito representable de tipo double. Utilizada para establecer un valor inicial alto para min_media
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
        printf("Año: %d\n", informacion[i].fecha[0].anio);
        printf("Maxima media: %.2f (Energia: %s)\n", max_media, informacion[i].datos[max_fuente_media].energia);
        printf("Minima media: %.2f (Energia: %s)\n", min_media, informacion[i].datos[min_fuente_media].energia);
    }
}

void darlachapa() {
    setlocale(LC_ALL, "spanish");
    int i=0;
    char *archivos[] = {"muchachapa.txt", "muchisimachapa.txt", "chapafinal.txt"};
    char *nombres[] = {"Energía Eólica", "Ciclo combinado", "Conclusiones sobre ambas energías"};
    // Iterar sobre cada archivo y nombre correspondiente
    for ( i = 0; i < 3; i++) {
        printf("¿Desea ver el archivo %d: %s? (s/n): ", i+1, nombres[i]);
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
    // Solicitar al usuario el índice de la energía
    printf("Ingrese el índice de la energía (0-16): ");
    scanf("%d", &indice);
    // Verificar si el índice es válido
    if (indice < 0 || indice > 16) {
        printf("Índice inválido.\n");
        return;
    }
    char opcion;
    // Preguntar al usuario si desea calcular la media de esta energía
    printf("¿Desea calcular la media de esta energía? %s (s/n): ",informacion[indice].datos[indice].energia);
    scanf(" %c", &opcion);
    bool calcularMedia = false;
    // Preguntar al usuario si desea calcular el mínimo y máximo de esta energía
    if (opcion == 's' || opcion == 'S') {
        calcularMedia = true;
    }
    printf("¿Desea calcular el mínimo y máximo de esta energía? (s/n): ");
    // Preguntar al usuario si desea borrar los datos antiguos del archivo
    scanf(" %c", &opcion);
    bool calcularMinimoMaximo = false;
    if (opcion == 's' || opcion == 'S') {
        calcularMinimoMaximo = true;
    }
    if (calcularMedia || calcularMinimoMaximo) {
        printf("¿Desea borrar los datos antiguos del archivo? (s/n): ");
        scanf(" %c", &opcion);
        FILE *fp;
        // Abrir el archivo en modo de escritura o anexado según la respuesta del usuario
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
        // Calcular la media, mínimo y máximo de la energía para cada año
        for (int i = 0; i < num_anios; i++) {
            fprintf(fp,"Año: %d\n", informacion[i].fecha[0].anio);
            double min = informacion[i].datos[indice].cantidad[0];
            double max = informacion[i].datos[indice].cantidad[0];
            int min_mes = 0;
            int max_mes = 0;
            double sum = 0;
            // Calcular la suma, mínimo y máximo de la energía para cada mes
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
                fprintf(fp,"Mínimo: %.2f (Mes: %d)\n", min, min_mes + 1);
                fprintf(fp,"Máximo: %.2f (Mes: %d)\n", max, max_mes + 1);
            }
        }
        //Se cierra el archivo una vez terminado todos los procesos.
        fclose(fp);
    }
}
