/*
 * funciones.h
 *
 *  Created on: 10 abr. 2022
 *      Author: Iván Wesley Serna Alegre
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int GetFloat(char mensaje[],int reintetos,float minimo,float maximo,char mensajeError[],float *pNumeroIngresado);//Introduciendo float con parametros respectivos.

int DescuentoIntereses(float *pPrecioDebitoCredito,float precioVuelo,float porcentajeDescuentoIncremento,char sumaResta);//Calculando descuentos e intereces.

int ConversorBitcoinUnitario(float *pPrecioVueloBitcoinUnitario,float precioVuelo,float valorBitcoinKilometros);//Conversor de pesos a bitcoin y a valor unitario.

int DiferenciaPrecios(float *pDiferenciaPrecios,float precioVuelo1,float precioVuelo2);//Calculando diferencia de precios.

#endif /* FUNCIONES_H_ */
