#include <stdio.h>

// Cabaeres de funciones que serán utilizadas luego.
// C tiene que conocer nuestras funciones para poder llamarlas luego.
// Si  no proporcionamos una cabecera, entonces debemos implementarla en esta misma línea.
float calcular(int, int, char);

int main() {
    int num1, num2;
    char operacion;

    // Pedimos la operación que el usuario quiere realizar.
    printf("Ingrese la operación a realizar (+ - * /): ");
    // Leemos la consola y colocamos el char ingresado en la variable 'operacion'.
    scanf("%c", &operacion);

    // Ingresamos los valores
    // El símbolo de "\n" representa un salto de línea, para un resultado más estético.
    printf("\nIngrese el primer valor: ");
    scanf("%d", &num1);

    printf("\nIngrese el segundo valor: ");
    scanf("%d", &num2);

    // Obtenemos el resultado antes de mostrarlo usando nuestra función.
    float resultado = calcular(num1, num2, operacion);

    // Mostramos todo al final.
    printf("\nResultado: %d %c %d = %.1f\n", num1, operacion, num2, resultado);

    return 0;
}

// Implementación concreta de la función 'calcular'.
float calcular(int n1, int n2, char op) {
    float calculado;
    
    switch (op) {
    case '+': 
        calculado = n1 + n2;
        break;
        
    case '-':
        calculado = n1 - n2;
        break;

    case '*':
        calculado = n1 * n2;
        break;
    
    case '/':
        // ¿Qué pasará cuando se divida entre 0? :]
        calculado = n1 / n2;
        break;
    }

    return calculado;
}