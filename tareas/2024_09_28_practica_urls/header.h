/**
 * @file header.h
 * @brief Implementación de una tabla hash para gestionar pares de URLs (corta, larga).
 * Este archivo define las estructuras y funciones necesarias para crear, gestionar
 * y liberar una tabla hash que almacena pares de URLs.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_TABLE_SIZE 10
#define MAX_URL_LENGTH 2048

// Estructura para almacenar pares (URL corta, URL larga)
typedef struct URLNode {
    char* url_larga;
    char* url_corta;
    struct URLNode* siguiente;
} URLNode;

// Estructura para la tabla hash
typedef struct HashTable{
    URLNode** items;
    int tamano;
    int num_elementos;
} TablaHash;

unsigned int funcion_hash(const char* key, int tamano_tabla);
char* generar_url_corta(unsigned int hash); //Uso de chatgpt
TablaHash* crear_tabla_hash(int tamano_inicial);
void redimensionar_tabla(TablaHash* tabla);
void liberar_tabla(TablaHash* tabla);
void imprimir_tabla(TablaHash* tabla);

//Funciones a Implementar
void insertar(TablaHash* tabla, const char* url_larga);
char* buscar(TablaHash* tabla, const char* url_corta);
int eliminar(TablaHash* tabla, const char* url_corta);