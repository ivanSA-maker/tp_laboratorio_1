/*
 * funciones.c
 *
 *  Created on: 10 abr. 2022
 *      Author: Iván Wesley Serna Alegre
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//Introduciendo float con parametros respectivos.
int GetFloat(char mensaje[],int reintetos,float minimo,float maximo,char mensajeError[],float *pNumeroIngresado)
{
	int retorno = -1;
	int retornoScanf;
	float auxiliarFloat;

	//Revisar que todos los datos esten bien.
	if (mensaje != NULL && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL)
	{
		printf("%s",mensaje);
		retornoScanf = scanf("%f", &auxiliarFloat);

		do//Bucle de reintentos.
		{
			//Revisar que todos los datos ingresados esten bien.
			if (retornoScanf != 1 || auxiliarFloat < minimo || auxiliarFloat > maximo)
			{
				if (reintetos != -1)
				{
					printf("\nNúmero de intentos restantes: %d",reintetos);
					reintetos--;
				}
				printf("%s",mensajeError);
				printf("%s",mensaje);
				retornoScanf = scanf("%f", &auxiliarFloat);
			}

			//Revisar que todos los datos ingresados esten bien.
			if (retornoScanf == 1 && auxiliarFloat <= maximo && auxiliarFloat >= minimo)
			{
				retorno = 0;
				*pNumeroIngresado = auxiliarFloat;
				reintetos = 0;
			}

		} while (reintetos > 0 || reintetos == -1);
	}

	return retorno;
}

//Calculando descuentos e intereces.
int DescuentoIntereses(float *pPrecioDebitoCredito,float precioVuelo,float porcentajeDescuentoIncremento,char sumaResta)
{
	int retorno = -1;

	//if (*pPrecioDebitoCredito != NULL && precioVuelo != NULL && porcentajeDescuentoIncremento != NULL && sumaResta != NULL)
	{
		//Calculando porcentaje y/e descuento/intereces.
		porcentajeDescuentoIncremento = precioVuelo * (porcentajeDescuentoIncremento / 100);

		if (sumaResta == 'S')
		{
			*pPrecioDebitoCredito = precioVuelo + porcentajeDescuentoIncremento;
		}
		else
		{
			*pPrecioDebitoCredito = precioVuelo - porcentajeDescuentoIncremento;
		}
		retorno = 0;
	}

	return retorno;
}

//Conversor de pesos a bitcoin y a valor unitario.
int ConversorBitcoinUnitario(float *pPrecioVueloBitcoinUnitario,float precioVuelo,float valorBitcoinKilometros)
{
	int retorno = -1;

	//if (*pPrecioVueloBitcoinUnitario != NULL && precioVuelo != NULL && valorBitcoinKilometros != NULL)
	{
		//Calculanco converción.
		*pPrecioVueloBitcoinUnitario = precioVuelo / valorBitcoinKilometros;

		retorno = 0;
	}

	return retorno;
}

//Calculando diferencia de precios.
int DiferenciaPrecios(float *pDiferenciaPrecios,float precioVuelo1,float precioVuelo2)
{
	int retorno = -1;

	//if (*pDiferenciaPrecios != NULL && precioVuelo1 != NULL && precioVuelo2 != NULL)
	{
		//Calculanco converción.
		*pDiferenciaPrecios = precioVuelo1 - precioVuelo2;
		if (*pDiferenciaPrecios < 0)
		{
			*pDiferenciaPrecios = *pDiferenciaPrecios * -1;
		}

		retorno = 0;
	}

	return retorno;
}
