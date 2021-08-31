/*
 ============================================================================
 Name        : Ejercicio 1-3:
 Author      : Tejeda Roberto
 Version     :1
 Copyright   : Your copyright notice
 Description :
Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: "libre" - P: "presencial" – R: "remota")
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);
	char sigue='s';
	int legajo;//var datos
	char cursada;
	int cantidadMaterias;
	char sexo;
	int notaPromedio;
	int edad;
	int banderaMejorPromFeme=1;//var para a)
	int legajoMejorPromFeme;
	int mejorPromFem;
	int banderaMasJovenMasc=1;//var para b)
	int legajoMasJovenMasc;
	int edadMasJovenMasc;
	int cuentaMascLibres=0;
	int acumulaNotaFem=0;//var c)
	int cuentaFem=0;
	float promNotaFem;
	int acumulaNotaMasc=0;
	int cuentaMasc=0;
	float promNotaMasc;
	int acumulaNotaNB=0;
	int cuentaNB=0;
	float promNotaNB;
	int banderaMayorCantMat=1;//var d)
	int mayorCantMat;
	int edadMayorCantMat;
	int legajoMayorCantMat;

	//Pedido al usuario hasta que quiera
	while (sigue == 's')
	{
		//pido legajo
		printf("\nIngrese número de Legajo: \n");
		scanf("%d",&legajo);
		//pido tipo de cursada
		printf("\nTipo cursada (L:'libre'-P:'presencial'-R:'remota')\n");
		scanf("%c",&cursada);
		while(cursada != 'L' && cursada != 'P' && cursada != 'R' )
				{
					printf("\nERROR DE CARGA - Tipo cursada (L:'libre'-P:'presencial'-R:'remota')\n");
					__fpurge (stdin);
					scanf("%c",&cursada);
				}
		//pido Cantidad de materias( mas de cero y menos de 8)
		printf("\nCantidad de materias( mas de cero y menos de 8)\n");
		scanf("%d",&cantidadMaterias);
		while(cantidadMaterias <=0 || cantidadMaterias>8)
				{
					printf("\nERROR DE CARGA - Cantidad de materias( mas de cero y menos de 8)\n");
					scanf("%d",&cantidadMaterias);
				}
		//Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
		printf("\nIngrese Sexo (F: “femenino” – M: “masculino” , O: “no binario”)\n");
		scanf("%c",&sexo);
		while(sexo != 'F' && sexo != 'M' && sexo != 'O' )
				{
					printf("\nERROR DE CARGA - Ingrese Sexo (F: “femenino” – M: “masculino” , O: “no binario”)\n");
					__fpurge (stdin);
					scanf("%c",&sexo);
				}
		//Nota promedio (entre 0 y 10)
		printf("\nNota promedio (entre 0 y 10)\n");
		scanf("%d",&notaPromedio);
		while(notaPromedio <=0 || notaPromedio>10)
				{
					printf("\nERROR DE CARGA - Nota promedio (entre 0 y 10)\n");
					scanf("%d",&notaPromedio);
				}
		//Edad (validar)
		printf("\nEdad (validar)\n");
		scanf("%d",&edad);
		while(edad <=18 || edad>100)
				{
					printf("\nERROR DE CARGA - Nota promedio (entre 0 y 10)\n");
					scanf("%d",&edad);
				}
		switch (sexo) {
			case 'M':
				cuentaMasc++;
				acumulaNotaMasc=acumulaNotaMasc+notaPromedio;
				// b) Busco El legajo del más joven de los alumnos masculinos entre los que dan libre.
				if (cursada == 'L')
				{
					cuentaMascLibres++;
					if(banderaMasJovenMasc)//busco el minimo
					{
						banderaMasJovenMasc=1;
						legajoMasJovenMasc=legajo;
						edadMasJovenMasc=edad;
					}
					else
					{
						if (edad<edadMasJovenMasc)
						{
							legajoMasJovenMasc=legajo;
							edadMasJovenMasc=edad;
						}
					}
				}
				break;
			case 'F':
				cuentaFem++;
				acumulaNotaFem=acumulaNotaFem+notaPromedio;
				// a) Busco El Legajo del mejor promedio femenino.
				if(banderaMejorPromFeme) //busco el max
										{
											banderaMejorPromFeme=0;
											legajoMejorPromFeme=legajo;
											mejorPromFem=notaPromedio;
										}
											else
											{
												if (notaPromedio>mejorPromFem)
													{
														legajoMejorPromFeme=legajo;
														mejorPromFem=notaPromedio;
													}
											}
				break;
			case 'O':
				cuentaNB++;
				acumulaNotaNB=acumulaNotaNB+notaPromedio;
				break;
			default:
				break;
		}
		// d) La edad y legajo del que cursa más materias. (Sin importar su género)
		if (banderaMayorCantMat)
			{
			banderaMayorCantMat=1;
			edadMayorCantMat=edad;
			legajoMayorCantMat=legajo;
			mayorCantMat=cantidadMaterias;
			}
			else
				{
					if (cantidadMaterias>mayorCantMat)
					{
						edadMayorCantMat=edad;
						legajoMayorCantMat=legajo;
						mayorCantMat=cantidadMaterias;
					}

				}
		printf("\n¿desea conntinuar?s-n\n");
		__fpurge (stdin);
		scanf("%s",&sigue);
	}
	// c) El promedio de nota por sexo.
	promNotaMasc=(float)acumulaNotaMasc/cuentaMasc;
	promNotaFem=(float)acumulaNotaFem/cuentaFem;
	promNotaNB=(float)acumulaNotaNB/cuentaNB;

	//Se debe informar de existir, o informar que no existe , en el caso que corresponda.
	//a) Informo El Legajo del mejor promedio femenino.
	if (cuentaFem>0)
		{
		printf("\nEl legajo del mejor promedio Femenino es %d", legajoMejorPromFeme);
		}
		else
			{
			printf("\nNo existen datos sobre promedios Femeninos\n");		}
	//b) informo El legajo del más joven de los alumnos masculinos entre los que dan libre.
	if (cuentaMascLibres>0)
		{
			printf("\nEl legajo del más joven de los alumnos masculinos entre los que dan libre es %d", legajoMasJovenMasc);
		}
		else
			{
			printf("\nNo existen datos sobre alumnos masculinos que den libre\n");
			}
	// c) Informo El promedio de nota por sexo.
	if (cuentaNB>0)
		{
			printf("\nEl promedio de nota de sexo No Binario es %.2f", promNotaNB);
		}
		else
			{
			printf("\nNo existen datos sobre alumnes No Binarios\n");
			}
	if (cuentaFem>0)
			{
				printf("\nEl promedio de nota de sexo Femenino es %.2f", promNotaFem);
			}
			else
				{
				printf("\nNo existen datos sobre alumnas\n");
				}
	if (cuentaMasc>0)
			{
				printf("\nEl promedio de nota de sexo Masculino es %.2f", promNotaMasc);
			}
			else
				{
				printf("\nNo existen datos sobre alumnos\n");
				}
	// d) Informo La edad y legajo del que cursa más materias. (Sin importar su género)
	printf("\nLa edad y legajo del que cursa más materias son %d,%d",edadMayorCantMat, legajoMayorCantMat);
	return EXIT_SUCCESS;
}
