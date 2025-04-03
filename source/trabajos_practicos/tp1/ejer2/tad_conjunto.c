#include "tad_conjunto.h"
#include <stdio.h>
#include <stdlib.h>

Conjunto inicializar(int n) {
    Conjunto res = {};
    char ch;
    int i;

    res.cant = 0;
    i = 0;
    while (i < n) {
        // Generamos un caracter ASCII aleatorio. Es decir, un número entre 0 y 127.
        ch = rand() % 128;
        // Si no pertenece, lo agregamos.
        // Caso contrario, seguimos buscando uno que no pertenezca.
        if (pertenece(res, ch) == 0) {
            res = agregar(res, ch);
            i++;
        }
    }

    return res;
}

Conjunto agregar(Conjunto c, char ch) {
    // Siempre que no pertenezca y no exceda la capacidad máxima, lo agregamos.
    if (pertenece(c, ch) == 0 && (c.cant+1) <= CAP_CONJUNTO) {
        // Utilizamos el algoritmo de ordenamiento por inserción.
        int i = c.cant - 1;
        while(i >= 0 && c.elems[i] > ch) {
            c.elems[i+1] = c.elems[i];
            i--;
        }
        c.elems[i+1] = ch;
        c.cant++;
    }
    return c;
}

Conjunto union_conjuntos(Conjunto c1, Conjunto c2) {    
    Conjunto resultado = {};
    resultado.cant = 0;

    int i;

    // Agregar todos los elementos de c1
    for (i = 0; i < c1.cant; i++) {
        resultado = agregar(resultado, c1.elems[i]);
    }

    // Agregar todos los elementos de c2
    for (i = 0; i < c2.cant; i++) {
        resultado = agregar(resultado, c2.elems[i]);
    }

    return resultado;
}

/*
    Debido a que el conjunto está ordenado ascendentemente,
    podemos utilizar el siguiente algoritmo que es más
    eficiente que un bucle `for` normal.

    Si el valor del elemento que intentamos comparar
    es mayor a `ch` significa que nunca lo vamos a poder encontrar.
    Por lo tanto, sólo nos queda salir del bucle ya que `ch` no
    pertenece al conjunto.

    Esta optimización evita que recorramos la totalidad del
    conjunto cada vez que queremos comprobar si un caracter
    pertenece o no.
*/
int pertenece(Conjunto c, char ch) {
    int i = 0;
    while (i < c.cant) {
        if (c.elems[i] > ch) {
            return 0;
        }
        if (c.elems[i] == ch) {
            return 1; // sí pertenece.
        }
        i += 1;
    }
    return 0; // no pertenece.
}

void mostrar(Conjunto c) {
    printf("\n{ ");
    for (int i = 0; i < c.cant; i++) {
        printf("%c ", c.elems[i]);
    }
    printf("}");
}