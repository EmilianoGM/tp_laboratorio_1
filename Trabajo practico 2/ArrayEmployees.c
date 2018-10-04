#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
    if(list != NULL && len > 0)
    {
        int indice;
        for(indice = 0; indice < len; indice ++)
        {
            list[indice].isEmpty = TRUE;
        }
        return 0;
    }
    return -1;
}

int buscarLibreEmployee(Employee* list, int len)
{
    int indice = -1;
    if(list != NULL && len > 0)
    {
        for(indice = 0; indice < len; indice ++)
        {
            if(list[indice].isEmpty == TRUE)
            {
                break;
            }
        }
    }
    return indice;
}

void mostrarEmployee(Employee empleado)
{
    printf("%4d | %20s | %20s | %10.3f | %6d\n", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int indice;
    if(list != NULL && len > 0)
    {
        indice = buscarLibreEmployee(list, len);
        if(indice > -1)
        {
                list[indice].id = id;
                strcpy(list[indice].name, name);
                strcpy(list[indice].lastName, lastName);
                list[indice].salary = salary;
                list[indice].sector = sector;
                list[indice].isEmpty = FALSE;
                return 0;
        }
    }
    return -1;
}

int generarIdEmployee(Employee* list, int len)
{
    int retorno = -1;
    int indice;
    int cantidadDeAltas;
    if(list != NULL && len > 0 && (contarAltasEmployee(list, len)) > 0)
    {
        cantidadDeAltas = contarAltasEmployee(list, len);
        retorno = 1;
        if(cantidadDeAltas > 1)
        {
            int listadoDeIds[cantidadDeAltas];
            generarListaOrdenadaDeIdsEmployee(list, len, listadoDeIds, cantidadDeAltas);
            if(listadoDeIds[0] != 1)
            {
                retorno = 1;
            } else
            {
                for(indice = 0; indice < (cantidadDeAltas - 1); indice++)
                {
                    if((listadoDeIds[indice + 1] - listadoDeIds[indice]) != 1)
                    {
                        retorno = listadoDeIds[indice] + 1;
                        break;
                    }
                }
                if((listadoDeIds[cantidadDeAltas - 1] - listadoDeIds[cantidadDeAltas - 2]) == 1)
                {
                    retorno = listadoDeIds[cantidadDeAltas - 1] + 1;
                }
            }
        }
    }
    return retorno;
}

int generarListaOrdenadaDeIdsEmployee(Employee* list, int len, int listaDeIds[], int cantidadDeIds)
{
    int retorno = -1;
    int indice;
    int indiceDos = 0;
    if(list != NULL && len > 0 && listaDeIds != NULL && cantidadDeIds > 0)
    {
        for(indice = 0; indice < len; indice ++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                listaDeIds[indiceDos] = list[indice].id;
                indiceDos++;
            }
        }
        ordenarArrayNumerica(listaDeIds, cantidadDeIds);
        retorno = 0;
    }
    return retorno;
}

int contarAltasEmployee(Employee* list, int len)
{
    int retorno = -1;
    int indice;
    if(list != NULL && len > 0)
    {
        retorno = 0;
        for(indice = 0; indice < len; indice++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                retorno++;
            }
        }
    }
    return retorno;
}

int modificarEmployee(Employee* list, int len,int id, int opcion)
{
    int indice;
    if(list != NULL && len > 0)
    {
        indice = id;
        if(indice != -1)
        {
            switch(opcion)
            {
                case 1:
                    pedirTexto(list[indice].name, TAMANIO_NAME, "\nIntroduzca nuevo nombre:\n",
                    "Error, nombre invalido.Introduzca nuevo nombre:\n");
                    printf("\nNombre modificado.\n");
                    break;
                case 2:
                    pedirTexto(list[indice].lastName, TAMANIO_LASTNAME, "\nIntroduzca nuevo apellido:\n",
                    "Error, apellido invalido.Introduzca nuevo apellido:\n");
                    printf("\nApellido modificado.\n");
                    break;
                case 3:
                    list[indice].salary = pedirFlotante("\nIntroduzca nuevo salario:\n",
                    "Error, salario invalido. Introduzca nuevo salario:\n", MIN_SALARY, MAX_SALARY);
                    printf("\nSalario modificado.\n");
                    break;
                case 4:
                    list[indice].sector = pedirEntero("\nIntroduzca nuevo sector:\n",
                    "Error, sector invalido. Introduzca nuevo sector:\n", 0, 5);
                    printf("\nSector modificado.\n");
                    break;
            }
            printf("Empleado modificado con exito:\n");
            mostrarEmployee(list[indice]);
            return 0;
        }
    }
    return -1;
}
int findEmployeeById(Employee* list, int len,int id)
{
    int indice;
    if(list != NULL && len > 0)
    {
        for(indice = 0; indice < len; indice ++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                if(list[indice].id == id)
                {
                    return indice;
                }
            }
        }
    }
    return -1;
}

int removeEmployee(Employee* list, int len, int id)
{
    char respuesta;
    int indice;
    if(list != NULL && len > 0)
    {
        indice = findEmployeeById(list, len, id);
        if(indice != -1)
        {
            mostrarEmployee(list[indice]);
            respuesta = pedirRespuestaS_N("\nDesea borrar empleado(s(para SI) | n(para NO)?\n",
            "\nRespuesta invalida. Introduzca s para SI o n para NO:\n");
            if(respuesta == 's')
            {
                list[indice].isEmpty = FALSE;
                printf("\nEmpleado removido con exito.\n");
            } else
            {
                printf("\nEmpleado no removido.\n");
            }
            return 0;
        } else
        {
            printf("Indice no encontrado.\n");
        }
    }
    return -1;
}

int printEmployees(Employee* list, int len)
{
    if(list != NULL && len > 0)
    {
        printf("%4s | %20s | %20s | %10s | %6s\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
        int indice;
        for(indice = 0; indice < len; indice ++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                mostrarEmployee(list[indice]);
            }
        }
        return 0;
    }
    return -1;
}

int sortEmployeesByLastName(Employee* list, int len, int order)
{
    int indice;
    int j;
    Employee auxiliar;
    if(list != NULL && len > 0 && (order == 1 || order == 0))
    {
        for(indice = 1; indice < len; indice++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                auxiliar = list[indice];
                j = indice - 1;
                if(order == 0)
                {
                    while(j >= 0 && strcmp(auxiliar.lastName, list[j].lastName) < 0)
                    {
                        list[j + 1] = list[j];
                        j--;
                    }
                }
                if(order == 1)
                {
                    while(j >= 0 && strcmp(auxiliar.lastName, list[j].lastName) > 0)
                    {
                        list[j + 1] = list[j];
                        j--;
                    }
                }
                list[j + 1] = auxiliar;
            }
        }
        return 0;
    }
    return -1;
}

int sortEmployeesBySector(Employee* list, int len, int order)
{
    int indice;
    int j;
    Employee auxiliar;
    if(list != NULL && len > 0 && (order == 1 || order == 0))
    {
        for(indice = 1; indice < len; indice++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                auxiliar = list[indice];
                j = indice - 1;
                if(order == 0)
                {
                    while(j >= 0 && auxiliar.sector < list[j].sector && list[j].isEmpty == FALSE)
                    {
                        list[j + 1] = list[j];
                        j--;
                    }
                }
                if(order == 1)
                {
                    while(j >= 0 && auxiliar.sector > list[j].sector)
                    {
                        list[j + 1] = list[j];
                        j--;
                    }
                }
                list[j + 1] = auxiliar;
            }
        }
        return 0;
    }
    return -1;
}

int contarSalariosMasDelPromedio(Employee* list, int len)
{
    int indice;
    int contador = -1;
    float promedio;
    if(list != NULL && len > 0)
    {
        contador = 0;
        promedio = calcularPromedioSalarios(list, len);
        for(indice = 0; indice < len; indice++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                if(list[indice].salary > promedio)
                {
                    contador++;
                }
            }
        }
    }
    return contador;
}

float calcularPromedioSalarios(Employee* list, int len)
{
    int indice;
    float promedio = -1;
    int contadorSalarios = 0;
    float totalSalarios;
    if(list != NULL && len > 0)
    {
        promedio = 0;
        for(indice = 0; indice < len; indice++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                contadorSalarios++;
            }
        }
        if(contadorSalarios > 0)
        {
            totalSalarios = sumarTotalSalarios(list, len);
            promedio = totalSalarios / contadorSalarios;
        }
    }
    return promedio;
}

float sumarTotalSalarios(Employee* list, int len)
{
    int indice;
    float total = -1;
    if(list != NULL && len > 0)
    {
        total = 0;
        for(indice = 0; indice < len; indice++)
        {
            if(list[indice].isEmpty == FALSE)
            {
                total = total + list[indice].salary;
            }
        }
    }
    return total;
}
