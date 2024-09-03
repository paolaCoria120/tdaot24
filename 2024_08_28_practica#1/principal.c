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
        printf("No se puede abrir el arcvhivo %s\n", argv[1]); //determina si pudo leer y abrir el archivo
        return 1;
    }

    char caracter;
    int n = 1; //por las especificaciones de la práctica, tiene al menos una frase

    while ((caracter = fgetc(archivo)) != EOF && n <= 99) //evita contar mas de 100 frases
    {
        if (caracter == '\n') // sumar una linea cuando se encuentre un salto de línea
            n++;
    }
    rewind(archivo); // rebobinar puntero de archivo

    char frases[n][1000];
    int resultados[n];
    char trash;

    int c = 0, f = 0; //index de caracter y frase
    while ((caracter = fgetc(archivo)) != EOF && f < n) //evita leer mas lineas que el numero de frases
    {
        if (caracter == '\n') //identificar cambio de frase
        {
            frases[f][c] = '\0';//insertar final de cadena
            f++; //aumentar index de frase
            c = 0; //reiniciar index de caracter
        } else if (c >= 999) trash = caracter;
        else
        {
            frases[f][c] = caracter; //guardar caracter
            c++; //aumentar index de caracter
        }
    }
    frases[f][c]='\0';//fin de frase a la ultima frase
    fclose(archivo);  // Cerrar el archivo

    son_pangramas(n + 1, frases, resultados); //evaluar frases

    
    for (int i = 0; i < n; i++) //imprimir resultados
    {
        printf ("%d. ", i+1);
        if (i == 0)
            for (int j = 4; j < 14; j++)
                printf ("%c", frases[i][j]);
        else
            for (int j = 0; j < 10; j++)
                printf ("%c", frases[i][j]);
        printf (": %d\n", resultados[i]);
    }

    return 0;
}
