/*
 * dataWereHouse.c
 *
 *  Created on: Oct 14, 2022
 *      Author: advalos
 */
#include "dataWareHouse.h"

int idaerolineas[6] = {1001, 1000, 1001,1003,1000,1003};
int idTipos[6] = {5000, 5002, 5001,5003, 5000,5001};
int capacidad[6] = {10, 100, 300,130,25,56};
int idDestinos[6] = {20001, 20003, 20000,20002,20003,20001};
int idAviones[6] = {1, 2,3,4,5,6};
int dias[6]={26,24,18,15,8,27};
int mes[6]={3,5,12,10,12,11};
int anios[6]={2020,2023,2019,2018,2024,2025};
int idPilotos[6] = {1, 2,3,1,3,2};
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
			(lista + i)->idPiloto = idPilotos[i];
			(lista+ i )->isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
int harcodearVuelos(eVuelo *lista, int tamLista, int cant, int * pId)
{
	int contador = -1;

	if(lista != NULL && tamLista > 0 && cant >= 0 && cant <= tamLista && pId != NULL)
	{
		contador =0;
		for(int i = 0; i < cant; i++)
		{
			(lista + i)->id = *pId;
			(*pId)++;
			(lista + i)->idAvion= idAviones[i];
			(lista + i)->idDestino = idDestinos[i];
			(lista + i)->fecha.dia = dias[i];
			(lista + i)->fecha.mes = mes[i];
			(lista + i)->fecha.anio = anios[i];
			(lista + i )->isEmpty = 0;
			contador++;
		}
	}
	return contador;
}
