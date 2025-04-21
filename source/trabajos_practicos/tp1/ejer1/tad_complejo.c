#include "tad_complejo.h"
#include <stdio.h>

// (a + b.i) + (c + d.i) = (a + c) + (b + d).i
void sumar(complejo elem1, complejo elem2, complejo resultado) {
	float a = elem1[0], b = elem1[1];
	float c = elem2[0], d = elem2[1];
	resultado[0] = a + c;
	resultado[1] = b + d;
}

// (a + b.i) (c + d.i) = (a - c) + (b - d).i
void restar(complejo elem1, complejo elem2, complejo resultado) {
	float a = elem1[0], b = elem1[1];
	float c = elem2[0], d = elem2[1];
	resultado[0] = a - c;
	resultado[1] = b - d;
}

// (a + b.i) * (c + d.i) = (ac + bd) + (ad + bc).i
void multiplicar(complejo elem1, complejo elem2, complejo resultado) {
	float a = elem1[0], b = elem1[1];
	float c = elem2[0], d = elem2[1];
	resultado[0] = a*c + b*d;
	resultado[1] = a*d + b*c;
}

// (a + b.i) / (c + d.i) = [ (ac + bd)/(c^2 + d^2) ] + [ (bc - ad)/ (c^2 + d^2) ].i
void dividir(complejo elem1, complejo elem2, complejo resultado) {
	float a = elem1[0], b = elem1[1];
	float c = elem2[0], d = elem2[1];
	resultado[0] = (a*c + b*d) / (c*c + d*d);
	resultado[1] = (b*c - a*d) / (c*c + d*d);
}

void mostrar(complejo elem) {
	if (elem[1] < 0) {
		printf("\n(%.2f - %.2fi)\n", elem[0], elem[1]*(-1));
	} else {
		printf("\n(%.2f + %.2fi)\n", elem[0], elem[1]);
	}
}
