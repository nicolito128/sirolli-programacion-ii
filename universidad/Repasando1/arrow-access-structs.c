#include <stdio.h>

typedef struct {
	int h, w;
} A;

typedef struct {
	A elementA;
} B;

typedef struct {
	B elementB;
} C;

void modifyA(A*, int);
void modifyB(B*, int);
void modifyC(C*, int);

int main() {
	A letter = {50, 25};
	printf("Valor h: %d - Valor w: %d\n", letter.h, letter.w);
	
	modifyA(&letter, 2);
	printf("Valor h: %d - Valor w: %d\n", letter.h, letter.w);
	
	B letterB = {letter};
	modifyB(&letterB, 3);
	printf("Valor B->elementA->h: %d - Valor B->elementA->w: %d\n", letterB.elementA.h, letterB.elementA.w);
	printf("Valor A->h: %d - Valor A->w: %d\n", letter.h, letter.w);
	return 0;
}

void modifyA(A *element, int pr) {
	element->h *= pr;
	element->w *= pr;
}

void modifyB(B *element, int plus) {
	element->elementA.h += plus;
	element->elementA.w += plus;
}

void modifyC(C *element, int minus) {
	element->elementB.elementA.h -= minus;
	element->elementB.elementA.w -= minus;
}
