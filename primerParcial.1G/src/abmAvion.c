/*
 * abm.avion.c
 *
 *  Created on: Oct 21, 2022
 *      Author: advalos
 */


#include "abmAvion.h"

int altaAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos, int *pId)
{
	int retorno = 0;
	int indiceLibre;
	eAvion auxAvion;
	if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0 && pId != NULL)
	{
		printf("   **** ALTA AEROLINEA ****\n");
		indiceLibre = buscarLibre(listaAvion ,tamAvion);

		if(indiceLibre == -1)
		{
			printf("No hay lugar\n");
		}else
		{
			auxAvion.id = *pId;
			(*pId)++;

			do{
				mostrarAerolineas(listaAerolinea, tamAerolinea);
			}while(!utn_getEnteroSoloNumeros(&auxAvion.idAerolinea, 6, "Ingrese id Aerolinea: ",
					"Error, intente nuevamente", 3) &&
					!buscarIdExistenteAerolinea(listaAerolinea, auxAvion.idAerolinea ,tamAerolinea));
			do{
				mostrarTipos(listaTipos,tamTipos);
			}while(!utn_getEnteroSoloNumeros(&auxAvion.idTipo, 6, "Ingrese id tipo: ",
					"Error, intente nuevamente", 3) &&
					!buscarIdExistenteTipo(listaTipos, auxAvion.idTipo ,tamTipos));

			do{
				utn_getEnteroSoloNumeros(&auxAvion.capacidad, 4, "Ingrese Capacidad (10-300): ",
						"Error, intente nuevamente", 3);

			}while(auxAvion.capacidad < 10 || auxAvion.capacidad > 300);

			auxAvion.isEmpty =0;
			*(listaAvion + indiceLibre) = auxAvion;
			retorno = 1;

		}

	}


	return retorno;
}
int modificarAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos)
{
	int retorno = 0;
	eAvion auxAvion;
	int opcion;
	char confirma = 'n';
	if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		printf("  ****MODIFICAR AVION ****\n");

		do{
			printf("\n1. tipo");
			printf("\n2. capacidad");
			utn_getEnteroSoloNumeros(&opcion, 2, "Ingrese una opcion: ",
					"Error, intente nuevamente", 3);
		}while(opcion < 1 || opcion > 2);

		do{

			mostrarAviones(listaAvion, tamAvion,listaAerolinea, tamAerolinea, listaTipos,tamTipos);

		}while(!utn_getEnteroSoloNumeros(&auxAvion.id, 20, "Ingrese el id : ",
				"Error, intente nuevamente", 3) &&
				!buscarIdExistenteAvion(listaAvion, auxAvion.id ,tamAvion));
		mostrarAvion(listaAvion, listaAerolinea, tamAerolinea, listaTipos, tamTipos);
		printf("\n¿Confirma moto seleccionada?: ");
		__fpurge(stdin);
		scanf("%c", &confirma);

		if(opcion == 1)
		{
			do{
				mostrarTipos(listaTipos,tamTipos);
			}while(!utn_getEnteroSoloNumeros(&auxAvion.idTipo, 6, "Ingrese id tipo: ",
					"Error, intente nuevamente", 3) &&
					!buscarIdExistenteTipo(listaTipos, auxAvion.idTipo ,tamTipos));
			listaAvion->idTipo = auxAvion.idTipo;

			retorno =1;
		}else
		{
			do{
				utn_getEnteroSoloNumeros(&auxAvion.capacidad, 4, "Ingrese Capacidad (10-300): ",
						"Error, intente nuevamente", 3);

			}while(auxAvion.capacidad < 10 || auxAvion.capacidad > 300);
			listaAvion->capacidad = auxAvion.capacidad;
			retorno =1;
		}


	}

	return retorno;
}
int bajaAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos)
{
	int retorno = 0;
	eAvion auxAvion;
	int indiceAvion;
	char confirma = 'n';
	if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		printf("  ****BAJA AVION ****\n");
		do{

			mostrarAviones(listaAvion, tamAvion,listaAerolinea, tamAerolinea, listaTipos,tamTipos);

		}while(!utn_getEnteroSoloNumeros(&auxAvion.id, 20, "Ingrese el id : ",
				"Error, intente nuevamente", 3) &&
				!buscarAvionPorId(listaAvion, auxAvion.id ,tamAvion, &indiceAvion));
		mostrarAvion((listaAvion + indiceAvion), listaAerolinea, tamAerolinea, listaTipos, tamTipos);

		printf("\n¿Confirma baja?: ");
		__fpurge(stdin);
		scanf("%c", &confirma);
		if(confirma == 's' || confirma =='S')
		{
			(listaAvion + indiceAvion)->isEmpty = 1;
			retorno =1;

		}
	}

	return retorno;
}

