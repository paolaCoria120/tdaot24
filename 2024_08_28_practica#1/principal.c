#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(int argc, char* argv[])
{
    if (argc !=2)
    {
        printf("Introdujo mal los argumentos\n"); //determina si los argumentos fueron correctos
        return 1;
    }

    FILE* archivo = fopen(argv[1],"r");
    if(archivo == NULL)
    {
        printf("No se puede abrir el arcvhivo %s\n", argv[1]); //determina si pudo leer el archivo
        return 1;
    }

    char caracter;
    int n = 1;//por las especificaciones de la práctica, tiene al menos una frase

    while ((caracter = fgetc(archivo)) != EOF)
        if (caracter == '\n') // Contar las líneas cuando se encuentre un salto de línea
            n++;
    rewind(archivo);

    char frases[n][1000];
    int resultados[n];

    int c = 0, f = 0; //index de caracter y frase
    while ((caracter = fgetc(archivo)) != EOF) {
        if (caracter == '\n') //identificar cambio de frase
        {  
            frases[f][c] = '\0';//insertar final de cadena al final de cada frase
            f++; //aumentar index de frase
            c = 0; //reiniciar index de caracter
        } else {
            frases[f][c] = caracter; //guardar caracter
            c++;
            if (c >= 999)//prevenir el desbordamiento de memoria
            {
                printf("Advertencia: Se alcanzó la longitud máxima de la frase (1000 caracteres).\n");
                frases[f][c] = '\0';
                f++;
                c = 0;
            }
        }
    }
    frases[f][c]='\0';//fin de frase a la ultima frase
    fclose(archivo);  // Cerrar el archivo

    son_pangramas(n + 1, frases, resultados); //evaluar frases

    for (int i = 0; i < n; i++) //imprimir resultados
        printf ("%d. %d\n", i+1, resultados[i]);
    
    return 0;
}
