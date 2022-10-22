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
