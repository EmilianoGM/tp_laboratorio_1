#define MAX_EMPLOYEES 1000
#define TRUE 1
#define FALSE 0
#define TAMANIO_NAME 51
#define TAMANIO_LASTNAME 51
#define MAX_SALARY 250000
#define MIN_SALARY 1
#define MAX_SECTOR 10
#define MIN_SECTOR 1

typedef struct
{
 int id;
 char name[TAMANIO_NAME];
 char lastName[TAMANIO_LASTNAME];
 float salary;
 int sector;
 int isEmpty;
}Employee;

/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len);

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int buscarLibreEmployee(Employee* list, int len);

/** \brief
 *
 * \param empleado Employee
 * \return void
 *
 */
void mostrarEmployee(Employee empleado);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int generarIdEmployee(Employee* list, int len);

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \param listaDeIds[] int
 * \param cantidadDeIds int
 * \return int
 *
 */
int generarListaOrdenadaDeIdsEmployee(Employee* list, int len, int listaDeIds[], int cantidadDeIds);

/** \brief
 *
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int contarAltasEmployee(Employee* list, int len);

int modificarEmployee(Employee* list, int len,int id, int opcion);

/** \brief find an Employee by Id and returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id);

int printEmployees(Employee* list, int len);

int sortEmployeesByLastName(Employee* list, int len, int order);

int sortEmployeesBySector(Employee* list, int len, int order);

int contarSalariosMasDelPromedio(Employee* list, int len);

float calcularPromedioSalarios(Employee* list, int len);

float sumarTotalSalarios(Employee* list, int len);
