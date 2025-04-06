#include <stdio.h>
#include "cadena.h"

int main() {
    cadena xs;
    pedir_cadena("\nIngrese una cadena de texto > ", &xs);
    printf("\n\t%s", xs);
    return 0;
}