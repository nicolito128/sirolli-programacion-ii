#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getInput(const char *);
int randInterval(int, int);

int main() {
	int tail = getInput("Ingrese el inicio del intervalo: ");
	int head = getInput("Ingrese el final del intervalo: ");
	
	int timeA = randInterval(tail, head);
	int timeB = randInterval(tail, head);
	
	while(timeA == timeB) {
		timeA = randInterval(tail, head);
		timeB = randInterval(tail, head);
	}
	
	if (timeA < timeB) {
		printf("\nEl cliente A sera atendido primero.");
		printf("\nValor de timeA: %d", timeA);
		printf("\nValor de timeB: %d", timeB);
	} else {
		printf("\nEl cliente B sera atendido primero.");
		printf("\nValor de timeA: %d", timeA);
		printf("\nValor aleatorio: %d", timeB);
	}
	
	return 0;
}

// getInput read a new input with the stdio.
int getInput(const char * message) {
	int input = 0;
	
	printf(message);
	scanf("%d", &input);
	
	return input;
}

// randInterval gets an [a, b] interval.
int randInterval(int a, int b) {
	int randomizer;
	srand(time(NULL));
	
	randomizer = rand() % (b - a + 1) + a;
	return randomizer;
}

