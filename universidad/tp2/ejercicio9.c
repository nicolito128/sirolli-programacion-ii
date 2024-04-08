#include <stdio.h>

int main() {
	float num, i;
	int trunc, dig;
	
	printf("Ingrese un numero real: ");
	scanf("%f", &num);
	
	trunc = (int)num;
	num -= (int)num;
	
	for (i = 0; i <= 5; i++) {
		num = (num * 10);
	}
	
	printf("\n-%d-\n", num);
	
	dig = dig % (int)num;
	while(dig == 0) {
		num /= 10;
		dig %= (int)num;
	}
	
	printf("\nParte entera: %d", trunc);
	printf("\nParte decimal: %d", num);
	
	return 0;
}

