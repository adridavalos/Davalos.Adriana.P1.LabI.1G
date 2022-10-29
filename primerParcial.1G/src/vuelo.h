/*
 * vuelo.h
 *
 *  Created on: Oct 22, 2022
 *      Author: advalos
 */

#ifndef VUELO_H_
#define VUELO_H_
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;
typedef struct
{
	int id;
	int idAvion;
	int idDestino;
	eFecha fecha;
	int isEmpty;
}eVuelo;

int buscarLibreVuelo(eVuelo *lista , int tam);
int inicializarVuelo(eVuelo *lista, int tam);
#endif /* VUELO_H_ */
