#include <stdio.h>
#define tam 100

typedef int lista[tam];

void ingreso_condicional(lista,int*);
int calcular_promedio(lista,int);
void remplazo(lista,int);

int main(){
	lista A;
	int cant=0;
	ingreso_condicional(A,&cant);
	return 0;
}
	
void ingreso_condicional(lista A,int* cant){
	float aux;
	printf("\nIngrese un valor:");
	scanf("%f",&aux);
	
	while(aux == (int)aux){
		*cant += 1;
		A[*cant]=(int)aux;
		printf("\nIngrese otro valor: ");
		scanf("%f",&aux);
	}
}
