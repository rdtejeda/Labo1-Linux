/*
 ============================================================================
 Name        : FuncionesByErnesto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"

#define REINTENTOS 3


//EJEMPLO PEDIR DIVIDIR
//-------------------------------------------------------------------
int main (void)
{
	int estado;
	float r;

	estado=dividir(45,4,&r);
	if (estado == 0)
	{
		// pude dividir
		printf ("El resultado da:%3f",r);
	}
	else
	{
		printf ("No se puede dividir\n");
	}
	return EXIT_SUCCESS;
}



//----------------------------------------------------------------------
//PEDIR NUMERO V3
/*
int pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos);

int main (void)
{
	float r;
	int estado;
	float num1,num2;

	printf("r vale:%f y la direccion es:%f\n",r,&r);

	if(pedirFloatAUsuario(&num1,0.0,1000.0,REINTENTOS)==0)
	{
		printf("Ingresaste %f:\n",num1);

		if(pedirFloatAUsuario(&num2,0.01,1000.0,REINTENTOS)==0)
		{
			printf("Ingresaste %f:",num2);

			estado = dividir(num1,num2,&r);
			if(estado==0)
			{
				// pude dividir
				printf("El resultado da:%f",r);
			}
			else
			{
				printf("No se puede dividir\n");
			}
		}
		else
		{
			printf("ese numero noooooo");
		}
	}
	else
	{
		printf("ese numero noooooo, no puedo seguir con el programa");

	}
}
*/
//---------------------------------------------------------------------
//PEDIR NUMERO V1
void pedirNumeroAlUsuario(float* pResultado)
{
	printf("Ingrese numero:"); // OK
	//float aux;
	//scanf("%f",&aux);
	//*pResultado = aux;

	scanf("%f",pResultado);
}
//---------------------------------------------------------------------
//PEDIR NUMERO V2

int pedirNumeroAlUsuario1(float* pResultado,float min, float max)
{
	int estado;
	printf("Ingrese numero:"); // OK
	float numero;
	scanf("%f",&numero);

	if(numero>=min && numero<=max)
	{
		// estoy dentro del rango
		*pResultado = numero; // escribo en la var externa
		estado=0;// OK
	}
	else
	{
		estado=1; // ERROR
	}

	return estado;
}
//----------------------------------------------------------------------
//PEDIR NUMERO FLOAT V3
int pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos)
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
//PEDIR NUMERO V4
int pedirFloatAUsuario2(float* pResultado, float min, float max, int reintentos)
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
//Pedir numero v5
int pedirFloatAUsuario3(float* pResultado, float min, float max, int reintentos, char* variableTexto)
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
//---------------------------------------------------------------------
//agregar a la funcion , para hacer la V6. que reciba el argumento del mensaje de error, que se imprime cuando la funcion detecta que el numero ingresado esta fuera de rango.
