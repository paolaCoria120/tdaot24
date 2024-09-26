/**                                                                                                                                                                                  
 * @file principal.c                                                                                                                                                                 
 * @brief Programa que realiza operaciones con números complejos(inclluyendo caracteres)                                                                                             
 * leídos desde la línea de comandos.                                                                                                                                                
 * Este programa lee dos números complejos desde la línea de comandos y                                                                                                              
 * calcula su suma y multiplicación.                                                                                                                                                 
 * @date 2024-09-25                                                                                                                                                                  
 */


#include "header.h"

/**                                                                                                                                                                                  
 * @param argc Número de argumentos ingresados por la línea de comandos.                                                                                                             
 * @param argv Cadenas de caracteres que contiene los argumentos.                                                                                                                    
 * @return Devuelve 0 si la ejecución es exitosa, o 1 si hay un error en la entrada.                                                                                                 
 */

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Los numeros fueron ingresados de manera incorrecta.\n\n");
        return 1;
    }

    //Leer números complejos desde la línea de comandos                                                                                                                              
    complejo num1 = castComplejo(argv[1], argv[2]);
    complejo num2 = castComplejo(argv[3], argv[4]);

    //Calcular operaciones                                                                                                                                                           
    complejo suma = sumar(num1, num2);
    complejo producto = multiplicar(num1, num2);

    //Imprimir resultados en pantalla                                                                                                                                                
    imprimirResultados(num1, num2, suma, producto);

    return 0;
}
