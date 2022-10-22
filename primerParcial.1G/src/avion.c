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
int buscarLibre(eAvion *lista , int tam)
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
			if((lista +i)->id == idComparar)
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
/*int ordenarAvionTipoyId(eAvion *aviones, int tam, eTipo *tipos,int tamTipos)
{
	int retorno = 0;
	eAvion auxMoto;
	char descripcionA[20];
	char descripcionJ[20];

	if(aviones != NULL && tam >0)
	{
		for(int i = 0; i<tam-1;i++)
		{
			for(int j= i+1; j<tam;j++ )
			{
				cargarDescripcionTipo((aviones + i)->idTipo, tipos, tamTipos, descripcionI);
				cargarDescripcionAerolonea(int idComparar , eAerolinea *lista, int tamLista, char *descripcion)
				cargarDescripcionTipo((aviones + j)->idTipo, tipos, tamTipos, descripcionJ);

				if(strcmp(descripcionI, descripcionJ)>0 ||(strcmp(descripcionI, descripcionJ) == 0 &&
						(aviones + i)->id > (aviones + j)->id))
				{
					auxMoto = *(aviones + i);
					*(aviones + i) = *(aviones + j);
					*(aviones + j) = auxMoto;
				}
			}
		}
		retorno =1;
	}
	return retorno;
}*/
