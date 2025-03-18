/*
    Calcular un descuento dado
    1. Monto de compra.
    2. Cantidad de descuento a aplicar.
*/
#include <stdio.h>

float ingresar_fl(const char *mensaje);
float aplicar_descuento(float precio, float descuento);

int main() {
    float precio, descuento, resultado;
    
    precio = ingresar_fl("Ingrese el precio: ");
    descuento = ingresar_fl("Ingrese el descuento: ");
    resultado = aplicar_descuento(precio, descuento);

    printf("Aplicado un 10%% de descuento, el precio final queda en $%.2f\n", resultado);
    return 0;
}

float ingresar_fl(const char *mensaje) {
    float dato;
    printf("%s", mensaje);
    scanf("%f", &dato);
    return dato;
}

float aplicar_descuento(float precio, float descuento) {
    return precio - (precio * (descuento / 100));
}