#include <stdio.h>
#include <stdlib.h>

#define MAX_AUTOS 1000

typedef struct {
    int hour;
    float arrival_time;
    float waiting_time;
} CarDato;

void histograma(int count, CarDato* autos);
void dispersion(int count, CarDato* autos);
void calor(int count, CarDato* autos);
void bigotes(int count, CarDato* autos);