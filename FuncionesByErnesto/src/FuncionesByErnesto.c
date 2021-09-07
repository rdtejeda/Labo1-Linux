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


int main (void)
{
	float r;
	int estado;
	float num1,num2;

	//printf("r vale:%f y la direccion es:%f\n",r,&r);

	//if(pedirFloatAUsuario4(&num1,0.0,1000.0,REINTENTOS)==0) //V3y4
	if (pedirFloatAUsuario5(&num1, 0.01, 1000, REINTENTOS, "Primer numero")==0) //V5
	{
		printf("Ingresaste %f:\n",num1);

		//if(pedirFloatAUsuario4(&num2,0.01,1000.0,REINTENTOS)==0)//V3y4
		//if(pedirFloatAUsuario5(&num2,0.01,1000.0,REINTENTOS, "Segundo numero")==0)//V5
		if(pedirFloatAUsuario6(&num2,0.01,1000.0,REINTENTOS, "Segundo numero", "Mas de 0 y menos de 1000")==0)//V6
		{
			printf("Ingresaste %f:\n",num2);

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

//---------------------------------------------------------------------
/* //SOLO PIDE DIVIDIR en Libreria
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
}*/

/*//---------------------------------------------------------------------
//PEDIR NUMERO V1

void pedirNumeroAlUsuario1(float* pResultado)
{
	printf("Ingrese numero:"); // OK
	//float aux;
	//scanf("%f",&aux);
	//*pResultado = aux;
	scanf("%f",pResultado);
}
*/

/*//---------------------------------------------------------------------
//PEDIR NUMERO V2
int pedirNumeroAlUsuario2(float* pResultado,float min, float max)
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
}*/
