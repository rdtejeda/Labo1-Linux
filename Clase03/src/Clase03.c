/*
 ============================================================================
 Name        : Clase03.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int maximo;
	int minimo;
	int acumulador;
	int auxiliarInt;
	int i;

	// Solicito el primer número el cual por ser el primero sera tanto el
	// maximo como el minimo y el primer numero a ser acumulado
	printf("Ingrese un numero: ");
	scanf("%d", &auxiliarInt);
	maximo = auxiliarInt;
	minimo = auxiliarInt;
	acumulador = auxiliarInt;

	// Solicito el resto de los numeros
	for (i = 0; i < 4; i++) {
		printf("Ingrese un numero: ");
		scanf("%d", &auxiliarInt);
		acumulador = acumulador + auxiliarInt;

		if (auxiliarInt > maximo) {
			maximo = auxiliarInt;
		}

		if (auxiliarInt < minimo) {
			minimo = auxiliarInt;
		}
	}

	printf("El maximo es: %i\n", maximo);
	printf("El minimo es: %i\n", minimo);
	printf("El promedio es: %f\n", ((float) acumulador) / 5);
	return 0;

}
