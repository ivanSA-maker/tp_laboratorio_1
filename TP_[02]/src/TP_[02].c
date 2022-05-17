/*
 ============================================================================
 Name        : TP_[02].c
 Author      : Iván Serna Alegre
 Version     :
 Description : Una aerolínea requiere un sistema para administrar los pasajeros de cada vuelo. Se sabe
			   que no puede tener más de 2000 pasajeros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayPassenger.h"

int main(void)
{
	//Variables.
	int inputMenu;
	int idBuscar;
	Passenger ListaPasajeros[ELEMENTS];

	//Inicializando lista de pasajeros.
	initPassengers(ListaPasajeros,ELEMENTS);

	//Menu.
	do
	{
		GetNum("\n [1: ALTAS]\n [2: MODIFICAR]\n [3: BAJA]\n [4: INFORMAR]\n [0: Salir]\n : ",-1,0,4,"\n No has ingresado una opcion valida.",&inputMenu);

		switch (inputMenu)
		{
		case 1:
			inputMenu = intrDataPassengers(ListaPasajeros, ELEMENTS);
			break;
		case 2:
			GetNum(" Ingrese ID del pasajero a modificar: ",3,1111,9999999,"\n No has ingresado una opcion valida.",&idBuscar);

			if ((modifyPassenger(ListaPasajeros, ELEMENTS, idBuscar)) != 0)
			{
				printf("\n Error al ingresar ID, en MODIFICAR.");
			}
			break;
		case 3:
			GetNum(" Ingrese ID del pasajero a dar de baja: ",3,1111,9999999,"\n No has ingresado una opcion valida.",&idBuscar);

			if ((removePassenger(ListaPasajeros, ELEMENTS, idBuscar)) != 0)
			{
				printf("\n Error al ingresar ID, en MODIFICAR.");
			}
			break;
		case 4:
			if ((printPassenger(ListaPasajeros, ELEMENTS)) != 0)
			{
				printf("\n Error al intentar INFORMAR.");
			}
			break;
		}

	} while (inputMenu > 0 && inputMenu <= 4);

	return EXIT_SUCCESS;
}
