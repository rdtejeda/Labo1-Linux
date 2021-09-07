/*
 * utn.c
 *
 *  Created on: 5 sep. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

//DIVIDIR DOS ENTEROS
int dividir(float a,float b,float*pResultado)// FORMATO FUNCION
{
	//resultado flotante;
	int estado;
	float resultado;
	//printf ("a vale:%.2f b vale:%.2f pResultado:%p\n",a, b, pResultado);

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
//----------------------------------------------------------------------
//PEDIR NUMERO FLOAT V3 entre min y max con reintentos
int pedirFloatAUsuario3(float* pResultado, float min, float max, int reintentos)
{
	float aux;
	int retorno;
	int i;
	for (i=0; i<=reintentos; i++)
	{
		printf("Ingrese numero:\n");
		scanf("%f", &aux);

			if (aux>=min && aux<=max)
			{
				retorno = 0; // OK
				*pResultado=aux;
				break;
			}
			else
			{
				retorno = 1;
				printf("Numero fuera de rango\n");
			}
	}
	return retorno;
}
//--------------------------------------------------------------------
//PEDIR NUMERO V4 entre min y max con reintentos
int pedirFloatAUsuario4(float* pResultado, float min, float max, int reintentos)
{
	float aux;
	int retorno=1;
	int i;
	if(min<max)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("Ingrese numero:\n");
			scanf("%f", &aux);

			if (aux>=min && aux<=max)
			{
				retorno = 0; // OK
				*pResultado=aux;
				break;
			}
			else
			{
				retorno = 1;
				printf("Numero fuera de rango\n");
			}
		}
	}
	return retorno;
}
//--------------------------------------------------------------------
//Pedir numero v5 entre min y max con reintentos y con Texto del pedido
int pedirFloatAUsuario5(float* pResultado, float min, float max, int reintentos, char* variableTexto)
{
	float aux;
	int retorno=1;
	int i;
	if(min<max)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			scanf("%f", &aux);

			if (aux>=min && aux<=max)
			{
				retorno = 0; // OK
				*pResultado=aux;
				break;
			}
			else
			{
				retorno = 1;
				printf("Numero fuera de rango\n");
			}
		}
	}
	return retorno;
}
//--------------------------------------------------------------------
//agregar a la funcion , para hacer la V6. que reciba el argumento del mensaje de error, que se imprime cuando la funcion detecta que el numero ingresado esta fuera de rango.
//Pedir numero v6 entre min y max con reintentos y con Texto del pedido y pasar mensaje de error
int pedirFloatAUsuario6(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float aux;
	int retorno=1;
	int i;
	if(min<max)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			scanf("%f", &aux);

			if (aux>=min && aux<=max)
			{
				retorno = 0; // OK
				*pResultado=aux;
				break;
			}
			else
			{
				retorno = 1;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}
