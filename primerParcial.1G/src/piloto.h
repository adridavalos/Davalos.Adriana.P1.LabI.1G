/*
 * piloto.h
 *
 *  Created on: Oct 28, 2022
 *      Author: advalos
 */

#ifndef PILOTO_H_
#define PILOTO_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int id;
	char nombre[20];
	char sexo;

}ePiloto;
int buscarIdExistentePiloto(ePiloto* lista, int idComparar ,int tam);
int cargarDescripcionPiloto(int idComparar , ePiloto *lista, int tamLista, char *descripcion);
#endif /* PILOTO_H_ */
