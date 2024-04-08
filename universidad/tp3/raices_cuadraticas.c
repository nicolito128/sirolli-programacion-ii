#include <stdio.h>
#include <math.h>

void quadraticRoots(float, float, float, float*, float*, int*);
int cantRoots(float, float, float);

int main() {
	float a, b, c, x1, x2;
	int roots;
	
	printf("Ingrese un valor para a: ");
	scanf("%f", &a);
	
	printf("\nIngrese un valor para b: ");
	scanf("%f", &b);
	
	printf("\nIngrese un valor para c: ");
	scanf("%f", &c);
	
	quadraticRoots(a, b, c, &x1, &x2, &roots);
	
	switch(roots) {
	case 0:
		printf("\n\nNo existen raices para mostrar.");
		break;
		
	case 1:
		printf("\nRaiz unica o doble de la ecuacion ax^2 + bx + c: %f", x1);
		break;
		
	case 2:
		printf("\nRaices de la ecuacion ax^2 + bx + c. X1: %f & X2: %f", x1, x2);
	}
	
	return 0;
}

void quadraticRoots(float a, float b, float c, float* x1, float* x2, int* disc) {
	*disc = cantRoots(a, b, c);
	
	if (*disc == 0) {
		*x1 = 0;
		*x2 = 0;
	} else {
		*x1 = (-b + sqrt(b*b - 4*a*c)) / 2*a;
		*x2 = (-b - sqrt(b*b - 4*a*c)) / 2*a;
	}
}

int cantRoots(float a, float b, float c) {
	float disc;
	if (a == 0) return 0;
	
	disc = (b*b - 4*a*c);
	
	if (disc > 0) {
		return 2;
	} else if (disc == 0) {
		return 1;
	} else {
		return 0;
	}
}
