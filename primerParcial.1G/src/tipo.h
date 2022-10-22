/*
 * tipo.h
 *
 *  Created on: Oct 21, 2022
 *      Author: advalos
 */

#ifndef TIPO_H_
#define TIPO_H_
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
	int id;
	char descripcion[20];
}eTipo;

int buscarIdExistenteTipo(eTipo* lista, int idComparar ,int tam);
int cargarDescripcionTipo(int idComparar , eTipo *lista, int tamLista, char *descripcion);
#endif /* TIPO_H_ */
