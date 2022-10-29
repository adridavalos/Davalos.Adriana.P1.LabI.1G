

#ifndef MOSTRAR_H_
#define MOSTRAR_H_
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aerolinea.h"
#include "tipo.h"
#include "piloto.h"
#include "avion.h"
#include "abmAvion.h"
#include "destino.h"
#include "vuelo.h"
#include "utn.h"


void mostrarMenu(void);
int mostrarAerolineas(eAerolinea* lista, int tamList);
int mostrarTipos(eTipo* lista, int tamList);
int mostrarPiloto(ePiloto* lista, int tamList);
void mostrarAvion(eAvion *listaAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos, ePiloto *listaPilotos, int tamPilotos);
void mostrarAviones(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);
int mostrarDestino(eDestino* lista, int tamList);
void mostrarVuelo(eVuelo *listaVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion,
		eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos);
void mostrarVuelos(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion,
		int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos);
void mostrarMenuInforme(void);
//Informe

int mostrarAvionAerolineaSeleccionado(eAvion *aviones, int tamAviones,eAerolinea *aerolineas,int tamAerolineas, eTipo *tipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);

int mostrarAvionesAerolineaSeleccionado(int idAerolinea, eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);

int mostrarAvionTipoSeleccionado(eAvion *aviones, int tamAviones,eAerolinea *aerolineas,int tamAerolineas, eTipo *tipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);
int mostrarAvionesTipoSeleccionado(int idTipo, eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);
int mostrarPromedioJetsobreAerolinea(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea);

int mostrarAvionesSeparadosPorAerolinea(eAvion *aviones, int tamAviones,eAerolinea *aerolineas,int tamAerolineas, eTipo *tipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);
int mostrarAerolineaTransportarMasPasajeros(eAvion *aviones, int tamAviones,eAerolinea *aerolineas,int tamAerolineas);
int mostrarAerolineaMenorantidadAviones(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea);
int mostrarVuelosAvionSeleccionado(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos ,int idAvion);
int mostrarVueloAvionSeleccionado(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);
int pedirAvionParaCosto(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos);
int mostrarCostoVuelosRealizados(eVuelo *listaVuelos, int tamVuelos,eAvion *listaAvion, int tamAvion, eDestino *listaDestino,int tamDestino, int idAvion);
int pedirDestino(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamDestinos,eAvion *listaAvion,
		int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos);
int mostrarAvionesQueVolaronPorDEstino(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion,
		int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos ,int idDestino);
int mostrarAvionesQueVolaronPorFecha(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion,
		eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos ,int dia, int mes, int anio);
int pedirUnaFecha(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamDestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos);

#endif /* MOSTRAR_H_ */
