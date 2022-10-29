/*
 * abmAvion.h
 *
 *  Created on: Oct 21, 2022
 *      Author: advalos
 */

#ifndef ABMAVION_H_
#define ABMAVION_H_

#include "mostrar.h"
int altaAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos, ePiloto *listaPilotos, int tamPilotos, int *pId);
int modificarAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);
int bajaAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);
#endif /* ABMAVION_H_ */
