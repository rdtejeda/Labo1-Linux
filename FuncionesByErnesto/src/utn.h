/*
 * utn.h
 *
 *  Created on: 5 sep. 2021
 *      Author: usuario
 */

#ifndef UTN_H_
#define UTN_H_

int dividir(float a,float b,float*pResultado);
int pedirFloatAUsuario3(float* pResultado, float min, float max, int reintentos);
int pedirFloatAUsuario4(float* pResultado, float min, float max, int reintentos);
int pedirFloatAUsuario5(float* pResultado, float min, float max, int reintentos, char* variableTexto);
int pedirFloatAUsuario6(float* pResultado, float min, float max, int reintentos, char* variableTexto, char* textoError);

#endif /* UTN_H_ */
