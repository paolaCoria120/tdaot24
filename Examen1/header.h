/**                                                                                                                            
 * @file header.h                                                                                                              
 * @brief Definición de la estructura y funciones para trabajar con números complejos.                                         
 * Este archivo contiene la definición de la estructura y las funciones                                                        
 * para operar con ellos, como sumar, multiplicar y convertir                                                                  
 * cadenas de caracteres a números complejos.                                                                                  
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
        double real;
        double imaginario;
}complejo;


complejo castComplejo(char* real, char* imag);

complejo sumar(complejo c1, complejo c2);
complejo multiplicar(complejo c1, complejo c2);


void imprimirComplejo(complejo c);
void imprimirResultados(complejo num1, complejo num2, complejo suma, complejo producto);


