/*
 * vuelo.c
 *
 *  Created on: Oct 22, 2022
 *      Author: advalos
 */

#include "vuelo.h"
int inicializarVuelo(eVuelo *lista, int tam)
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
int buscarLibreVuelo(eVuelo *lista , int tam)
{
	int retorno =-1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if((lista+ i)->isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
