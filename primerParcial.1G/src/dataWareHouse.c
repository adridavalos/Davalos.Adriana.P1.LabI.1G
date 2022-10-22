/*
 * dataWereHouse.c
 *
 *  Created on: Oct 14, 2022
 *      Author: advalos
 */
#include "dataWareHouse.h"

int idaerolineas[4] = {1001, 1000, 1001,1003};
int idTipos[4] = {5000, 5002, 5001,5003};
int capacidad[4] = {10, 100, 300,130};


int harcodearAvion(eAvion*lista, int tamLista, int cant, int * pId)
{
	int contador = -1;

	if(lista != NULL && tamLista > 0 && cant >= 0 && cant <= tamLista && pId != NULL)
	{
		contador =0;
		for(int i = 0; i < cant; i++)
		{
			(lista + i)->id = *pId;
			(*pId)++;
			(lista + i)->idAerolinea = idaerolineas[i];
			(lista + i)->idTipo = idTipos[i];
			(lista + i)->capacidad = capacidad[i];
			(lista+ i )->isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
