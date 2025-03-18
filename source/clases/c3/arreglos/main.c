#include <stdio.h>
#define TAM 5

int main() {
    int arreglo[TAM];
    int i;

    printf("Ingrese %d números enteros:\n", TAM);
    for (i = 0; i < TAM; i++) {
        printf("arreglo[%d] = ", i);
        scanf("%d", &arreglo[i]);
    }

    printf("El arreglo ingresado es:\n");
    for (i = 0; i < TAM; i++) {
        printf("arreglo[%d]: %d\n", i, arreglo[i]);
    }

    return 0;
}