/*
 * Operar.c
 *
 *  Created on: 16 sep. 2021
 *      Author: usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#include "Mi-utn.h"
#include "Matriz.h"
#include "Pedir.h"
#include "Txt.h"
#include "Operar.h"
//==================================================================================================
/**
* \brief Calcula el factorial de numero naturales igual o mayor a 0
* \param recibe natural valor del factorial por puntero
* \return return Retorna 0 (salio bien) y -1 (salio mal)
*/
int factorial(int* result, int valor)
{
	int estado=-1;
	if (valor < 0)
	{
		printf("\nError: Parametro fuera de rango\n");
	}else
		{
		if(valor==1 || valor==0)
			{
			*result = 1;
			estado=0;
			}else
			{
				*result=valor*(valor-1);
				while(valor>2)
					{
					valor--;
					*result=*result*(valor-1);
					}
			estado=0;
			}
		printf("\nEl factorial es %d\n",*result);
	}
	return estado;
}
//==================================================================================================
/**
* \brief suama dos numeros entero
* \param recibe dos enteros resultado por puntero
* \return return Retorna 0 (salio bien) y -1 (salio mal)
*/
int sumaInt(int* z, int x, int y)
{
	int estado=-1;
	*z=x+y;
	estado=0;
	return estado;
}
//==================================================================================================
/**
* \brief Divide dos numero float y verifica no dividir por 0
* \param recibe dos float, puntero float de resultado
* \return Retorna 1 (salio bien) y 0 (salio mal) No dividir por 0
*/
int dividirFloat(float* z, float x,float y)
{
	int estado = -1;
	if(y !=0 && z!=NULL)
	{
		*z =x / y;
		estado=0;
	}
	else
	{
		printf("\nError: División por cero\n");
	}
	return estado;
}
//==================================================================================================
/**
* \brief Divide dos numero enteros y verifica no dividir por 0
* \param recibe dos enteros, puntero float de resultado
* \return Retorna 0 (salio bien) y -1 (salio mal) No dividir por 0
*/
int dividirInt(float* z,int x,int y) //pasaje por referencia
{
	int estado = -1;
	if(y!=0 && z!=NULL)
	{
		*z =(float)x / y;
		estado=0;
	}
	else
	{
		printf("\nError: División por cero\n");
	}
	return estado;
}
//==================================================================================================
/**
 * \brief verifica par
 * \param recibe entero
 * \return Retorna 0 (salio bien) y -1 (salio mal) No dividir por 0
*
*/
int VerificarParidad(int x)
{
	int estado=-1;
	if (x%2==0)
	{
		estado=0;
	}
	return estado;
}
//==================================================================================================
/**
* \brief suama dos float
* \param recibe dos float resultado por puntero
* \return return Retorna 0 (salio bien) y -1 (salio mal)
*/
int sumaFloat(float* z, float x, float y)
{
	int estado=-1;
	if(z !=NULL)
	{
		*z=x+y;
		estado=0;
	}
	return estado;
}
//==================================================================================================
/**
* \brief resta dos float
* \param recibe dos float resultado por puntero
* \return return Retorna 0 (salio bien) y -1 (salio mal)
*/
int restaFloat(float* z, float x, float y)
{
	int estado=-1;
	if(z != NULL)
	{
		*z=x-y;
		estado=0;
	}
	return estado;
}
//==================================================================================================
/**
* \brief multipluica dos float
* \param recibe dos float resultado por puntero
* \return return Retorna 0 (salio bien) y -1 (salio mal)
*/
int multiplicacionFloat(float* z, float x, float y)
{
	int estado=-1;
	if(z != NULL)
	{
		*z=x*y;
		estado=0;
	}
	return estado;
}
//==================================================================================================
/**
* \brief Calcula el factorial de numero naturales igual o mayor a 0
* segun el APUNTE RECURSIVA
* \param recibe natural valor del factorial por puntero
* \return return Retorna 0 (salio bien) y -1 (salio mal)
*/
int factorialApunte(int n)
{
	int resp=1;
	if(n==1)
	{
	return resp;
	}
	resp=n*factorialApunte(n-1);
	return (resp);
}
//==================================================================================================
