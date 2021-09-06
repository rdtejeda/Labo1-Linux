/*
 * utn.c
 *
 *  Created on: 5 sep. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int dividir(float a,float b,float*pResultado)// FORMATO FUNCION
{
	//resultado flotante;
	int estado;
	float resultado;
	printf ("a vale:%.2f b vale:%.2f pResultado:%p\n",a, b, pResultado);

	if (b != 0)
	{
	resultado = a / b;
	estado = 0; // OK
		// devuelvo resultado
		// escribir la variable externa, que no tengo acceso
		// pero tengo la direccion
		* pResultado = resultado; // escribiendo "r"
	}else
	{
	estado = 1; // ERROR
	}
	return estado;
}

