/*
 ============================================================================
 Name        : Clase04.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

float dividir(float a, float b, float* pResultado);

int main(void)
{
	setbuf(stdout,NULL);
	float r;
	float estado;
	estado = dividir(10, 4.33, &r); //retur devolver por valor y &por diferencia

	if(estado==0)
	{
		printf("El valor de la division es: %.3f",r);
	}else
	{
		printf("No es posible dividir por 0");
	}

	return EXIT_SUCCESS;
}
float dividir(float a, float b, float* pResultado)
{
	float resultado;
	int estado;
	if(b!=0)
	{
		resultado = a/b;
		estado=0;
	}else
	{
		estado=1;
	}
	*pResultado = resultado;
	return estado;
}


