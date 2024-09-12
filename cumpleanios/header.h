#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NOMBRE 50

typedef struct lifo{
        int dia;
        int mes;
        int anio;
        char nombre[MAX_NOMBRE];
        struct lifo *sig;
        struct lifo *ant;
}lista;

void insertaInicio(lista **raiz, int dia, int mes, int anio, const char *nombre);
void insertaFin(lista **raiz, int dia, int mes, int anio, const char *nombre);
void insertaDesdeArchivo(lista **raiz, const char *nombreArchivo);
void imprime(lista *raiz);
void borrar(lista **raiz);
void eliminaCumple(lista **raiz, int anio, int mes, int dia, const char *nombre);
void buscarMes(lista *raiz,int mesBuscado);
void menu(lista **raiz);
void eliminaPorPosicion(lista **raiz, int posicion);
int longitudLista(lista *raiz);
void eliminaRandom(lista **raiz);