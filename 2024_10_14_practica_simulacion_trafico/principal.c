/**
 * @file principal.c
 * @brief El programa puede leer datos de autos desde un archivo CSV y generar diferentes gráficas.
 * El programa lee un archivo CSV con información de autos, almacenando los datos en una estructura
 * "CarDato" definida en el archivo header. Posteriormente, genera diferentes gráficas de los datos,
 * como un histograma, un diagrama de dispersión, un mapa de calor y un gráfico de caja y bigotes.
 * @date 2024-09-28
 */

#include "header.h"

/**
 * @brief Función principal del programa.
 * @param argc Número de argumentos pasados por la línea de comandos.
 * @param argv Arreglo de cadenas de caracteres con los argumentos de la línea de comandos.
 * @return salida: 1 en caso de error, 0 en caso de éxito.
 */

int main(int argc, char* argv[]) {
    CarDato autos[MAX_AUTOS];
    int count = 0;

    if (argc !=2)
    {
        printf("Introdujo mal los argumentos\n");
        return 1;
    }

    FILE* archivo = fopen(argv[1],"r");
    if(archivo == NULL)
    {
        printf("No se puede abrir el arcvhivo %s\n", argv[1]);
        return 1;
    }

    char line[100];
    fgets(line, sizeof(line), archivo);

    // Leer los datos del archivo CSV
    while (fscanf(archivo, "%d,%f,%f", &autos[count].hour, &autos[count].arrival_time, &autos[count].waiting_time) == 3) {
        count++;
        if (count >= MAX_AUTOS) break;
    }

    fclose(archivo);
    printf("Datos leídos correctamente: %d autos.\n", count);

    histograma(count, autos);
    dispersion(count, autos);
    calor(count, autos);
    bigotes(count, autos);
    return 0;
}