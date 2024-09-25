#include "header.h"

void menu(lista **raiz){
        int opcion,numero,valorBuscado;
        while(opcion != 5)
        {
                fpurge(stdin);
                printf("1. Crear nueva lista\n");
                printf("2. Imprimir Lista\n");
                printf("3. Buscar valor anterior\n");
                printf("4. Borrar lista\n");
                printf("5. Salir\n");
                printf("Seleccione una opcion: ");
                scanf("%d",&opcion);
                switch(opcion){
                        case 1:
                                system("clear");
                                if(*raiz == NULL){
                                        printf("Ingrese una serie de numeros(termina cuando ingrese una letra):\n");
                                        while ((scanf("%d",&numero))==1)
                                                inserta(raiz,numero);
                                        printf("La lista se ha creado con exito\n\n");
                                }
                                else
					printf("Ya existe una lista, en caso de querer crear una nueva, borre la antigua primero\n\n");
                        break;

                        case 2:
                                system("clear");
                                if(*raiz!=NULL)
                                        imprime(*raiz);
                                else
                                        printf("La lista esta vacia\n\n");
                        break;

                        case 3:
                                system("clear");
                                if(*raiz!=NULL){
                                        fpurge(stdin);
                                        printf("Ingrese el valor para encontrar el anterior: ");
                                        scanf("%d",&valorBuscado);
                                        buscarAnterior(*raiz,valorBuscado);
                                }
                                else
                                        printf("La lista esta vacia\n\n");
                        break;

                        case 4:
                                system("clear");
                                borrar(raiz);
                                printf("Lista borrada con exito\n\n");
                        break;

                        case 5:
                                system("clear");
                                printf("Hasta luego :)\n\n");
                                borrar(raiz);
                        break;
                        default:
                                system("clear");
                                printf("Ingrese una opcion valida\n\n");
                        break;
                }
        }
}
void inserta(lista **raiz, int valor){
        lista *temp;
        temp = (lista*) malloc (sizeof(lista));
        temp -> num = valor;
        temp -> sig = *raiz;
        *raiz = temp;
}

void imprime(lista *raiz){
        lista *temp = raiz;
        while (temp != NULL){
                printf("%d\n",temp->num);
                temp = temp->sig;
        }
}

void borrar(lista **raiz){
        lista *temp;
        while (*raiz != NULL){
                temp = *raiz;
                *raiz = temp->sig;
                free(temp);
        }
}

void buscarAnterior(lista *raiz,int valorBuscado){
        if(raiz->num == valorBuscado){
                printf("No hay valor anterior porque es el primer elemento de la lista\n\n");
                return;
        }
        if (raiz->sig->num == valorBuscado){
                printf("EL numero anterior al buscado es: %d\n",raiz->num);
                return;
        }
        else{
                raiz = raiz-> sig;
                if (raiz->sig == NULL){
                        printf("No se encontró el valor ingresado\n\n");
                        return;
                }
                buscarAnterior(raiz,valorBuscado);
        }
}