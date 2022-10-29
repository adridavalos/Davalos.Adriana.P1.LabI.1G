/*
 * dataWarehouse.h
 *
 *  Created on: Oct 14, 2022
 *      Author: advalos
 */

#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "avion.h"
#include "vuelo.h"

int harcodearAvion(eAvion*lista, int tamLista, int cant, int * pId);
int harcodearVuelos(eVuelo *lista, int tamLista, int cant, int * pId);

#endif /* DATAWAREHOUSE_H_ */
