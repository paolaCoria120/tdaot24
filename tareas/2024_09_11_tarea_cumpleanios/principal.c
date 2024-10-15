/**
 * @file principal.c
 * @brief Función para gestionar una lista de cumpleaños.
 * Este programa gestiona una lista de cumpleaños, permitiendo al usuario crear una lista, 
 * insertar nodos, buscar y eliminar cumpleaños.
 */

#include "header.h"
/**
 * @brief Función principal del programa.
 * Esta función inicializa el programa, limpia la pantalla y llama a la función de menú 
 * para que el usuario interactúe con la lista de cumpleaños.
 * @return 0 si se ejecuta correctamente.
 */

int main(void){
        
        system("clear");
        lista *raiz= NULL;//variable de tipo lista
        menu(&raiz);
}
