/*
 ============================================================================
 Name        : TP_[01].c
 Author      : Iván Wesley Serna Alegre
 Version     : 1.0
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	//Variables.
	float kilometros;

	float precioVueloAerolineas, precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario;

	float precioVueloLatam, precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario;

	float diferenciaPrecios;

	int error = 0;
	const float porcentajeDebito = 10;
	const float porcentajeCredito = 25;
	const float valorBitcoin = 4606954.55;
	const char descuentoDebito = 'R';
	const char interecesCredito = 'S';

	//Ingresando kilometros.
	GetFloat("\n Ingresar Kilómetros: ",-1,0,9999999,"\n El número ingresado no cumple con los parametros.\n Ingrese un valor mayor a cero.",&kilometros);

	//Ingresando precios.
	printf("\n Ingresar Precio de Vuelos");
	GetFloat(" - Precio vuelo Aerolíneas: ",-1,0,9999999,"\n El número ingresado no cumple con los parametros.\n Ingrese un valor mayor a cero.",&precioVueloAerolineas);
	GetFloat(" - Precio vuelo Latam: ",-1,0,9999999,"\n El número ingresado no cumple con los parametros.\n Ingrese un valor mayor a cero.",&precioVueloLatam);
	system("cls");//Limpiando pantalla.

	//Calculando descuentos de tarjeta de debito.
	error = DescuentoIntereses(&precioAerolineasDebito,precioVueloAerolineas,porcentajeDebito,descuentoDebito);
	if (error != 0) { printf("\n Error [precioAerolineasDebito]"); error = 0; }
	error = DescuentoIntereses(&precioLatamDebito,precioVueloLatam,porcentajeDebito,descuentoDebito);
	if (error != 0) { printf("\n Error [precioLatamDebito]"); error = 0; }

	//Calculando intereses de tarjeta de credito.
	error = DescuentoIntereses(&precioAerolineasCredito,precioVueloAerolineas,porcentajeCredito,interecesCredito);
	if (error != 0) { printf("\n Error [precioAerolineasCredito]"); error = 0; }
	error = DescuentoIntereses(&precioLatamCredito,precioVueloLatam,porcentajeCredito,interecesCredito);
	if (error != 0) { printf("\n Error [precioLatamCredito]"); error = 0; }

	//Convercion de pesos a bitcoin.
	error = ConversorBitcoinUnitario(&precioAerolineasBitcoin,precioVueloAerolineas,valorBitcoin);
	if (error != 0) { printf("\n Error [precioAerolineasBitcoin]"); error = 0; }
	error = ConversorBitcoinUnitario(&precioLatamBitcoin,precioVueloLatam,valorBitcoin);
	if (error != 0) { printf("\n Error [precioLatamBitcoin]"); error = 0; }

	//Calculando precio unitario.
	error = ConversorBitcoinUnitario(&precioAerolineasUnitario,precioVueloAerolineas,kilometros);
	if (error != 0) { printf("\n Error [precioAerolineasUnitario]"); error = 0; }
	error = ConversorBitcoinUnitario(&precioLatamUnitario,precioVueloLatam,kilometros);
	if (error != 0) { printf("\n Error [precioLatamUnitario]"); error = 0; }

	//Calculando diferencia de precios.
	error = DiferenciaPrecios(&diferenciaPrecios,precioVueloLatam,precioVueloAerolineas);
	if (error != 0) { printf("\n Error [precioLatamUnitario]"); error = 0; }

	//Mostrando datos obtenidos.
	printf("\n KMs ingresados: %.2f km\n",kilometros);

	printf("\n Precio Aerolíneas: $%.2f",precioVueloAerolineas);
	printf("\n a) Precio con tarjeta de débito: $ %.2f",precioAerolineasDebito);
	printf("\n b) Precio con tarjeta de crédito: $ %.2f",precioAerolineasCredito);
	printf("\n c) Precio pagando con bitcoin: $ %.2f BTC",precioAerolineasBitcoin);
	printf("\n d) Precio unitario: $ %.2f\n",precioAerolineasUnitario);

	printf("\n Precio Latam: $%.2f",precioVueloLatam);
	printf("\n a) Precio con tarjeta de débito: $ %.2f",precioLatamDebito);
	printf("\n b) Precio con tarjeta de crédito: $ %.2f",precioLatamCredito);
	printf("\n c) Precio pagando con bitcoin: $ %.2f BTC",precioLatamBitcoin);
	printf("\n d) Precio unitario: $ %.2f\n",precioLatamUnitario);

	printf("\n La diferencia de precio es: $ %.2f",diferenciaPrecios);

	return EXIT_SUCCESS;
}
