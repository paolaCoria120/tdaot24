/**
 * @file funciones.c
 * @brief Definiciones y funciones relacionadas con la gestión de una lista de cumpleaños.
 */

#include "header.h"
/**
 * @brief Muestra el menú de opciones para gestionar la lista de cumpleaños.
 * Esta función presenta al usuario varias opciones para interactuar con una lista de cumpleaños,
 * incluyendo la creación de una nueva lista, la impresión de la lista, la inserción de nodos, 
 * y la eliminación de cumpleaños.
 * @param raiz Doble puntero a la lista que representa la raíz de la lista de cumpleaños.
 */
void menu(lista **raiz){//referencia al apuntador del inicio de la lista
    int opcion,mesBuscado, eliminaDia;
    int dia, mes, anio;
    char nombre[MAX_NOMBRE];
    char archivo[40];
    while(opcion != 12)
    {
        fpurge(stdin);//pone el contenido en nulo
        printf("1. Crear nueva lista\n");
        printf("2. Imprimir Lista\n");
        printf("3. Insertar nodo al inicio\n");
        printf("4. Insertar nodo al fin\n");
        printf("5. Insertar nodo en orden\n");//faltante
        printf("6. Ordenar\n");//faltante
        printf("7. Buscar por mes\n");
        printf("8. Borrar un cumpleanios\n");
        printf("9. Borrar una posicion\n");
        printf("10. Borrar un cumpleanios al azar\n");
        printf("11. Borrar lista\n");
        printf("12. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                system("clear");
                if(*raiz == NULL){
                    printf("Ingrese nombre del archivo a guardar:\n");
                    scanf("%s",archivo);
                    insertaDesdeArchivo(raiz, archivo);
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
				printf("Ingrese el cumpleaños a colocar en el inicio: ");
				scanf("%d-%d-%d-%s",&anio,&mes,&dia,nombre);
				insertaInicio(raiz,dia,mes,anio,nombre);
            break;
        
            case 4:
                printf("Ingrese el cumpleaños a colocar en el final: ");
				scanf("%d-%d-%d-%s",&anio,&mes,&dia,nombre);
				insertaFin(raiz,dia,mes,anio,nombre);

            break;

            case 7:
                system("clear");
                if(*raiz!=NULL){
                    fpurge(stdin);
                    printf("Ingrese el mes a buscar: ");
                    scanf("%d",&mesBuscado);
                    buscarMes(*raiz,mesBuscado);
                }
                else
                    printf("La lista esta vacia\n\n");
            break;

            case 8:
                system("clear");
                printf("Ingresa los datos del cumpleanios que quieres borrar:\n");
                scanf("%d-%d-%d-%s", &anio, &mes, &dia, nombre);
                eliminaCumple(raiz, dia, mes, anio, nombre);
                printf("Cumpleanios borrado con exito\n\n");
            break;

            case 9:
                system("clear");
                printf("Ingresa la posición que deseas eliminar: ");
                scanf("%d", &eliminaDia);
                eliminaPorPosicion(raiz, eliminaDia);
            break;

            case 10:
                eliminaRandom(raiz);
                system("clear");
                printf("Posicion aleatoria eliminada\n\n");
            break;

            case 11:
                borrar(raiz);
                printf("Toda la lista fue eliminada\n\n");
            break;

            case 12:
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

void insertaDesdeArchivo(lista **raiz, const char *nombreArchivo) {
    FILE *archivo;
    int anio, mes, dia;
    char nombre[MAX_NOMBRE];
    char linea[MAX_NOMBRE+11];  // Cadena para almacenar cada línea del archivo

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        // Usamos sscanf para extraer el formato YYYY-MM-DD-Nombre
        sscanf(linea, "%d-%d-%d-%s", &anio, &mes, &dia, nombre);
        // Insertamos en la lista
        insertaInicio(raiz, anio, mes, dia, nombre);//obtine los datos del archivo
    }

    fclose(archivo);
}

void imprime(lista *raiz){
    lista *temp = raiz;
    while (temp != NULL) {
        printf("%04d-%02d-%02d %s\n", temp->anio, temp->mes, temp->dia, temp->nombre);
        temp = temp->sig;
    }
}

void insertaInicio(lista **raiz, int dia, int mes, int anio, const char *nombre){
        lista *temp,*temp2;
        temp = (lista*) malloc (sizeof(lista));
	temp2 = *raiz;
        temp -> dia = dia;
        temp -> mes = mes;
        temp -> anio = anio;
        strncpy(temp->nombre, nombre, MAX_NOMBRE);
        temp -> ant = NULL;

	if(*raiz == NULL){
		temp -> sig = NULL;
		temp -> ant = NULL;
		*raiz = temp;
	}
	else{
		temp2 -> ant = temp;
		temp -> sig = temp2;
		*raiz = temp;
	}
}

void insertaFin(lista **raiz, int dia, int mes, int anio, const char *nombre){
	lista *temp, *temp2;
	temp2 = *raiz;
	temp = (lista*) malloc (sizeof(lista));
	temp -> dia = dia;
        temp -> mes = mes;
        temp -> anio = anio;
        strncpy(temp->nombre, nombre, MAX_NOMBRE);
        temp -> sig = NULL;

	if(*raiz == NULL){
		temp -> sig = NULL;
		temp -> ant = NULL;
		*raiz = temp;
	}
	else{
		while(temp2 -> sig != NULL)
			temp2 = temp2 -> sig;
		temp -> ant = temp2;
		temp2 -> sig = temp;
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

void eliminaCumple(lista **raiz, int anio, int mes, int dia, const char *nombre) {
    lista *temp = *raiz;
    
    while (temp != NULL) {
        if (temp->anio == anio && temp->mes == mes && temp->dia == dia && strcmp(temp->nombre, nombre) == 0) {
            // Si el nodo no es el primer nodo
            if (temp->ant != NULL) {
                temp->ant->sig = temp->sig;
            } else {
                // Si es el primer nodo, la raíz debe apuntar al siguiente
                *raiz = temp->sig;
            }

            // Si el nodo no es el último nodo
            if (temp->sig != NULL) {
                temp->sig->ant = temp->ant;
            }

            // Liberamos la memoria del nodo
            free(temp);
            printf("Cumpleaños eliminado: %04d-%02d-%02d %s\n", anio, mes, dia, nombre);
            return;
        }
        temp = temp->sig;
    }
    // Si no se encuentra el nodo
    printf("Cumpleaños no encontrado: %04d-%02d-%02d %s\n", anio, mes, dia, nombre);
}

void buscarMes(lista *raiz, int mesBuscado){
    if(raiz->mes == mesBuscado)
        printf("%04d-%02d-%02d %s\n", raiz->anio, raiz->mes, raiz->dia, raiz->nombre);

    raiz = raiz-> sig;
    if (raiz->sig == NULL){
        printf("No se encontraron mas\n\n");
        return;
    } else 
        buscarMes(raiz,mesBuscado);
}

// Función para eliminar un nodo en una posición específica de la lista
void eliminaPorPosicion(lista **raiz, int posicion) {
    if (posicion < 0 || *raiz == NULL) {
        printf("Posición no válida o la lista está vacía.\n");
        return;
    }

    lista *temp = *raiz;
    int index = 0;

    // Buscar el nodo en la posición especificada
    while (temp != NULL && index < posicion) {
        temp = temp->sig;
        index++;
    }

    // Si la posición es mayor que la longitud de la lista
    if (temp == NULL) {
        printf("Posición fuera de rango.\n");
        return;
    }

    // Ajustamos los punteros para eliminar el nodo
    if (temp->ant != NULL) {
        temp->ant->sig = temp->sig;
    } else {
        *raiz = temp->sig;  // Si es el primer nodo, actualizamos la raíz
    }

    if (temp->sig != NULL) {
        temp->sig->ant = temp->ant;
    }

    printf("Nodo en la posición %d eliminado: %04d-%02d-%02d %s\n\n", posicion, temp->anio, temp->mes, temp->dia, temp->nombre);
    free(temp);  // Liberamos la memoria
}

int longitudLista(lista *raiz) {
    int longitud = 0;
    lista *temp = raiz;
    while (temp != NULL) {
        longitud++;
        temp = temp->sig;
    }
    return longitud;
}

// Función para eliminar un nodo aleatorio de la lista
void eliminaRandom(lista **raiz) {
    int longitud = longitudLista(*raiz);
    
    if (longitud == 0) {
        printf("La lista está vacía, no se puede eliminar un nodo.\n");
        return;
    }

    srand(time(NULL));  // Inicializar la semilla del generador de números aleatorios
    int posicionRandom = rand() % longitud;

    // Llamar a la función eliminaPorPosicion para eliminar el nodo en la posición aleatoria
    eliminaPorPosicion(raiz, posicionRandom+1);
}
