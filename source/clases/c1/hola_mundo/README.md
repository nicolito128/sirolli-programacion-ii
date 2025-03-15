# Hola Mundo en C

Cuando empezamos con cualquier lenguaje de programación el programa más simple que podemos hacer es el conocido como "Hola mundo", se trata de una aplicación que imprime por consola un mensaje y poco más.

Un _hola mundo_ en C se puede ver de la siguiente manera:

```c
#include <stdio.h>

int main() {
    printf("Hola, mundo!\n");
    return 0;
}
```

Si decide copiar el código anterior en su IDE de preferencia y lo ejecuta, verá por consola el mensaje `"Hola, mundo!"` seguido por un _salto de línea_ (denotado por `\n`).

Sin embargo, aunque sea capaz de ejecutar ese código, probablemente no entienda todo lo que se muestra en el programa. Vamos desgranando línea por línea lo que vemos.

---

```c
#include <stdio.h>
```

La primera línea de todas es de suma importancia, sin ella no seríamos capaces de usar el subproceso `printf` en nuestro programa.

La instrucción `#include` es una **directiva del preprocesador**. Las directivas de preprocesado son instrucciones especiales ejecutadas por el _Preprocesador de C_. El preprocesador es un programa que se ejecuta antes de la instancia de compilado del lenguaje y se encarga de _reemplazar_ las instrucciones que encuentra por otra pieza de código.

Yendo a lo concreto, `#include` es una directiva que _incluye_ en el programa código C externo, que puede, o no, estar escrito por nosotros, para así tener acceso a funciones, procesos, y variables que no hayamos declarado de manera explicita en el archivo. Por otro lado, `<stdio.h>` es parte de la **biblioteca estándar** de C; es decir, código perteneciente al lenguaje de programación y que, en este caso, nos da acceso a distintas operaciones de _entrada_ y _salida_, de ahí su nombre: `std` por la biblioteca estándar e `io` por _input/output_. Por ahora no nos preocupemos por el significado del `.h`, sólo hay que saber que se conocen como _cabeceras_.

A diferencia del resto de código en C, las directivas no tienen que finalizar con un `;`.

---

```c
int main() {
```

En esta línea tenemos la _función main_, en cualquier programa de C es el **punto de entrada** que se ejecutará cuando intentemos correr un binario. Posee la estructura típica de una función:

    <Tipo de Dato de Retorno> <Nombre de la función>(<Argumentos>) {
        <Cuerpo>
    }

Para este caso _main_ retornará un entero, denotado por el tipo de dato `int`, y no tendrá argumentos. No nos explayaremos mucho sobre qué es una función, sólo hay que entender que son un conjunto de instrucciones reutilizables.

Notemos que la función abre llaves (`{`) y las cierra (`}`) en su última línea. Esta sintaxis marca el _scope_ o entorno donde podremos escribir instrucciones. En un lenguaje de programación como Python, en lugar de usar `{}` tendríamos que escribir sangrías o _tabs_ que dejen un espacio en blanco (que también escribimos para hacer el código más legible).

---

```c
printf("Hola, mundo!\n");
```

Gracias a todo lo que hemos visto hasta ahora, sabemos que `printf` es sólo una función que proviene de hacer un _include_ a `<stdio.h>` y cuyo trabajo es imprimir por pantalla. La letra `f` en el nombre proviene de `format`, significa que la función admite ciertos caracteres especiales que decoren el texto y la posibilidad de insertar variables. En este sentido, el símbolo `\n` representa el caracter de _salto de línea_.

Además, toda instrucción en el lenguaje debe finalizar con un `;`. Esto también permite que se coloquen instrucciones una después de la otra.

---

```c
return 0;
```

Para finalizar tenemos el valor de retorno de _main_. Como el retorno debe ser un entero, se establece la convención de devolver el valor `0` cuando le programa ha terminado sin errores.