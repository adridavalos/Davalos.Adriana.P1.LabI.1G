/*
 * destino.h
 *
 *  Created on: Oct 22, 2022
 *      Author: advalos
 */

#ifndef DESTINO_H_
#define DESTINO_H_
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
	int id;
	char descripcion[25];
	float precio;
}eDestino;
/// @brief busca si existe ese el id que recibe por parametro
///
/// @param lista es un array de estructura
/// @param idComparar es el id que comparo contra el array
/// @param tam es el tamaño la lista
/// @return retorna 1 si salio bien y 0 si salio mal
int buscarIdExistenteDestino(eDestino* lista, int idComparar ,int tam);
/// @brief carga los datos que se acceden atraves del ID
///
/// @param idComparar idComparar es el id que comparo contra el array
/// @param lista lista es un array de estructura
/// @param tamLista es el tamaño la lista
/// @param descripcion es un parametro tipo puntero de array de char donde escribo la descripcion obtenina
/// @param precio es un parametro tipo puntero donde escribo el precio
/// @return retorna 1 si salio bien y 0 si salio mal
int cargarDescripcionDestinoyPrecio(int idComparar , eDestino *lista, int tamLista, char *descripcion, float *precio);
/// @brief obtine la posicion accediendo por el id
///
/// @param idComparar  es el id que comparo contra el array
/// @param lista es un array de estructura
/// @param tamLista es el tamaño la lista
/// @return retorna la posicion si salio bien y -1 si salio mal
int obtenerPositionPorId(int idComparar , eDestino *lista, int tamLista);
#endif /* DESTINO_H_ */
