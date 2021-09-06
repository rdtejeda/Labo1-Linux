	/*
 ============================================================================
 Name        : Hola.c
 Author      : Tejeda Roberto
 Version     : División 1-H
 Copyright   : Your copyright notice
 Description : Clase 1 - Ejercicio #001 in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumarEnteros(int numUno,int numDos);

int main(void) {

	int numeroUno;
	int numeroDos;
	int resultado;
	float promedio;

	printf("\nIngrese el número uno : \n");
	scanf("%d",&numeroUno);

	printf("\nIngrese el número dos : \n");
	scanf("%d",&numeroDos);

	resultado = sumarEnteros(numeroUno, numeroDos);
	promedio=(float)resultado/2;

	printf("\nEl resultado de la suma %d", resultado);
	printf("\nEl resultado del promedio %f", promedio);
	return EXIT_SUCCESS;
}
int sumarEnteros(int numUno,int numDos)
	{
		int retorno;
		retorno=numUno+numDos;
		return  retorno;
	}
