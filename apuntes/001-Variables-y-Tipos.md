# Variables

De manera informal podemos entender a las variables como cajitas en las que podemos guardar varoles. Estas cajas poseen un nombre, un valor, un identificador único (llamado puntero), y un tipo de dato que las describen. Por ejemplo, una variable que almacena una edad puede tener el nombre de `edad`, un puntero con valor `0x000001`, y como tipo de dato un entero sin signo, debido a que la edad de una persona no puede ser negativa. 

Sabiendo esto, definimos a una **variable** como **un espacio en memoria que cuenta con cuatro elementos**: un *nombre*, un _valor_, un _puntero_, y un _tipo de dato_. En el lenguaje C, el tipo de dato determina qué valores puede almacenar la variable y cuanto espacio ocupará.

## Tipos de datos

### Primitivos

- Enteros:
  - `char, short, int, long, long int, long long int, signed, unsigned`
- Reales:
  - `float, double, long double`
- Otros:
  - `void`

Podemos decir que `long` más que un tipo de dato es un _modificador_, sólo puede ser usado con `int` y `double`. Por defecto, el tipo `long` es interpretado como `long int` por el compilador de C. Si asignamos a una variable el tipo `long long`, el compilador lo entenderá como `long long int`.

También existen, de manera similar a `long`, los tipos `unsigned` y `signed`, que son equivalentes a `unsigned int` (entero sin signo negativo) y `signed int` (enteros con signo).

### Lista completa de tipos

| Tipo          | Descripción   | Tamaño (bits)         | Rango | Formato        |
| ------------- | ------------- | -------------- | --------------| -------------- |
| `bool` | Un booleano. No disponible en todas las versiones de C. | 1 | {0, 1} | `%d` |
| `char` | Un caracter. Alias para un entero. | >= 8 | [−127, +127]  | `%c` |
| `signed char` | Un char con signo.  | >= 8 | [−127, +127] |  `%c` |
| `unsigned char` | Un char sin signo. | >= 8 | [0, 255] | `%c` |
| `short`, `short int`, `short short`, `short short int` | Entero short.  | >= 16 | [−32.767, +32.767] | `%hi` o `%hd` |
| `unsigned short` `unsigned short int` | Entero short sin signo. | >= 16 | [0, 65.535] | `%hu` |
| `int` `signed` `signed int` | Entero con signo. | >= 16 | [−32.767, +32.767]  | `%i` o `%d` |
| `unsigned` `unsigned int` | Entero sin signo. | >= 16 | [0, 65.535] | `%u` |
| `long` `long int` `signed long` `signed long int` | Entero long con signo. | >= 32 | [−2.147.483.647, +2.147.483.647] | `%li` o `%ld` |
| `unsigned long` `unsigned long int` | Entero long sin signo. | >= 32 | [0, 4.294.967.295] | `%lu` |
| `long long` `long long int` `signed long long` `signed long long int` | Entero long long con signo. | >= 64 | [−9.223.372.036.854.775.807, +9.223.372.036.854.775.807]  | `%lli` o `%lld` |
| `unsigned long long` `unsigned long long int` | Entero long long sin signo. | >= 64 | [0, 18.446.744.073.709.551.615] | `%llu` |
| `float` | Número real con precisión de 32 bits. |  |  | `%f` o `%e` |
| `double` |  Número real con precisión de 64 bits. | |  | `%lf` o `%le` |
| `long double` | Número real con precisión de 128 bits. Puede varíar según la plataforma. |  |  | `%Lf` o `%Le` |
