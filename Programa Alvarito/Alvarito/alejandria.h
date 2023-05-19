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

////Funciones de la versión 1.
//void convertir_caracteres_especiales(char *cadena);
//Energias* leer_archivo(char* filename, int* num_lines);
//fecha* leer_fechas(char* filename, int* num_lines);


//Funciones de la versión prueba.
void compilar_fechas(char fila[], Datos informacion[]);
void compilar_datos2(char fila[], Datos informacion[], int num_anios, int num_fuentes, int meses[]);
void leer_titulo(char fila[], Datos informacion[], int num_anio, int num_fuente);
void print_energy_type(Datos informacion[], int num_anios);
