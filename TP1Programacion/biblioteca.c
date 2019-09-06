#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"




float hacerSuma (float numeroA, float numeroB)

{

    float resultado;

    resultado = numeroA + numeroB;

    return resultado;

}

float hacerResta (float numeroA, float numeroB)

{

    float resultado;

    resultado = numeroA - numeroB;

    return resultado;

}

float hacerMultiplicacion (float numeroA, float numeroB)

{

    float resultado;

    resultado = numeroA * numeroB;

    return resultado;
}

float hacerDivision(float numeroA, float numeroB)
{

    float resultado;

    resultado = numeroA/numeroB;

    return resultado;

}



int hacerFactorial (int numero)

{

    float acumulador = 1;
    float i;

    for (i=numero; i>0; i--)

    {

        acumulador= acumulador*i;

    }

    return acumulador;

}









