/*
 ============================================================================
 Name        : Lab_CL5Array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define EDADES_MAX 5

void imprimirArrayDeEdades(int pEdades[], int max);
void inicializarArrayDeEdades(int pEdades[],int len,int valorinicial);

//float pedirNumeroAlUsuario2(float* pResultado,float min, float max);
//int pedirFloatAUsuario6(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);

int main(void)
{
	float v;
	float edades[5];
	int i=0;

	//printf("\nEn main ingreso %f",d);

	inicializarArrayDeEdades(edades, EDADES_MAX, 0);
	imprimirArrayDeEdades(edades, EDADES_MAX);

	return EXIT_SUCCESS;
}
/**
 *
 *
 *
 */

/**
 brief realiza una resta
	 * param me da el 1er numero para realizar la operacion resta
	 * param me da el 2do numero para realizar la operacion resta
	 * return me devuelve el resultado de la resta
	 * */






void inicializarArrayDeEdades(int pEdades[],int len,int valorinicial)
{
	int i=0;
	int v=0;
	for (int i = 0; i< EDADES_MAX; i++)
		{
			pEdades[i]=valorinicial;
			v++;
		}
}

void imprimirArrayDeEdades(int pEdades[], int max) //solo paso la direccion de memoria o int* pArrayEdades
{
	int i=0;
	for (int i = 0; i < EDADES_MAX; i++)
		{
			printf ("\n%d",pEdades[i]);
		}
}
/*

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


float pedirNumeroAlUsuario2(float* pResultado,float min, float max)
{
	int estado;
	float numero;
	printf("Ingrese numero:"); // OK
	scanf("%f",&numero);
	printf("en funcion es %f",numero);


	if(numero>=min && numero<=max)
	{
		// estoy dentro del rango
		*pResultado = numero; // escribo en la var externa
		estado=0;
		__fpurge(stdin);
		printf("\nen f despues de puntero es %f",*pResultado);// OK
	}
	else
	{
		estado=1; // ERROR
	}

	return estado;
}

int pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
{
	float buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pResultado != NULL && min<max && reintentos >=0 && variableTexto != NULL && textoError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			salidaScanf=scanf("%f", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{

				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-1;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}
*/
