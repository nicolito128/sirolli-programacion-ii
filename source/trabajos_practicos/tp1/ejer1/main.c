// std
#include <stdio.h>
// TADs
#include <tad_complejo.h>

void menu();
void opcion_sumar();
void opcion_restar();
void opcion_multiplicar();
void opcion_dividir();
void ingresar_complejo(complejo num);
void cargar_complejos(complejo num1, complejo num2);

int main(void) {
    menu();
    return 0;
}

void menu() {
    char opcion;
    do {
        printf("\n--- Menú de opciones para la calculadora de complejos ---\n");
        printf("[ 0 ] Salir.\n");
        printf("[ + ] Sumar dos complejos.\n");
        printf("[ - ] Restar dos complejos.\n");
        printf("[ * ] Multiplicar dos complejos.\n");
        printf("[ / ] Dividir dos complejos.\n");
        printf("\nEscriba la operación que quiera realizar > ");
        scanf("%c[^\n]", &opcion);

        switch (opcion) {
        case '+':
            opcion_sumar();
            break;
        case '-':
            opcion_restar();
            break;
        case '*':
            opcion_multiplicar();
        case '/':
            opcion_dividir();
            break;
        }
    } while(opcion != '0');
    printf("Finalizando el programa.\nCiao!\n");
}

void ingresar_complejo(complejo num) {
    printf("\nIngrese la parte Real > ");
    scanf("%f", &num[0]);

    printf("Ingrese la parte Imaginaria > ");
    scanf("%f", &num[1]);
}

void cargar_complejos(complejo num1, complejo num2) {
    printf("\n-- Cargando el 1er número --");
    ingresar_complejo(num1);

    printf("\n-- Cargando el 2do número --");
    ingresar_complejo(num2);
}

void opcion_sumar() {
    complejo num1, num2, resultado;
    cargar_complejos(num1, num2);
    sumar(num1, num2, resultado);
    mostrar(resultado);
}

void opcion_restar() {
    complejo num1, num2, resultado;
    cargar_complejos(num1, num2);
    restar(num1, num2, resultado);
    mostrar(resultado);
}

void opcion_multiplicar() {
    complejo num1, num2, resultado;
    cargar_complejos(num1, num2);
    multiplicar(num1, num2, resultado);
    mostrar(resultado);
}

void opcion_dividir() {
    complejo num1, num2, resultado;
    cargar_complejos(num1, num2);
    dividir(num1, num2, resultado);
    mostrar(resultado);
}