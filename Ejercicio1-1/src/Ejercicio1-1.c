/*
 ============================================================================
 Name        : Ejercicio1-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 1-1:
 Ingresar números enteros, hasta que el usuario lo decida.
 Calcular y mostrar:
 a) El promedio de los números positivos.
 b) El promedio de los números negativos.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);
	int numeroIngresado; //pedir numero entero
	int contadorDenegativos=0; //contador y acumuladores
	int contadorDepositivos=0;
	int acumuladorDepositivos=0;
	int acumuladorNegativos=0;
	float promedioPositivos; //promedios
	float promedioNegativos;
	char sigue='s';//caracter para seguir

	//Pedido al usuario hasta que quiera
	while (sigue == 's')
	{
		printf("\nIngrese el numero: \n");//pido el entero
		scanf("%d",&numeroIngresado); //cargo valor a la variable

		if (numeroIngresado<0) //acumulo y cuento negativos
		{
		acumuladorNegativos = acumuladorNegativos +numeroIngresado;
		contadorDenegativos++;
		}

		if(numeroIngresado>0) //acumulo y cuento positivos
		{
		acumuladorDepositivos = acumuladorDepositivos+numeroIngresado;
		contadorDepositivos++;
		}
		printf("\n¿desea conntinuar?s-n\n");
		__fpurge (stdin);
		scanf("%s",&sigue);
	}
	//calcular promedios
	promedioPositivos=(float)acumuladorDepositivos/contadorDepositivos; //calculo +++
	promedioNegativos=(float)acumuladorNegativos/contadorDenegativos; //calculo ---
	//Mostramos resultados
	printf("\nEl promedio de los postivos es %.2f", promedioPositivos);
	printf("\nEl promedio de los negativos es %.2f", promedioNegativos);
	return EXIT_SUCCESS;
}
