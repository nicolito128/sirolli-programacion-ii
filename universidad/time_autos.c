#include <stdio.h>
// Un script por Nicolas Abel Sern
// Materia: Programacion

struct Time {
	float hs, mm, ss;
};

static struct Time getTimeBySeconds(float sec);

int main(void) {
	int vehicle;
	float vehiclePrice, tariff, result;
	float hsIn, hsOut, mmIn, mmOut, secs;
	
	// Ingreso de vehiculo y tarifa
	printf("Ingrese el identificador numerico para especificar el tipo de vehiculo a ingresar:\n");
	printf("1 (Moto)\n");
	printf("2 (Auto)\n");
	printf("3 (Camioneta)\n");
	scanf("%d", &vehicle);
	
	printf("\nIngrese la tarifa a utilizar:\n");
	scanf("%f", &tariff);

	vehiclePrice = (float)vehicle * tariff;
	
	// Pidiendo las hora de entrada y salido
	printf("\nIngrese la hora de entrada:\n");
	scanf("%f", &hsIn);
	printf("Ingrese los minutos de entrada:\n");
	scanf("%f", &mmIn);
	
	printf("Ingrese la hora de salida:\n");
	scanf("%f", &hsOut);
	printf("Ingrese los minutos de salida:\n");
	scanf("%f", &mmOut);
	
	secs = ((hsOut + (mmOut / 60)) - (hsIn + (mmIn / 60))) * 3600;
	struct Time hs_mm_ss = getTimeBySeconds(secs);
	
	result = (int)hs_mm_ss.hs * vehiclePrice;
	
	// Si transcurrieron por lo menos 5 minutos, agrega un cobro
	if ((int)hs_mm_ss.mm > 0 ) {
		result += vehiclePrice;
	}
	
	if (vehicle == 1) {
		printf("\nVehiculo: moto - Tarifa: $%.2f", tariff);
	} else if (vehicle == 2) {
		printf("\nVehiculo: automovil - Tarifa: $%.2f", tariff);
	} else {
		printf("\nVehiculo: camioneta - Tarifa: $%.2f", tariff);
	}
	
	printf("\nTotal a pagar: $%.2f", result);
		
	return 0;
}

// getTimeBySeconds gets the explicit HS:MM:SS values as a Time struct.
struct Time getTimeBySeconds(float sec) {
	float hs, mm;
	
	// Converting hs to seconds
	hs = sec / 3600;
	sec = (int)sec % 3600;
	
	// Converting minutes to seconds
	mm = sec / 60;
	sec = (int)sec % 60;
		
	struct Time result = {
		.hs = hs,
		.mm = mm,
		.ss = sec
	};
		
	return result;
}
