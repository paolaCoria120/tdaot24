/**
 * @file funciones.c
 * @brief Implementación de una tabla hash para el almacenamiento y gestión de URLs.
 * Este archivo proporciona funciones para manejar una tabla hash que almacena
 * pares de URLs cortas y largas. Incluye funciones para insertar, buscar, eliminar
 * y liberar memoria de las URLs almacenadas.
 */

#include "header.h"

/**
 * @brief Genera un histograma basado en el número de autos por hora.
 * La función cuenta el número de autos que llegan en cada hora y escribe los datos
 * en un archivo llamado "datos_histograma.txt" en un formato adecuado para ser utilizado
 * con gnuplot para las graficas.
 * @param count Número de autos cuyos datos se van a procesar.
 * @param autos Arreglo de estructuras "CarDato" que contiene los datos de los autos,
 */


void histograma(int count, CarDato* autos)
{
    // Contar el número de autos por cada hora
    int autos_por_hora[24] = {0};
    for (int i = 0; i < count; i++) {
        autos_por_hora[autos[i].hour]++;
    }

    // Guardar los datos en un archivo para gnuplot
    FILE *histograma_archivo = fopen("datos_histograma.txt", "w");
    for (int i = 0; i < 24; i++) {
        fprintf(histograma_archivo, "%d %d\n", i, autos_por_hora[i]);
    }
    fclose(histograma_archivo);
}

/**
 * @brief Genera un diagrama de dispersión con los datos de los autos.
 * Los resultados se escriben en un archivo llamado "datos_dispersion.txt"
 * @param count Número de autos cuyos datos se van a procesar.
 * @param autos Arreglo de estructuras `CarDato` que contiene los datos de los autos.
 */


void dispersion(int count, CarDato* autos)
{
    // Calcular el número de autos y el tiempo de espera promedio por hora
    int autos_por_hora[24] = {0};
    int suma_espera[24] = {0};
    int cuenta_espera[24] = {0};

    for (int i = 0; i < count; i++) {
        int hora = autos[i].hour;
        autos_por_hora[hora]++;
        suma_espera[hora] += autos[i].waiting_time;
        cuenta_espera[hora]++;
    }

   
    FILE *dispersion_archivo = fopen("datos_dispersion.txt", "w");
    for (int i = 0; i < 24; i++) {
        if (cuenta_espera[i] > 0) {
            float promedio_espera = (float)suma_espera[i] / cuenta_espera[i];
            fprintf(dispersion_archivo, "%d %d %.2f\n", i, autos_por_hora[i], promedio_espera);
        }
    }
    fclose(dispersion_archivo);
}

/**
 * @brief Genera un mapa de calor con los datos de los autos.
 * @param count Número de autos cuyos datos se van a procesar.
 * @param autos Arreglo de estructuras `CarDato` que contiene los datos de los autos.
 */

void calor (int count, CarDato* autos)
{
  
    int autos_por_hora[24][60] = {0};

    for (int i = 0; i < count; i++) {
        int hora = autos[i].hour;
        int minuto = autos[i].arrival_time;
        autos_por_hora[hora][minuto]++;
    }

  
    FILE *calor_archivo = fopen("datos_calor.txt", "w");
    for (int hora = 0; hora < 24; hora++) {
        for (int minuto = 0; minuto < 60; minuto++) {
            fprintf(calor_archivo, "%d %d %d\n", hora, minuto, autos_por_hora[hora][minuto]);
        }
        fprintf(calor_archivo, "\n"); 
    }
    fclose(calor_archivo);
}

/**
 * @brief Genera un gráfico de caja y bigotes basado en los datos de los autos.
 * @param count Número de autos cuyos datos se van a procesar.
 * @param autos Arreglo de estructuras "CarDato" que contiene los datos de los autos.
 */


void bigotes (int count, CarDato* autos){

FILE *bigotes_archivo = fopen("datos_bigotes.txt", "w");
    for (int hora = 0; hora < 24; hora++) {
        fprintf(bigotes_archivo, "# Hora %d\n", hora);
        for (int i = 0; i < count; i++) {
            if (autos[i].hour == hora) {
                fprintf(bigotes_archivo, "%f\n", autos[i].waiting_time);
            }
        }
        fprintf(bigotes_archivo, "\n"); 
    }
    fclose(bigotes_archivo);

}


