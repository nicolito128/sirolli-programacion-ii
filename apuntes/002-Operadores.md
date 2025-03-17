# Operadores

## Incremento y decremento

En C existe el concepto de `operador de incremento`, que es una forma corta de escribir lo siguiente

```c
    i++;

    // Es equivalente a

    i += 1;
```

Este operador puede usarse como una instrucción particular o componiéndolo dentro de expresiones más complejas. Por ejemplo:

```c
    int j = 127;
    printf("%d\n", j++);

    // Es traducido a

    int j = 127;
    printf("%d\n", j);
    j += 1;
```

Por lo tanto, el valor que se mostrará con `printf` es lo que está almacenado en `j` antes de ser modificado; o sea, el valor `127`.

Esta notación recibe el nombre de `Postfix`, porque el operador aparece posteriormente a la variable. Utlizando esta misma idea, podemos definir al operador de incremento en notación de `Prefix` (prefijo):

```c
    int k = 87;
    printf("%d\n", ++j);

    // Es traducido a

    int k = 87;
    k += 1;
    printf("%d\n", j);
```

En este caso el resultado mostrado será el número `88`.

Podemos aplicar la misma lógica vista con anterioridad para el operador de decremento `--`.

Hay que resaltar que, pese a funcionar de manera distinta, los operadores de decremento e incremento en ambas variantes (prefix y postfix) se comportan de la misma manera cuando se utilizan dentro de un bucle clásico. Visto en código:

```c
    int i;
    int N = 10;

    // Su comportamiento es equivalente:
    for (i = 0; i < N; ++i) // ...
    for (i = 0; i < N; i++) // ...
```

Un ejemplo donde el comportamiento de `for` se vería afectado es el siguiente:

```c
    int i;
    int n = 5;

    for (i = 0; i < 5;) {
        printf("%d ", ++i); // Resultado: 1 2 3 4 5
    }
```

Sin embargo, resulta poco recomendable hacer bucles de esta manera.