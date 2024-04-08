#include <stdio.h>

int main() {
	// Variable declaration
	float width, height, area, perimeter;
	
	// Requering data
	printf("Ingrese el ancho del rectangulo:\n");
	scanf("%f", &width); 
	
	printf("Ingrese la altura del rectangulo:\n");
	scanf("%f", &height);
	
	// Setting variables
	area = width * height;
	perimeter = (2 * width) + (2 * height);
	
	// Printing results
	printf("Para una cuadrado de %.2fx%.2f\n", width, height);
	printf("Area = %.2f\n", area);
	printf("Perimetro = %.2f\n", perimeter);
	
	return 0;
}

