/*
    Dado un número en radianes, calcular su seno.
*/
#include <stdio.h>
// Importamos la biblioteca math.h de C
#include <math.h>

int main() {
    double num, seno;

    printf("Ingrese un número en radianes para calcular su seno: ");
    scanf("%lf", &num);

    // La función `sin` obtiene el valor del seno.
    seno = sin(num);
    printf("sin(%lf) = %lf\n", num, seno);

    return 0;
}