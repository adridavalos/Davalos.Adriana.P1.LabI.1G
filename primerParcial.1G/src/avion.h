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
typedef struct
{
	int id;
	int idAerolinea;
	int idTipo;
	int capacidad;
	int isEmpty;
}eAvion;
int inicializarAvion(eAvion *lista, int tam);
int buscarLibre(eAvion *lista , int tam);
int buscarIdExistenteAvion(eAvion* lista, int idComparar ,int tam);
int buscarAvionPorId(eAvion* lista, int idComparar ,int tam, int *pPos);

#endif /* AVION_H_ */
