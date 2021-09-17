/*
 * Pedir.c
 *
 *  Created on: 16 sep. 2021
 *      Author: usuario
 */
/**
* \brief pide un int, intentos y mensajes
* \param recibe min, max, intento y mensajes a mostra y erro, puntero int de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "Mi-utn.h"
#include "Operar.h"
#include "Matriz.h"

int pedirNumeroInt(int* px, int intentos, char* txt, char* txtError)
{
	int buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(px != NULL && intentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=intentos; i++)
		{
			printf("%s",txt);
			__fpurge(stdin);
			salidaScanf=scanf("%d", &buffer);
			printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0)
			{
				retorno = 0; // OK
				*px=buffer;
				break;
			}
			else
				{
					retorno=-2;
					printf("%s\n",txtError);
				}
		}

	}
	return retorno;
}
/**
* \brief pide un int, con minimos y max, intentos y mensajes
* \param recibe min, max, intento y mensajes a mostra y erro, puntero int de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
int pedirNumeroIntconMaxyMin(int* px, int min, int max, int intentos, char* txt, char* txtError)
{
	int buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(px != NULL && min<max && intentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=intentos; i++)
		{
			printf("%s",txt);
			__fpurge(stdin);
			salidaScanf=scanf("%d", &buffer);
			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*px=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",txtError);
			}
		}
	}
	return retorno;
}
/**
* \brief Meter un valor al array
* \param array, extension
* \return posicio y por puntero la direccion del valor
*/
/**
* \brief pide un char al ususario
* \param puntero cahr, reintentos y textos de pedido y erro
* \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
int pedirCharAUsuario(char* pChar, int reintentos, char* txt, char* txtError)
{
	char buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(pChar != NULL && reintentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",txt);
			salidaScanf=scanf("%c", &buffer);
			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0) //&& buffer != NULL
			{
				retorno = 0; // OK
				*pChar=buffer;
				printf("el caracter es %c \n",buffer);
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",txtError);
			}
		}
	}
	return retorno;
}
/**
* \brief pide un float, con minimos y max, intentos y mensajes
* \param recibe min, max, intento y mensajes a mostra y erro, puntero float de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
int pedirNumeroFloat(float* px, int intentos, char* txt, char* txtError)
{
	float buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(px != NULL && intentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=intentos; i++)
		{
			printf("%s",txt);
			__fpurge(stdin);
			salidaScanf=scanf("%f", &buffer);

			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0)
			{
				retorno = 0; // OK
				*px=buffer;
				//printf("%.4f\n", buffer);
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",txtError);
			}
		}
	}
	return retorno;
}
/**
* \brief pide un float, con minimos y max, intentos y mensajes
* \param recibe min, max, intento y mensajes a mostra y erro, puntero float de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
int pedirNumeroFloatconMaxyMin(float* px, float min, float max, int intentos, char* txt, char* txtError)
{
	float buffer;
	int retorno=-1;
	int i;
	int salidaScanf;
	if(px != NULL && min<max && intentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=intentos; i++)
		{
			printf("%s",txt);
			__fpurge(stdin);
			salidaScanf=scanf("%f", &buffer);
			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
			if (salidaScanf>0 && buffer>=min && buffer<=max)
			{
				retorno = 0; // OK
				*px=buffer;
				break;
			}
			else
			{
				retorno=-2;
				printf("%s\n",txtError);
			}
		}
	}
	return retorno;
}
