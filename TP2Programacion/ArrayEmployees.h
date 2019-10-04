#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1


typedef struct
{
   int id;
   char name[50];
   char lastName[50];
   float salary;
   int sector;
   int isEmpty;
}eEmpleado;


eEmpleado pedirEmpleado();

/** PEDIDAS EN EL TP: sortEmployees, printEmployees, initEmployees, removeEmployee, addEmployees,           **/


/** \brief Ordena la estructura por apellido y sector (Si el apellido es es igual, pone al sector mas bajo arriba del otro) en forma ascendente
 *
 * \param Estructura eEmpleado
 * \param Tamaño del array de empleados
 * \return void
 *
 */
void sortEmployeesUp (eEmpleado [], int );

/** \brief Muestra a un empleado (singular)
 *
 * \param eEmpleado Estructura eEmpleado
 * \return void Devuelve el printf del empleado
 *
 */
void mostrarEmpleado(eEmpleado);

/** \brief Carga el empleado si el estado esta VACIO
 *
 * \param eEmpleado[] Estructura eEmpleado
 * \param int Tamaño del array
 * \return void
 *
 */
void printEmployees(eEmpleado[], int);

/** \brief Pone en 0 a todos los valores de la estructuras (Inicializar)
 *
 * \param eEmpleado[] Estructura eEmpleado
 * \param int Tamaño del array
 * \return void
 *
 */
void initEmployees(eEmpleado[], int);

/** \brief Si el array esta vacio, lo llena con los datos que ingrese el usuario y le asigna un ID.
 *
 * \param [] eEmpleado Estructura eEmpleado
 * \param int Tamaño del array
 * \return int el indice
 *
 */
int addEmployees(eEmpleado [], int );

/** \brief si hay un lugar libre, devuelve el indice en el cual se encuentra ese valor igual a LIBRE
 *
 * \param eEmpleado[] Estructura eEmpleado
 * \param int Tamaño del array
 * \return int el indice
 *
 */
int dameLugarLibre(eEmpleado[],int);

/** \brief Borra al empleado mediante la ID.
 *
 * \param eEmpleado[] Estructura eEmpleado
 * \param int Tamaño del array
 * \return --
 *
 */
int removeEmployee(eEmpleado[], int);

/** \brief Muestra la lista de ID'S y los apellidos, una vez puesto el ID de alguno de ellos se puede elegir que dato modificar y lo reemplaza en la estrucuctura.
 *
 *
 * \param [] eEmpleado Estructura eEmpleado.
 * \param int Tamaño del array.
 * \return int 0
 *
 */
int editarEmpleado(eEmpleado [], int );

/** \brief Genera una ID Automatica a la persona.
 *
 * \param [] eEmpleado Estructura eEmpleado
 * \param int Tamaño del array
 * \return int el ID.
 *
 */
int generarId(eEmpleado [],int );

/** \brief Suma los sueldos, saca su promedio y tambien cuenta la cantidad de empleados que superan el sueldo basico que es 15000.
 *
 * \param Estructura eEmpleado
 * \param Tamaño del array
 * \return Retonna 0 pero tambien 2 printf con los sueldos y cantidad de empleados.
 *
 */
float sueldo (eEmpleado [], int);


/** \brief Forma un menu.
 *
 * \param [] char Esqueleto del menu.
 * \return int 0
 *
 */
int menuOp(char []);


/** \brief Ordena la estructura por apellido y sector (Si el apellido es es igual, pone al sector mas bajo arriba del otro) en forma descendente
 *
 * \param Estructura eEmpleado
 * \param Tamaño del array de empleados
 * \return void
 *
 */
void sortEmployeesDown (eEmpleado [], int );







