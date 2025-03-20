/*
    Cargar un arreglo de 5 frutas y mostrarlas.
*/
#include <stdio.h>
#define TAM 5
#define LEN 10

int main() {
    // Emojis de frutas: 🍉 🍇 🍊 🍋 🍌
    char frutas[TAM][LEN];
    char fruta;
    int i;

    for (i = 0; i < TAM; ++i) {
        printf("frutas[%d] = ", i);
        scanf("%s", &frutas[i]);
    }

    for (i = 0; i < TAM; ++i) {
        printf("%s ", frutas[i]);
    }

    return 0;
}