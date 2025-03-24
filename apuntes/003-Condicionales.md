# Condicionales

## `if...else`

Las condicionales de selección nos permiten evaluar una _expresiones booleana_ y tomar una decisión en función de su valor de *verdadero* o *falso*.

En C podemos escribirlas usando la siguiente sintaxis:

```c
    if (CONDICIÓN) EXPRESIÓN o BLOQUE
    else ALTERNATIVA
```

Por ejemplo, compararemos una variable llamada `edad` para determinar si una persona es mayor o menor de edad, o si tiene justo 18 años:

```c
    int edad = 18;

    if (edad > 18) {
        // Caso mayor a 18
    }
    else if (edad < 18) {
        // Caso menor a 18
    } else {
        // Caso igual a 18
    }
```

También podemos escribir estas condicionales de forma acortada en una única línea:

```c
    int cantidad = 128;

    if (cantidad == 128) printf("Verdadero!");
    else printf("Falso...");

    if (cantidad <= 127) printf("Sólo con caso verdadero.");
```

## `switch`

La estructura `switch...case` permite ejecutar uno o varios bloques de código en función del valor de una expresión. Su estructura general es la siguiente:

```c
    switch (VALOR) {
        case CASO_1:
            CÓDIGO
            break;
        case CASO_2:
            CÓDIGO
            break;
        .
        .
        .

        default:
            CÓDIGO DEL CASO BASE
    }
```

Por ejemplo:

```c
#include <stdio.h>

int main() {

    int var = 1;

    switch (var) {
    case 1:
        printf("Caso 1.");
        break;

    case 2:
        printf("Caso 2.");
        break;

    case 3:
        printf("Caso 3.");
        break;

    default:
        printf("Caso por defecto.");
        break;
    }

    return 0;
}
```

En este código el _valor_ contenido en la variable `var` se va comparando con cada caso desde arriba hacía abajo. Cuando el programa encuentra un caso que coincida, ejecuta el bloque de código que hayamos escrito y, al final, sale de la estructura `switch` cuando encuentra un `break`. En caso de no encontrar ninguna coincidencia, ejecuta el caso por defecto (`default`).

Si decidimos eliminar la instrucción `break`, los subsecuentes casos serán evaluadas incluso cuando ya se haya ejecutado alguno anterior. También es importante recordar colocar el caso `default` al final, ya que este siempre llegará ejecutarse y puede imposibilitar la ejecución de casos por debajo de él.