/*
 * ArrayPassenger.c
 *
 *  Created on: 28 abr. 2022
 *      Author: Iván Serna Alegre
 */

#include "ArrayPassenger.h"

static int generarId();

/** \brief Para indicar que todas las posiciones en el array están vacías,
*    esta función pone la bandera (isEmpty/Esta vacio) en VERDADERO en todas
*    las posiciónes del array.
* \param list Passenger* Puntero del array Passenger/Espructura pasajero.
* \param len int Longitud del array.
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien.
*/
int initPassengers(Passenger* list, int len)
{
	int retorno = -1;

	if (list != NULL && len >= 0)
	{
		for (int i = 0; i < len; ++i)
		{
			list[i].isEmpty = 0;
			list[i].id = 0;
		}
		retorno = 0;
	}

	return retorno;
}

/** \brief Para ingresar todos los datos de la estructura Passenger.
* \param list Passenger* Puntero del array Passenger/Espructura pasajero.
* \param len int Longitud del array.
* \return int Devuelve (-1) si hay error [longitud no válida, puntero NULL o
*  error en algun ingreso] - (0) si está bien.
*/
int intrDataPassengers(Passenger* list, int len)
{
	//Variables.
	int retorno = -1;

	int id;
	char name[51];
	char lastName[51];
	float price;
	int typePassenger;
	int statusFlight;
	char flycode[10];

	int r;
	int indice;

	if (list != NULL && len >= 0)
	{
		id = generarId();
		GetString(" Ingrese el nombre del pasajero: ",-1,51,"\n Error del programa, vuelva a intentar.",name);
		GetString(" Ingrese el apellido del pasajero: ",-1,51,"\n Error del programa, vuelva a intentar.",lastName);
		GetNumFloat(" Ingrese el precio del vuelo: ", -1, 0.0f, 9999999.0f, "\n Error de ingreso, vuelva a intentar.", &price);
		printf("\n Que tipo de pasajero es?");
		GetNum("\n [1: Primera clase]\n [2: Clase ejecutiva o business]\n [3: Clase premium economy]\n [4: Clase turista o económica]\n : ",-1,1,4,"\n No has ingresado una opcion valida.",&typePassenger);
		printf("\n Cual es el estado del vuelo?");
		r = GetNum("\n [1: Vuelo activo]\n [2: Vuelo canselado]\n : ",-1,1,2,"\n No has ingresado una opcion valida.",&statusFlight);
		GetString(" Ingrese el codigo de vuelo: ",-1,10,"\n Error del programa, vuelva a intentar.",flycode);

		retorno = addPassenger(list, len, id, name, lastName, price, typePassenger, flycode);

		if (retorno == 0 && r == 0)
		{
			indice = findPassengerById(list, len, id);

			list[indice].statusFlight = statusFlight;
		}
		else
		{
			retorno = -1;
		}
	}

	return retorno;
}

/** \brief Agrega en una lista existente de pasajeros los valores recibidos como parámetros
*    en la primera posición vacía.
* \param  list passenger*
* \param  len int
* \param  id int
* \param  name[] char
* \param  lastName[] char
* \param  price float
* \param  typePassenger int
* \param  flycode[] char
* \return int Devuelve (-1) si hay error [Longitud no válida o puntero NULL o sin espacio libre]
*  - (0) si está bien.
*/
int addPassenger(Passenger* list, int len, int id, char name[],
	char lastName[],float price,int typePassenger, char flycode[])
{
	//Variables.
	int retorno = -1;
	int indice = -1;
	int largoName = strlen(name);
	int largoLastName = strlen(lastName);
	int largoFlycode = strlen(flycode);

	if (list != NULL && len >= 0 && id > 0 && name != NULL && lastName != NULL && price > 0 && typePassenger > 0 && flycode != NULL)
	{
		//Buscando indice.
		for (int i = 0; i < len; ++i)
		{
			if (list[i].isEmpty == 0)
			{
				indice = i;

				break;
			}
		}

		if (indice != -1)
		{
			//Guardando datos.
			list[indice].id = id;
			strncpy(list[indice].name,name,largoName);
			strncpy(list[indice].lastName,lastName,largoLastName);
			list[indice].price = price;
			list[indice].typePassenger = typePassenger;
			strncpy(list[indice].flycode,flycode,largoFlycode);
			list[indice].isEmpty = -1;

			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Modifica datos de un pasajero por Id..
*
* \param list Passenger*
* \param len int
* \param id int
* \return Devuelve (-1) si hay error [Longitud no válida o puntero NULL o indice no encontrado]
*  - (0) si está bien.
*
*/
int modifyPassenger(Passenger* list, int len,int id)
{
	//Variables.
	int retorno = -1;
	int indice = -1;
	int inputMenu;

	if (list != NULL && len >= 0 && id > 1110)
	{
		indice = findPassengerById(list, len, id);

		if (indice != -1)
		{
			do
			{
				printf("\n Modificar campo del pasajero.");
				GetNum("\n [1: Nombre]\n [2: Apellido]\n [3: Precio]\n [4: Tipo de pasajero]\n [5: Estado del vuelo]\n [6: Código de vuelo]\n [0: Salir]\n : ",-1,0,6," No has ingresado una opcion valida.",&inputMenu);

				switch (inputMenu)
				{
				case 1:
					GetString(" Ingrese el nuevo nombre del pasajero: ",-1,51,"\n Error del programa, vuelva a intentar.",list[indice].name);
					break;
				case 2:
					GetString(" Ingrese el nuevo apellido del pasajero: ",-1,51,"\n Error del programa, vuelva a intentar.",list[indice].lastName);
					break;
				case 3:
					GetNumFloat(" Ingrese el nuevo precio del vuelo: ", -1, 0.0f, 9999999.0f, "\n Error de ingreso, vuelva a intentar.", &list[indice].price);
					break;
				case 4:
					printf("\n Que tipo de pasajero es ahora?");
					GetNum("\n [1: Primera clase]\n [2: Clase ejecutiva o business]\n [3: Clase premium economy]\n [4: Clase turista o económica]\n : ",-1,1,4,"\n  No has ingresado una opcion valida.",&list[indice].typePassenger);
					break;
				case 5:
					printf("\n Cual es el nuevo estado del vuelo?");
					GetNum("\n [1: Vuelo activo]\n [2: Vuelo canselado]\n : ",-1,1,2,"\n No has ingresado una opcion valida.",&list[indice].statusFlight);
					break;
				case 6:
					GetString(" Ingrese el nuevo codigo de vuelo: ",-1,10,"\n Error del programa, vuelva a intentar.",list[indice].flycode);
					break;
				}

			} while (inputMenu != 0);

			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Encuentra un pasajero por Id y devuelve la posición del índice en el array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Devuelve la posición del índice del pasajero o (-1) si [Longitud no válida o puntero
*  recibido NULL o pasajero no encontrado].
*
*/
int findPassengerById(Passenger* list, int len,int id)
{
	int retornoIndice = -1;

	if (list != NULL && len >= 0 && id > 1110)
	{
		//Buscando indice.
		for (int i = 0; i < len; ++i)
		{
			if (list[i].id == id)
			{
				retornoIndice = i;

				break;
			}
		}
	}

	return retornoIndice;
}

/** \brief Eliminar un pasajero por Id (poner bandera isEmpty en 0).
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL o si no se puede
*  encontrar un pasajero] - (0) si está bien.
*
*/
int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int indice;

	if (list != NULL && len >= 0 && id > 1110)
	{
		indice = findPassengerById(list, len, id);

		if (indice != -1)
		{
			list[indice].isEmpty = 0;

			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Ordene los elementos en el array de pasajeros, el orden de los argumentos
*    indica el orden ARRIBA o ABAJO.
*
* \param list Passenger*
* \param len int
* \param order int [1] indica A-Z - [0] indica Z-A
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien.
*
*/
int sortPassengersLastName(Passenger* list, int len, int order)
{
	int retorno = -1;
	int firstLetter;
	int repeticion;
	Passenger hand;

	if (list != NULL && len >= 0 && (order == 0 || order == 1))
	{
		for (int i = 0; i < len; ++i)
		{
			firstLetter = 1;
			repeticion = -1;

			for (int j = i+1; j < len; ++j)
			{
				if (order == 1)
				{
					if (list[i].lastName == list[j].lastName)
					{
						if (list[i].typePassenger > list[j].typePassenger)
						{
							copyPassenger(&hand, &list[i]);
							copyPassenger(&list[i], &list[j]);
							copyPassenger(&list[j], &hand);
						}
					}
					else
					{
						do
						{
							if (list[i].lastName[firstLetter] > list[j].lastName[firstLetter])
							{
								copyPassenger(&hand, &list[i]);
								copyPassenger(&list[i], &list[j]);
								copyPassenger(&list[j], &hand);
								repeticion = 0;
							}
							else if (list[i].lastName[firstLetter] < list[j].lastName[firstLetter]) {repeticion = 0;}
							else
							{
								firstLetter++;
							}

						} while (repeticion != 0);
					}
				}
				else
				{
					if (list[i].lastName == list[j].lastName)
					{
						if (list[i].typePassenger < list[j].typePassenger)
						{
							copyPassenger(&hand, &list[i]);
							copyPassenger(&list[i], &list[j]);
							copyPassenger(&list[j], &hand);
						}
					}
					else
					{
						do
						{
							if (list[i].lastName[firstLetter] < list[j].lastName[firstLetter])
							{
								copyPassenger(&hand, &list[i]);
								copyPassenger(&list[i], &list[j]);
								copyPassenger(&list[j], &hand);
								repeticion = 0;
							}
							else if (list[i].lastName[firstLetter] > list[j].lastName[firstLetter]) { repeticion = 0; }
							else
							{
								firstLetter++;
							}

						} while (repeticion != 0);
					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

/** \brief Imprimir el contenido del array de pasajeros.
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length)
{
	int retorno = -1;
	int retornoListLastName = -1;
	int retornoListFlycode = -1;
	Passenger listLastName[length];
	Passenger listFlycode[length];

	if (list != NULL && length >= 0)
	{
		for (int i = 0; i < length; ++i)
		{
			retornoListLastName = copyPassenger(&listLastName[i], &list[i]);
			retornoListFlycode = copyPassenger(&listFlycode[i], &list[i]);
			if (retornoListLastName != 0 && retornoListFlycode != 0 ) { break; }
			if (list[i+1].isEmpty == 0) { break; }
		}

		if (retornoListLastName == 0 && retornoListFlycode == 0)
		{
			sortPassengersLastName(list, length, 1);
			sortPassengersFlycode(list, length, 1);

			printf("\n");
			for (int i = 0; i < length; ++i)
			{
				printf("\n");
				retornoListLastName = showPassenger(listLastName[i]);
				if (retornoListLastName != 0 || listLastName[i+1].isEmpty == 0) { break; }
			}

			calculatingPricePassenger(list, length);

			printf("\n");
			for (int i = 0; i < length; ++i)
			{
				printf("\n");
				retornoListFlycode = showPassenger(listFlycode[i]);
				if (retornoListFlycode != 0 || listFlycode[i+1].isEmpty == 0) { break; }
			}

			retorno = 0;
		}
	}

	return retorno;
}

/** \brief Ordene los elementos en el array de pasajeros, el orden de los argumentos
*    indica el orden ARRIBA o ABAJO.
*
* \param list Passenger*
* \param len int
* \param order int [1] indica ARRIBA - [0] indica ABAJO
* \return int Devuelve (-1) si hay error [longitud no válida o puntero NULL] - (0) si está bien.
*
*/
int sortPassengersFlycode(Passenger* list, int len, int order)
{
	int retorno = -1;
	int firstLetter;
	int repeticion;
	Passenger hand;

	if (list != NULL && len >= 0 && (order == 0 || order == 1))
	{
		for (int i = 0; i < len; ++i)
		{
			firstLetter = 1;
			repeticion = -1;

			for (int j = i+1; j < len; ++j)
			{
				if (order == 1)
				{
					if (list[i].flycode == list[j].flycode)
					{
						if (list[i].statusFlight > list[j].statusFlight)
						{
							copyPassenger(&hand, &list[i]);
							copyPassenger(&list[i], &list[j]);
							copyPassenger(&list[j], &hand);
						}
					}
					else
					{
						do
						{
							if (list[i].flycode[firstLetter] > list[j].flycode[firstLetter])
							{
								copyPassenger(&hand, &list[i]);
								copyPassenger(&list[i], &list[j]);
								copyPassenger(&list[j], &hand);
								repeticion = 0;
							}
							else if (list[i].flycode[firstLetter] < list[j].flycode[firstLetter]) {repeticion = 0;}
							else
							{
								firstLetter++;
							}

						} while (repeticion != 0);
					}
				}
				else
				{
					if (list[i].flycode == list[j].flycode)
					{
						if (list[i].statusFlight < list[j].statusFlight)
						{
							copyPassenger(&hand, &list[i]);
							copyPassenger(&list[i], &list[j]);
							copyPassenger(&list[j], &hand);
						}
					}
					else
					{
						do
						{
							if (list[i].flycode[firstLetter] < list[j].flycode[firstLetter])
							{
								copyPassenger(&hand, &list[i]);
								copyPassenger(&list[i], &list[j]);
								copyPassenger(&list[j], &hand);
								repeticion = 0;
							}
							else if (list[i].flycode[firstLetter] > list[j].flycode[firstLetter]) { repeticion = 0; }
							else
							{
								firstLetter++;
							}

						} while (repeticion != 0);
					}
				}
			}
		}

		retorno = 0;
	}

	return retorno;
}

/** \brief Copia estructura de pasajeros.
*
* \param listOriginal Passenger*
* \param listCopy Passenger*
* \param length int
* \return int
*
*/
int copyPassenger(Passenger* listCopy, Passenger* listOriginal)
{
	int retorno = -1;
	int largoName = strlen(listOriginal->name);
	int largoLastName = strlen(listOriginal->lastName);
	int largoFlycode = strlen(listOriginal->flycode);

	if (listOriginal != NULL && listCopy != NULL)
	{
		listCopy->id = listOriginal->id;
		strncpy(listCopy->name,listOriginal->name,largoName);
		strncpy(listCopy->lastName,listOriginal->lastName,largoLastName);
		listCopy->price = listOriginal->price;
		listCopy->typePassenger = listOriginal->typePassenger;
		strncpy(listCopy->flycode,listOriginal->flycode,largoFlycode);
		listCopy->statusFlight = listOriginal->statusFlight;
		listCopy->isEmpty = listOriginal->isEmpty;

		retorno = 0;
	}

	return retorno;
}

/** \brief Mostrar pasajero.
*
* \param passenger Passenger
* \return int
*
*/
int showPassenger(Passenger passenger)
{
	int retorno = -1;

	//if (passenger != NULL)
	{
		printf(" Apellido: %s",passenger.lastName);
		printf(" / Nombre: %s",passenger.name);

		switch (passenger.typePassenger)
		{
		case 1:
			printf(" / Tipo de pasajero: Primera clase");
			break;
		case 2:
			printf(" / Tipo de pasajero: Clase ejecutiva o business");
			break;
		case 3:
			printf(" / Tipo de pasajero: Clase premium economy");
			break;
		case 4:
			printf(" / Tipo de pasajero: Clase turista o económica");
			break;
		}

		printf(" / Codigo de vuelo: %s",passenger.flycode);

		switch (passenger.statusFlight)
		{
		case 1:
			printf(" / Estado del vuelo: Activo");
			break;
		case 2:
			printf(" / Estado del vuelo: Cancelado");
			break;
		}

		printf(" / Precio del vuelo: %.2f $",passenger.price);
		printf(" / ID del Pasajero: %d",passenger.id);

		retorno = 0;
	}

	return retorno;
}

/** \brief Calculando y mostrando precios.
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int calculatingPricePassenger(Passenger* list, int length)
{
	int retorno = -1;
	int pasajerosPromedioArriba = 0;
	int contador = 0;
	float total = 0.0f;
	float promedio;

	if (list != NULL && length >= 0)
	{
		for (int i = 0; i < length; ++i)
		{
			total = total + list[i].price;
			contador++;
			if (list[i+1].isEmpty == 0) { break; }
		}

		promedio = total / contador;

		for (int i = 0; i < length; ++i)
		{
			if (list[i].price > promedio)
			{
				pasajerosPromedioArriba++;
			}

			if (list[i+1].isEmpty == 0) { break; }
		}

		printf("\n\n Total de precios de pasajes: %.2f $ / Promedio de precios de pasajes: %.2f $ / Pasajes que superan el promedio: %d", total, promedio, pasajerosPromedioArriba);

		retorno = 0;
	}

	return retorno;
}

/** \brief Genera un numero que siempre aumenta.
*
* \return int Devuelve Devuelve un numero que nunca es igual que el anterior.
*
*/
static int generarId()
{
	static int idContador = 1110;

	return idContador++;
}
