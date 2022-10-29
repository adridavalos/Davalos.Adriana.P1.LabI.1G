/*
 * avion.h
 *
 *  Created on: Oct 21, 2022
 *      Author: advalos
 */

#ifndef AVION_H_
#define AVION_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aerolinea.h"

typedef struct
{
	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
	int idPiloto;
	int isEmpty;
}eAvion;
/// @brief inicializa el listado de avion
///
/// @param lista la lista a inicializar
/// @param tam el tamaño de la lista a inicializar
/// @return retorna 1 si salio bien o 0 si salio mal
int inicializarAvion(eAvion *lista, int tam);
/// @brief busca la posicion libre de la lista y lo retorna
///
/// @param lista es la lista recorrida
/// @param tam es el tamaño de la lista
/// @return retorno el indice si lo encontro y de lo contrario -1
int buscarLibreAvion(eAvion *lista , int tam);
/// @brief recorre la lista y verifica si existe el id que recibe por parametro
///
/// @param lista es la lista recorrida
/// @param idComparar es el id que recibe por parametro para validar
/// @param tam es el tamaño de la lista
/// @return retorna 1 si salio bien o 0 si salio mal
int buscarIdExistenteAvion(eAvion* lista, int idComparar ,int tam);
int buscarAvionPorId(eAvion* lista, int idComparar ,int tam, int *pPos);
int ordenarPorAerolineayCapacidad(eAvion *aviones, int tamAviones, eAerolinea *aerolinea, int tamAero);

#endif /* AVION_H_ */
