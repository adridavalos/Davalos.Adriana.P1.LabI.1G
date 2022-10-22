
#include "utn.h"

/////SE UTILIZAN EN TODAS LAS FUNCIONES


/**
* \brief El usuario ingresa una cadena con fgets
* \param pBuffer Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*
*/
void myFpurge()
{
    __fpurge(stdin);
}

/**
* \brief El usuario ingresa una cadena con fgets
* \param pBuffer Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*
*/
int getString(char *pBuffer, int limite)
{
    int retorno = -1;
    int len;
    char bufferString[4096];
    if(pBuffer != NULL && limite > 0 )
    {
        myFpurge();
        fgets(bufferString, 4096, stdin);
        len = strlen(bufferString);
        if(len <= limite)
        {
            if(len != limite-1 || bufferString[limite-2] == '\n')
            {
                bufferString[len-1] = '\0';
            }
            strncpy(pBuffer, bufferString, limite);
            retorno = 0;
        }
        else
        {
            printf("Se admite un maximo de %d caracteres\n", limite - 1);
        }
    }
    return retorno;
}

/////NUMEROS ENTEROS

/**
* \brief Evalua si se trata de un entero sin signo
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
int isValidEnteroSoloNumeros(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if (pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Toma una cadena y evalua si es un entero sin signo
* \param pEntero Recibe el numero ingresado en caso de exito
* \param limite Es el numero de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getEnteroSoloNumeros(   int *pEntero, int limite, char *mensaje,
                                char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferEntero[4096];
    if( pEntero != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferEntero, limite) == 0 &&
                isValidEnteroSoloNumeros(bufferEntero, limite))
            {
                *pEntero = atoi(bufferEntero);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

////NOMBRE

/**
* \brief    Evalua si es un nombre, solo puede tener un espacio y cada nombre
*           debe empezar por mayuscula y el resto minusculas (Jose)(Jose Maria)(Lopez)(Lopez Gomez)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    int cantidadEspacios = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 && pBuffer[0]>='A' && pBuffer[0]<='Z')
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }
            else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') &&
                    !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] == ' '))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief    Toma una cadena y evalua si es un nombre, solo puede tener un espacio y cada nombre
*           debe empezar por mayuscula y el resto minusculas (Jose)(Jose Maria)(Lopez)(Lopez Gomez)
* \param pNombre Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getNombre(char *pNombre, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pNombre != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidNombre(buffer, limite))
            {
                strncpy(pNombre, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
/**
* \brief    Evalua si es de tipo es string y no admite espacio
*
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/
int isValidString(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z') &&
                    !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/// @brief  Toma una cadena y lo pasa a minuscula
///
/// @param p es la cadena que conviertimos

void ToLower(char* p)
{
	while( *p )
	{
		*p=tolower( *p );
		p++;
	}
}
/// @brief Toma una cadena y pasa el primer caracter a mauscula
///
/// @param caracter es la cadena que realizamos el cambio
/// @return En caso de exito retorna 1, si no 0
int formatoPrimeraLetraMayuscula(char *caracter)
{
	int retorno =0;
	if(caracter != NULL)
	{
		ToLower(caracter);
		*caracter = toupper(*caracter);
		retorno = 1;
	}

	return retorno;
}
/**
* \brief verifica lo que se ingreso por teclado sea string y la primera letra lo cambia
* a mauyscula y no admite espacio entre palabras.
* \param pString Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getString(char *pString, int limite, char *mensaje, char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pString != NULL && limite > 0 && mensaje != NULL && mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 && isValidString(buffer, limite))
            {
            	formatoPrimeraLetraMayuscula(buffer);
                strncpy(pString, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}
////

/**
* \brief Evalua si se trata de un entero
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/
int isValidFloat(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if  ((pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0) &&
            (((pBuffer[0] == '-' || pBuffer[0] == '+') && pBuffer[1] != '.') ||
             (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }
            else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Toma una cadena y evalua si es un float
* \param pFloat Recibe el numero ingresado en caso de exito
* \param limite Es el numero de cifras
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferFloat, limite) == 0 &&
                isValidFloat(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


/**
* \brief Toma una cadena y evalua si es una fecha valida (dd/mm/aaaa)
* \param pFecha Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/

int isValidFecha(int dia, int mes, int anio)
{
    int retorno = 0;
    if(dia > 0 && mes > 0 &&  anio > 0)
    {
        if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) &&
                (dia > 0 && dia <= 31)) ||
                ((mes == 4 || mes == 6 || mes == 9 || mes == 11) &&
                 (dia > 0 && dia <= 30)) ||
                ((mes == 2 && (anio % 4) == 0) &&
                 (dia > 0 && dia <= 29)) ||
                ((mes == 2 && (anio % 4) != 0) &&
                 (dia > 0 && dia <= 28)))
        {
            retorno = 1;
        }
    }
    return retorno;
}
/**
* \brief Toma una cadena y evalua si es una fecha valida (dd/mm/aaaa)
* \param pFecha Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/
int utn_getFecha(   int *dia,int *mes, int *anio, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferDia[512];
    char bufferMes[512];
    char bufferAnio[512];
    int auxDia;
    int auxMes;
    int auxAnio;

    if( limite >= 11 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            printf("\nIntroduzca Dia(dd): ");
            if( getString(bufferDia, limite) == 0 &&
                    strlen(bufferDia) == 2 &&
					isValidEnteroSoloNumeros(bufferDia, limite))
            {
            	auxDia = atoi(bufferDia);
            }
            else
            {
                continue;
            }
            printf("\nIntroduzca Mes(mm): ");
            if( getString(bufferMes, limite) == 0 &&
                    strlen(bufferMes) == 2 &&
					isValidEnteroSoloNumeros(bufferMes, limite))
            {
                auxMes = atoi(bufferMes);
            }
            else
            {
                continue;
            }
            printf("\nIntroduzca Anio(aaaa): ");
            if( getString(bufferAnio, limite) == 0 &&
                    strlen(bufferAnio) == 4 &&
					isValidEnteroSoloNumeros(bufferAnio, limite))
            {
                auxAnio = atoi(bufferAnio);
            }
            else
            {
                continue;
            }
            if (isValidFecha(auxDia, auxMes, auxAnio))
            {
            	*dia =auxDia;
            	*mes = auxMes;
            	*anio = auxAnio;

                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}


