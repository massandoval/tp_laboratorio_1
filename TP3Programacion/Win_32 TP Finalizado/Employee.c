#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new()
{
    Employee* retornoEmpleado;
    retornoEmpleado = (Employee*) malloc (sizeof (Employee));
    return retornoEmpleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* returnEmployee;

    returnEmployee = employee_new();

    int id = atoi (idStr);
    int sueldo = atoi (sueldoStr);
    int horasTrabajadas = atoi(horasTrabajadasStr);



    if (returnEmployee !=NULL)
    {
        employee_setId(returnEmployee, id);
        employee_setSueldo(returnEmployee, sueldo);
        employee_setHorasTrabajadas(returnEmployee, horasTrabajadas);
        employee_setNombre(returnEmployee, nombreStr);
    }

    return returnEmployee;

}

int employee_setSueldo(Employee* pEmpleado,int sueldo)
{

    int esCorrect = 0;

    if (pEmpleado!=NULL && sueldo> 0 )

    {
        pEmpleado->sueldo=sueldo;
        esCorrect=1;
    }
    return esCorrect;
}

int employee_getSueldo(Employee* pEmpleado,int* sueldo)
{
    if (pEmpleado !=NULL)
    {
        *sueldo=pEmpleado->sueldo;
    }
    return *sueldo;

}

int employee_setId(Employee* pEmpleado,int id)
{

    int esCorrect = 0;

    if (pEmpleado!=NULL)

    {
        pEmpleado->id=id;
        esCorrect=1;
    }
    return esCorrect;
}

int employee_getId(Employee* pEmpleado,int* id)
{
    if (pEmpleado !=NULL)
    {
        *id=pEmpleado->id;
    }
    return *id;

}

int employee_setNombre(Employee* pEmpleado,char* nombre)
{
    int esCorrect = 0;

    if (pEmpleado!=NULL)

    {

        strcpy(pEmpleado->nombre, nombre);
        esCorrect=1;
    }
    return esCorrect;

}

int employee_getNombre(Employee* pEmpleado,char* nombre)
{

    int seUsa = 0;

    if (pEmpleado !=NULL)
    {
        strcpy(nombre, pEmpleado->nombre);
        seUsa = 1;

    }

    return seUsa;

}


int employee_setHorasTrabajadas(Employee* pEmpleado,int horasTrabajadas)
{

    int esCorrect = 0;

    if (pEmpleado!=NULL)

    {
        pEmpleado->horasTrabajadas=horasTrabajadas;
        esCorrect=1;
    }
    return esCorrect;
}

int employee_getHorasTrabajadas(Employee* pEmpleado,int* horasTrabajadas)
{
    if (pEmpleado !=NULL)
    {
        *horasTrabajadas=pEmpleado->horasTrabajadas;
    }
    return *horasTrabajadas;

}

void employee_delete(Employee* this)
{
    free(this);
}

int employee_sortByName(Employee* employee1, Employee* employee2)
{
    int retorno;

    retorno = stricmp(employee1->nombre, employee2->nombre);

    return retorno;
}

int employee_buscarPorId(LinkedList* pLista, int idEmployee)
{
    int indice = -1;
    int i;
    int tamLista;
    int idAux;
    Employee* pEmployeeAux;

    tamLista = ll_len(pLista);

    if(pLista != NULL)
    {
        for(i=0; i<tamLista; i++)
        {
            pEmployeeAux = (Employee*) ll_get(pLista,i);///tomo un empleado

            employee_getId(pEmployeeAux,&idAux);///tomo su id
            ///matcheo los ids
            if(idAux == idEmployee)///lo comparo, si son iguales retorno el indice
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}


