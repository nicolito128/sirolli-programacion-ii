# Operadores

## Aritméticos

En C podemos expresar distintas operaciones matemáticas básicas con todos los tipos de datos numéricos. En la siguiente tabla puede ver aquellos operadores:

| Símbolo       | Uso           | Descripción   | 
| ------------- | ------------- | -------------- |
| **+** | `a + b` | Operador binario para la adición. |
| **-** | `a - b` | Operador binario para la sustracción. |
| **\*** | `a * b` | Operador binario para la multiplicación. |
| **/** | `a / b` | Operador binario para la división. Requiere que `b` sea diferente de `0`. |
| **%** | `a % b` | Operador binario para obtener el módulo o resto de una división. Requiere que `b` sea diferente de `0`. |
| **+** | `+a` | Operador unitario que representa un signo positivo. |
| **-** | `-a` | Operador unitario que representa un signo negativo. |

### Bitwise

Este tipo de operadores nos permiten alterar el _valor en binario_ de un número.

| Símbolo       | Operador      | Sintaxis       |  Descripción    | 
| ------------- | ------------- | -------------- | --------------- |
| **&** | `AND` | `a & b` | Producto lógico entre los bits de cada valor. |
| **\|** | `OR` | `a \| b` | Suma lógica entre los bits de cada valor. |
| **^** | `XOR` | `a ^ b` | Operación XOR entre los bits de cada valor. |
| **~** | `Complemento` | `~a` | Intercambia cada bit de un número por su complemento. |
| **<<** | `Leftshift` | `a << b` | Desplaza los bits del número `a` una `b` cantidad de veces hacía la _izquierda_. |
| **>>** | `Rightsift` | `a >> b` | Desplaza los bits del número `a` una `b` cantidad de veces hacía la _derecha_. |

## Asignación

Los operadores de asignación nos permiten establecer o modificar el valor de una variable. El más básico es la `asignación` simple:

```c
    int mi_variable = 0;
```

Otra opción es:

```c
    int mi_variable;

    // Otro código...

    mi_variable = 0;
```

Es importante que asignemos valores a las variables, ya que C se encarga de establecer por defecto basura de memoria cuando las declaramos sin asignar.

### Otras asignaciones

Podemos combinar las asignaciones con las operaciones aritméticas que ya conocemos. Siendo `N` cualquier valor numérico, podemos utilizar:

| Uso            | Equivalencia  | 
| -------------- | ------------- |
| `a += N` | `a = a + N` |
| `a -= N` | `a = a - N` |
| `a *= N` | `a = a * N` |
| `a /= N` | `a = a / N` |
| `a %= N` | `a = a % N` |
| `a &= N` | `a = a & N` |
| `a \|= N` | `a = a \| N` |
| `a ^= N` | `a = a ^ N` |
| `a <<= N` | `a = a << N` |
| `a >>= N` | `a = a >> N` |

## Incremento y decremento

Existe el concepto de `operador de incremento`, que es una forma corta de escribir lo siguiente

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

## Lógicos

Los operadores lógicos nos permiten escribir _expresiones booleanas_ que evalúan a _verdadero_ o _falso_:

| Símbolo        | Operador      | Ejemplo       | Descripción   |
| -------------- | ------------- | ------------- | ------------- |
| **&&** | `AND` | `a && b` | Producto lógico. |
| **\|\|** | `OR` | `a \|\| b` | Suma lógica. |
| **!** | `NOT` | `!` | Negación de una expresión. |
| **==** |  | `a == b` | Expresa _"`a` igual que `b`"_. |
| **!=** |  | `a != b` | Expresa _"`a` distinto que `b`"_. |
| **<=** |  | `a <= b` | Expresa _"`a` menor o igual que `b`"_. |
| **>=** |  | `a >= b` | Expresa _"`a` mayor o igual que `b`"_. |