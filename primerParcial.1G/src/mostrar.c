#include "mostrar.h"

void mostrarMenu(void)
{
	printf("\n***MENU DE OPCIONES ***\n");
	printf("A-  ALTA AVION\n");
	printf("B-  MODIFICAR AVION\n");
	printf("C-  BAJA AVION\n");
	printf("D-  LISTAR AVIONES\n");
	printf("E-  LISTAR AEROLINEAS\n");
	printf("F-  LISTAR TIPOS\n");
	printf("G-  LISTAR DESTINOS\n");
	printf("H-  ALTA VUELO\n");
	printf("I- LISTAR VUELOS\n");
	printf("J- Salir\n");
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

void mostrarAvion(eAvion *listaAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos)
{
	char descripcionAerolinea[20];
	char descripcionTipo[20];

	if(listaAvion != NULL &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		cargarDescripcionAerolonea(listaAvion->idAerolinea , listaAerolinea, tamAerolinea, descripcionAerolinea);
		cargarDescripcionTipo(listaAvion->idTipo ,listaTipos, tamTipos, descripcionTipo);
		printf("|  %d |	%-10s|  %-10s  |    %3d    |\n",
				listaAvion->id,
				descripcionAerolinea,
				descripcionTipo,
				listaAvion->capacidad
		);
	}

}
void mostrarAviones(eAvion *listaAvion, int tamAvion, eAerolinea *listaAerolinea, int tamAerolinea, eTipo *listaTipos, int tamTipos)
{
	if(listaAvion != NULL && tamAvion > 0 &&  listaAerolinea != NULL && tamAerolinea > 0 && listaTipos !=NULL && tamTipos > 0)
	{
		printf("\n                    ****LISTA AVIONES ***\n");
		printf("==============================================\n");
		printf("| ID | AEROLINEA  |     TIPO     | CAPACIDAD |\n");
		printf("----------------------------------------------\n");

		for(int i =0; i< tamAvion;i++)
		{
			if(!(listaAvion + i)->isEmpty)
			{
				mostrarAvion((listaAvion +i),listaAerolinea, tamAerolinea,listaTipos, tamTipos);
			}
		}
		printf("==============================================\n");

	}



}
