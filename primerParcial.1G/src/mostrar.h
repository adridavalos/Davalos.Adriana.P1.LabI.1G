

#ifndef MOSTRAR_H_
#define MOSTRAR_H_
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aerolinea.h"
#include "tipo.h"
#include "avion.h"
#include "abmAvion.h"
#include "utn.h"

void mostrarMenu(void);
int mostrarAerolineas(eAerolinea* lista, int tamList);
int mostrarTipos(eTipo* lista, int tamList);
void mostrarAvion(eAvion *listaAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos);
void mostrarAviones(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos);
#endif /* MOSTRAR_H_ */
