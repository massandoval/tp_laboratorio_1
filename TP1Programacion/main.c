#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


int main()
{

    float numeroA = 0;
    float numeroB = 0;
    int opcion;
    char seguir = 's';
    float numeroSuma;
    float numeroResta;
    float numeroMulti;
    float numeroDivision;
    int numeroFactorialA;
    int numeroFactorialB;
    int flag = 0;

    /**MENU*/

    printf(" #*********CALCULADORA EN C*********# \n\n");


    printf("*    1. Ingresar 1er operando (A=X)        *\n");
    printf("*    2. Ingresar 2do operando (B=Y)        *\n");
    printf("*    3. Calcular todas las operaciones     *\n");
    printf("*    4. Informar resultados                *\n");
    printf("*    5. Salir                              *\n\n");
    printf("#    6. Elija una opcion: ");
    do

    {

   /** Cuando se ingresen los numeros AyB, se reemplazan en el menu. */

    if (flag==1) {

    printf(" #*********CALCULADORA EN C*********# \n\n");

    printf("*    1. Ingresar 1er operando (A=%.3f)     *\n", numeroA);
    printf("*    2. Ingresar 2do operando (B=%.3f)     *\n", numeroB);
    printf("*    3. Calcular todas las operaciones      *\n");
    printf("*    4. Informar resultados                 *\n");
    printf("*    5. Salir                               *\n\n");
    printf("#    6. Elija una opcion: ");

    }
    flag= 1;
    scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:

            printf("\nIngrese el operando A: ");
            scanf("%f",&numeroA);
            break;


        case 2:

            printf("\nIngrese el operando B: ");
            scanf("%f",&numeroB);
            break;

        case 3:


            /** SUMA */

            numeroSuma = hacerSuma (numeroA, numeroB) ;

            /** RESTA */

            numeroResta = hacerResta (numeroA, numeroB) ;

            /** MULTIPLICACION */

            numeroMulti = hacerMultiplicacion(numeroA, numeroB) ;

            /** DIVISION */

            if (numeroB > 0)
            {

                numeroDivision = hacerDivision(numeroA, numeroB);

            }

            /** NUMERO FACTORIAL DE CADA OPERANDO */


            numeroFactorialA = hacerFactorial (numeroA);
            numeroFactorialB = hacerFactorial (numeroB);


            printf ("-- Las cuentas ya se calcularon!  :) --\n ");

            /** Se realizan las cuentas sin mostrarlas al usuario */

            break;

        case 4:

            /** Se muestran los resultados al usuario */

            printf ("- a) El resultado de %.1f + %.1f es: %.2f \n", numeroA, numeroB, numeroSuma);
            printf ("- a) El resultado de %.1f - %.1f es: %.2f \n", numeroA, numeroB, numeroResta);
            printf ("- a) El resultado de %.1f * %.1f es: %.2f \n", numeroA, numeroB, numeroMulti);

            /** Division si el operandoB es 0 */

            if (numeroB == 0)
            {
                printf ("- d) No se puede dividir si el operandoB es 0 \n");
            }
            else
            {
                printf ("- a) El resultado de %.1f / %.1f es: %.2f \n", numeroA, numeroB, numeroDivision);

            }

                printf("- e) El factorial de A es: %.1d y el factorial de B es: %.1d \n", numeroFactorialA, numeroFactorialB);

            break;

        /** Boton para salir del Menu */

        case 5:
            seguir = 'n';
            break;


        /** Accion que se realiza si no se pone un numero de los indicados */

        default:
            printf ("Opcion incorrecta \n");
            break;
        }

        /** Comandos para que el MENU no se reinicie y queden datos guardados */

        system("pause");
        system ("cls");

        }

    while(seguir == 's');



    return 0;
}



