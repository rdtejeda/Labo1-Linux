/*
 * Pedir.c
 *
 *  Created on: 16 sep. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "Mi-utn.h"
#include "Operar.h"
#include "Matriz.h"
#include "Pedir.h"
#include "Txt.h"

static int dameUnIdNuevo(void);

//==============================================================================
/**
  * \brief te da un entero consecutivo y lo recuerda
  * \param VOID
  * \return Retorna un entero desde 1 y lo recuerda
  */
static int dameUnIdNuevo(void)
{
	static int contador=0; //varable Global y solo de esta funcio
	contador++;
	return contador;
}
//==================================================================================================
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int pedirInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
{
	int retorno = -1;
	int bufferInt;
	int i;
	char bufferCadenaAux[32];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
	{
		for(i=0; i<=intentos; i++)
		{
			printf("\n%s\n", mensaje);
			__fpurge(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNumericaInt(bufferCadenaAux)==0)
					{
					bufferInt = atoi(bufferCadenaAux);
					if(bufferInt >= minimo && bufferInt <= maximo)
						{
							*pResultado = bufferInt;
							retorno = 0;
							break;
						}else
							{
							printf("%s", mensajeError);
							}
					}
				else
					{
					printf("%s", mensajeError);
					}
			}
			else
				{
				printf("%s", mensajeError);
				}
		}
		if(retorno==-1)
		{
			printf("\nTe quedaste sin intentos\n");
		}
	}
	return retorno;
}
//=====================================================================================================
/**
* \brief pide un char al ususario
* \param puntero cahr, reintentos y textos de pedido y erro
* \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
int pedirCharAUsuario(char* pChar, int reintentos, char* txt, char* txtError)
{

	int retorno=-1;
	int i;
	char bufferCadenaAux[32];
	if(pChar != NULL && reintentos >=0 && txt != NULL && txtError != NULL)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("\n%s\n", txt);
			__fpurge(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
				{
				//if(es loque necesite)
				strncpy(pChar, bufferCadenaAux,1);
					retorno = 0;
					break;
				}else
				{
						printf("%s", txtError);

				}
		}
	}
	return retorno;
}
//================================================================================================================================================
/**
* \brief pide un texto al ususario
* \param puntero cahr, reintentos y textos de pedido y error , intentos
* \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
int pedirText(char* pResultado, int len, char* mensaje, char* mensajeError, int intentos)
{
	int retorno = -1;
	int i;
	char bufferCadenaAux[32];//esto
	for(i=0; i<=intentos; i++)
	{
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && intentos >= 0)
		{

			printf("\n%s\n", mensaje);
			__fpurge(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				strncpy(pResultado, bufferCadenaAux,len);
				//if(es loque necesite)
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}
//==================================================================================================
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int pedirFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int intentos)
{
	int retorno = -1;
	float bufferInt;
	int i;
	char bufferCadenaAux[32];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && intentos >= 0)
	{
		for(i=0; i<=intentos; i++)
		{
			printf("\n%s\n", mensaje);
			__fpurge(stdin);
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNumericaFloat(bufferCadenaAux)==0)
					{
					bufferInt = atof(bufferCadenaAux);
					if(bufferInt >= minimo && bufferInt <= maximo)
						{
							*pResultado = bufferInt;
							retorno = 0;
							break;
						}else
							{
							printf("%s", mensajeError);
							}
					}
				else
					{
					printf("%s", mensajeError);
					}
			}
			else
				{
				printf("%s", mensajeError);
				}
		}
		if(retorno==-1)
		{
			printf("\nTe quedaste sin intentos\n");
		}
	}
	return retorno;
}
//=====================================================================================================
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero  y -1 (ERROR) si no
*/
int esNumericaInt(char* cadena)
{
	int i=0;
	int retorno=-1;
	if(cadena!=NULL && strlen(cadena)> 0)
	{
		retorno=0;
		while(cadena[i]!='\0')
			{
				if(cadena[i]<'0'||cadena[i]> '9')
					{
					retorno=-1;
					break;
					}
				i++;
			}
	}
	return retorno;
}
//=========================================================================================================
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
*/
int esNumericaFloat(char* cadena)
{
	int i=0;
	int retorno = -1;
	int contNeg=0;
	int contPuntos=0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		retorno=0;
		while(cadena[i] != '\0')
			{
				if(cadena[i] < '0' || cadena[i] > '9')
					{
					if(cadena[i]=='-' || cadena[i]=='.')
						{
							if(cadena[i]=='-')
							{
								contNeg++;
								if(i!=0)
								{
									retorno = -1;
									break;
								}
							}
							if(cadena[i]=='.')
							{
								contPuntos++;
							}
						}else
						{
							retorno = -1;
							break;
						}
					}
				i++;
			}
		if(contNeg>1 ||contPuntos>1)
		{
			retorno=-1;
		}
	}
	return retorno;
}
//=====================================================================================================
/**
 * \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param len Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*/
int myGets(char pResultado[], int len)
{
	int retorno=-1;
	int indexFinal;
	//__fpurge(stdin);
	if(fgets(pResultado,len,stdin)!=NULL)
	{
		__fpurge(stdin);
		indexFinal = strlen(pResultado)-1;
		if(pResultado[indexFinal] == '\n')
			{
			pResultado[indexFinal] = '\0';
			}
		retorno = 0;
	}
	return retorno;
}
//====================================================================================================

























//==============================================================================================
/*
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	int i;

	for(i=0; i<=reintentos; i++)
	{
		if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
		{
			printf("%s", mensaje);
			__fpurge(stdin);

			//gets(pResultado); // NOOOOOOO
			//if(scanf("%s", pResultado)==1) // NOOOOOOO
			//if(fgets(pResultado,len,stdin)!=NULL)
			if(myGets(pResultado, len)==0)
			{
				retorno = 0;
				break;
			}
			else
				printf("%s", mensajeError);
		}
	}
	return retorno;
}
*/
//==================================================================================================
/**
* \brief pide un cadenaal ususario
* \param puntero cahr, reintentos y textos de pedido y erro
* \return Retorna -1  salio mal, 0 salio bien y 2 sin reintento
*/
/*
int pedirTextoAUsuario(char* pChar, int len; int reintentos, char* txt, char* txtError)
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
*/

//===================





/**
* \brief pide un int, sin  minimos y max, intentos y mensajes
* \param recibe , intento y mensajes a mostra y erro, puntero int de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
/*
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
			printf("%s\n",txt);
			__fpurge(stdin);
			salidaScanf=scanf("%d", &buffer);
			//printf("\nLa salida del scanf es : %d\n",salidaScanf);
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
*/
/**
* \brief pide un int, con minimos y max, intentos y mensajes
* \param recibe min, max, intento y mensajes a mostra y erro, puntero int de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
/*
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
*/
/**
* \brief Meter un valor al array
* \param array, extension
* \return posicio y por puntero la direccion del valor
*/

/**
* \brief pide un float, con minimos y max, intentos y mensajes
* \param recibe min, max, intento y mensajes a mostra y erro, puntero float de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
/*
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
*/
/**
* \brief pide un float, con minimos y max, intentos y mensajes
* \param recibe min, max, intento y mensajes a mostra y erro, puntero float de resultado
* \return Retorna 1 salio mal, 0 salio bien y 2 sin reintento
*/
/*
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
*/
