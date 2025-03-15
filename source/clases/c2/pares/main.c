/*
    En el rango de números desde el 1 hasta el 100 (excluído), mostrar todos los valores pares.
*/
#include <stdio.h>

// Cabecera de función.
// Usamos esta función como demostración.
int es_par(int);

int main() {
    int i, min = 1, max = 100;

    for (i = min; i < max; i++) {
        if (es_par(i) == 1) {
            // Mostramos los números uno al lado del otro dejando un espacio en blanco.
            printf("%d ", i);
        }
    }
    // Un salto de línea para ser más estético. No es obligatorio.
    printf("\n");

    return 0;
}

// Determina si el número entero ingresado es par.
int es_par(int numero) {
    // Si el resto de dividir el `numero` entre 2 es 0, entonces el número es par.
    // Esto también nos permite ver cómo es el if...else en C.
    if (numero%2 == 0) {
        return 1;
    } else {
        return 0;
    }
}
