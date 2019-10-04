#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 1000
#include "ArrayEmployees.h"

int main()
{



    ///MENUS///

    int flag = 0;
    char seguir = 's';
    int opcion;
    int subMenu;

    /// FORMAR LA ESTRUCTURA DE EMPLEADOS ///


    eEmpleado listadoEmpleados[T];
    initEmployees(listadoEmpleados,T);


    ///



    do
    {
        printf("\n\n \t \t/******** ADMINISTRAR LA EMPRESA ********/\n");


        printf("\n1.ALTA\n2.MODIFICAR\n3.BAJA\n4.MOSTRAR\n\n0.SALIR\n\nElija opcion: ");
        scanf("%d", &opcion);

        if (flag == 0 && (opcion==2 || opcion==4 || opcion==3 || opcion==0)) // BANDERA PARA QUE ENTRE SI O SI A LA OPCION 1//
        {

            printf("\nHay que entrar si o si a la opcion 1.ALTA!!!");
            printf("\n\n\n");
            system("pause");
            system ("cls");

            continue;
        }


        switch(opcion)
        {

        case 1:

            addEmployees(listadoEmpleados, T); //DAR DE ALTA
            flag = 1; //la bandera pasa a ser 1 para que puedan a ingresar a otras opciones//
            break;

        case 2:

            editarEmpleado(listadoEmpleados, T); //Permite editar al empleado elegido por ID//
            break;
        case 3:
            removeEmployee(listadoEmpleados,T); //Borrar al empleado mediante la ID//
            break;

        case 4:

            /* UN SUBMENU PARA LA OPCIONES DE LISTAR */

            printf("\n1. Empleados ordenados alfabeticamente Ascendente (Apellido y Sector). \n2. Empleados ordenados alfabeticamente Descendente (Apellido y Sector). \n3. Mostrar suma y promedio de salarios, y cuantos empleados superan el salario  minimo ($15000).\n\nElija opcion: ");
            scanf("%d", &subMenu);

            switch(subMenu)
            {

            case 1:

                sortEmployeesUp(listadoEmpleados, T); /*ORDENA A LOS EMPLEADOS*/
                printEmployees(listadoEmpleados,T); /*MUESTRA*/
                break;

             case 2:

                sortEmployeesDown(listadoEmpleados, T); /*ORDENA A LOS EMPLEADOS*/
                printEmployees(listadoEmpleados,T); /*MUESTRA*/
                break;

            case 3:
                sueldo(listadoEmpleados, T); /*MANEJA EL TOTAL Y PROMEDIO DE LOS EMPLEADOS, Y MUESTRA LOS QUE SUPERAN EL SUELDO BASICO*/
               // superanPromedio(listadoEmpleados, T);
                break;

            default:
                printf("\nNo ingresaste una opcion valida!!\n");
                break;

                }
            break;

        case 0:
            printf("\nSaliendo.\n"); /*SALIR DEL PROGRAMA*/
            seguir = 'n';
            break;

        default:
            printf("\nNo ingresaste una opcion valida!!\n");
            break;
        }

        printf("\n\n");
        system("pause"); /*REINICIA EL CODIGO PARA QUE NO SE ALMACENE TODO EN UNA SOLA ESCENA*/
        system ("cls");

    }
    while(seguir != 'n'); /*CUANDO INGRESA A CASE 0, 'SEGUIR' CAMBIA SU VALOR Y HACE QUE SALGA DEL PROGRAMA*/



}
