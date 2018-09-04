#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main()
{
    printf("Calculadora\n");

    int opcion;
    float primerOperando;
    float segundoOperando;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    int primerOperandoEntero;
    int segundoOperandoEntero;
    long int factorialPrimerOperando;
    long int factorialSegundoOperando;
    int primerOperandoIngresado = 0;
    int segundoOperandoIngresado = 0;
    int divisionPorCero = 0;
    int calculosRealizados;
    int posibleFactorizarPrimerOperando;
    int posibleFactorizarSegundoOperando;


    do{
        printf("\nSeleccion de opciones:\n");
        if(primerOperandoIngresado == 0){
            printf("1) Ingresar primer operando\n");
        } else {
            printf("1) Ingresar primer operando (Valor actual = %f)\n", primerOperando);
        }
        if(segundoOperandoIngresado == 0){
            printf("2) Ingresar segundo operando\n");
        } else {
            printf("2) Ingresar segundo operando (Valor actual = %f\n", segundoOperando);
        }
        printf("3) Calcular todas las operaciones\n");
        printf("4) Resultados de las operaciones\n");
        printf("5) Salir\n");

        opcion = pedirNumero("\nIngrese numero de opcion: ");

        switch(opcion){
            case 1:
                primerOperando = pedirNumero("\nIngrese el primer operando:\n");
                printf("Primer operando: %f\n", primerOperando);
                primerOperandoIngresado = 1;
                posibleFactorizarPrimerOperando = comprobarFactorizacion(primerOperando);
                break;
            case 2:
                segundoOperando = pedirNumero("\nIngrese el segundo operando: ");
                printf("Segundo operando: %f\n", segundoOperando);
                segundoOperandoIngresado = 1;
                posibleFactorizarSegundoOperando = comprobarFactorizacion(segundoOperando);
                break;
            case 3:
                if(primerOperandoIngresado == 1 && segundoOperandoIngresado == 1){
                    suma = calcularSuma(primerOperando, segundoOperando);
                    resta = calcularResta(primerOperando, segundoOperando);
                    if(segundoOperando == 0){
                        divisionPorCero = 1;
                    } else {
                        division = calcularDivision(primerOperando, segundoOperando);
                    }
                    multiplicacion = calcularMultiplicacion(primerOperando, segundoOperando);
                    if(posibleFactorizarPrimerOperando == 1){
                        primerOperandoEntero = primerOperando;
                        factorialPrimerOperando = calcularFactorial(primerOperandoEntero);
                    } else {
                        factorialPrimerOperando = 0;
                    }
                    if(posibleFactorizarSegundoOperando == 1){
                        segundoOperandoEntero = segundoOperando;
                        factorialSegundoOperando = calcularFactorial(segundoOperandoEntero);
                    } else {
                        factorialSegundoOperando = 0;
                    }
                    calculosRealizados = 1;
                    printf("\nLos calculos se han completado.\n");
                } else {
                    calculosRealizados = 0;
                    printf("\nFalta ingresar algun operando, los calculos no se han realizado.\n");
                }
                break;
            case 4:
                if(calculosRealizados == 1){
                    printf("\nResultados:\n");
                    printf("\na) El resultado de %.3f + %.3f es: %.3f\n", primerOperando, segundoOperando, suma);
                    printf("b) El resultado de %.3f - %.3f es: %.3f\n", primerOperando, segundoOperando, resta);
                    if(divisionPorCero == 0){
                        printf("c) El resultado de %.3f / %.3f es: %.3f\n", primerOperando, segundoOperando, division);
                    } else{
                        printf("c) No es posible dividir un numero por cero.\n");
                    }
                    printf("c) El resultado de %.3f * %.3f es: %.3f \n", primerOperando, segundoOperando, multiplicacion);
                    if(posibleFactorizarPrimerOperando == 1){
                        printf("d) El factorial de %.0f es: %ld y ",primerOperando, factorialPrimerOperando);
                    } else{
                        printf("d) No es posible factorizar el primer operando y ");
                    }
                    if(posibleFactorizarSegundoOperando == 1){
                        printf("el factorial de %.0f es: %ld\n", segundoOperando, factorialSegundoOperando);
                    } else{
                        printf("No es posible factorizar el segundo operando\n");
                    }
                } else {
                    printf("\nLos calculos aun no han sido realizados.\n");
                }
                break;
            case 5:
                break;
            default:
                printf("\nNo ha ingresado una opcion valida\n");
        }

        printf("\n");
        system("pause");
        system("cls");

    } while(opcion != 5);

    printf("\nGracias por usar la aplicacion.\n");

    return 0;
}
