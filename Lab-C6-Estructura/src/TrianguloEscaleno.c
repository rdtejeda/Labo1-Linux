/*
 * TrianguloEscaleno.c
 *
 *  Created on: 29 sep. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "TrianguloEscaleno.h"

//A - Crear una función llamada "trianguloMostrarPorValor()" que reciba como parámetro un tipo de dato eTrianguloEscaleno por valor e imprima su contenido. No retorna nada.
void trianguloMostrarPorValor(TrianguloEscaleno unTriangulo)
{
    printf("\nPor valor\nLado 1 %.4f, Lado2 %.4f, Lado3 %.4f\n", unTriangulo.lado1, unTriangulo.lado2, unTriangulo.lado3);
}

//B - Crear una función llamada "trianguloMostrarPorReferencia()" que reciba como parámetro un tipo de dato eTrianguloEscaleno por referencia e imprima su contenido. No retorna nada.
void trianguloMostrarPorReferencia(TrianguloEscaleno* punTriangulo)
{
     printf("\nPor refernecia\nLado 1 %.4f, Lado2 %.4f, Lado3 %.4f\n", punTriangulo->lado1, punTriangulo->lado2, punTriangulo->lado3);
}

//C - Crear una función llamada "trianguloCarga()"que reciba como parámetro un tipo de dato eTrianguloEscaleno por referencia
//y dentro pida al usuario cada uno de sus miembros (cada uno de sus lados). Retornará 0 (cero) por algún error - 1 (uno) todo OK.


int trianguloCarga(TrianguloEscaleno *unTriangulo)
{
   int estado=-1;
   float lado1Aux;
   float lado2Aux;
   float lado3Aux;

   if (pedirFloat(&lado1Aux, "Entre lado 1","No es float",-1000, 1000,5)==0)
   {
	   if(pedirFloat(&lado2Aux, "Entre lado 2","No es float",-1000, 1000,5)==0)
	   {
		   if (pedirFloat(&lado3Aux, "Entre lado 3","No es float",-1000, 1000,5)==0)
		   {
			   unTriangulo->lado1 = lado1Aux;
			   unTriangulo->lado2 = lado2Aux;
			   unTriangulo->lado3 = lado3Aux;
			   estado=0;
		   }
	   }
   }
   return estado;
}

//D - Crear una función llamada "trianguloPerimetro()" que reciba como parámetro un tipo de dato eTrianguloEscaleno por referencia
//y calcule el perímetro del mismo. Retornara el perímetro del mismo.

float trianguloPerimetro(TrianguloEscaleno *unTriangulo)
{
    //float perimetro;

    return unTriangulo->lado1+unTriangulo->lado2+unTriangulo->lado3;

    //return perimetro;
}

//E - Crear una función llamada "trianguloArea()" que reciba como parámetro un tipo de dato eTrianguloEscaleno por referencia
//y calcule el área del mismo. Retornara el área del mismo.

float trianguloArea(TrianguloEscaleno *unTriangulo)
{
	float area;
	 area= (unTriangulo->lado1*unTriangulo->lado2)/2;
	return area;
}



//============================================================================================
/**
 * \brief Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param minimo Es el numero maximo a ser aceptado
 * \param maximo Es el minimo minimo a ser aceptado
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int pedirFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos)
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
//=========================================================================================================
/**
* \brief Verifica si la cadena ingresada es numerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
*/
int esNumericaFloat(char *cadena)
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


