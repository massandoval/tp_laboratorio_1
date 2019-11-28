#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int flag = 0;



    do
    {

        printf("\n\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).  3. Alta de empleado \n 4. Modificar datos de empleado \n 5. Baja de empleado \n 6. Listar empleados \n 7. Ordenar empleados \n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n 9. Guardar los datos de los empleados en el archivo data.bin (modo binario) \n 10. Salir \n\n Elija opcion: ");
        scanf("%d", &option);

         if (flag == 0 && (option==3 || option==4 || option==5 || option==6 || option == 7 || option==8 || option==9)) // BANDERA PARA QUE ENTRE SI O SI A LA OPCION 1//
        {

            printf("\nHay que entrar si o si a la opcion 1 o 2!!!");
            printf("\n\n\n");
            system("pause");
            system ("cls");

            continue;
        }


        switch(option)
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            flag = 1;
            break;
        case 2:
            controller_loadFromBinary("data.dat", listaEmpleados);
            flag = 1;
            break;

        case 3:
            controller_addEmployee(listaEmpleados);
            break;
        case 4:
            controller_editEmployee(listaEmpleados);
            break;
        case 5:
            controller_removeEmployee(listaEmpleados);
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            controller_saveAsText("data.csv", listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("data.dat", listaEmpleados);
            break;
        case 10:
            printf("\n Saliendo...");
            option = 10;
            break;
        default:
            printf("Ingrese una opcion valida! \n");
            break;
        }


        printf("\n\n");
        system("pause"); /*REINICIA EL CODIGO PARA QUE NO SE ALMACENE TODO EN UNA SOLA ESCENA*/
        system ("cls");



    }
    while(option != 10);
    return 0;
}
