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

int dividir(float a, float b, float* pResultado);

int main(void)
{
	// WINDORRRRRRR
	setbuf (stdout,NULL);
	//______________
	float r;
	float pepito;
	int estado;

	printf("r vale:%f la direccion es %p\n",r,&r);

	estado = dividir(45,0,&r);
	if(estado==0)
	{
		// pude dividir
		printf("El resultado da:%f",r);
	}
	else
	{
		printf("No se puede dividir\n");
	}



	return EXIT_SUCCESS;
}







// FORMATO FUNCION
int dividir(float a, float b, float* pResultado)
{
	float resultado;
	int estado;

	printf("a vale:%f b vale:%f pResultado : %p\n",a,b,pResultado);


	if(b!=0){
		resultado = a/b;
		estado=0; // OK

		//devuelvo resultado
		// escribir la variable externa, que no tengo acceso
		// pero tengo la direccion
		*pResultado = resultado; // escribiendo "r"
	}
	else
		estado=1; // ERROR


	return estado;
}
float pedirFloatAlusuario(float a)
{
	printf("Ingresar numero")
}





