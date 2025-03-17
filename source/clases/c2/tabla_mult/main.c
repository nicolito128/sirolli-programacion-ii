/*
    Dado un número cualquiera, mostrar su tabla de multiplicar del 1 al 10.
*/
#include <stdio.h>

int main() {
    // Declaramos nuestras variables.
    // En múltiples líneas porque sí, se puede hacer en C.
    int i;
    int num;
    int prod;

    printf("Ingrese un número para mostrar su tabla: ");
    scanf("%d", &num);

    // Iteramos desde 1 hasta 10 (incluído): [1, 10]
    for (i = 1; i <= 10; ++i) { // En C podemos usar ++<variable> o <variable>++, ¿cuál será la diferencia? :)
        // Calcumaos los respectivos valores. Ejemplo, si num = 5, entonces: `5x1, 5x2, 5x3, ..., 5x10`
        prod = num*i;
        // Mostramos la multiplicación
        printf("%dx%d = %d\n", num, i, prod);
    }

    return 0;
}