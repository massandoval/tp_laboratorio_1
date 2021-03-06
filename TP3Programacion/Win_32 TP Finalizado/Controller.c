#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;

    pFile = fopen(path, "r");

    if (pFile != NULL)
    {

        parser_EmployeeFromText(pFile, pArrayListEmployee);
        printf("Se cargaron los datos correctamente!\n\n");
        retorno = 0;
    }
    else
    {

        printf ("No se pudo cargar el archivo!\n\n");

    }

    fclose(pFile);
    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;

    pFile = fopen(path, "r");

    if (pFile != NULL)
    {

        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        printf("Se cargaron los datos correctamente!\n\n");
        retorno = 0;
    }
    else
    {

        printf ("No se pudo cargar el archivo!\n\n");

    }

    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    char nombreAux [30];
    int sueldoAux;
    int horasTrabajadasAux;
    int idAux;

    Employee* newEmployee;
    newEmployee = employee_new();

    if (newEmployee != NULL)
    {

        idAux == ll_len(pArrayListEmployee) + 10;

        getValidString(" Ingrese Nombre: ", " Error, solo letras!", nombreAux);
        sueldoAux = getValidInt(" Ingrese sueldo: ", " Error, reingrese y que sea mayor a 0! ", 0, 10000000);
        horasTrabajadasAux = getValidInt(" Ingrese horas trabajadas: ", " Error, reingrese! ", 0, 1000);

        employee_setId(newEmployee, idAux);
        employee_setHorasTrabajadas(newEmployee, horasTrabajadasAux);
        employee_setNombre(newEmployee, nombreAux);
        employee_setSueldo(newEmployee, sueldoAux);


        ll_add(pArrayListEmployee, newEmployee);
        retorno = 0;
        printf("Empleado cargado con exito!\n\n");
    }

    else
    {
        employee_delete(newEmployee);
        printf("No se pudo cargar un nuevo empleado.\n");
    }

    return retorno;



}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    int idAModificar;
    int indiceEmpleadoAModificar;
    int opcion;

    char nombreAux[128];
    int horasTrabajadasAux;
    int sueldoAux;
    char rta;
    Employee* employeeAModificar;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        idAModificar = getValidInt("Ingrese el id del empleado a modificar: \n","Error, solo numeros.",1,10000);
        indiceEmpleadoAModificar = employee_buscarPorId(pArrayListEmployee,idAModificar);

        if(indiceEmpleadoAModificar != -1)
        {
            ///muestro el empleado que se esta modifciando.
            employeeAModificar = (Employee*) ll_get(pArrayListEmployee, indiceEmpleadoAModificar);
            printf("\nID:%d NOMBRE:%s HRS:%d SUELDO:%d\n",employeeAModificar->id,employeeAModificar->nombre,employeeAModificar->horasTrabajadas,employeeAModificar->sueldo);

            printf("Ingrese el numero del campo a modificar: \n");
            opcion = getValidInt("1-Nombre \n2-Hrs trabajadas \n3-Sueldo \n","Error, vuelva a ingresar.\n",1,3);

            switch(opcion)
            {
            case 1:
                getValidString("Ingrese nuevo nombre: \n","Error,vuelva a ingresar.\n",nombreAux);
                printf("Desea confirmar el cambio? s/n\n");
                fflush(stdin);
                rta = getche();

                while(rta != 's' && rta != 'n' && rta != 'S' && rta != 'N')
                {
                    printf("Desea confirmar el cambio? s/n\n");
                    fflush(stdin);
                    rta = getche();
                }

                if(rta == 's' || rta == 'S')
                {
                    employee_setNombre(employeeAModificar,nombreAux);///seteo nuevo nombre.
                    printf("\nNombre modificado con exito.\n");
                    retorno = 0;
                }
                else if(rta == 'n' || rta == 'N')
                {
                    printf("\nSe cancelo la modificacion.\n");
                }

                break;
            case 2:
                horasTrabajadasAux = getValidInt("Ingrese nuvas horas trabajadas: \n","Error, vuelva a ingresar",0,1000);

                printf("Desea confirmar el cambio? s/n\n");
                fflush(stdin);
                rta = getche();

                while(rta != 's' && rta != 'n' && rta != 'S' && rta != 'N')
                {
                    printf("Desea confirmar el cambio? s/n\n");
                    fflush(stdin);
                    rta = getche();
                }

                if(rta == 's' || rta == 'S')
                {
                    employee_setHorasTrabajadas(employeeAModificar,horasTrabajadasAux);///seteo nuevas horas
                    printf("\nHoras modificadas con exito.\n");
                    retorno = 0;
                }
                else if(rta == 'n' || rta == 'N')
                {
                    printf("\nSe cancelo la modificacion.\n");
                }
                break;
            case 3:
                sueldoAux = getValidInt("Ingrese nuevo sueldo: \n","Error, vuelva ingresar.\n",1,100000);

                printf("Desea confirmar el cambio? s/n\n");
                fflush(stdin);
                rta = getche();

                while(rta != 's' && rta != 'n' && rta != 'S' && rta != 'N')
                {
                    printf("Desea confirmar el cambio? s/n\n");
                    fflush(stdin);
                    rta = getche();
                }

                if(rta == 's' || rta == 'S')
                {
                    employee_setSueldo(employeeAModificar,sueldoAux);///seteo nuevo sueldo
                    printf("\nSueldo modificado con exito.\n");
                    retorno = 0;
                }
                else if(rta == 'n' || rta == 'N')
                {
                    printf("\nSe cancelo la modificacion.\n");
                }
                break;
            }
        }
        else
        {
            printf("\nNo se encontro empleado con ese id.\n");
        }
    }
    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
     int retorno = -1;
    char rta;
    int idABorrar;
    int indiceEmpleadoABorrar;
    Employee* pEmployeeABorrar;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        idABorrar = getValidInt("Ingrese el ID del empleado a borrar: \n","Error, solo numeros.",1,10000);
        indiceEmpleadoABorrar = employee_buscarPorId(pArrayListEmployee,idABorrar);

        if(indiceEmpleadoABorrar != -1)
        {
            ///muestro el empleado que se esta por borrar.
            pEmployeeABorrar = (Employee*) ll_get(pArrayListEmployee, indiceEmpleadoABorrar);
            printf("\nID:%d NOMBRE:%s HRS:%d SUELDO:%d\n",pEmployeeABorrar->id,pEmployeeABorrar->nombre,pEmployeeABorrar->horasTrabajadas,pEmployeeABorrar->sueldo);

            printf("Esta seguro que desea borrar el empleado? s/n \n");
            fflush(stdin);
            rta = getche();

            while(rta != 's' && rta != 'n' && rta != 'S' && rta != 'N')
            {
                printf("Desea confirmar el cambio? s/n\n");
                fflush(stdin);
                rta = getche();
            }

            if(rta == 's' || rta == 'S')
            {
                ll_remove(pArrayListEmployee,indiceEmpleadoABorrar);
                printf("\nSe borro el empleado con exito.\n");
                retorno = 0;
            }
            else if(rta == 'n' || rta == 'N')
            {
                printf("\nSe cancelo la baja del empleado.\n");
            }
        }

    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int retorno= -1;
    Employee* indexEmp;

    printf("ID \t\t NOMBRE \t HORAS \t\t SUELDO\n");
    fflush(stdin);

    for (i=1 ; i < ll_len(pArrayListEmployee) ; i++)
    {

        indexEmp = (Employee*) ll_get(pArrayListEmployee, i);

        if (indexEmp != NULL)
        {

            printf("%3d %19s %14d %15d\n", indexEmp->id, indexEmp->nombre,indexEmp->horasTrabajadas, indexEmp ->sueldo);
            retorno = 0;
        }


    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    LinkedList* cloneLinkedList;

    if(pArrayListEmployee != NULL )
    {
        cloneLinkedList = ll_clone(pArrayListEmployee);
        if(cloneLinkedList != NULL)
        {
            ll_sort(cloneLinkedList, employee_sortByName,1);

            controller_ListEmployee(cloneLinkedList);

            for(i=0 ; i<ll_len(cloneLinkedList); i++)
            {
                ll_remove(cloneLinkedList,i);
            }
            ll_deleteLinkedList(cloneLinkedList);
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    FILE* pArchivo;
    Employee* pEmployeeAux;
    pArchivo = fopen(path, "w");
    if (pArchivo != NULL)
    {

        fprintf(pArchivo, "%s,%s,%s,%s\n", "id", "nombre", "horasTrabajadas", "sueldo");
        for (i=0 ; i < ll_len(pArrayListEmployee) ; i++)
        {
            pEmployeeAux = (Employee*) ll_get(pArrayListEmployee, i);
            if (pEmployeeAux != NULL);
            {
                fprintf(pArchivo, "%d,%s,%d,%d", pEmployeeAux->id, pEmployeeAux->nombre, pEmployeeAux->horasTrabajadas, pEmployeeAux->sueldo);
            }
        }
        retorno = 0;
        printf("Se guardo en modo texto correctamente! \n");
        fclose(pArchivo);
    }
    return  retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    int i;
    FILE* pArchivo;
    Employee* pEmployeeAux;


    pArchivo = fopen(path, "wb");
    if (pArchivo != NULL)
    {
        for (i=0 ; i < ll_len(pArrayListEmployee) ; i++)
        {
            pEmployeeAux = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(pEmployeeAux, sizeof (Employee), 1, pArchivo);
        }

        printf("Se guardo todo en modo binario correctamente!");
        retorno = 0;

    }
    fclose(pArchivo);
    return retorno;
}

