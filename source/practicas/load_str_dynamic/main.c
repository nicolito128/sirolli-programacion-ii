/*
    Cargar un arreglo de strings de tamaño desconocido y mostrarlos.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 5

// Alias para el tipo de dato `char *` en la forma de `string`.
typedef char *string;

// Cabeceras de funciones.
string obtener_cadena(char delimitador);
void free_arreglo(string arreglo[TAM]);

int main() {
    // Arreglo con las cadenas.
    string arreglo[TAM];
    // Delimitador para el ingreso de la cadena por consola.
    char delim = '\n';
    // Auxiliares.
    string cadena;
    int i;

    printf("Ingreso de las frutas\n");
    for (i = 0; i < TAM; i++) {
        printf("arreglo[%d] = ", i);
        cadena = obtener_cadena(delim);
        // Algo fue mal en el proceso, liberamos la memoria y terminaremos el programa.
        if (cadena == NULL) {
            free_arreglo(arreglo);
            printf("Algo salió terriblemente mal...\n");
            return 1;
        }
        arreglo[i] = cadena;
    }

    for (i = 0; i < TAM; i++) {
        printf("\n[%d] %s ", i, arreglo[i]);
    }

    // Debemos liberar la memoria reservada.
    free_arreglo(arreglo);

    return 0;
}

// free_arreglo libera la memoria de cada elemento siempre que no sea nulo.
void free_arreglo(string arreglo[TAM]) {
    for (int i = 0; i < TAM; i++) {
        if (arreglo[i] != NULL) {
            free(arreglo[i]);
        }
    }
}

// obtener_cadena lee una serie de caracteres de la consola hasta que encuentra el `delimitador` que le pasamos y se detiene.
string obtener_cadena(char delimitador) {
    // Un tamaño inicial para reservar la memoria.
    int tam_inicial = 16;
    // Reservamos la memoria para la cadena de caracteres.
    string cadena = (string)malloc(tam_inicial*sizeof(string));
    // Sucedió un problema y no se puede reservar memoria.
    if (cadena == NULL) {
        return NULL;
    }
    // Auxiliares
    string nueva_cadena;
    int longitud = 0;
    char caracter;

    // Leemos caracteres hasta que encontremos un End-Of-File.
    while ((caracter = getchar()) != EOF) {
        // Si encontramos el delimitador, entonces colocamos el caracter de fin de string y retornamos su valor.
        if (caracter == delimitador) {
            cadena[longitud] = '\0';
            return cadena;
        }

        cadena[longitud] = caracter;
        longitud++;

        // Nos pasamos del tamaño inicial, necesitamos reservar más memoria dinámica.
        if (longitud >= tam_inicial) {
            // El tamaño inicial se multiplica por 2 :]
            tam_inicial = tam_inicial*2;
            // `realloc` nos ahorra tener que volver a copiar todo al usar un `malloc`.
            nueva_cadena = (string)realloc(cadena, tam_inicial*sizeof(string));
            // Algo salió mal, liberamos lo reservado y devolvemos un NULL.
            if (nueva_cadena == NULL) {
                free(cadena);
                return NULL;
            }
            cadena = nueva_cadena;
        }
    }

    return NULL;
}