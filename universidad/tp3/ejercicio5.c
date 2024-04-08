#include <stdio.h>

int getMenuOption();
void getFraction(int*, int*);
int mcd(int, int);
int mcm(int, int);
void reset(int*, int*);
void simplify(int*, int*);
void addFractions(int, int, int, int, int*, int*);
void incrementFraction(int*, int*, int, int);
void subtractFractions(int, int, int, int, int*, int*);
void decrementFraction(int*, int*, int, int);
void multiply(int, int, int, int, int*, int*);
void divide(int, int, int, int, int*, int*);

int main() {
	int op, num1, den1, num2, den2, numR, denR;
	num1 = 0;
	den1 = 0;
	
	do {
		op = getMenuOption();
		
		switch(op) {
		case 1:
			getFraction(&num1, &den1);
			getFraction(&num2, &den2);
			
			addFractions(num1, den1, num2, den2, &numR, &denR);
			simplify(&numR, &denR);
			
			printf("\n! Resultado de la suma: %d/%d", numR, denR);
			reset(&num1, &den1);
			break;
			
		case 2:
			getFraction(&num1, &den1);
			getFraction(&num2, &den2);
			
			subtractFractions(num1, den1, num2, den2, &numR, &denR);
			simplify(&numR, &denR);
			
			printf("\n! Resultado de la resta: %d/%d", numR, denR);
			reset(&num1, &den1);
			break;
			
		case 3:
			getFraction(&num1, &den1);
			getFraction(&num2, &den2);
			
			multiply(num1, den1, num2, den2, &numR, &denR);
			simplify(&numR, &denR);
			
			printf("\n! Resultado de la multiplicacion: %d/%d", numR, denR);
			reset(&num1, &den1);
			break;
			
		case 5:
			if (num1 == 0 && den1 == 0) {
				getFraction(&num1, &den1);
			}
			getFraction(&num2, &den2);
			
			incrementFraction(&num1, &den1, num2, den2);
			simplify(&num1, &den1);
			
			printf("\n! Resultado del incremento: %d/%d", num1, den1);
			break;
			
		case 6:
			if (num1 == 0 && den1 == 0) {
				getFraction(&num1, &den1);
			}
			getFraction(&num2, &den2);
			
			decrementFraction(&num1, &den1, num2, den2);
			simplify(&num1, &den1);
			
			printf("\n! Resultado del decremento: %d/%d", num1, den1);
			break;
		}
	} while(op != 0);
	
	printf("\nFinalizando el programa.");
	
	return 0;
}

int getMenuOption() {
	int option;
	
	do {
		printf("\n<-- Menu de Calculadora -->\n");
		printf("Para efectuar una operacion ingrese el numero correspondiente o 0 (cero) para salir:\n\n");
		printf("0. Salir\n");
		printf("1. Sumar\n2. Restar\n3. Multiplicar\n4. Cociente\n");
		printf("5. Incremento\n6. Decremento\n");
		printf("7. >\n8. <\n9. =\n");
		printf("10. >=\n11. <=\n");
		printf("\n> ");
		
		scanf("%d", &option);
	} while(option != 0 && option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7 && option != 8 && option != 9 && option != 10 && option != 11);
	
	return option;
}

void getFraction(int* numerator, int* denominator) {
	printf("\n- Obteniendo una fraccion -");
	do {
		printf("\nIngrese un valor para el numerador: ");
		scanf("%d", numerator);
		
		printf("\nIngrese un valor para el denominador: ");
		scanf("%d", denominator);
			
		if (*denominator == 0) {
			printf("\nDenominator invalido.");
		}
	} while(denominator == 0);
	
	if (*numerator <= 0 && *denominator < 0) {
		*denominator *= (-1);
		*numerator *= (-1);
	}
	
	if (*denominator < 0 && *numerator >= 0) {
		*denominator *= (-1);
		*numerator *= (-1);
	}
}

void reset(int* num,  int* den) {
	*num = 0;
	*den = 0;
}

// Maximo comun divisor
int mcd(int numA, int numB) {
	int div, b = 0;
	
	if (numA > numB) {
		div = numA;
	} else {
		div = numB;
	}
	
	while(div >= 1 && b != 1) {
		if ((numA%div) != 0 || (numB%div) != 0) {
			div--;
		} else {
			b = 1;
		}
	}
	
	return div;
}

// Minimo comun multiplo
int mcm(int numA, int numB) {
	return (numA * numB) / mcd(numA, numB);
}

void simplify(int* numerator, int* denominator) {
	int div = mcd(*numerator, *denominator);
	*numerator = *numerator / div;
	*denominator = *denominator / div;
}

void addFractions(int numerator1, int denominator1, int numerator2, int denominator2, int* numeratorResult, int* denominatorResult) {
	// MCD between the denominators
	*denominatorResult = mcm(denominator1, denominator2);
	// Addition algorithm for fractions
	*numeratorResult = (*denominatorResult / denominator1) * numerator1 + (*denominatorResult / denominator2) * numerator2;
}

void incrementFraction(int* numeratorResult, int* denominatorResult, int numerator, int denominator) {
	addFractions(*numeratorResult, *denominatorResult, numerator, denominator, numeratorResult, denominatorResult);
}

void subtractFractions(int numerator1, int denominator1, int numerator2, int denominator2, int* numeratorResult, int* denominatorResult) {
	addFractions(numerator1, denominator1, numerator2*(-1), denominator2, numeratorResult, denominatorResult);
}

void decrementFraction(int* numeratorResult, int* denominatorResult, int numerator, int denominator) {
	subtractFractions(*numeratorResult, *denominatorResult, numerator, denominator, numeratorResult, denominatorResult);
}

void multiply(int numerator1, int denominator1, int numerator2, int denominator2, int* numeratorResult, int* denominatorResult) {
	*numeratorResult = numerator1 * numerator2;
	*denominatorResult = denominator1 * denominator2;
}
