/*
 * ArrayPassenger.h
 *
 *  Created on: 28 abr. 2022
 *      Author: Iván Serna Alegre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Input.h"

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define ELEMENTS 2000

typedef struct
{
	int   id;//identificación
	char  name[51];//Nombre.
	char  lastName[51];//Apellido.
	float price;//Precio del pasaje.
	char  flycode[10];//Código de vuelo.
	int   typePassenger;//Tipo de pasajero.
	int   statusFlight;//Estado del vuelo.
	int   isEmpty;//Esta vacio.
}Passenger;//Espructura pasajero.

int initPassengers(Passenger* list, int len);
int intrDataPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int id, char name[],
	char lastName[],float price,int typePassenger, char flycode[]);
int modifyPassenger(Passenger* list, int len,int id);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int sortPassengersLastName(Passenger* list, int len, int order);
int printPassenger(Passenger* list, int length);
int sortPassengersFlycode(Passenger* list, int len, int order);
int copyPassenger(Passenger* listCopy, Passenger* listOriginal);
int showPassenger(Passenger passenger);
int calculatingPricePassenger(Passenger* list, int length);

#endif /* ARRAYPASSENGER_H_ */
