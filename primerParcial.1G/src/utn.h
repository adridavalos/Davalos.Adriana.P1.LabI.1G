

#ifndef UTN_H_
#define UTN_H_
#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void myFpurge();
int getString(char *pBuffer, int limite);

int isValidEnteroSoloNumeros(char *pBuffer, int limite);
int utn_getEnteroSoloNumeros(   int *pEntero, int limite, char *mensaje,
                                char *mensajeError, int reintentos);

int isValidNombre(char *pBuffer, int limite);
int utn_getNombre(  char *pNombre, int limite, char *mensaje,
                    char *mensajeError, int reintentos);

int isValidString(char *pBuffer, int limite);
int formatoNombre(char *caracter);
void ToLower(char* p);
int formatoPrimeraLetraMayuscula(char *caracter);
int utn_getString(char *pString, int limite, char *mensaje, char *mensajeError, int reintentos);


int isValidFloat(char *pBuffer, int limite);
int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos);


int isValidFecha(int dia, int mes, int anio);
int utn_getFecha(   int *dia,int *mes, int *anio, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
#endif /* UTN_H_ */
