/*
 * altaVuelo.c
 *
 *  Created on: Oct 22, 2022
 *      Author: advalos
 */


#include "altaVuelo.h"
int altaVuelo(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,
		eDestino *listaDestinos, int tamDestinos,eVuelo *listaVuelos, int tamVuelos,ePiloto *listaPilotos, int tamPilotos, int *pId)
{
	int retorno = 0;
	int indiceLibre;
	eVuelo auxVuelo;
	if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0 && pId != NULL)
	{
		printf("   **** ALTA VUELO ****\n");
		indiceLibre = buscarLibreVuelo(listaVuelos ,tamVuelos);
		if(indiceLibre == -1)
		{
			printf("No hay lugar\n");
		}else
		{
			auxVuelo.id = *pId;
			(*pId)++;

			do{
				 mostrarAviones(listaAvion,tamAvion, listaAerolinea, tamAerolinea, listaTipos, tamTipos,listaPilotos,tamPilotos);
			}while(!utn_getEnteroSoloNumeros(&auxVuelo.idAvion, 6, "Ingrese id: ",
					"Error, intente nuevamente", 3) &&
					!buscarIdExistenteAvion(listaAvion, auxVuelo.idAvion ,tamAvion));

			do{
				mostrarDestino(listaDestinos,tamDestinos);
			}while(!utn_getEnteroSoloNumeros(&auxVuelo.idDestino, 6, "Ingrese id: ",
					"Error, intente nuevamente", 3) &&
					!buscarIdExistenteDestino(listaDestinos, auxVuelo.idDestino ,tamDestinos));

			if(!utn_getFecha(&auxVuelo.fecha.dia ,&auxVuelo.fecha.mes,&auxVuelo.fecha.anio,11,"\nIngrese fecha: ",
					"Error, fecha no valida", 6))
			{
				auxVuelo.isEmpty = 0;
				*(listaVuelos + indiceLibre) = auxVuelo;
				retorno = 1;
			}else
			{
				printf("\nError, muchos intentos fallidos");
			}
		}
	}
	return retorno;
}
