#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"
#include "ArrayEmployees.h"
#include "Menu.h"

int printMenuPrincipal(void)
{
    int respuesta;
    printf("Menu principal\n");
    printf("\n");
    printf("1) Altas\n2) Modificar\n3) Baja\n4) Informes\n5) Salir\n");
    respuesta = pedirEntero("\nIntroduzca una opcion:\n", "Error, opcion invalida. Introduzca una opcion:\n", 1, 5);
    return respuesta;
}

int printMenuAltas(void)
{
    int respuesta;
    printf("Altas:\n");
    printf("\n");
    printf("1)Dar de alta un empleado\n2) Volver al menu principal\n");
    printf("\n");
    respuesta = pedirEntero("\nIntroduzca una opcion:\n", "Error, opcion invalida. Introduzca una opcion:\n", 1, 2);
    return respuesta;
}

int printMenuModificar(void)
{
    int respuesta;
    printf("1) Nombre\n2 )Apellido\n3) Salario\n4) Sector\n5) Volver al menu principal.\n");
    respuesta = pedirEntero("\nIntroduzca una opcion:\n", "Error, opcion invalida. Introduzca una opcion:\n", 1, 5);
    return respuesta;
}

int printMenuBajas(void)
{
    int respuesta;
    printf("1) Dar de baja.\2) Volver al menu principal.\n");
    respuesta = pedirEntero("\nIntroduzca una opcion:\n", "Error, opcion invalida. Introduzca una opcion:\n", 1, 2);
    return respuesta;
}

int printMenuInformar(void)
{
    int respuesta;
    printf("Informes\n");
    printf("\n");
    printf("1)Mostrar empleados por apellido (A-Z)\n2) Mostrar empleados por apellido (Z-A)\n");
    printf("3) Mostrar empleados por sector (menor - mayor)\n4) Mostrar empleados por sector (mayor - menor)");
    printf("5) Mostrar salarios (total, promedio y empleados arriba del promedio)\n");
    printf("6) Volver al menu principal.\n");
    respuesta = pedirEntero("\nIntroduzca una opcion:\n", "Error, opcion invalida. Introduzca una opcion:\n", 1, 6);
    return respuesta;
}

void menuAltas(Employee* list, int len)
{
    int respuesta;
    int libre;
    int id;
    char nombre[TAMANIO_NAME];
    char apellido[TAMANIO_LASTNAME];
    float salario;
    int sector;
    libre = buscarLibreEmployee(list, len);
    if(libre > -1)
    {
        respuesta = printMenuAltas();
        if(respuesta == 1)
        {
            printf("\n");
            id = generarIdEmployee(list, len);
            pedirTexto(nombre, TAMANIO_NAME, "\nIntroduzca el nombre: ",
                       "\nError nombre invalido. Introduzca nombre nuvamente: ");
            pedirTexto(apellido, TAMANIO_LASTNAME, "\nIntroduzca el apellido: ",
                       "\nError apellido invalido. Introduzca apellido nuevamente: ");
            salario = pedirFlotante("\nIntroduzca salario: ", "\Error, salario invalido. Introduzca salario nuevamente: ",
                                    MIN_SALARY, MAX_SALARY);
            sector = pedirEntero("\nIntroduzca sector: ","\nError, sector invalido. Introduzca sector nuevamente: ",
                                 MIN_SECTOR, MAX_SECTOR);
            addEmployee(list, len, id, nombre, apellido, salario, sector);
        }
    } else
    {
        printf("Lista llena.\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void menuModificar(Employee* list, int len)
{
    int id;
    int respuesta;
    int indice;
    printf("Modificar por ID\n");
    printf("\n");
    id = pedirEntero("\nID a buscar: ", "Error, id invalida. Introduzca una ID valida:", 1, MAX_EMPLOYEES);
    printf("\n");
    indice = findEmployeeById(list, len, id);
    if(indice != -1)
    {
        respuesta = printMenuModificar();
        if(respuesta != 5)
        {
            modificarEmployee(list, len, indice, respuesta);
        }
    }else
    {
        printf("Id inexistente.\n");
    }
    printf("\n");
    system("pause");
    system("cls");
}

void menuBajas(Employee* list, int len)
{
    int id;
    int respuesta;
    printf("Bajas por ID\n");
    id = pedirEntero("\nID a buscar: ", "Error, id invalida. Introduzca una ID valida:", 1, MAX_EMPLOYEES);
    printf("\n");
    respuesta = printMenuBajas();
    if(respuesta == 1)
    {
        removeEmployee(list, len, id);
    }
    printf("\n");
    system("pause");
    system("cls");
}

void menuInformes(Employee* list, int len)
{
    int respuesta;
    float total;
    float promedio;
    int contadorSalarioArribaDelPromedio;
    respuesta = printMenuInformar();
    switch(respuesta)
    {
        case 1:
            sortEmployeesByLastName(list, len, 0);
            printEmployees(list, len);
            break;
        case 2:
            sortEmployeesByLastName(list, len, 1);
            printEmployees(list, len);
            break;
        case 3:
            sortEmployeesBySector(list, len, 0);
            printEmployees(list, len);
            break;
        case 4:
            sortEmployeesBySector(list, len, 1);
            printEmployees(list, len);
            break;
        case 5:
            total = sumarTotalSalarios(list, len);
            promedio = calcularPromedioSalarios(list, len);
            contadorSalarioArribaDelPromedio = contarSalariosMasDelPromedio(list, len);
            printf("Total de salarios: %.3f\nPromedio de salarios: %.3f\n", total, promedio);
            printf("Cantidad de empleados con salario arriba del promedio: %d", contadorSalarioArribaDelPromedio);
            break;
        case 6:
            break;
    }
    printf("\n");
    system("pause");
    system("cls");
}
