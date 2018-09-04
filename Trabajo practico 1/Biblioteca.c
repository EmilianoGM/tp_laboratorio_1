#include <stdio.h>
#include "Biblioteca.h"

float pedirNumero(char texto[]){
    float numero;
    printf("%s", texto);
    setbuf(stdin, NULL);
    scanf("%f", &numero);
    return numero;
}

float calcularSuma(float numeroUno, float numeroDos){
    float adicion;
    adicion = numeroUno + numeroDos;
    return adicion;
}

float calcularResta(float numeroUno, float numeroDos){
    float sustraccion;
    sustraccion = numeroUno - numeroDos;
    return sustraccion;
}

float calcularDivision(float numeroUno, float numeroDos){
    float resultado;
    resultado = numeroUno / numeroDos;
    return resultado;
}

float calcularMultiplicacion(float numeroUno, float numeroDos) {
    float producto;
    producto = numeroUno * numeroDos;
    return producto;
}

long int calcularFactorial(int numero){
    long int resultado;
    int i;
    resultado = 1;
    for(i = numero; i >= 1; i--){
        resultado = resultado * i;
    }
    return resultado;
}

int comprobarFactorizacion(float numero){
    int esEntero;
    esEntero = comprobarEntero(numero);
    if(numero >= 0 && esEntero == 1){
        return 1;
    } else {
        return 0;
    }
}

int comprobarEntero(float numero){
    int enteroDelNumero = numero;
    float resultado;
    resultado = numero - enteroDelNumero;
    if(resultado > 0 || resultado < 0){
        return 0;
    } else
        return 1;
}

