#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TAM 100

typedef char cadena[TAM];

void leeCad(cadena, int);

int main() {
    cadena dest, src = "hello";

    // Concatenando ' world' en src
    strcat(src, " world");
    // Copiando 'src' en 'dest'
    strcpy(dest, src);
    // Comparando dos cadenas
    printf("%d\n", strcmp(dest, "hello world"));

    printf("%s\n", dest);

    return 0;
}

void leeCad(cadena cad, int tam) {
    int j, m;
    j = 0;
    
    fflush(stdin); // caso particular no escribir en el examen
    while (j < (tam - 1) && (m = getchar()) != EOF && m != '\n') {
        cad[j] = m;
        j++;
    }

    cad[j] = '\0';

    if (m != EOF && m != '\n') /* limpiar buffer */
        while ((m = getchar()) != EOF && m != '\n');
}