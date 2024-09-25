#include <stdio.h>
#include <stdlib.h>

typedef struct lifo{
        int num;
        struct lifo *sig;
}lista;

void inserta(lista **raiz, int valor);
void imprime(lista *raiz);
void borrar(lista **raiz);
void buscarAnterior(lista *raiz,int valorBuscado);
void menu(lista **raiz);
