/*
 * Matriz.c
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

/**
* \brief Verifica si la cadena ingresada es email
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
*/
int eseMail(char* cadena)
{
	int i=0;
	int retorno = 0;
	int contararroba=0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if((cadena[i]<48||cadena[i]>57)&&(cadena[i]< 65||cadena[i]>90)&&(cadena[i]<97||cadena[i]>122))//0-9 48-57 A-Z 65-90 a-z 97-122
					{
						if(cadena[i]==46||cadena[i]==64)// . 46 @ 64
						{
							if(cadena[i]==64)//@64
							{
							contararroba++;
							}
							if(i==0)
							{
								retorno = -1;
								break;
							}
						}else
							{
								retorno = -1;
								break;
							}
					}
				i++;
			}
		if(contararroba>1)
		{
			retorno=-1;
		}
	}
	return retorno;
}
/**
* \brief Verifica si la cadena ingresada es alfanumerica
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es
*/
int esAlfaumerica(char* cadena)
{
	int i=0;
	int retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if((cadena[i]<48||cadena[i]>57)&&(cadena[i]< 65||cadena[i]>90)&&(cadena[i]<97||cadena[i]>122))//0-9 48-57 A-Z 65-90 a-z 97-122
					{
								retorno = -1;
								break;

					}
				i++;
			}
	}
	return retorno;
}
/**
* \brief ordena Array elegir de mayor a menor 0 menor a mayor 1
* \param Array, extencion
* \return estado o cantidad de vueltas
*/
int OrdenarArrayIntElegir(int pArray[], int ext, int mayorUnomenorCero)
{
	int estado=-1;
	int banderaSwapp;
	int aux;
	int vueltas=0;
	int limite=ext;

	if(pArray!=NULL && ext>0 && (mayorUnomenorCero<=1||mayorUnomenorCero>=0))
	{
		do
		{
			banderaSwapp=0;
			limite=limite-1;
			for (int i=0; i<limite; i++)
			{
				if (mayorUnomenorCero==1)
				{
					if(pArray[i]<pArray[i+1])
						{
							banderaSwapp=1;
							aux=pArray[i];
							pArray[i]=pArray[i+1];
							pArray[i+1]=aux;
						}
				}else
					{
					if(pArray[i]>pArray[i+1])
						{
						banderaSwapp=1;
						aux=pArray[i];
						pArray[i]=pArray[i+1];
						pArray[i+1]=aux;
						}
					}
			}
			vueltas++;
		}while(banderaSwapp==1);
	estado=0;
	}
	return estado; //o numero de vueltas
}
/**
* \brief ordena Array de mayor a menor
* \param Array, extencion
* \return suma
*/
int OrdenarArrayInt(int pArray[], int ext)
{

	int estado=-1;
	int banderaSwapp;
	int aux;
	int vueltas=0;
	int limite=ext;

	if(pArray!=NULL && ext>0)
	{
		do
		{
			banderaSwapp=0;
			limite=limite-1;
			for (int i=0; i<limite; i++)
			{

				if(pArray[i]<pArray[i+1])
				{
					banderaSwapp=1;
					aux=pArray[i];
					pArray[i]=pArray[i+1];
					pArray[i+1]=aux;
				}
			}
			vueltas++;
		}while(banderaSwapp==1);
	}
	return estado;
}
/**
* \brief busca y suma pares
* \param Array, extencion
* \return suma
*/
int sumaImpares(int pArray[],int ext)
{
	int suma=0;
	if(pArray!=NULL && ext>0)
	{
		for (int i=0; i<ext; i++)
			{
				if (VerificarParidad(pArray[i])==-1)
				{
					suma=suma+pArray[i];
				}
			}
	}else
	{

	}

return suma;
}
/**
* \brief busca y suma pares
* \param Array, extencion
* \return suma
*/
int sumaPares(int pArray[],int ext)
{
	int suma=0;
	for (int i=0; i<ext; i++)
	{
		if (VerificarParidad(pArray[i])==0)
		{
			suma=suma+pArray[i];
		}
	}
return suma;
}
/**
* \brief carag datos  en u array
* \param Array, extencion
* \return Retorna 0 (salio bien) y -1 (salio mal) No dividir por 0
*/
void cargarArrayInt(int pArray[],int ext)
{
	//int v;
	for (int i=0; i<ext; i++)
	{
		if (pArray!=NULL && ext>0)
		{

		pedirInt(pArray, "INGESE NUMERO ENTERO", "El dato ingresado debe ser un 'NUMERO ENTERO'", -100000, 100000, 5);
		//pedirNumeroInt(&v, 3, "INGESE NUMERO ENTERO", "El dato ingresado debe ser un 'NUMERO ENTERO'");
		//printf("\nIngrese Numero\n");
		//__fpurge(stdin);
		//scanf("%d",&v);
		//pArray[i]=v;
		}
	}
}
/**
* \brief carag un dato en u array en una posicion determinada
* \param Array, extencion
* \return Retorna 0 (salio bien) y -1 (salio mal) No dividir por 0
*/
int cargarArrayIntUnDato(int pArray[],int ext)
{
	int estado=-1;
	int valor;
	int posicion;
	 //pedir posicion
	printf("\nIngrese Posición");
	scanf("%d",&posicion);
	//pedir valor
	printf("\nIngrese Valor");
	scanf("%d",&valor);
	//transform posicion
	posicion--;
	//cargar en la posicion
	pArray[posicion]=valor;
	estado=0;
	return estado;
}
/**
* \brief imprime un array flot
* \param Array, extencion
* \return
*/
int imprimirArrayInt(int pArray[],int ext)
{
	int estado=-1;
	if(pArray!=NULL && ext>0)
	{
		estado=0;
		for(int i=0; i<ext; i++)
		{
			printf("En la posición %d, el valor es %d\n",i+1,pArray[i]);
		}
	}
	printf("\n");
	return estado;
}
/**
* \brief Iniciciliza un array flot
* \param Array, extencion y el valor inicial
* \return
*/
void inicializarArrayInt(int pArray[],int ext,int valorInicial)
{
	for(int i=0; i<ext; i++)
	{
		pArray[i]=valorInicial;
	}
}
/**
* \brief carag un dato en u array en una posicion determinada
* \param Array, extencion
* \return Retorna 0 (salio bien) y -1 (salio mal) No dividir por 0
*/
int cargarArrayFloatUnDato(float pArray[],int ext)
{
	int estado=-1;
	float valor;
	int posicion;
	 //pedir posicion
	printf("\nIngrese Posición");
	scanf("%d",&posicion);
	//pedir valor
	printf("\nIngrese Valor");
	scanf("%f",&valor);
	//transform posicion
	posicion--;
	//cargar en la posicion
	pArray[posicion]=valor;
	estado=0;
	return estado;
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
* \brief busca cantidad de  impares
* \param Array, extencion
* \return cantidad de impares
*/
int cantidadImpares(int pArray[],int ext)
{
	int cantidad=0;
	for (int i=0; i<ext; i++)
	{
		if (VerificarParidad(pArray[i])==-1)
		{
			cantidad++;
		}
	}
return cantidad;
}
/**
* \brief busca cantidad de pares pares
* \param Array, extencion
* \return cantidada de pares
*/
int cantidadPares(int pArray[],int ext)
{
	int cantidad=0;
	for (int i=0; i<ext; i++)
	{
		if (VerificarParidad(pArray[i])==0)
		{
			cantidad++;
		}
	}
return cantidad;
}
/**
* \brief busca  pares y cambia por valor
* * \param Array, extencion y valor
* \return cantidad de pares
*/
int cambiarPares(int pArray[],int ext, int valor)
{
	int cantidad=0;
	if(pArray!=NULL && ext>0)
	{
		for (int i=0; i<ext; i++)
			{
				if (VerificarParidad(pArray[i])==0)
				{
					pArray[i]=valor;
					cantidad++;
				}
			}
	}
	return cantidad;
}
/**
* \brief busca   impares y cambia por valor
* \param Array, extencion
* \return cantidad de impares
*/
int cambiarImpares(int pArray[],int ext, int valor)
{
	int cantidad=0;
	if(pArray!=NULL && ext>0)
	{
		for (int i=0; i<ext; i++)
			{
				if (VerificarParidad(pArray[i])==-1)
				{
					pArray[i]=valor;
					cantidad++;
				}
			}
	}
	return cantidad;
}

/**
* \brief Verifica si la cadena ingresada es numerica float
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es

int esNumericaFloat1(char* cadena)
{
	int i=0;
	int retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if(cadena[i] < 48 || cadena[i] > 57)
					{
					if(cadena[i]==46)
						{

						}else
						{
							retorno = -1;
							break;
						}
					}
				i++;
			}
	}
	return retorno;
}
*/

/**
* \brief Verifica si la cadena ingresada es numerica int
* \param cadena Cadena de caracteres a ser analizada
* \return Retorna 0 (vardadero) si la cadena es numerica y -1 (falso) si no lo es

int esNumericaInt(char* cadena)
{
	int i=0;
	int retorno = 0;
	if(cadena != NULL && strlen(cadena) > 0)
	{
		while(cadena[i] != '\0')
			{
				if(cadena[i] < 48 || cadena[i] > 57)
					{
						retorno = -1;
						break;
					}
				i++;
			}
	}
	return retorno;
}
*/

