/*
 * Input.c
 *
 *  Created on: 28 abr. 2022
 *      Author: Iván Serna Alegre
 */

#include "Input.h"

/** \brief Ingreso de dato numerico con todas las validaciones y avisos.
*
* \param mensaje[] char String con el mensaje orientativo antes de ingresar el input
* \param reintetos int Cantidad de intentos para ingresar el input - (-1) si los intentos son infinitos
* \param minimo int Valor minimo posible del valor ingresado
* \param maximo int Valor maximo posible del valor ingresado
* \param mensajeError[] char String con el mensaje de error por mal ingreso
* \param pNumeroIngresado int* Puntero donde se guardara el numero ingresado
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
*
*/
int GetNum(char mensaje[],int reintetos,int minimo,int maximo,char mensajeError[],int *pNumeroIngresado)
{
	int retorno = -1;
	int retornoScanf;
	int auxiliarNum;

	//Revisar que todos los datos esten bien.
	if (mensaje != NULL && (reintetos > 0 || reintetos == -1) && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL)
	{
		printf("%s",mensaje);
		retornoScanf = GetInt(&auxiliarNum);

		do//Bucle de reintentos.
		{
			//Revisar que todos los datos ingresados esten bien.
			if (retornoScanf != 0 || auxiliarNum < minimo || auxiliarNum > maximo)
			{
				if (reintetos != -1)
				{
					printf("\nNúmero de intentos restantes: %d",reintetos);
					reintetos--;
				}
				printf("%s",mensajeError);
				printf("%s",mensaje);
				retornoScanf = GetInt(&auxiliarNum);
			}

			//Revisar que todos los datos ingresados esten bien.
			if (retornoScanf == 0 && auxiliarNum <= maximo && auxiliarNum >= minimo)
			{
				retorno = 0;
				*pNumeroIngresado = auxiliarNum;
				reintetos = 0;
			}

		} while (reintetos > 0 || reintetos == -1);
	}

	return retorno;
}

/** \brief Ingreso de dato numerico con todas las validaciones y avisos.
*
* \param mensaje[] char String con el mensaje orientativo antes de ingresar el input
* \param reintetos int Cantidad de intentos para ingresar el input - (-1) si los intentos son infinitos
* \param minimo float Valor minimo posible del valor ingresado
* \param maximo float Valor maximo posible del valor ingresado
* \param mensajeError[] char String con el mensaje de error por mal ingreso
* \param pNumeroIngresado float* Puntero donde se guardara el numero ingresado
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
*
*/
int GetNumFloat(char mensaje[],int reintetos,float minimo,float maximo,char mensajeError[],float *pNumeroIngresado)
{
	int retorno = -1;
	int retornoScanf;
	float auxiliarNum;

	//Revisar que todos los datos esten bien.
	if (mensaje != NULL && (reintetos > 0 || reintetos == -1) && minimo < maximo && mensajeError != NULL && pNumeroIngresado != NULL)
	{
		printf("%s",mensaje);
		retornoScanf = GetFloat(&auxiliarNum);

		do//Bucle de reintentos.
		{
			//Revisar que todos los datos ingresados esten bien.
			if (retornoScanf != 0 || auxiliarNum < minimo || auxiliarNum > maximo)
			{
				if (reintetos != -1)
				{
					printf("\nNúmero de intentos restantes: %d",reintetos);
					reintetos--;
				}
				printf("%s",mensajeError);
				printf("%s",mensaje);
				retornoScanf = GetFloat(&auxiliarNum);
			}

			//Revisar que todos los datos ingresados esten bien.
			if (retornoScanf == 0 && auxiliarNum <= maximo && auxiliarNum >= minimo)
			{
				retorno = 0;
				*pNumeroIngresado = auxiliarNum;
				reintetos = 0;
			}

		} while (reintetos > 0 || reintetos == -1);
	}

	return retorno;
}

/** \brief Ingreso de dato string con todas las validaciones y avisos.
*
* \param mensaje[] char String con el mensaje orientativo antes de ingresar el string
* \param reintetos int Cantidad de intentos para ingresar el input - (-1) si los intentos son infinitos
* \param caracteres int Cantidad de caracteres que se pueden ingresar
* \param mensajeError[] char String con el mensaje de error por mal ingreso
* \param textoIngresado[] char Cadena donde se guardara el string ingresado
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien
*
*/
int GetString(char mensaje[],int reintetos,int caracteres,char mensajeError[],char textoIngresado[])
{
	int retorno = -1;
	int retornoScanf;
	char auxiliarString[caracteres];

	//Revisar que todos los datos esten bien.
	if (mensaje != NULL && (reintetos > 0 || reintetos == -1) && caracteres > 0 && mensajeError != NULL && textoIngresado != NULL)
	{
		printf("%s",mensaje);
		retornoScanf = MyGets(auxiliarString,caracteres);

		do//Bucle de reintentos.
		{
			//Revisar que todos los datos ingresados esten bien.
			if (retornoScanf != 0)
			{
				if (reintetos != -1)
				{
					printf("\nNúmero de intentos restantes: %d",reintetos);
					reintetos--;
				}
				printf("%s",mensajeError);
				printf("%s",mensaje);
				retornoScanf = MyGets(auxiliarString,caracteres);
			}

			//Revisar que todos los datos ingresados esten bien.
			if (retornoScanf == 0)
			{
				retorno = 0;
				textoIngresado = auxiliarString;
				reintetos = 0;
			}

		} while (reintetos > 0 || reintetos == -1);
	}

	return retorno;
}

/** \brief Ingreso y comprovación de signos de entero.
*
* \param pNumeroTomado int* Puntero de variable entero requerida.
* \return int Devuelve (-1) si hay error [puntero NULL o alguna funcion no devuelve 0]
* - (0) si está bien
*
*/
int GetInt(int *pNumeroTomado)
{
	int retorno = -1;
	char numeroAuxiliar[11];

	if (pNumeroTomado == NULL && MyGets(numeroAuxiliar,11) == 0 && EsEntero(numeroAuxiliar) == 0)
	{
		*pNumeroTomado = atoi(numeroAuxiliar);//Pasar a dato numerico.
	}

	return retorno;
}

/** \brief Ingreso y comprovación de signos de flotante.
*
* \param pNumeroTomado float* Puntero de variable flotante requerida.
* \return int Devuelve (-1) si hay error [puntero NULL o alguna funcion no devuelve 0]
* - (0) si está bien
*
*/
int GetFloat(float *pNumeroTomado)
{
	int retorno = -1;
	char numeroAuxiliar[16];

	if (pNumeroTomado == NULL && MyGets(numeroAuxiliar,11) == 0 && EsFlotante(numeroAuxiliar) == 0)
	{
		*pNumeroTomado = atof(numeroAuxiliar);//Pasar a dato numerico.
	}

	return retorno;
}

/** \brief Ingreso de cadena de caracteres y ajuste de cantidad de caracteres.
*
* \param cadena[] char Cadena de carecteres.
* \param largo int Cantidad de caracteres de la cadena.
* \return int Devuelve (-1) si hay error [Cadena NULL o alguna funcion no devuelve 0] - (0) si está bien
*
*/
int MyGets(char cadena[],int largo)
{
	int retorno = -1;
	char auxiliarcadena[1000];//buffer

	//Validacion e ingreso de datos.
	if (cadena != NULL && largo > 0 && fgets(auxiliarcadena,sizeof(auxiliarcadena),stdin) == auxiliarcadena)
	{
		strncpy(cadena,auxiliarcadena,largo);//Copiando datos validados.
		retorno = 0;
	}

	return retorno;
}

/** \brief Comprovante de que los caracteres pertenescan a un dato del tipo entero.
*
* \param arrayPosiblesNumeros[] char Cadena de carecteres.
* \return int Devuelve (-1) si hay error [Cadena NULL] - (0) si está bien
*
*/
int EsEntero(char arrayPosiblesNumeros[])
{
	int retorno = -1;
	int i = 0;

	if (arrayPosiblesNumeros != NULL)
	{
		while (arrayPosiblesNumeros[i] != '\0')
		{
			//Comprovacion del array.
			if (arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] < '9')
			{
				if (arrayPosiblesNumeros[0] != '-')
				{
					return retorno;
				}
			}
			i++;
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief Comprovante de que los caracteres pertenescan a un dato del tipo flotante.
*
* \param arrayPosiblesNumeros[] char Cadena de carecteres.
* \return int Devuelve (-1) si hay error [Cadena NULL] - (0) si está bien
*
*/
int EsFlotante(char arrayPosiblesNumeros[])
{
	int retorno = -1;
	int punto = -1;
	int i = 0;

	if (arrayPosiblesNumeros != NULL)
	{
		while (arrayPosiblesNumeros[i] != '\0')
		{
			//Comprovacion del array.
			if (arrayPosiblesNumeros[i] < '0' || arrayPosiblesNumeros[i] < '9')
			{
				if (arrayPosiblesNumeros[0] != '-' || punto == 0)
				{
					return retorno;
				}
				else if (arrayPosiblesNumeros[i] == '.' && punto != 0)
				{
					punto = 0;
				}
			}
			i++;
		}
		retorno = 0;
	}

	return retorno;
}
