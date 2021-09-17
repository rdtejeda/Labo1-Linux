/*
 *  Mi-utn.c
 *
 *  Created on: 11 sep. 2021
 *  Author: Tejeda Roberto
 */
//Como Documentar cada funcióm
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Mi-utn.h"
#define INTENTOS 3


/**
* \brief pide un int, intentos y mensajes
* \param recibe min, max, intento y mensajes a mostra y erro, puntero int de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
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
			//printf("\nLa salida del scanf es : %d\n\n",salidaScanf);
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
int cargarArrayFloat(float pArray[], int ext)
{
	float a;
	int b;
	//pedir posicion PERSONALIZAD PAR EJERCISIO DE TEMP
	pedirNumeroIntconMaxyMin(&b, 1, 31, INTENTOS, "Ingreso el día", "ERROR - Entre 1 y 31");
	pedirNumeroFloatconMaxyMin(&a, -60, 60, INTENTOS, "Ingrese la temperatura", "Error- Entre -60 y 60 ºC");
	//transform posicion
	b--;
	//cargar en la posicion
	pArray[b]=a;
	return b;
}
/**
* \brief imprime un array flot
* \param Array, extencion
* \return
*/
void imprimirArrayFloat(float pArray[],int ext)
{
	for(int i=0; i<ext; i++)
	{
		printf("%f\n",pArray[i]);
	}
}
/**
* \brief Iniciciliza un array flot
* \param Array, extencion y el valor inicial
* \return
*/
void inicializarArrayFloat(float pArray[],int ext,float valorInicial)
{
	for(int i=0; i<ext; i++)
	{
		pArray[i]=valorInicial;
	}
}
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
/**
* \brief Divide dos numero float y verifica no dividir por 0
* \param recibe dos float, puntero float de resultado
* \return Retorna 1 (salio bien) y 0 (salio mal) No dividir por 0
*/
int dividirFloat(float x,float y,float* z) //pasaje por referencia
{
	int retorno = 0;
	if(y !=0)
	{
		*z =x / y;
	}
	else
	{
		retorno = -1;
	}
	return retorno;
}
/**
* \brief Divide dos numero enteros y verifica no dividir por 0
* \param recibe dos enteros, puntero float de resultado
* \return Retorna 1 (salio bien) y 0 (salio mal) No dividir por 0
*/
int dividirEnteros(int x,int y,float* z) //pasaje por referencia
{
	int retorno = 0;
	if(y !=0)
	{
		*z =(float)x / y;
	}
	else
	{
		printf("\nError: División por cero\n");
		retorno = -1;
	}
	return retorno;
}
/**
* \brief imprime un entero
* \param recibe un char y un int
* \return
*/
void imprimirNumeroInt(char txt[],int x)
{
	printf("\n%s %d\n",txt,x);
	__fpurge(stdin);
}
/**
* \brief imprime un numero float con 4 decimales
* \param recibe un char y un int
* \return
*/
void imprimirNumeroFloat(char txt[],float x)
{
	printf("\n%s %.4f\n",txt,x);
	__fpurge(stdin);
}









