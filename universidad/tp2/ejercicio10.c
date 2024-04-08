#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int scanValue(char);
int generateRandNum(int, int);
int isDeficient(int);

int main() {
	int N, A, B, randNum, generated, i;
	srand(time(NULL));
	
	N = scanValue('N');
	A = scanValue('A');
	B = scanValue('B');
	generated = 0;
	
	for (i = 0; i < N; i++) {
		randNum = generateRandNum(A, B);
		
		if (isDeficient(randNum) == 0) {
			printf("\nNumero no deficiente generado: %d", randNum);
			generated = 1;
		}
	}
	
	if (generated == 0) {
		printf("\nNo se logro generar ningun numero no deficiente.");
	}
	
	return 0;
}

int scanValue(char var) {
	float input;
	do {
		printf("\nIngrese un numero natural %c: ", var);
		scanf("%f", &input);
	} while (input <= 0 || input != (int)(input));
	
	return (int)input;
}

int generateRandNum(int tail, int head) {
	int rb = rand() % (head - tail + 1) + tail;
	return rb;
}

int isDeficient(int number) {
	int i, value;
	value = 1;
	
	for (i = 2; i <= number/2; i++) {
		if ((number % i) == 0) value += i;
	}
	
	if (value > number) return 0;
	return 1;
}
