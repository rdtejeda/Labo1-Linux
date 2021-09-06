/*
 ============================================================================
 Name        : C01-E004.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Escribir un programa que realice las siguientes acciones:

- Solicite al usuario 10 números
- Calcule cuántos son negativos y cuantos son positivos
- Muestre por pantalla la cantidad de negativos y la cantidad de positivos
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int main(void) {
	int i;
	int numero;
	int cantidadPositivos=0;
	int cantidadNegativos=0;
	for (i=0;i<10;++i)
	{
		printf("\nIngrese el numero: \n");
		__fpurge(stdin);
		scanf("%d",&numero);
		printf("el tamao de numero es %d\n",sizeof(numero));
		printf("la direccio de numero es %d\n",&numero);
		if(numero>0)
		{
			cantidadPositivos++;
		}
		if (numero<0)
		{
			cantidadNegativos++;
		}
	}
	printf("\nLa cantidad de numero positivos ingresados es %d\n",cantidadPositivos);
	printf("\nLa cantidad de numero negativos ingresados es %d\n",cantidadNegativos);
	return EXIT_SUCCESS;
}
