/*
    Un profesor realizó un examen final a 10 alumnos y quiero obtener el promedio
    de notas las notas.
*/
#include <stdio.h>

int main() {
    // Declaramos las variables arriba del todo.
    // Algunas son asignadas a un valor en el momento.
    // ¿Qué valor tendrá una variable sin asignar? :]
    int i, cantidad_notas = 10;
    float promedio, nota, suma = 0;

    // Un bucle for en el rango [0, cantidad_notas)
    for (i = 0; i < cantidad_notas; i++) {
        printf("Ingrese la nota %d: ", i+1);
        // Necesitamos la variable auxiliar para ir guardando las notas
        scanf("%f", &nota);
        suma += nota;
    }
    promedio = suma / cantidad_notas;
    printf("Promedio: %f\n", promedio);

    return 0;
}