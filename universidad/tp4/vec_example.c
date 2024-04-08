#include <stdio.h>
#define digitsLength 10

typedef int digits[digitsLength];

int main() {
	int i;
	digits myVec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	printf("Pos del vec: %d\n", &myVec);
	for(i = 0; i <= digitsLength; i++) {
		printf("Elemento %d: %d\n", i, myVec[i]);		
		printf("Posicion %d: %d\n", i, &myVec[i]);
	}
		
	return 0;
}

