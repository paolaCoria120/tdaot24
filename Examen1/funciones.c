/**                                                                                                                                                                                  
 * @file funciones.c                                                                                                                                                                 
 * @brief Funciones para operaciones con números complejos.                                                                                                                          
 * Este archivo contiene funciones para convertir cadenas de caracteres en valores numericos                                                                                         
 */


#include "header.h"

/**                                                                                                                                                                                  
 * @brief Convierte dos cadenas de texto en un número complejo.                                                                                                                               
 * @param real Cadena de caracteres que representa la parte real del número complejo.                                                                                                
 * @param imaginario Cadena de caracteres que representa la parte imaginaria del número complejo.                                                                                    
 * @code  capturado.real = atof(real)                                                                                                                                                
 * Esta función convierte las cadenas de caracteres que representan la parte real e imaginaria                                                                                       
 * en un float  utilizando atof.                                                                                                                                                     
 * la función atoi es  para convertir una cadena en un int y atof en un float.                                                                                                       
 * @see "https://es.stackoverflow.com/questions/581608/cómo-convertir-char-de-varios-caracteres-a-int-y-float-en-c"                                                                  
 * @return Un número complejo con la parte real e imaginaria.                                                                                                                        
 */
complejo castComplejo(char* real, char* imaginario)
{

 complejo capturado;
 capturado.real = atof(real);//atof = ASCCI to Float                                                                                                                                 
 imaginario[strlen(imaginario) - 1] = '\0';
 capturado.imaginario = atof(imaginario);



 return capturado;
}

/**                                                                                                                                                                                  
 * @brief Suma dos números complejos.                                                                                                                                                
 * @param num1 el primer número complejo.                                                                                                                                            
 * @param num2 el segundo número complejo.                                                                                                                                           
 * @return Un número complejo que representa la suma de num1 y num2.                                                                                                                 
 */

complejo sumar(complejo num1, complejo num2)
{
    complejo resultado;
    resultado.real = num1.real + num2.real;
    resultado.imaginario = num1.imaginario + num2.imaginario;
    return resultado;
}



/**                                                                                                                                                                                  
 * @brief Multiplica dos números complejos.                                                                                                                                          
 * Formula:                                                                                                                                                                          
 * (a1 + b1i) * (a2 + b2i) = (a1a2 - b1b2) + (a1b2 + b1a2)i                                                                                                                                      
 * @param num1 el primer número complejo.                                                                                                                                            
 * @param num2 el segundo número complejo.                                                                                                                                           
 * @return Un número complejo que representa el producto de num1 y num2.                                                                                                             
 */

complejo multiplicar(complejo num1, complejo num2)
{
    complejo resultado;
    resultado.real = (num1.real * num2.real) - (num1.imaginario * num2.imaginario);
    resultado.imaginario = (num1.real * num2.imaginario) + (num1.imaginario * num2.real);
    return resultado;
}

 /**                                                                                                                                                                                 
 * Esta función imprime un número complejo en la consola                                                                                                                             
 *  + a + bi  (si la parte real y la imaginaria son positivas)                                                                                                                       
 *  - a - bi  (si alguna parte es negativa)                                                                                                                                          
 *                                                                                                                                                                                   
 * @param numero el número a imprimir.                                                                                                                                               
 */

void imprimirComplejo(complejo numero)
{
    if (numero.real < 0) //Si la parte real es negativa                                                                                                                              
        printf("- %.1lf ", numero.real*-1);
    else
        printf("+ %.1lf ", numero.real);

    if (numero.imaginario < 0) //Si la parte imaginaria es negativa                                                                                                                  
        printf("- %.1lfi\n", numero.imaginario*-1);
    else
        printf("+ %.1lfi\n", numero.imaginario);
}

/**                                                                                                                                                                                  
 * @brief Imprime los números complejos ingresados y los resultados de las operaciones.                                                                                              
 * @param num1, num2 numeros complejos.                                                                                                                                              
 * @param suma es el  resultante de la suma de num1 y  num2                                                                                                                          
 * @param producto es el  resultante de la multiplicación de  num1  y  num2                                                                                                          
 */

void imprimirResultados(complejo num1, complejo num2, complejo suma, complejo producto)
{
    printf ("\nNumero complejo 1: ");
    imprimirComplejo(num1);
    printf ("Numero complejo 2: ");
    imprimirComplejo(num2);

    printf("\nLa suma es: ");
    imprimirComplejo(suma);
    printf("La multiplicación es: ");
    imprimirComplejo(producto);

    printf("\n");
}
