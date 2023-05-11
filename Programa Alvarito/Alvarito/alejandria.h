typedef struct {
    char name[20];
    double values[26];
    int num_values;
} Energias;

typedef struct{
    int anio;
    int mes;
}fecha;

void convertir_caracteres_especiales(char *cadena);
Energias* leer_archivo(char* filename, int* num_lines);
