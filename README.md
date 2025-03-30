# Asignatura de  Programación II
En este [repositorio](https://es.wikipedia.org/wiki/Repositorio_de_software) podrá encontrar archivos varios en el lenguaje de programación C que se relacionan con las actividades llevadas a cabo en la materia de Programación II en el Instituto de Enseñanza Superior Sirolli.

El presente intenta ser un registro en el tiempo y, a su vez, una guía práctica de cómo usar el lenguaje C.

## Clases
Programas y ejercicios desarrollados durante las clases en [source/clases](./source/clases/README.md).

## Trabajos Prácticos
Ejercicios resueltos de los distintos TP en [source/trabajos_practicos](./source/trabajos_practicas/).

## Apuntes
Notas y explicaciones sobre varios temas puntuales en [apuntes/](./apuntes/README.md).

## Herramientas
- [ZinjaI IDE](https://zinjai.sourceforge.net/)
- [GCC - GNU Compiler Collection](https://gcc.gnu.org/)
- [Instalar GCC en Winwdows - Guía en Inglés](https://code.visualstudio.com/docs/cpp/config-mingw)

## Lecturas
Libros y/o artículos que puede leer para aprender más sobre C:

- [El Manual para principiantes C: Aprende las bases del lenguaje de programación C en sólo unas horas](https://www.freecodecamp.org/espanol/news/el-libro-para-principiantes-c-aprende-las-bases-del-lenguaje-de-programacion-c-en-solo-unas-horas/)
- [Introducción a las Herramientas de Desarrollo (ZinjaI)](https://zinjai.sourceforge.net/Anexo1.pdf)

## Notas
- El entorno de desarrollo recomendado por la docente es _ZinjaI_, pero puede elegir el que prefiera. Por ejemplo, este proyecto se compila usando `gcc` y un archivo `Makefile` para automatizar ciertos comandos. No es necesario que sepa usarlos, aunque es recomendado.
- Los distintos códigos fuentes pueden ir acompañados de un archivo `README.md` con explicaciones más detalladas o recursos adicionales para consultar.

## ¿Cómo puedo compilar un archivo `*.c` usando `gcc`?
En caso de no utilizar un entorno de desarrollo, use la siguiente instrucción en su consola de comandos:

    gcc <ARCHIVO FUENTE>.c -o <ARCHIVO DE SALIDA>

Reemplace `<ARCHIVO FUENTE>` por el nombre del código fuente en C y `<ARCHIVO DE SALIDA>` por el nombre que tendrá su binario.

Luego ejecute su binario en Linux con:

    ./<NOMBRE DEL BINARIO>

O en Windows:

    .\<NOMBRE DEL BINARIO>.exe

**IMPORTANTE**: Nunca ejecute archivos binarios de los cuales no conozca su procedencia o que vengan de fuentes dudosas. Esto último incluye a sus amigos y conocidos.