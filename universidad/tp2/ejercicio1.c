#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323

int main() {
	double value;
	printf("Ingrese un valor real: ");
	scanf("%lf", &value);
	
	double sen = sin(value * (PI / (double)180));
	double lg = log(value);
	double absolute = fabs(value);
	
	printf("\n\nSeno: %lf\n", (sen * ((double)180/PI)));
	printf("Logaritmo: %lf\n", lg);
	printf("Valor absoluto: %lf\n", absolute);
	
	return 0;
}

