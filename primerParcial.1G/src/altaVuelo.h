/*
 * altaVuelo.h
 *
 *  Created on: Oct 22, 2022
 *      Author: advalos
 */

#ifndef ALTAVUELO_H_
#define ALTAVUELO_H_
#include "mostrar.h"
int altaVuelo(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,
		eDestino *listaDestinos, int tamDestinos,eVuelo *listaVuelos, int tamVuelos,ePiloto *listaPilotos, int tamPilotos, int *pId);
#endif /* ALTAVUELO_H_ */
