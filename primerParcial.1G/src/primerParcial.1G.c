/*
 ============================================================================
 Name        : Davalos Insaurralde Adriana Maria
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "mostrar.h"
#include "dataWareHouse.h"
#define TAM_LISTA_AEROLINEA 5
#define TAM_LISTA_TIPOS 4
#define TAM_LISTA_AVIONES 10
int main(void) {
		char opcion;
		int salir =0;
		int nexIdAvion = 1;
		int flagAltaAerolinea =0;

		eAerolinea aerolineas [TAM_LISTA_AEROLINEA] =
			{
					{1000, "Lan"},
					{1001, "Iberia"},
					{1002, "Norwegian"},
					{1003, "American"},
					{1004, "Austral"}
			};
		eTipo tipos [TAM_LISTA_TIPOS] =
		{
					{5000, "Jet"},
					{5001, "Helice"},
					{5002, "Planeador"},
					{5003, "Carga"}
		};
		eAvion aviones[TAM_LISTA_AVIONES];
		if(inicializarAvion(aviones, TAM_LISTA_AVIONES))
		{
			//UTILICE PARA HARCODEAR
			//harcodearAvion(aviones, TAM_LISTA_AVIONES, 4, &nexIdAvion);
			//flagAltaAerolinea =1;

		}
		do
		{
			mostrarMenu();
			utn_getString(&opcion, 2, "INGRESE LA OPCION: ",  "ERROR. INGRESE OPCION VALIDA", 5);
			switch(opcion)
			{
			case 'A':
				if(altaAvion(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS, &nexIdAvion))
				{
					printf("\n¡Alta exitosa!");
					flagAltaAerolinea =1;
				}else
				{
					printf("\nError, el alta no se pudo realizar");
				}
				;
				break;

			case 'B':
				if(flagAltaAerolinea)
				{
					modificarAvion(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS);
					printf("\n¡Modificacion exitosa!");
				}else
				{
					printf("\nError, no se pudo modificar");

				}

				break;

			case 'C':
				if(flagAltaAerolinea)
				{
					bajaAvion(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS);
					printf("\n¡Baja exitosa!");
				}else
				{
					printf("\nError, no se pudo realizar la baja");

				}

				break;

			case 'D':
				if(flagAltaAerolinea)
				{
					mostrarAviones(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS);

				}else
				{
					printf("\nError, primero realizar alta");

				}

				break;

			case 'E':
				if(flagAltaAerolinea)
				{
					mostrarAerolineas(aerolineas , TAM_LISTA_AEROLINEA);

				}else
				{
					printf("\nError, primero realizar alta");

				}

				break;

			case 'F':
				if(flagAltaAerolinea)
				{
					mostrarAerolineas(aerolineas , TAM_LISTA_AEROLINEA);
					mostrarTipos(tipos, TAM_LISTA_TIPOS);

				}else
				{
					printf("\nError, primero realizar alta");

				}

				break;

			case 'G':


				break;

			case 'H':

				break;
			case 'I':

				break;
			case 'J':
				salir =1;
				break;
			default:
				printf("\nError, opcion no valida\n");
			}

		}while(salir != 1);

		return EXIT_SUCCESS;
}
