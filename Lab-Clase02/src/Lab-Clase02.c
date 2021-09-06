/*
 ============================================================================
 Name        : Lab-Clase02.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Funciones el inicio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define REINTENTOS 3

int sumarEnteros(int numUno, int numDos);

int main(void)
{
	setbuf(stdout,NULL);
	int numeroUno;
	int numeroDos;
	int resultado;
	float promedio;
	float impuestos;
	float impuestoresultado;

	printf("ingrese el valor de la priemra compra : \n");
	__fpurge(stdin);
	scanf("%d",&numeroUno);

	printf("ingrese el valor de la segunda compra : \n");
	__fpurge(stdin);
	scanf("%d",&numeroDos);

	resultado=sumarEnteros(numeroUno, numeroDos);
	promedio=(float)resultado/2;

	printf("El resultado de la suma %d\n", resultado);
	printf("El resultado del promedio %.2f\n", promedio);

	printf("Ahora decime los impuestos abonado : \n");
	__fpurge(stdin);
	scanf("%f",&impuestos);

	impuestoresultado=impuestos+resultado;
	printf("El importe total con impuestos es : %.2f",impuestoresultado);
	return EXIT_SUCCESS;
}

//una funcio para crearla consta de tres partes
	// Parte A
	//retorna nombreFuncion(parametros de la funcion)

int sumarEnteros(int numUno,int numDos)
{
		int retorno;
		retorno=numUno+numDos;
		return  retorno;
}

int restaEnteros(int numUno,int numDos)
{
	int retorno;
	retorno=numUno-numDos;
	return retorno;

}
//factorial
int factorial (int numUno)
{
	int retorno;
	retorno=factorial(numUno);
	return retorno;
}
//numeroPar

void imprimirResultadoMio(int numero) //void imprimirResultado entero
{
	printf("El resultados es %d",numero);
}

void imprimirResultado(char mensaje[],int numero)
{
	printf("%s %d",mensaje,numero);
}

//construyendo pasaje por referencia
int dividirEnteros(int numUno,int numDos,float* resultado)
{
	int retorno = 0;//salio todo bien

	if(numDos!=0) //esto es lo que causa el error
	{
		*resultado =(float)numUno / numDos;
	}
	else
	{
		retorno = 1;//si salio todo mal
	}

	return retorno;
}
//solo devuelve direccion de memoria para carcar com & en programa
void pedirFloatAlusuario(float* pResultado)
{
	printf("Ingresar numero");
	scanf("%f",pResultado);
}
//(pedirFloatAUsuario (&num1,0.0,1000.0)
int pedirFloatAUsuario_1(float* pResultado, float min, float max)
{
	int estado;
	printf("Ingresar numero");
	float aux;
	scanf("%f",&aux);
	if (aux>=0 && aux<1000)
	{
		*pResultado=aux;//esta dentro del rango
		estado=0;
	}else
	{
		printf ("\nno esta en el rango\n");
		estado=1;//error
	}
	return estado;
}

//(pedirFloatAUsuario (&num1,0.0,1000.0,REINTENTOS)
int pedirFloatAUsuario_2(float* pResultado, float min, float max, int reintentos)
{
	int estado;
	int i;
	for (i = 0; i <=reintentos ; ++i)
	{
		printf("Ingresar numero\n");
			float aux;
			scanf("%f",&aux);

			if (aux>=min && aux<max)
			{
				*pResultado=aux;//esta dentro del rango
				estado=0;
				break;
			}else
			{
				printf ("\nno esta en el rango\n");
				estado=1;//error
			}
	}
	return estado;
}
//(pedirFloatAUsuario (&num1,0.0,1000.0,REINTENTOS, "Ingrese la humedad:") char* variable
int pedirFloatAUsuario_3(float* pResultado, float min, float max, int reintentos, char* variableTexto)
{
	float aux;
	int retorno=1;
	int i;
	if(min<max)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			scanf("%f", &aux);

			if (aux>=min && aux<=max)
			{
				retorno = 0; // OK
				*pResultado=aux;
				break;
			}
			else
			{
				retorno = 1;
				printf("Numero fuera de rango\n");
			}
		}
	}
	return retorno;
}

//(pedirFloatAUsuario (&num1,0.0,1000.0,REINTENTOS, "Ingrese la humedad:", ingrese error) char* variable
//agregar a la funcion , para hacer la V6. que reciba el argumento del mensaje de error, que se imprime cuando la funcion detecta que el numero ingresado esta fuera de rango.
int pedirFloatAUsuario_4(float* pResultado, float min, float max, int reintentos, char* variableTexto)
{
	float aux;
	int retorno=1;
	int i;
	if(min<max)
	{
		for (i=0; i<=reintentos; i++)
		{
			printf("%s",variableTexto);
			scanf("%f", &aux);

			if (aux>=min && aux<=max)
			{
				retorno = 0; // OK
				*pResultado=aux;
				break;
			}
			else
			{
				retorno = 1;
				printf("Numero fuera de rango\n");
			}
		}
	}
	return retorno;
}
