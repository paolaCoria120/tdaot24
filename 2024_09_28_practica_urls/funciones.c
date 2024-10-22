/**
 * @file funciones.c
 * @brief Implementación de una tabla hash para el almacenamiento y gestión de URLs.
 * Este archivo proporciona funciones para manejar una tabla hash que almacena
 * pares de URLs cortas y largas. Incluye funciones para insertar, buscar, eliminar
 * y liberar memoria de las URLs almacenadas.
 */

#include "header.h"

/**
 * @brief Función hash para generar un índice único en la tabla.
 * Esta función toma una clave (una cadena) y calcula un índice basado en
 * el valor hash de la clave, ajustándolo al tamaño de la tabla hash.
 * @param key La cadena de entrada que se utilizará para generar el índice.
 * @param tamano_tabla El tamaño de la tabla hash.
 * @return El índice calculado que corresponde a la clave proporcionada.
 */

unsigned int funcion_hash(const char* key, int tamano_tabla) { 
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_len = strlen(key);

    for (; i < key_len; ++i) {
        value = value * 13579 + key[i];
    }

    return value % tamano_tabla;
}
/**
 * @brief Genera una URL corta basada en el índice hash.
 * Esta función toma un valor hash y lo convierte en una cadena de 4 caracteres
 * hexadecimales que representa la URL corta.
 * @param hash El valor hash que se convertirá en una URL corta.
 * @code  snprintf(url_corta, 5, "%04x", hash);
 * La función snprintf, que se utiliza para formatear cadenas de caracteres en C. 
 * @see "https://stackoverflow.com/questions/7793408/snprintf-for-integer-to-string-conversion-in-c"
 * @return Un puntero a la cadena que representa la URL corta generada.
 */
char* generar_url_corta(unsigned int hash) {
    char* url_corta = (char*)malloc(5);
    snprintf(url_corta, 5, "%04x", hash); // Convierte el hash en una cadena de 6 caracteres hexadecimales
    return url_corta;
}

// Crear una tabla hash con un tamaño inicial
TablaHash* crear_tabla_hash(int tamano_inicial) {
    TablaHash* tabla = (TablaHash*) malloc(sizeof(TablaHash));
    tabla->tamano = tamano_inicial;
    tabla->num_elementos = 0;
    tabla->items = (URLNode**) calloc(tamano_inicial, sizeof(URLNode*));
    return tabla;
}

// Función para redimensionar la tabla cuando el factor de carga supere 0.7
void redimensionar_tabla(TablaHash* tabla) {
    int nuevo_tamano = tabla->tamano * 2;
    URLNode** nueva_tabla = (URLNode**) calloc(nuevo_tamano, sizeof(URLNode*));

    for (int i = 0; i < tabla->tamano; i++) {
        URLNode* nodo_actual = tabla->items[i];
        while (nodo_actual) {
            unsigned int nuevo_indice = funcion_hash(nodo_actual->url_larga, nuevo_tamano);
            URLNode* siguiente_nodo = nodo_actual->siguiente;
            nodo_actual->siguiente = nueva_tabla[nuevo_indice];
            nueva_tabla[nuevo_indice] = nodo_actual;
            nodo_actual = siguiente_nodo;
        }
    }

    free(tabla->items);
    tabla->items = nueva_tabla;
    tabla->tamano = nuevo_tamano;
}

// Insertar una nueva URL larga en la tabla hash
void insertar(TablaHash* tabla, const char* url_larga) {
    unsigned int indice = funcion_hash(url_larga, tabla->tamano);
    URLNode* nuevo_nodo = (URLNode*)malloc(sizeof(URLNode));
    nuevo_nodo->url_larga = strdup(url_larga);
    nuevo_nodo->url_corta = generar_url_corta(indice);
    nuevo_nodo->siguiente = tabla->items[indice];
    tabla->items[indice] = nuevo_nodo;
    tabla->num_elementos++;
    
    // Redimensionar la tabla si el factor de carga es mayor a 0.7
    if ((float)tabla->num_elementos / tabla->tamano > 0.7) {
        redimensionar_tabla(tabla);
    }
    printf("URL insertada con éxito.\n");
}

// Buscar la URL larga asociada a una URL corta dada
char* buscar(TablaHash* tabla, const char* url_corta) {
    for (int i = 0; i < tabla->tamano; i++) {
        URLNode* nodo_actual = tabla->items[i];
        while (nodo_actual) {
            if (strcmp(nodo_actual->url_corta, url_corta) == 0) {
                return nodo_actual->url_larga;
            }
            nodo_actual = nodo_actual->siguiente;
        }
    }
    return NULL; // No encontrada
}

// Eliminar una URL corta y su URL larga asociada de la tabla hash
int eliminar(TablaHash* tabla, const char* url_corta) {
    unsigned int indice = funcion_hash(url_corta, tabla->tamano);
    URLNode* nodo_actual = tabla->items[indice];
    URLNode* nodo_anterior = NULL;
    
    while (nodo_actual) {
        if (strcmp(nodo_actual->url_corta, url_corta) == 0) {
            if (nodo_anterior) {
                nodo_anterior->siguiente = nodo_actual->siguiente;
            } else {
                tabla->items[indice] = nodo_actual->siguiente;
            }
            free(nodo_actual->url_corta);
            free(nodo_actual->url_larga);
            free(nodo_actual);
            tabla->num_elementos--;
            return 1; //Encontrada
        }
        nodo_anterior = nodo_actual;
        nodo_actual = nodo_actual->siguiente;
    }
    return 0; //No encontrada
}

// Liberar la memoria de la tabla hash
void liberar_tabla(TablaHash* tabla) {
    for (int i = 0; i < tabla->tamano; i++) {
        URLNode* nodo_actual = tabla->items[i];
        while (nodo_actual) {
            URLNode* temp = nodo_actual;
            nodo_actual = nodo_actual->siguiente;
            free(temp->url_corta);
            free(temp->url_larga);
            free(temp);
        }
    }
    free(tabla->items);
    free(tabla);
}

// Función para imprimir la tabla hash (para pruebas)
void imprimir_tabla(TablaHash* tabla) {
    printf("+----------------------+-------------------------------------------+\n");
    printf("| URL Corta             | URL Larga                                |\n");
    printf("+----------------------+-------------------------------------------+\n");

    for (int i = 0; i < tabla->tamano; i++) {
        URLNode* nodo_actual = tabla->items[i];
        while (nodo_actual) {
            printf("| %-20s | %-35s \n", nodo_actual->url_corta, nodo_actual->url_larga);
            nodo_actual = nodo_actual->siguiente;
        }
    }

    printf("+----------------------+-------------------------------------------+\n");
}