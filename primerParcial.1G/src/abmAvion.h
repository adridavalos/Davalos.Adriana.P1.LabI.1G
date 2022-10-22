/*
 * abmAvion.h
 *
 *  Created on: Oct 21, 2022
 *      Author: advalos
 */

#ifndef ABMAVION_H_
#define ABMAVION_H_

#include "mostrar.h"
int altaAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipo, int tamTipo, int *pId);
int modificarAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos);
int bajaAvion(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos);
#endif /* ABMAVION_H_ */
