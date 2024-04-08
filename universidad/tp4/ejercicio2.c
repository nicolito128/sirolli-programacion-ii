#include <stdio.h>
#define listSize 100

typedef int list[listSize];

void getVector(list, int*);
int calculateAverage(list, int);
void filterVectorByAverage(int, list, int, list, int*);

int main() {
	int lengthA, lengthB, average, i;
	list vecA, vecB;
	
	getVector(vecA, &lengthA);
	average = calculateAverage(vecA, lengthA);
	filterVectorByAverage(average, vecA, lengthA, vecB, &lengthB);
	
	printf("\nPromedio del vector A: %d", average);
	
	if (lengthB > 0) {
		printf("\nVector filtrado resultante:\n");
		printf("[ ");
		for(i = 1; i <= lengthB; i++) {
			printf("%d ", vecB[i]);
		}
		printf("]");
	} else {
		printf("\nNingun elemento del vector supera el promedio.");
	}
}

void getVector(list vec, int* length) {
	float len;
	int i;
	do {
		printf("Ingresa la longitud del arreglo a ingresar: ");
		scanf("%f", &len);
	} while(len < 0 || len != (int)len);
	*length = (int)len;
	
	for (i = 1; i <= *length; i++) {
		printf("Ingresa un valor: ");
		scanf("%d", &vec[i]);
	}
}

int calculateAverage(list vec, int length) {
	int i, count, average;
	
	average = 0;
	count = 0;
	for (i = 1; i <= length; i += 2) {
		average += vec[i];
		count++;
	}
	
	average /= count;
	return average;
}

void filterVectorByAverage(int average, list vecA, int lengthA, list vecResult, int* lengthResult) {
	int i, len;
	
	len = 0;
	for (i = 1; i <= lengthA; i++) {
		if (vecA[i] > average) {
			len++;
			vecResult[len] = vecA[i];
		}
	}
	
	*lengthResult = len;
}
