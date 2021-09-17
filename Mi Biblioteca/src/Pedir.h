/*
 * Pedir.h
 *
 *  Created on: 16 sep. 2021
 *      Author: usuario
 */

#ifndef PEDIR_H_
#define PEDIR_H_

int pedirNumeroInt(int* px, int intentos, char* txt, char* txtError);
int pedirNumeroIntconMaxyMin(int* px, int min, int max, int intentos, char* txt, char* txtError);
int pedirCharAUsuario(char* pResultado, int reintentos, char* variableTexto, char* textoError);
int pedirNumeroFloat(float* px, int intentos, char* txt, char* txtError);
int pedirNumeroFloatconMaxyMin(float* px, float min, float max, int intentos, char* txt, char* txtError);

#endif /* PEDIR_H_ */
