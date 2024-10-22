/**
 * @file principal.c
 * @brief Este programa es para gestionar una tabla hash en un sistema de acortamiento de URLs.
 * Permite al usuario insertar, buscar, eliminar y mostrar URLs
 * almacenadas en una tabla hash. Utiliza una tabla hash dinámica con manejo
 * de colisiones mediante listas enlazadas.
 * @date 2024-09-28
 */

#include "header.h"
/**
 * @brief Función principal del programa.
 * Proporciona un menú interactivo para realizar las siguientes acciones:
 * 1. Insertar una URL larga en la tabla hash y generar una URL corta asociada.
 * 2. Buscar una URL larga usando una URL corta.
 * 3. Eliminar una URL de la tabla hash usando la URL corta.
 * 4. Mostrar el contenido de la tabla hash.
 * 5. Salir del programa.
 * @return int Devuelve 0 si el programa finaliza correctamente.
 */

int main() {
    TablaHash* tabla = crear_tabla_hash(INITIAL_TABLE_SIZE);
    int opcion;
    char url_larga[2048];
    char url_corta[100];
    
    do {
        printf("\n--- Menú de Opciones ---\n");
        printf("1. Insertar URL\n");
        printf("2. Buscar URL\n");
        printf("3. Eliminar URL\n");
        printf("4. Mostrar tabla\n");
        printf("5. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar el salto de línea del buffer de entrada

        switch (opcion) {
            case 1:
                printf("Introduce la URL larga: ");
                fgets(url_larga, 2048, stdin);
                url_larga[strcspn(url_larga, "\n")] = 0; // Eliminar el salto de línea

                insertar(tabla, url_larga);
                break;
            case 2:
                printf("Introduce la URL corta a buscar: ");
                fgets(url_corta, 100, stdin);
                url_corta[strcspn(url_corta, "\n")] = 0; // Eliminar el salto de línea

                char* url_encontrada = buscar(tabla, url_corta);
                if (url_encontrada) {
                    printf("La URL larga asociada es: %s\n", url_encontrada);
                } else {
                    printf("URL no encontrada.\n");
                }
                break;
            case 3:
                printf("Introduce la URL corta a eliminar: ");
                fgets(url_corta, 100, stdin);
                url_corta[strcspn(url_corta, "\n")] = 0; // Eliminar el salto de línea

                if (eliminar(tabla, url_corta)) {
                    printf("URL eliminada con éxito.\n");
                } else {
                    printf("No se encontró la URL para eliminar.\n");
                }
                break;
            case 4:
                imprimir_tabla(tabla);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida. Inténtalo de nuevo.\n");
        }
    } while (opcion != 5);

    liberar_tabla(tabla);
    return 0;
}