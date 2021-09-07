/*
 ============================================================================
 Name        : factorial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(void)
{
	int valor,result;
	printf("\nIngrese numero:");
	scanf("%d",&valor);
	result=factorial(valor);
	//result=valor*factorial(valor-1);
	printf("\nEl factorial de %d es %d",valor,result);

	return EXIT_SUCCESS;
}

int factorial(int n)
{
int resp;
if(n==1)
	{
	return 1;
	}
resp=n*factorial(n-1);
return (resp);
}
