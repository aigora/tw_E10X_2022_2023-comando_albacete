//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <locale.h>
//
//
//int main()
//{
//    FILE *archivo;
//    char linea[500], *token;
//    char fechas[25][20], energias[25][20];
//    int numfecha = 0, numenergia = 0, i;
//    setlocale(LC_ALL,"spanish");
//
//    archivo = fopen("generacion.txt", "r");
//
//    if (archivo != NULL) {
//        // Leer la quinta línea (fecha)
//        for (i = 0; i < 4; i++) {
//            fgets(linea, 500, archivo);
//        }
//        fgets(linea, 500, archivo);
//        token = strtok(linea, ",");
//        while (token != NULL && numfecha < 25) {
//            strcpy(fechas[numfecha], token);
//            numfecha++;
//            token = strtok(NULL, ",");
//        }
//
//        fgets(linea, 500, archivo);
//        token = strtok(linea, ",");
//        while (token != NULL && numenergia < 25)
//            {
//            strcpy(energias[numenergia], token);
//            numenergia++;
//            token = strtok(NULL, ",");
//            }
//        }
//
//        // Imprimir las fechas y energías
//// Imprimir las fechas y energías
//for (i = 0; i < numfecha; i++) {
//    printf("%s\t%s\n", fechas[i], (energias[i]));
//}
//        fclose(archivo);
//
//    return 0;
//}
//
//

