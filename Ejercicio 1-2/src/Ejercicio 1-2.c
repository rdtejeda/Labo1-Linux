/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Tejeda R
 Version     :
 Copyright   : Your copyright notice
 Description :Ejercicio 1-2:
Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en qué orden
fue ingresado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout,NULL);
	int numeroIngresado; //pedir numero entero
	int i=1;
	int banderaMax=1;
	int numeroMax;
	int banderaMin=1;
	int numeroMin;
	int ordenMax;
	int ordenMin;
	//Pedido 5 numeros
	for (int i = 1; i < 6; ++i) {
		printf("\nIngrese el numero: \n");//pido el entero
		scanf("%d",&numeroIngresado); //cargo valor a la variable
		if(banderaMax) //busco el max
		{
			banderaMax=0;
			numeroMax=numeroIngresado;
			ordenMax=i;
		}
			else
			{
				if (numeroIngresado>numeroMax)
				{
					numeroMax=numeroIngresado;
					ordenMax=i;
				}
			}
		if(banderaMin) //busco el min
				{
					banderaMin=0;
					numeroMin=numeroIngresado;
					ordenMin=i;
				}
					else
					{
						if (numeroIngresado<numeroMin)
						{
							numeroMin=numeroIngresado;
							ordenMin=i;
						}
					}
	}
	//Mostramos resultados
	printf("\nEl máximo es %i y el orden de ingreso fue %i", numeroMax,ordenMax);
	printf("\nEl mínimo es %i y el orden de ingreso fue %i", numeroMin,ordenMin);
	return EXIT_SUCCESS;
}
