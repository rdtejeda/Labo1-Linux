/*
 * Mi-utn.h
 *
 *  Created on: 11 sep. 2021
 *      Author: usuario
 */

#ifndef MI_UTN_H_
#define MI_UTN_H_

int pedirNumeroInt(int* px, int intentos, char* txt, char* txtError);
int pedirNumeroIntconMaxyMin(int* px, int min, int max, int intentos, char* txt, char* txtError);
int pedirCharAUsuario(char* pResultado, int reintentos, char* variableTexto, char* textoError);
int pedirNumeroFloat(float* px, int intentos, char* txt, char* txtError);
int pedirNumeroFloatconMaxyMin(float* px, float min, float max, int intentos, char* txt, char* txtError);
int dividirEnteros(int numUno,int numDos,float* resultado);
int dividirFloat(float x,float y,float* z);
void imprimirNumeroInt(char mensaje[],int x);
void imprimirNumeroFloat(char mensaje[],float x);
void inicializarArrayFloat(float pArray[],int ext,float valorInicial);
void imprimirArrayFloat(float pArray[],int ext);
int cargarArrayFloat(float pArray[], int ext);


#endif /* MI_UTN_H_ */
