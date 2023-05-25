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

void compilar_fechas(char fila[], Datos informacion[]);
void compilar_datos2(char fila[], Datos informacion[], int num_anios, int num_fuentes, int meses[]);
void leer_titulo(char fila[], Datos informacion[], int num_anio, int num_fuente);
void print_energy_type(Datos informacion[], int num_anios);
void imprimirTodo(Datos *valor_energia, int num_anio, int *num_mes_por_anio);
void mostrarMenu(Datos *valor_energia, int num_anio, int *num_mes_por_anio, Datos informacion[], int num_anios);
void imprimirIndices(Datos informacion);
void calcularMedia(Datos *informacion, int num_anios);
void calcularMinimoMaximo(Datos *informacion, int num_anios);
