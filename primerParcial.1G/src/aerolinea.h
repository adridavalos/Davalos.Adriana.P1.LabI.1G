/*
 * aerilinea.h
 *
 *  Created on: Oct 21, 2022
 *      Author: advalos
 */

#ifndef AEROLINEA_H_
#define AEROLINEA_H_

#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
	int id;
	char descripcion[20];
}eAerolinea;

int buscarIdExistenteAerolinea(eAerolinea* lista, int idComparar ,int tam);
int cargarDescripcionAerolonea(int idComparar , eAerolinea *lista, int tamLista, char *descripcion);
#endif /* AEROLINEA_H_ */
