/*
 ============================================================================
 Name        : Ejercisio 2.2
 Author      : Tejeda
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 2-2:
Realizar un programa que permita el ingreso de 10 números enteros.
Determinar el promedio de los positivos,
la cantidad de ceros y del menor de los negativos la suma de los antecesores.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define NUMEROS_PEDIDOS 10

int VerificaCeroPositivoNegativo (int numIngresado);
float CalcularPromedioPositivos (int acumuPosi, int cantiPosi);
int BuscarMenorNegativo(int negativo);
int SumarAntecesoresDelMenor(int menor);

int main(void)
{
	int i=0;
	int numero;
	int estado;
	int acumladorPositivos=0;
	int cantidadpositivos=0;
	float promedioPositivos;
	int cantidadCeros=0;
	int negMenor=0;
	int sumaAntecesores;
	for (i = 0; i < NUMEROS_PEDIDOS; ++i)
	{
		printf("Ingrese un numero entero\n");
		__fpurge(stdin);
		scanf("%d,",&numero);
		estado = VerificaCeroPositivoNegativo(numero);
		if (estado>0)
		{
			acumladorPositivos=acumladorPositivos+numero;
			cantidadpositivos++;
		}else
			{
			if(estado==0)
				{
				cantidadCeros++;
				}else
					{
					negMenor=BuscarMenorNegativo(numero);
					}
			}
	}
	promedioPositivos=CalcularPromedioPositivos(acumladorPositivos, cantidadpositivos);
	if (cantidadpositivos>0)
		{
		printf("El promedio de los positivos es: %.2f\n",promedioPositivos);
		__fpurge(stdin);
		}else
			{
			printf("No se han ingresado numeros positivos\n");
			__fpurge(stdin);
			}
	if (cantidadCeros>0)
		{
		printf("La cantidad de ceros ingresados es %d\n",cantidadCeros);
		__fpurge(stdin);
		}else
			{
			printf("No se han ingresado ceros\n");
			__fpurge(stdin);
			}
	sumaAntecesores=SumarAntecesoresDelMenor(negMenor);
	if (negMenor<0)
		{
		printf("La suma de los antecesores del menor de los negativos es %d\n", sumaAntecesores);
		}else
			{
			printf("No se han ingresado enteros negativos\n");
			__fpurge(stdin);
			}
	return EXIT_SUCCESS;
}
int SumarAntecesoresDelMenor(int menor)
{
	int sumaAnt=0;
	do
	{
	sumaAnt=sumaAnt+menor;
	menor++;
	}
	while(menor<0);
	return sumaAnt;
}
int BuscarMenorNegativo(int negativo)
{
	int banderaMenorNegativo=1;
	int menorNeg;
	if (banderaMenorNegativo)
		{
			banderaMenorNegativo=0;
			menorNeg=negativo;
		}else
		{
			if (menorNeg>negativo)
			{
				menorNeg=negativo;
			}
		}
	return menorNeg;
}
float CalcularPromedioPositivos (int acumuPosi, int cantiPosi)
{
	float promedio;
	promedio=(float)acumuPosi/cantiPosi;
	return promedio;
}
int VerificaCeroPositivoNegativo (int numIngresado)
{
	int estado;
	if (numIngresado>0)
	{
		estado=1;
	}else
		{
		if (numIngresado<0)
			{
			estado=-1;
			}else
				{
				estado=0;
				}
		}
	return estado;
}
