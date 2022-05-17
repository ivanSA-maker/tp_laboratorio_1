/*
 * Input.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Iván Serna Alegre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef INPUT_H_
#define INPUT_H_

int GetNum(char mensaje[],int reintetos,int minimo,int maximo,char mensajeError[],int *pNumeroIngresado);
int GetNumFloat(char mensaje[],int reintetos,float minimo,float maximo,char mensajeError[],float *pNumeroIngresado);
int GetString(char mensaje[],int reintetos,int caracteres,char mensajeError[],char textoIngresado[]);
int GetInt(int *pNumeroTomado);
int GetFloat(float *pNumeroTomado);
int MyGets(char cadena[],int largo);
int EsEntero(char arrayPosiblesNumeros[]);
int EsFlotante(char arrayPosiblesNumeros[]);

#endif /* INPUT_H_ */
