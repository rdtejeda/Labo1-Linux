/*
 ============================================================================
 Name        : Lab-C6-Estructura.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "TrianguloEscaleno.h"

#define TRIANGULOS_LEN 3


int main()
{

	TrianguloEscaleno triangulos[3];
	//float perimetros[3];
	float perimetroMayor;
	for (int j= 0;  j<3; j++)
	{
		trianguloCarga(&triangulos[j]);//pasamos la dirreccion de memoria de cada uno de los elementos del array
		//perimetros[j]=trianguloPerimetro(&triangulos[j]); //calculo cada perimetro
		//printf("%.4f",perimetros[j]);
	}

	perimetroMayor = trianguloPerimetro(&triangulos[0]); // tomo la primera como mayor
	int	indexDeTrianguloMayor = 0;
	int i;
	for( i=1 ; i<TRIANGULOS_LEN;i++)
		{
			if(trianguloPerimetro(&triangulos[i]) > perimetroMayor)
			{
				// encontre un nuevo mayor! jajajaj
				perimetroMayor = trianguloPerimetro(&triangulos[i]);
				indexDeTrianguloMayor = i;
			}
		}
		// en perimetroMayor me quedo el mayor (no me sirve pa nada)
		// en indexDeTrianguloMayor me quedo la posicion donde esta el mayor
		trianguloMostrarPorReferencia(&triangulos[indexDeTrianguloMayor]);
	/*
	int indexTrianguloMayor;
	TrianguloEscaleno triUno;
	TrianguloEscaleno triDos;
	TrianguloEscaleno triTres;


	if(trianguloCarga(&triUno)==0)
    {
        trianguloMostrarPorValor(triUno);
        //trianguloMostrarPorReferencia(&triUno);
    }
	if(trianguloCarga(&triDos)==0)
	    {
	        trianguloMostrarPorValor(triDos);
	       // trianguloMostrarPorReferencia(&triDos);
	    }
	if(trianguloCarga(&triTres)==0)
	    {
	        trianguloMostrarPorValor(triTres);
	        //trianguloMostrarPorReferencia(&triTres);
	    }

	float perUno=trianguloPerimetro(&triUno);
	float perDos=trianguloPerimetro(&triDos);
	float perTres=trianguloPerimetro(&triTres);
	perimetro[0]=perUno;
	perimetro[1]=perDos;
	perimetro[3]=perTres;



	perimetroMayor=perimetro[0];
	indexTrianguloMayor=0; //asumo que es el primero
	for (int i = 1; i <3; i++)
	{
		if(perimetro[i]>perimetroMayor)
		{
			perimetroMayor=perimetro[i];
			indexTrianguloMayor=i;
		}
	}
	 switch (indexTrianguloMayor)
	 {
		case 1:trianguloMostrarPorValor(triUno); break;
		case 2:trianguloMostrarPorValor(triDos); break;
		case 3:trianguloMostrarPorValor(triTres); break;
		default:break;
	}


    //printf("\nEl area(mal calculada) es %.4f\n",trianguloArea(&triUno));
*/
    return 0;
}


