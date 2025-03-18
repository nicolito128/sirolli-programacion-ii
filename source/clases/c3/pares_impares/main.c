/*
    Dada una lista de 10 números, calcular la suma de los pares e impares.
    Mostrar al final esas sumas y la cantidad de pares e impares respectivos.
*/
#include <stdio.h>

int main() {
    // Pares.
    int suma_pares = 0, cpares = 0;
    // Impares.
    int suma_impares = 0, cimpares = 0;
    // Cantidad de números a ingresar.
    int cantidad = 10;
    // Auxiliares.
    int i, num;

    for (i = 0; i < cantidad; i++) {
        printf("Ingrese un número: ");
        // Debemos guardar transitoriamente el valor ingresado en `num` y hacer las comprobaciones.
        scanf("%d", &num);
        if (num%2 == 0) { // ¿Existirá una manera más eficiente de comprobar esto sin la necesidad de usar el resto? :)
            suma_pares += num;
            cpares++;
        } else { // Si el número NO es par, entonces necesariamente es impar.
            suma_impares += num;
            cimpares++;
        }
    }
    printf("Cantidad de pares: %d | Suma total: %d\n", cpares, suma_pares);
    printf("Cantidad de impares: %d | Suma total: %d\n", cimpares, suma_impares);

    return 0;
}