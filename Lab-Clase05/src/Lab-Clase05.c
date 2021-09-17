/*
 ============================================================================
 Name        : Lab-Clase05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define REINTENTOS 3

int pedirFloatAUsuario(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);
int main (void)
{
	float r;
	float estado;
	float num1,num2;

	printf("r vale:%f y la direccion es:%f\n",r,&r);

	if (pedirFloatAUsuario(&num1, 0.01, 1000, REINTENTOS, "Primer numero", "Mas de 0 y menos de 1000")==0)
	{
		printf("Ingresaste %f:\n",num1);

		if(pedirFloatAUsuario(&num2,0.01,1000.0,REINTENTOS, "Segundo numero", "Mas de 0 y menos de 1000")==0)//V6
		{
			printf("Ingresaste %f:\n",num2);

			estado = num1/num2;

			printf("El resultado da:%f",estado);
		}else
			{
			printf("numero 2 erroneo, no puedo seguir con el programa");
			}
	}else
	{
		printf("numero 1 erroneo, no puedo seguir con el programa");
	}

}
//Version 7 con validacion de casi tode
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


//pedirIntAlUsuario
int pedirIntAUsuario(int* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
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

			printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{

				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}
//pedirCharAlUsuario
int pedirCharAUsuario(char* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError)
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

			printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{

				retorno = 0; // OK
				*pResultado=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",textoError);
			}
		}
	}
	return retorno;
}
