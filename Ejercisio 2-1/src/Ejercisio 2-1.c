/*
 ============================================================================
 Name        : Ejercisio 2-1
 Author      : Tejeda
 Version     : 1
 Copyright   : Your copyright notice
 Description : Clase 2
Ejercicio 2-1:
Crear una función que reciba como parámetro un numero entero.
La función retornara 1 en caso de que sea positivo, -1 en caso de que sea negativo y 0 en caso de que sea 0.
Realizar la prueba lógica de la función en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int VerificaCeroPositivoNegativo (int numIngresado);

int main(void)
{
	int numero;
	int estado;
	printf("Ingrese un numero entero\n");
	__fpurge(stdin);
	scanf("%d,",&numero);
	estado = VerificaCeroPositivoNegativo(numero);
	if (estado>0)
	{
		printf("Ingreso un entero positivo\n");
	}else
		{
		if(estado<0)
			{
			printf("Ingreso un entero negativo\n");
			}else
				{
				printf("Ingreso un CERO\n");
				}
		}
	return EXIT_SUCCESS;
}

int VerificaCeroPositivoNegativo (int numIngresado)
{
	int estado;
	if (numIngresado>0)
	{
		estado=1;
	}else
		{
		if (numIngresado<0)
			{
			estado=-1;
			}else
				{
				estado=0;
				}
		}
	return estado;
}
