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

int main(void)
{

	setbuf(stdout,NULL);
		int numeroUno;
		int numeroDos;
		int resultado;
		float promedio;
		float impuestos;
		float impuestoresultado;

		printf("ingrese el valor de la priemra compra : \n");
		scanf("%d",&numeroUno);

		printf("ingrese el valor de la segunda compra : \n");
		scanf("%d",&numeroDos);

		resultado = numeroUno+numeroDos;
		promedio=(float)resultado/2;

		printf("El resultado de la suma %d", resultado);
		printf("El resultado del promedio %.2f", promedio);

		printf("ingrese los impuestos abonadoa : \n");
		scanf("%f",&impuestos);

		impuestoresultado=impuestos+resultado;

	return EXIT_SUCCESS;
}


int sumarEnteros(int numUno,int numDos)
	{
		int retorno;
		retorno=numUno+numDos;
		return  retorno;
	}
int restaEnteros(int numUno,int numDos)
	{
	int retorno;
	retorno=numUno-numDos;
	return retorno;
	}
int dividirEnteros(int numUno,int numDos)
	{
	int retorno;
	if (numUno != 0)
		{
		retorno=numUno/numDos;
		}
	return retorno;
	}
int factorial (int numUno)
	{
	int retorno;
	retorno=factorial(numUno);
	return retorno;
	}
// factorial
