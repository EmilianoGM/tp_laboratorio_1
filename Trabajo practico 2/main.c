#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "Biblioteca.h"
#include "ArrayEmployees.h"
#include "Menu.h"


int main()
{
    Employee lista[MAX_EMPLOYEES];
    initEmployees(lista, MAX_EMPLOYEES);
    printf("Bienvenido\n");
    printf("\n");
    int respuesta;
    int bandera;
    do
    {
        respuesta = printMenuPrincipal();
        if(respuesta == 1)
        {
            printf("\n");
            system("pause");
            system("cls");
            menuAltas(lista, MAX_EMPLOYEES);
            bandera = contarAltasEmployee(lista, MAX_EMPLOYEES);
        }
        if(bandera > -1)
        {
            switch(respuesta)
            {
                case 2:
                    printf("\n");
                    system("pause");
                    system("cls");
                    menuModificar(lista, MAX_EMPLOYEES);
                    break;
                case 3:
                    printf("\n");
                    system("pause");
                    system("cls");
                    menuBajas(lista, MAX_EMPLOYEES);
                    break;
                case 4:
                    printf("\n");
                    system("pause");
                    system("cls");
                    menuInformes(lista, MAX_EMPLOYEES);
                    break;
                case 5:
                    break;
            }
        } else
        {
            printf("No se a dado de alta ningun empleado.\n");
        }
    } while(respuesta != 5);
    printf("\n");
    system("pause");
    system("cls");
    printf("Gracias por usar la aplicacion.\n");

    return 0;
}
