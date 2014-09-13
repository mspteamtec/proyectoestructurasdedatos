#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

/************************************************************************/

//Estructura de la lista Carrera Simple
struct Carrera
{
    string carrera; // La variable para guardar el nombre de la Carrera
    struct Carrera *sig; //Puntero al siguiente nodo de la lista
    struct Cursos *PrimeroCurso;//Puntero que enlaza con Curso

};
typedef struct Carrera *TCarreras;


/************************************************************************/

//Estructura de la Lista Cursos Doble
struct Cursos
{
    string codigo;// La variable para guardar el codigo
    string materia;// La variable para guardar el nombre del curso
    int grupo;// La variable para guardar el numero de grupo que va tener el Curso
    int creditos;// La variable para guardar la cantidad de creditos que va tener el Curso
    string restriccion;// La variable para guardar las restricciones
    string horario;// La variable para guardar el horario del Curso
    struct Cursos *sig, *ant;// Los punteros antes y siguiente
    struct Profesor *PrimeroProfesor;// Puntero que enlaza con Profesor
}ListaCursos;// La variable global para guardar los Cursos

/************************************************************************/

// Estructura de la Lista Aulas o Lab Circular
struct Aulas
{
    struct Aulas *sig;// Puntero siguiente
    int codigo; // La variable que guarda el codigo del lab o aula etc
    string espacio;//La variable que guarda el espacio Ej: aula lab piscina miniauditorio
}ListaAulas;//La variable global para guardar las Aulas

/************************************************************************/

//Estructura de la Lista Profesor simple
struct Profesor
{
    string nombre;// La variable para guardar el nombre del Profesor
    string restriccion;// La variable para guardar las restricciones del Profesor
    struct Profesor *sig;// Puntero siguiente
}ListaProfesor;// La variable global para guardar los Profesores


/************************************************************************/

void InsertarFinalCarrera(TCarreras &listaCarrera, string carrera)
{
    TCarreras temp, nuevo;// Se declara el temp y nuevo
    nuevo = new Carrera();// Creamos memoria

    nuevo->carrera = carrera;//Le damos el nombre
    nuevo->sig = NULL;//Le declaramos el puntero a NULL

    if(listaCarrera == NULL)
    {
        listaCarrera = nuevo;
    }
    else
    {
        temp = listaCarrera;
        while(temp->sig != NULL)//Recorremos la lista hasta el ultimo nodo
        {
            temp = temp->sig;
        }
        temp->sig = nuevo;
    }
}

/************************************************************************/

//Metodo para imprimir todos los elementos de una lista simple de Carrera
void ImprimirListaCarrera(TCarreras &listaCarrera)
{
    TCarreras temp = listaCarrera;
    while(temp != NULL) //Se recorren todos los nodos de conforman la lista
    {
        if(temp->sig != NULL)
        {
            cout << temp->carrera << "->"; //Se imprimen los nombres de la lista en pantalla, excepto el ùltimo
        }
        else // Es el ultimo
        {
            cout << temp->carrera << "->NULL"; //Se imprime el último valor del nodo de la lista
        }

        temp = temp->sig; //Se continua con el recorrido de la lista por medio del puntero temporal
    }
}

/************************************************************************/



int main()
{
    TCarreras listaCarrera = NULL;
    ImprimirListaCarrera(listaCarrera);
    InsertarFinalCarrera(listaCarrera, "Computacion");
    InsertarFinalCarrera(listaCarrera, "Agronomia");
    InsertarFinalCarrera(listaCarrera, "Produccion Indistrial");
    InsertarFinalCarrera(listaCarrera, "Electronica");
    ImprimirListaCarrera(listaCarrera);
    cout << "" << endl;
    return 0;
}
