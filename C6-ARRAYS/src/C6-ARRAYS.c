/*
 ============================================================================
 Name        : C6-ARRAYS.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


int main(void)
{
	int indice;
	int edades[5]={0,0,0,0,0,};//array estatico pongo numeros grandes
	for (indice = 0; indice < 5; ++indice)
	{
		printf("%d\n",edades[indice]);
	}



	__fpurge(stdin);
	return EXIT_SUCCESS;
}
