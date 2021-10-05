/*
 * TrianguloEscaleno.h
 *
 *  Created on: 29 sep. 2021
 *      Author: usuario
 */

#ifndef TRIANGULOESCALENO_H_
#define TRIANGULOESCALENO_H_

typedef struct{
float lado1;
float lado2;
float lado3;
}TrianguloEscaleno;

void trianguloMostrarPorValor(TrianguloEscaleno unTriangulo);
void trianguloMostrarPorReferencia(TrianguloEscaleno* punTriangulo);
int pedirFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int intentos);
int esNumericaFloat(char* cadena);
int myGets(char pResultado[], int len);


int trianguloCarga(TrianguloEscaleno *unTriangulo);

float trianguloPerimetro(TrianguloEscaleno *unTriangulo);

float trianguloArea(TrianguloEscaleno *unTriangulo);

#endif /* TRIANGULOESCALENO_H_ */
