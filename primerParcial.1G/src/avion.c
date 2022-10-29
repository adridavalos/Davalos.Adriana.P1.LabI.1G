/*
 * avion.c
 *
 *  Created on: Oct 21, 2022
 *      Author: advalos
 */

#include "avion.h"

int inicializarAvion(eAvion *lista, int tam)
{
	int retorno =0;

	if(lista != NULL && tam > 0)
	{
		for(int i=0; i<tam; i++)
		{
			(lista + i)->isEmpty = 1;
		}
		retorno =1;
	}

	return retorno;
}
int buscarLibreAvion(eAvion *lista , int tam)
{
	int retorno =-1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if((lista+ i)->isEmpty)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int buscarIdExistenteAvion(eAvion* lista, int idComparar ,int tam)
{
	int retorno = 0;

	if(lista != NULL && idComparar >= 0 && tam >0)
	{
		for(int i = 0; i < tam; i++)
		{
			if((lista +i)->id == idComparar && !(lista + i)->isEmpty)
			{
				retorno = 1;
				break;
			}
		}
		if(!retorno)
		{
			printf("\n¡Error, id inexistente!");
		}
	}

	return retorno;
}
int buscarAvionPorId(eAvion* lista, int idComparar ,int tam, int *pPos)
{
	int retorno = 0;

	if(lista != NULL && idComparar >= 0 && tam >0)
	{
		for(int i = 0; i < tam; i++)
		{
			if((lista +i)->id == idComparar && !(lista +i)->isEmpty)
			{
				*pPos = i;
				retorno = 1;
				break;
			}
		}
		if(!retorno)
		{
			printf("\n¡Error, id inexistente!");
		}
	}

	return retorno;
}
int ordenarPorAerolineayCapacidad(eAvion *aviones, int tamAviones, eAerolinea *aerolinea, int tamAero)
{
	int retorno = 0;
	eAvion auxAvion;
	char descripcionI[20];
	char descripcionJ[20];

	if(aviones != NULL && tamAviones >0 && aerolinea != NULL && tamAero >0)
	{
		for(int i = 0; i<tamAviones-1;i++)
		{
			for(int j= i+1; j<tamAviones;j++ )
			{
				cargarDescripcionAerolinea((aviones + i)->idAerolinea , aerolinea, tamAero, descripcionI);
				cargarDescripcionAerolinea((aviones + j)->idAerolinea , aerolinea, tamAero, descripcionJ);

				if(strcmp(descripcionI, descripcionJ)>0 ||(strcmp(descripcionI, descripcionJ) == 0 &&
						(aviones + i)->capacidad > (aviones + j)->capacidad))
				{
					auxAvion = *(aviones + i);
					*(aviones + i) = *(aviones + j);
					*(aviones + j) = auxAvion;
				}
			}
		}
		retorno =1;
	}
	return retorno;
}
