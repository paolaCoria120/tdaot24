#include <stdio.h>

/*
@brief Determina si una frase es pangrama o no
@param frase es un arreglo que contiene una sola frase, con salto de linea 
@return regresa 1 o 0 si la frase es pangrama o no
*/
int es_un_pangrama(char* frase)
{
    int abecedario[26] = {0}; //arreglo para registrar las letras encontradas
    int i = 0;

    while (frase[i]!= '\0')//determina cuando la frase termina
    {
        if(frase[i] >= 'a' && frase[i]<= 'z') //si la letra se encuentra entre la a y z en ASCII
            abecedario[frase[i] - 'a'] = 1;
            else
        if(frase[i] >= 'A' && frase[i]<= 'Z') //si la letra se encuentra entre la A y Z en ASCII
            abecedario[frase[i] - 'A'] = 1;
            else
            {
                int c = (int)frase[i];//si la letra es acentuada y minúscula, por sus valores en ASCII extendido
                switch (c)
                {
                    case -95:case -197: //á, Á
                        abecedario[0] = 1;
                        break;
                    case -87:case -119: //é, É
                        abecedario[4] = 1;
                        break;
                    case -83:case -115: //í, Í
                        abecedario[8] = 1;
                        break;
                    case -77:case -109: //ó, Ó
                        abecedario[14] = 1;
                        break;
                    case -70:case -102:case -68:case -100://ú, Ú, ü, Ü
                        abecedario[20] = 1;
                        break;
                }
            }
        i++;
    }

    for (i = 0; i < 26; i++)
    {
        if(abecedario[i] == 0) //si encuentra un espacio, no es un pangrama
            return 0;
    }
    return 1; //si no encuentra espacios, es un pangrama
}

/*
@brief Determina si un conjunto de frases es pangrama o no
@param frases es un arreglo que contiene todas las frases 
@return regresa el arreglo de resultados de la evaluacion de cada frase
*/
void son_pangramas(int n, char frases[][1000], int resultados[])
{
    for (int i = 0; i < n; i++)
        resultados[i]= es_un_pangrama(frases[i]); //recorre todos las frases
}
