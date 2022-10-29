#include "mostrar.h"

void mostrarMenu(void)
{
	printf("\n***MENU DE OPCIONES ***\n");
		printf("A- ALTA AVION\n");
		printf("B- MODIFICAR AVION\n");
		printf("C- BAJA AVION\n");
		printf("D- LISTAR AVIONES\n");
		printf("E- LISTAR AEROLINEAS\n");
		printf("F- LISTAR TIPOS\n");
		printf("G- LISTAR DESTINOS\n");
		printf("H- ALTA VUELO\n");
		printf("I- LISTAR VUELOS\n");
		printf("J- INFORMES\n");
		printf("k- Salir\n");
}


int mostrarAerolineas(eAerolinea* lista, int tamList)
{
	int retorno =0;
	if(lista != NULL && tamList > 0)
	{
		printf("\n*AEROLINEAS DISPONIBLES*\n");
		printf("======================\n");
		printf("|  ID  |  AEROLINEA  |\n");
		printf("----------------------\n");
		for(int i =0; i< tamList;i++)
		{
			printf("| %d |  %-10s |\n",
					(lista + i)->id,
					(lista + i)->descripcion
					);
		}
		printf("======================\n");
		retorno = 1;
	}
	return retorno;
}
int mostrarTipos(eTipo* lista, int tamList)
{
	int retorno =0;
	if(lista != NULL && tamList > 0)
	{
		printf("\n*TIPOS DISPONIBLES*\n");
		printf("======================\n");
		printf("|  ID  |   TIPO      |\n");
		printf("----------------------\n");
		for(int i =0; i< tamList;i++)
		{
			printf("| %d |  %-10s |\n",
					(lista + i)->id,
					(lista + i)->descripcion
					);
		}
		printf("======================\n");
		retorno = 1;
	}
	return retorno;
}
int mostrarPiloto(ePiloto* lista, int tamList)
{
	int retorno =0;
	if(lista != NULL && tamList > 0)
	{
		printf("\n *PILOTOS DISPONIBLES*\n");
		printf("=============================\n");
		printf("|  ID  |   TIPO      | SEXO |\n");
		printf("-----------------------------\n");
		for(int i =0; i< tamList;i++)
		{
			printf("| %d |  %-10s |  %c  |\n",
					(lista + i)->id,
					(lista + i)->nombre,
					(lista + i)->sexo
					);
		}
		printf("======================\n");
		retorno = 1;
	}
	return retorno;
}
void mostrarAvion(eAvion *listaAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos, ePiloto *listaPilotos, int tamPilotos)
{
	char descripcionAerolinea[20];
	char descripcionTipo[20];
	char descripcionPiloto[20];

	if(listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		cargarDescripcionAerolinea(listaAvion->idAerolinea , listaAerolinea, tamAerolinea, descripcionAerolinea);
		cargarDescripcionTipo(listaAvion->idTipo ,listaTipos, tamTipos, descripcionTipo);
		cargarDescripcionPiloto(listaAvion->idPiloto ,listaPilotos, tamPilotos, descripcionPiloto);
		printf("|  %d |	%-10s|  %-10s  |    %3d    |  %-8s  |\n",
				listaAvion->id,
				descripcionAerolinea,
				descripcionTipo,
				listaAvion->capacidad,
				descripcionPiloto
		);
	}
}
void mostrarAviones(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos)
{
	if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		printf("\n           ****LISTA AVIONES ***\n");
		printf("==========================================================\n");
		printf("| ID | AEROLINEA  |     TIPO     | CAPACIDAD |   NOMBRE  |\n");
		printf("----------------------------------------------------------\n");

		for(int i =0; i< tamAvion;i++)
		{
			if(!(listaAvion + i)->isEmpty)
			{
				mostrarAvion((listaAvion +i),listaAerolinea, tamAerolinea,listaTipos, tamTipos,listaPilotos,tamPilotos);
			}
		}
		printf("==========================================================\n");

	}
}
int mostrarDestino(eDestino* lista, int tamList)
{
	int retorno =0;
	if(lista != NULL && tamList > 0)
	{
		printf("\n     *DESTINOS DISPONIBLES*\n");
		printf("======================================\n");
		printf("|  ID   |  DESTINOS  |    PRECIO    |\n");
		printf("--------------------------------------\n");
		for(int i =0; i< tamList;i++)
		{
			printf("| %d |  %-10s |  %10.2f  |\n",
					(lista + i)->id,
					(lista + i)->descripcion,
					(lista + i)->precio
					);
		}
		printf("======================================\n");
		retorno = 1;
	}
	return retorno;
}

void mostrarVuelo(eVuelo *listaVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos)
{
	char descripcionAerolinea[20];
	char descripcionTipo[20];
	char descripcionDestino[25];
	int posicionAvion;
	float precioDestino;
	buscarAvionPorId(listaAvion,listaVuelos->idAvion,tamAvion, &posicionAvion);
	if(listaVuelos != NULL && listaDestinos != NULL && tamdestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		cargarDescripcionAerolinea((listaAvion + posicionAvion)->idAerolinea , listaAerolinea, tamAerolinea, descripcionAerolinea);
		cargarDescripcionTipo((listaAvion + posicionAvion)->idTipo ,listaTipos, tamTipos, descripcionTipo);
		cargarDescripcionDestinoyPrecio( listaVuelos->idDestino, listaDestinos , tamdestinos, descripcionDestino, &precioDestino);
		printf("|  %d |	%-10s|  %-10s  |    %3d    |   %-10s | %10.2f | %.2d/%.2d/%d |\n",
				listaVuelos->id,
				descripcionAerolinea,
				descripcionTipo,
				(listaAvion + posicionAvion)->capacidad,
				descripcionDestino,
				precioDestino,
				listaVuelos->fecha.dia,
				listaVuelos->fecha.mes,
				listaVuelos->fecha.anio
		);
	}

}
void mostrarVuelos(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos)
{
	if(listaVuelos != NULL && tamVuelos >0 &&listaDestinos != NULL && tamdestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		printf("\n                          ****LISTA VUELOS ***\n");
		printf("======================================================================================\n");
		printf("| ID | AEROLINEA  |     TIPO     | CAPACIDAD |   DESTINOS   |   PRECIO   |   FECHA    |\n");
		printf("--------------------------------------------------------------------------------------\n");

		for(int i =0; i< tamVuelos;i++)
		{
			if((listaVuelos + i)->isEmpty == 0)
			{
				mostrarVuelo((listaVuelos + i) ,listaDestinos, tamdestinos, listaAvion, tamAvion, listaAerolinea,tamAerolinea, listaTipos, tamTipos);
			}
		}
		printf("======================================================================================\n");

	}
}
void mostrarMenuInforme(void)
{
	printf("\n***INFORME***\n");
	printf("1.  Mostrar aviones de la aerolínea seleccionada por el usuario.\n");
	printf("2.  Mostrar aviones de un tipo seleccionado.\n");
	printf("3.  Informar porcentaje de aviones jet sobre el total de aviones de una aerolínea\n");
	printf("4.  Mostrar un listado de los aviones separados por aerolínea.\n");
	printf("5.  Informar la o las aerolíneas que pueden transportar mas pasajeros\n");
	printf("6.  Mostrar la aerolínea con menor cantidad de aviones\n");
	printf("7.  Pedir un avión y mostrar todos los vuelos que hizo el mismo.\n");
	printf("8.  Pedir un avión e informar la suma de los precios (costo) de todos los vuelos que realizo\n");
	printf("9.  Pedir un destino y mostrar los aviones que volaron a ese destino y en qué fecha\n");
	printf("10. Pedir una fecha y mostrar todos los vuelos realizados en la misma.\n");
}
//Informe
int mostrarAvionAerolineaSeleccionado(eAvion *aviones, int tamAviones,eAerolinea *aerolineas,int tamAerolineas, eTipo *tipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos)
{
	int retorno =0;

		int idAerolinea;
		if(aviones != NULL && tamAviones >0 && aerolineas !=NULL && tamAerolineas >0)
		{
			do{
				mostrarAerolineas(aerolineas, tamAerolineas);
			}while(!utn_getEnteroSoloNumeros(&idAerolinea, 6, "Ingrese id Aerolinea: ",
					"Error, intente nuevamente", 3) &&
					!buscarIdExistenteAerolinea(aerolineas, idAerolinea ,tamAerolineas));

			mostrarAvionesAerolineaSeleccionado(idAerolinea, aviones, tamAviones, aerolineas, tamAerolineas, tipos, tamTipos,listaPilotos, tamPilotos);

				retorno = 1;
		}

		return retorno;
}
int mostrarAvionesAerolineaSeleccionado(int idAerolinea, eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos)
{
	int retorno;
	int flag = 1;
	char descripcionAerolinea[20];
	if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		printf("\n           ****LISTA AVIONES ***\n");
		printf("==========================================================\n");
		printf("| ID | AEROLINEA  |     TIPO     | CAPACIDAD |   NOMBRE  |\n");
		printf("----------------------------------------------------------\n");

		for(int i =0; i< tamAvion;i++)
		{
			if(!(listaAvion + i)->isEmpty &&(listaAvion + i)->idAerolinea == idAerolinea)
			{
				mostrarAvion((listaAvion +i),listaAerolinea, tamAerolinea,listaTipos, tamTipos,listaPilotos, tamPilotos);
				flag =0;
			}
		}
		printf("========================================================\n");
		if(flag)
		{
			cargarDescripcionAerolinea(idAerolinea ,listaAerolinea, tamAerolinea, descripcionAerolinea);
			printf("No hay aviones en esta aerolinea %s\n", descripcionAerolinea);
		}
		retorno = 1;
	}
	return retorno;
}
int mostrarAvionTipoSeleccionado(eAvion *aviones, int tamAviones,eAerolinea *aerolineas,int tamAerolineas, eTipo *tipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos)
{
	int retorno =0;

		int idTipo;
		if(aviones != NULL && tamAviones > 0 &&  aerolineas != NULL && tamAerolineas > 0 && tipos !=NULL && tamTipos > 0)
			{
			do{
				mostrarTipos(tipos,tamTipos);
			}while(!utn_getEnteroSoloNumeros(&idTipo, 6, "Ingrese id tipo: ",
					"Error, intente nuevamente", 3) &&
					!buscarIdExistenteTipo(tipos, idTipo ,tamTipos));

			mostrarAvionesTipoSeleccionado(idTipo, aviones, tamAviones, aerolineas, tamAerolineas, tipos, tamTipos, listaPilotos, tamPilotos);

				retorno = 1;
		}

		return retorno;
}
int mostrarAvionesTipoSeleccionado(int idTipo, eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos)
{
	int retorno;
	int flag = 1;
	char descripcionAerolinea[20];
	if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		printf("\n           ****LISTA AVIONES ***\n");
				printf("==========================================================\n");
				printf("| ID | AEROLINEA  |     TIPO     | CAPACIDAD |   NOMBRE  |\n");
				printf("----------------------------------------------------------\n");

		for(int i =0; i< tamAvion;i++)
		{
			if(!(listaAvion + i)->isEmpty &&(listaAvion + i)->idTipo == idTipo)
			{
				mostrarAvion((listaAvion +i),listaAerolinea, tamAerolinea,listaTipos, tamTipos,listaPilotos, tamPilotos);
				flag =0;
			}
		}
		printf("=================================================================\n");
		if(flag)
		{
			cargarDescripcionAerolinea(idTipo ,listaAerolinea, tamAerolinea, descripcionAerolinea);
			printf("No hay aviones de este tipo: %s\n", descripcionAerolinea);
		}
		retorno = 1;
	}
	return retorno;
}
 //printf("3.  Informar porcentaje de aviones jet sobre el total de aviones de una aerolínea\n");
 int mostrarPromedioJetsobreAerolinea(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea)
 {
	 int retorno = 0;
	 int contadorAerolineas[]={0,0,0,0,0};
	 int contadorTipoJet[] = {0,0,0,0,0};
	 char descripcionAerolinea[20];

	int porcentaje;
	 if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0)
	 {

		 for(int i =0;i<tamAerolinea;i++)
		 {
			 for(int j=0;j<tamAvion; j++)
			 {
				 if(!(listaAvion +j)->isEmpty && (listaAvion +j)->idAerolinea == (listaAerolinea +i)->id)
				 {
					(*(contadorAerolineas + i))++;

					 if((listaAvion + j)->idTipo == 5000)
					 {
						 (*(contadorTipoJet + i))++;

					 }
				 }
			 }
			 cargarDescripcionAerolinea((listaAerolinea + i)->id ,listaAerolinea, tamAerolinea, descripcionAerolinea);
			 if(*(contadorAerolineas +i) >0 && *(contadorTipoJet + i) >=1)
			 {
				 porcentaje = (*(contadorTipoJet + i) * 100)/ *(contadorAerolineas + i);
				 printf("\nEl promedio de jet de %s es : %d porciento",descripcionAerolinea, porcentaje);
			 }else{
				 printf("\nLa aerolinea %s, no tiene avines tipo jet",descripcionAerolinea);
			 }

		 }
	 }
	 return retorno;
 }
 //printf("4.  Mostrar un listado de los aviones separados por aerolínea.\n");

int mostrarAvionesSeparadosPorAerolinea(eAvion *aviones, int tamAviones,eAerolinea *aerolineas,int tamAerolineas, eTipo *tipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos)
{
	int retorno =0;
	if(aviones != NULL && tamAviones > 0 &&  aerolineas != NULL && tamAerolineas > 0 && tipos !=NULL && tamTipos > 0)
	{
		for(int i =0;i<tamAerolineas;i++){

			mostrarAvionesAerolineaSeleccionado((aerolineas + i)->id, aviones, tamAviones, aerolineas, tamAerolineas, tipos, tamTipos,listaPilotos, tamPilotos);
		}
		retorno =1;
	}
	return retorno;
}
//printf("5.  Informar la o las aerolíneas que pueden transportar mas pasajeros\n");
int mostrarAerolineaTransportarMasPasajeros(eAvion *aviones, int tamAviones,eAerolinea *aerolineas,int tamAerolineas)
{
	int retorno =0;
	 int acumuladorCantidadPasajeros[]={0,0,0,0,0};
	 char descripcionAerolinea[20];
	 int mayor;

	if(aviones != NULL && tamAviones > 0 &&  aerolineas != NULL && tamAerolineas > 0)
	{
		for(int i =0;i<tamAerolineas;i++)
		{
			for(int j=0;j<tamAviones; j++)
			{
				if(!(aviones + j)->isEmpty && (aviones + j)->idAerolinea == (aerolineas +i)->id)
				{
					*(acumuladorCantidadPasajeros + i) = (aviones +j)->capacidad + *(acumuladorCantidadPasajeros + i);

				}
			}
			cargarDescripcionAerolinea((aerolineas + i)->id ,aerolineas, tamAerolineas, descripcionAerolinea);

		}
			for(int i =0;i<tamAerolineas;i++)
			{
				if(i == 0 ||*(acumuladorCantidadPasajeros + i) > mayor)
				{
					mayor = *(acumuladorCantidadPasajeros + i);
				}
			}
			printf("\nEstas son las areolineas que pueden transportar mas pasajeros");
			for(int i =0;i<tamAerolineas;i++)
			{
				if(*(acumuladorCantidadPasajeros + i) == mayor)
				{
					printf("%s: %d:\n", (aerolineas + i)->descripcion,mayor);
				}
			}

	}
	return retorno;
}

//printf("6.  Mostrar la aerolínea con menor cantidad de aviones\n");
int mostrarAerolineaMenorantidadAviones(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea)
 {
	 int retorno = 0;
	 int contadorAerolineas[]={0,0,0,0,0};
	 char descripcionAerolinea[20];
	 int menorCantidad;
	 int flag = 0;
	 int indiceAerolineaConMenorCantidad;

	 if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0)
	 {

		 for(int i =0;i<tamAerolinea;i++)
		 {
			 for(int j=0;j<tamAvion; j++)
			 {
				 if(!(listaAvion +j)->isEmpty && (listaAvion +j)->idAerolinea == (listaAerolinea +i)->id)
				 {
					(*(contadorAerolineas + i))++;

				 }
			 }

			 cargarDescripcionAerolinea((listaAerolinea + i)->id ,listaAerolinea, tamAerolinea, descripcionAerolinea);
			 if(flag == 0 ||(*(contadorAerolineas +i) < menorCantidad && *(contadorAerolineas +i) > 0))
			 {
				 menorCantidad = *(contadorAerolineas +i);
				 indiceAerolineaConMenorCantidad = i;
				 flag =1;
			 }
		 }
		 if(flag)
		 {
			 printf("La aerolinea con menor cantidad de aviones es: %s",(listaAerolinea + indiceAerolineaConMenorCantidad)->descripcion);
			 retorno =0;
		 }
	 }
	 return retorno;
 }
//	printf("7.  Pedir un avión y mostrar todos los vuelos que hizo el mismo.\n");
int mostrarVueloAvionSeleccionado(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos)
{
	int retorno =0;
	int idAvion;

	if(listaVuelos != NULL && tamVuelos >0 &&listaDestinos != NULL && tamdestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		do{
			mostrarAviones(listaAvion,tamAvion, listaAerolinea, tamAerolinea, listaTipos, tamTipos, listaPilotos, tamPilotos);
		}while(!utn_getEnteroSoloNumeros(&idAvion, 6, "Ingrese id: ",
				"Error, intente nuevamente", 3) &&
				!buscarIdExistenteAvion(listaAvion, idAvion ,tamAvion));
		mostrarVuelosAvionSeleccionado(listaVuelos, tamVuelos ,listaDestinos,tamdestinos,listaAvion, tamAvion, listaAerolinea, tamAerolinea, listaTipos,tamTipos ,idAvion);

		retorno =1;
	}

	return retorno;
}
int mostrarVuelosAvionSeleccionado(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos ,int idAvion)
{

	int retorno;
	int flag = 1;
	if(listaVuelos != NULL && tamVuelos >0 &&listaDestinos != NULL && tamdestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
			printf("\n                          ****LISTA VUELOS ***\n");
			printf("======================================================================================\n");
			printf("| ID | AEROLINEA  |     TIPO     | CAPACIDAD |   DESTINOS   |   PRECIO   |   FECHA    |\n");
			printf("--------------------------------------------------------------------------------------\n");

			for(int i =0; i< tamVuelos;i++)
			{
				if((listaVuelos + i)->isEmpty == 0 && (listaVuelos + i)->idAvion == idAvion)
				{
					mostrarVuelo((listaVuelos + i) ,listaDestinos, tamdestinos, listaAvion, tamAvion, listaAerolinea,tamAerolinea, listaTipos, tamTipos);
					flag =0;
				}
			}
			printf("======================================================================================\n");
			retorno =1;
	}
	if(flag)
	{

		printf("No hay vuelos con este avion\n");
	}

	return retorno;
}
//printf("8.  Pedir un avión e informar la suma de los precios (costo) de todos los vuelos que realizo\n");
int pedirAvionParaCosto(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos,ePiloto *listaPilotos, int tamPilotos)
{
	int retorno =0;
	int idAvion;

	if(listaVuelos != NULL && tamVuelos >0 &&listaDestinos != NULL && tamdestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		do{
			mostrarAviones(listaAvion,tamAvion, listaAerolinea, tamAerolinea, listaTipos, tamTipos, listaPilotos, tamPilotos);
		}while(!utn_getEnteroSoloNumeros(&idAvion, 6, "Ingrese id: ",
				"Error, intente nuevamente", 3) &&
				!buscarIdExistenteAvion(listaAvion, idAvion ,tamAvion));
		mostrarCostoVuelosRealizados(listaVuelos, tamVuelos,listaAvion,tamAvion,listaDestinos,tamdestinos, idAvion);
		retorno =1;
	}

	return retorno;
}
int mostrarCostoVuelosRealizados(eVuelo *listaVuelos, int tamVuelos,eAvion *listaAvion, int tamAvion, eDestino *listaDestino,int tamDestino, int idAvion)
{
	int retorno;
	float acumPrecio =0;
	int indiceAvion;
	int posicionDestino;
	buscarAvionPorId(listaAvion, idAvion ,tamAvion, &indiceAvion);
	if(listaVuelos != NULL && tamVuelos > 0 && listaDestino != NULL)
	{
		for(int i =0;i<tamVuelos;i++)
		{
			if(!(listaVuelos +i)->isEmpty && (listaVuelos +i)->idAvion == idAvion )
			{
				printf("entree\n");
				posicionDestino = obtenerPositionPorId((listaVuelos +i)->idDestino,listaDestino, tamDestino);
				acumPrecio = acumPrecio + (listaDestino + posicionDestino)->precio;

			}
		}
		if(acumPrecio)
		{
			printf("\nEl costo de los viejes realidados son: %.2f", acumPrecio);
			retorno =1;
		}else{
			printf("\nNo tiene viejes realizados");
		}
	}
	return retorno;
}
//printf("9.  Pedir un destino y mostrar los aviones que volaron a ese destino y en qué fecha\n");
int pedirDestino(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamDestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos)
{
	int retorno =0;
	int idDestino;

	if(listaVuelos != NULL && tamVuelos >0 &&listaDestinos != NULL && tamDestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		do{
			mostrarDestino(listaDestinos,tamDestinos);
		}while(!utn_getEnteroSoloNumeros(&idDestino, 6, "Ingrese id: ",
				"Error, intente nuevamente", 3) &&
				!buscarIdExistenteDestino(listaDestinos, idDestino ,tamDestinos));
		mostrarAvionesQueVolaronPorDEstino(listaVuelos, tamVuelos,listaDestinos,tamDestinos,listaAvion,tamAvion, listaAerolinea, tamAerolinea,listaTipos,tamTipos, idDestino);
		retorno =1;
	}
	return retorno;
}
int mostrarAvionesQueVolaronPorDEstino(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos ,int idDestino)
{

	int retorno;
	int flag = 1;
	if(listaVuelos != NULL && tamVuelos >0 &&listaDestinos != NULL && tamdestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
			printf("\n                          ****LISTA VUELOS ***\n");
			printf("======================================================================================\n");
			printf("| ID | AEROLINEA  |     TIPO     | CAPACIDAD |   DESTINOS   |   PRECIO   |   FECHA    |\n");
			printf("--------------------------------------------------------------------------------------\n");

			for(int i =0; i< tamVuelos;i++)
			{
				if((listaVuelos + i)->isEmpty == 0 && (listaVuelos + i)->idDestino == idDestino)
				{
					mostrarVuelo((listaVuelos + i) ,listaDestinos, tamdestinos, listaAvion, tamAvion, listaAerolinea,tamAerolinea, listaTipos, tamTipos);
					flag =0;
				}
			}
			printf("======================================================================================\n");
			retorno =1;
	}
	if(flag)
	{

		printf("No hay vuelos con este Destino\n");
	}

	return retorno;
}
//printf("10. Pedir una fecha y mostrar todos los vuelos realizados en la misma.\n");
int pedirUnaFecha(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamDestinos,eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos)
{
	int retorno =0;
	int dia;
	int mes;
	int anio;

	if(listaVuelos != NULL && tamVuelos >0 &&listaDestinos != NULL && tamDestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		utn_getFecha(&dia,&mes,&anio,11,"\nIngrese fecha: ",
							"Error, fecha no valida", 6);
		mostrarAvionesQueVolaronPorFecha(listaVuelos, tamVuelos,listaDestinos,tamDestinos,listaAvion,tamAvion, listaAerolinea, tamAerolinea,listaTipos,
				tamTipos, dia, mes,anio);
		retorno =1;
	}
	return retorno;
}
int mostrarAvionesQueVolaronPorFecha(eVuelo *listaVuelos, int tamVuelos ,eDestino *listaDestinos, int tamdestinos,eAvion *listaAvion, int tamAvion,
		eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos ,int dia, int mes, int anio)
{

	int retorno;
	int flag = 1;
	if(listaVuelos != NULL && tamVuelos >0 &&listaDestinos != NULL && tamdestinos > 0&&listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
			printf("\n                          ****LISTA VUELOS ***\n");
			printf("======================================================================================\n");
			printf("| ID | AEROLINEA  |     TIPO     | CAPACIDAD |   DESTINOS   |   PRECIO   |   FECHA    |\n");
			printf("--------------------------------------------------------------------------------------\n");

			for(int i =0; i< tamVuelos;i++)
			{
				if((listaVuelos + i)->isEmpty == 0 && (listaVuelos + i)->fecha.dia == dia && (listaVuelos + i)->fecha.mes && (listaVuelos + i)->fecha.anio)
				{
					mostrarVuelo((listaVuelos + i) ,listaDestinos, tamdestinos, listaAvion, tamAvion, listaAerolinea,tamAerolinea, listaTipos, tamTipos);
					flag =0;
				}
			}
			printf("======================================================================================\n");
			retorno =1;
	}
	if(flag)
	{

		printf("No hay vuelos con esta fecha\n");
	}

	return retorno;
}
