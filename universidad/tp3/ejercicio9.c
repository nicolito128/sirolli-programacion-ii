#include <stdio.h>

int ingreso_datos();
long int compruebo_repetidos(long int);
int pow(int, int);
void borrar_repetidos(long int*, int*);

int main() {
	long int clave;
	int del;
	scanf("%ld", &clave);
	borrar_repetidos(&clave, &del);
	printf("\nClave: %d - Elimnados: %d", clave, del);
	return 0;
}

int ingresar_datos() {}

long int compruebo_repetidos(long int clave){
	int aux,aux2;
	int digito,b=0,pos=0;
	aux=clave;
	while(aux >0 && b==0){
		digito=aux%10;
		aux2=aux/10;
		while(aux2>0 && b==0){
			if(digito==aux2%10) b=1;
			aux2/=10;
		}
		pos++;
		aux/=10;
	}
	if(b==1) return pos;
	else return 0;
}

// Nicolas A. Serna.
int pow(int base, int n) {
	if (n == 0) return 1;
	
	int i, p = base;
	for (i = 1; i < n; ++i) {
		p *= base;
	}
	
	return p;
}

// borrarRepetidos elimina de la clave aquellos elementos que se repiten y devuelve la clave modificada y la cantidad de eliminados.
// Modulo por Nicolas A. Serna.
void borrar_repetidos(long int* clave, int* eliminados) {
	int pos, aux, del;
	pos = compruebo_repetidos(*clave);
	aux = 0;
	del = 0;
	
	while(pos != 0) {
		aux = *clave % pow(10, (pos - 1));
		*clave /= pow(10, pos);
		*clave = (*clave * pow(10, (pos - 1)) + aux);
		
		del++;
		pos = compruebo_repetidos(*clave);
	}
	*eliminados = del;
}
