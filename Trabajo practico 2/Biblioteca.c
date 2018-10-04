#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"

int pedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo) /**CORREGIDO */
{
    char array[13];
    int numero;
    int error;
    printf("%s", mensaje);
    do
    {
        error = 0;
        fflush(stdin);
        fgets(array, 13, stdin);
        if(array[(strlen(array) - 1)] != '\n')
        {
            error = 1;
        } else
        {
            if(array[0] != '-' && isdigit(array[0]) == 0)
            {
                error = 1;
            }else
            {
                /**Devuelve 1 si ES NUMERICA y 0 si NO ES */
                if(comprobarArrayNumerica(array, (strlen(array) - 1)) == 0)
                {
                    error = 1;
                }else
                {
                    array[(strlen(array) - 1)] = '\0';
                    numero = atoi(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    }
                }
            }
        }
        if(error == 1)
        {
            printf("%s", mensajeError);
        }
    } while(error == 1);

    return numero;
}

float pedirFlotante(char mensaje[], char mensajeError[], float minimo, float maximo)
{
    char array[45];
    float numero;
    int error;
    int numeroDePuntos;
    int indice;
    printf("%s", mensaje);
    do
    {
        error = 0;
        numeroDePuntos = 0;
        fflush(stdin);
        fgets(array, 45, stdin);
        if((array[(strlen(array) - 1)]) != '\n')
        {
            error = 1;
        }else
        {
            if(array[0] != '-' && isdigit(array[0]) == 0)
            {
                error = 1;
            }else
            {
                for(indice = 1; indice < (strlen(array) - 1); indice++)
                {
                    if(isdigit(array[indice]) == 0 && array[indice] != '.')
                    {
                        error = 1;
                        break;
                    }
                    if(array[indice] == '.' && numeroDePuntos < 2)
                    {
                        numeroDePuntos++;
                    }
                }
                if(numeroDePuntos == 2 && error == 0)
                {
                    error = 1;
                }else
                {
                    array[(strlen(array) - 1)] = '\0';
                    numero = atof(array);
                    if(numero > maximo || numero < minimo)
                    {
                        error = 1;
                    }
                }
            }
        }
        if(error == 1)
        {
            printf("%s", mensajeError);
        }
    }while(error == 1);

    return numero;
}

void pedirTexto(char arrayTexto[], int tamanio, char mensaje[], char mensajeError[]) /**CORREGIDO */
{
    int error;
    char arrayAuxiliar[tamanio + 1];
    int indice;
    printf("%s", mensaje);
    do
    {
        error = 0;
        fflush(stdin);
        fgets(arrayAuxiliar, (tamanio + 1), stdin);
        if((arrayAuxiliar[(strlen(arrayAuxiliar) - 1)]) != '\n')
        {
            error = 1;
        } else
        {
            for(indice = 0; indice < (strlen(arrayAuxiliar) - 1); indice++)
            {
                if(isalpha(arrayAuxiliar[indice]) == 0 && arrayAuxiliar[indice] != ' ')
                {
                    error = 1;
                    break;
                }
            }
        }
        if(error == 1)
        {
            printf("%s", mensajeError);
        }
    }while(error == 1);

    arrayAuxiliar[(strlen(arrayAuxiliar) - 1)] = '\0';
    strncpy(arrayTexto, arrayAuxiliar, (strlen(arrayAuxiliar)+ 1));
}

int comprobarArrayNumerica(char cadenaNumerica[], int tamanio)
{
    int retorno = 1;
    int indice = 0;
    if(cadenaNumerica != NULL && tamanio > 0)
    {
        if(cadenaNumerica[0] == '-')
        {
            indice = 1;
        }
        for( ; indice < tamanio; indice++)
        {
            if(isdigit(cadenaNumerica[indice]) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

void ordenarArrayNumerica(int arrayNumerica[],int tamanio)
{
    int indice;
    int j;
    int auxiliar;
    for(indice = 1; indice < tamanio; indice++)
    {
        auxiliar = arrayNumerica[indice];
        j = indice - 1;
        while(j>=0 && auxiliar < arrayNumerica[j])
        {
            arrayNumerica[j+1] = arrayNumerica[j];
            j--;
        }
        arrayNumerica[j+1] = auxiliar;
    }
}

char pedirRespuestaS_N(char mensaje[], char mensajeError[])
{
    char respuesta;
    printf("%s", mensaje);
    do
    {
      respuesta = getche();
      respuesta = tolower(respuesta);
      if(respuesta != 's' && respuesta != 'n')
      {
          printf("%s", mensajeError);
      }
    } while(respuesta != 's' && respuesta != 'n');
    return respuesta;
}
