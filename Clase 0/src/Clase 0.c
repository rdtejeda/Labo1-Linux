/*
 ============================================================================
 Name        : Clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);
	printf("Esta es la primer clase");

	//declarar variables
	int numeroUno;
	int numeroDos;
	int suma;

	//pedir al usuario
	printf("\nIngrese el numero Uno : \n");
	scanf("%d",&numeroUno);
	printf("\nIngrese el numero Dos: \n");
	scanf("%d",&numeroDos);

	//calcular
	suma = numeroUno - numeroDos;

	//mostrar resultado
	printf("\nLa resta es %d", suma);

	return EXIT_SUCCESS;
}