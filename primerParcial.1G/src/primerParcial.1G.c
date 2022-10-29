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
#include "mostrar.h"
#include "dataWareHouse.h"
#include "altaVuelo.h"
#define TAM_LISTA_AEROLINEA 5
#define TAM_LISTA_TIPOS 4
#define TAM_LISTA_AVIONES 10
#define TAM_LISTA_DESTINOS 4
#define TAM_LISTA_VUELOS 10
#define TAM_LISTA_PILOTOS 3
int main(void) {
		char opcion[2];
		int salir =0;
		int nexIdAvion = 1;
		int flagAltaAerolinea =0;
		int nexIdVuelo = 1;
		int opcionInforme;

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

		eDestino destinos[TAM_LISTA_DESTINOS]=
		{
				{20000, "Calafate", 22250},
				{20001, "Miami", 103000,},
				{20002, "Milan", 84400},
				{20003, "Amsterdam",95600}
		};
		ePiloto pilotos[TAM_LISTA_PILOTOS] =
		{
			{1, "Raul", 'm'},
			{2, "Carlos", 'm',},
			{3, "Maria", 'f'}
		};
		eVuelo vuelos[TAM_LISTA_VUELOS];
		if(inicializarAvion(aviones, TAM_LISTA_AVIONES))
		{
			inicializarVuelo(vuelos,TAM_LISTA_VUELOS);
			//UTILICE PARA HARCODEAR
			harcodearAvion(aviones, TAM_LISTA_AVIONES, 4, &nexIdAvion);
			harcodearVuelos(vuelos,TAM_LISTA_VUELOS, 4, &nexIdVuelo);
			flagAltaAerolinea =1;

		}
		do
		{
			mostrarMenu();

			utn_getString(opcion, 2, "INGRESE UNA OPCION: ",  "ERROR. INGRESE OPCION VALIDA", 5);

			switch(*opcion)
			{
			case 'A':

				if(altaAvion(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS, &nexIdAvion))
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
					if(modificarAvion(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS)){
						printf("\n¡Modificacion exitosa!");
					}else{
						printf("\n¡Error, No se pudo modificar!");
					}
				}else
				{
					printf("\nError,  primero realizar alta de avion");

				}

				break;

			case 'C':
				if(flagAltaAerolinea)
				{
					if(bajaAvion(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS)){;
						printf("\n¡Baja exitosa!");
					}else{
						printf("\nError, no se pudo realizar la baja");
					}
				}else
				{
					printf("\nError, primero realizar alta de avion");

				}

				break;

			case 'D':
				if(flagAltaAerolinea)
				{
					ordenarPorAerolineayCapacidad(aviones,TAM_LISTA_AVIONES, aerolineas ,TAM_LISTA_AEROLINEA);
					mostrarAviones(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS);

				}else
				{
					printf("\nError,primero realizar alta de avion");

				}

				break;

			case 'E':
				if(flagAltaAerolinea)
				{
					mostrarAerolineas(aerolineas , TAM_LISTA_AEROLINEA);

				}else
				{
					printf("\nError, primero realizar alta de avion");

				}

				break;

			case 'F':
				if(flagAltaAerolinea)
				{
					mostrarAerolineas(aerolineas , TAM_LISTA_AEROLINEA);
					mostrarTipos(tipos, TAM_LISTA_TIPOS);

				}else
				{
					printf("\nError, primero realizar alta de avion");

				}
				break;

			case 'G':
				if(flagAltaAerolinea)
				{
					mostrarDestino(destinos,TAM_LISTA_DESTINOS);

				}else
				{
					printf("\nError, primero realizar alta de avion");

				}
				break;

			case 'H':
				if(flagAltaAerolinea)
				{

					altaVuelo(aviones, TAM_LISTA_AVIONES, aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,
							destinos,TAM_LISTA_DESTINOS,vuelos,TAM_LISTA_VUELOS,pilotos,TAM_LISTA_PILOTOS , &nexIdVuelo);
					printf("\n¡Alta exitosa!");

				}else
				{
					printf("\nError, primero realizar alta de avion");
				}
				break;
			case 'I':
				if(flagAltaAerolinea)
				{
					mostrarVuelos(vuelos,TAM_LISTA_VUELOS,destinos,TAM_LISTA_DESTINOS,aviones, TAM_LISTA_AVIONES,
							aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS);
				}else
				{
					printf("\nError, primero realizar alta de avion");
				}

				break;
			case 'J':
				if(flagAltaAerolinea)
				{
					mostrarMenuInforme();
					utn_getEnteroSoloNumeros(&opcionInforme, 3,"INGRESE UNA OPCION: ",
							"ERROR. INGRESE OPCION VALIDA", 3);
					switch (opcionInforme) {
					case 1:
						mostrarAvionAerolineaSeleccionado(aviones, TAM_LISTA_AVIONES,aerolineas, TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS);
						break;
					case 2:
						mostrarAvionTipoSeleccionado(aviones, TAM_LISTA_AVIONES,aerolineas, TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS);
						break;
					case 3:
						mostrarPromedioJetsobreAerolinea(aviones, TAM_LISTA_AVIONES,aerolineas, TAM_LISTA_AEROLINEA);
						break;
					case 4:
						mostrarAvionesSeparadosPorAerolinea(aviones, TAM_LISTA_AVIONES,aerolineas, TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS);
						break;
					case 5:
						mostrarAerolineaTransportarMasPasajeros(aviones, TAM_LISTA_AVIONES,aerolineas, TAM_LISTA_AEROLINEA);
						break;
					case 6:
						mostrarAerolineaMenorantidadAviones(aviones, TAM_LISTA_AVIONES,aerolineas, TAM_LISTA_AEROLINEA);
						break;
					case 7:
						mostrarVueloAvionSeleccionado(vuelos,TAM_LISTA_VUELOS,destinos,TAM_LISTA_DESTINOS,aviones, TAM_LISTA_AVIONES,
								aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS);

						break;
					case 8:
						pedirAvionParaCosto(vuelos,TAM_LISTA_VUELOS,destinos,TAM_LISTA_DESTINOS,aviones, TAM_LISTA_AVIONES,
								aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS,pilotos,TAM_LISTA_PILOTOS);

						break;
					case 9:
						pedirDestino(vuelos,TAM_LISTA_VUELOS,destinos,TAM_LISTA_DESTINOS,aviones, TAM_LISTA_AVIONES,
								aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS);

						break;
					case 10:
						pedirUnaFecha(vuelos,TAM_LISTA_VUELOS,destinos,TAM_LISTA_DESTINOS,aviones, TAM_LISTA_AVIONES,
								aerolineas , TAM_LISTA_AEROLINEA, tipos, TAM_LISTA_TIPOS);


						break;
					default:
						printf("\nError, opcion no valida\n");
						break;
					}

				}else
				{
					printf("\nError, primero realizar alta de avion");
				}
				break;
			case 'K':
				salir =1;
				break;
			default:
				printf("\nError, opcion no valida\n");
			}

		}while(salir != 1);

		return EXIT_SUCCESS;
}
