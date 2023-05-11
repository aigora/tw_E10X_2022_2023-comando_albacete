typedef struct {
    char name[20];
    double values[26];
    int num_values;
} Energias;

typedef struct
{
    int mes;
    int anio;
}fechas;

typedef struct{
    fecha date[12];
    Energias  energy[20];
}tocho;

//Funciones de la versión 1.
void convertir_caracteres_especiales(char *cadena);
Energias* leer_archivo(char* filename, int* num_lines);
fecha* leer_fechas(char* filename, int* num_lines);


//Funciones de la versión prueba.
void compilar_fechas(char fila[], Datos informacion[]);
void compilar_datos2(char fila[], Datos informacion[], int num_anios, int num_fuentes, int meses[]);
void leer_titulo(char fila[], Datos informacion[], int num_anio, int num_fuente);

