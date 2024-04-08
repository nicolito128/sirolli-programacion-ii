#include <stdio.h>
#define listSize 100

typedef char list[listSize];

void scanData(list, int*, char*);
int searchChar(char, list, int);

int main() {
	list vecA;
	int lengthA;
	char x;
	
	scanData(vecA, &lengthA, &x);
	
	return 0;
}

void scanList(list vec, int* length, char* element) {
	int index;
	float len;
	
	do {
		printf("Ingresa la longitud del vector: ");
		scanf("%f", &len);
	} while(len < 0 || len != (int)len);
	*length = (int)len;
	
	for(index = 1; index <= *length; index++) {
		printf("\nIngresa un valor: ");
		scanf("%c", &vec[index]);
	}
	
	printf("Ingrese un caracter para buscar: ");
	scanf("%c", element);
}

// If the char doesn't exists, then return -1.
int searchChar(char c, list vec, int length){}

