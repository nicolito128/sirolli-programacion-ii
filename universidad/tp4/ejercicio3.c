#include <stdio.h>
#define expedientSize 100

typedef struct Experiment {
	int id;
	float time, speed;
};

typedef Experiment Expedient[expedientSize];

void getExpedient(Expedient);

int main() {
	return 0;
}

void getExpedient(Expedient list) {
	float experiments;
	
	do {
		printf("Digite la cantidad de experimentos a ingresar: ");
		scanf("%d", &experiments);
	} while(experiments < 0 || experiments != (int)experiments);
}
