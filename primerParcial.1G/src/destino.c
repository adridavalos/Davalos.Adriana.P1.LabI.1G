/*
 * destino.c
 *
 *  Created on: Oct 22, 2022
 *      Author: advalos
 */


#include "destino.h"
int buscarIdExistenteDestino(eDestino* lista, int idComparar ,int tam)
{
	int retorno = 0;
	int posicion;

	posicion = obtenerPositionPorId(idComparar, lista, tam);
	if(posicion != -1){
		retorno = 1;
	}
	return retorno;
}
int cargarDescripcionDestinoyPrecio(int idComparar , eDestino *lista, int tamLista, char *descripcion, float *precio)
{
	int retorno = 0;
	int posicion;
	posicion = obtenerPositionPorId(idComparar,lista,tamLista);

	if(posicion != -1){
		strcpy(descripcion,(lista+ posicion)->descripcion);
		*precio = (lista +posicion)->precio;
		retorno = 1;
	}

	return retorno;
}

int obtenerPositionPorId(int idComparar , eDestino *lista, int tamLista){
	int retorno =-1;
		if(idComparar > 0 && lista != NULL)
		{
			for(int i = 0; i<tamLista;i++)
			{
				if(idComparar == (lista+ i)->id)
				{
					retorno = i;
					break;
				}
			}

		}

		return retorno;
}
