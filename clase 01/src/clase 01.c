/*
 ============================================================================
 Name        : clase.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
		setbuf(stdout,NULL);
		printf("Esta es la primer clase");

		//declarar variables
		int numeroUno;
		int suma;
		suma = 0;
		int i;

		for(i=0;i<5;i++) //pedir al usuario 5 numeros
		{
			printf("\nIngrese el numero: \n");
			scanf("%d",&numeroUno);
			suma = suma + numeroUno; //acumular valor de la suma
		}

		//mostrar resultado
		printf("\nLa suma es %d", suma);
		return EXIT_SUCCESS;
}
