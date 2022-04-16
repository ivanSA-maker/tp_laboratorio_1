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

	const float porcentajeDebito = 10;
	const float porcentajeCredito = 25;
	const float valorBitcoin = 4606954.55;
	const char descuentoDebito = 'R';
	const char interecesCredito = 'S';

	//Ingresando kilometros.
	GetFloat("\n Ingresar Kilómetros: ",-1,0,9999999,"\n El número ingresado no cumple con los parametros.\n Ingrese un valor mayor a cero.",&kilometros);

	//Ingresando precios.
	printf("\n Ingresar Precio de Vuelos\n");
	GetFloat(" - Precio vuelo Aerolíneas: ",-1,0,9999999,"\n El número ingresado no cumple con los parametros.\n Ingrese un valor mayor a cero.",&precioVueloAerolineas);
	GetFloat(" - Precio vuelo Latam: ",-1,0,9999999,"\n El número ingresado no cumple con los parametros.\n Ingrese un valor mayor a cero.",&precioVueloLatam);
	//system("cls");//Limpiando pantalla.

	//Calculando descuentos de tarjeta de debito.
	DescuentoIntereses(&precioAerolineasDebito,precioVueloAerolineas,porcentajeDebito,descuentoDebito);
	DescuentoIntereses(&precioLatamDebito,precioVueloLatam,porcentajeDebito,descuentoDebito);

	//Calculando intereses de tarjeta de credito.
	DescuentoIntereses(&precioAerolineasCredito,precioVueloAerolineas,porcentajeCredito,interecesCredito);
	DescuentoIntereses(&precioLatamCredito,precioVueloLatam,porcentajeCredito,interecesCredito);

	//Convercion de pesos a bitcoin.
	ConversorBitcoinUnitario(&precioAerolineasBitcoin,precioVueloAerolineas,valorBitcoin);
	ConversorBitcoinUnitario(&precioLatamBitcoin,precioVueloLatam,valorBitcoin);

	//Calculando precio unitario.
	ConversorBitcoinUnitario(&precioAerolineasUnitario,precioVueloAerolineas,kilometros);
	ConversorBitcoinUnitario(&precioLatamUnitario,precioVueloLatam,kilometros);

	//Calculando diferencia de precios.
	DiferenciaPrecios(&diferenciaPrecios,precioVueloLatam,precioVueloAerolineas);

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
