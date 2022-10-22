/*
 * aerilinea.c
 *
 *  Created on: Oct 21, 2022
 *      Author: advalos
 */


#include "aerolinea.h"

int buscarIdExistenteAerolinea(eAerolinea* lista, int idComparar ,int tam)
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
int cargarDescripcionAerolonea(int idComparar , eAerolinea *lista, int tamLista, char *descripcion)
{
	int retorno =0;
	if(idComparar > 0 && lista != NULL && descripcion != NULL)
	{
		for(int i = 0; i<tamLista;i++)
		{
			if(idComparar == (lista+ i)->id)
			{
				strcpy(descripcion,(lista+ i)->descripcion);
				retorno = 1;
				break;
			}
		}

	}

	return retorno;
}
