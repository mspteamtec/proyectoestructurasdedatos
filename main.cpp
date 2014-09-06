#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

/************************************************************************/

//Estructura de la lista Carrera simple
struct Carreras
{
    string carrera; // La variable para guardar el nombre de la Carrera
    struct Carreras *sig; //Puntero al siguiente nodo de la lista
    struct Cursos *PrimeroCurso;//Puntero que enlaza con Curso
}ListaCarreras;//La variable global para guardar las Carreras

/************************************************************************/

//Estructura de la Lista Cursos doble
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

//Estructura de la Lista Profesor simple
struct Profesor
{
    string nombre;// La variable para guardar el nombre del Profesor
    string restriccion;// La variable para guardar las restricciones del Profesor
    struct Profesor *sig;// Puntero siguiente
}ListaProfesor;


/************************************************************************/





int main()
{
    cout << "Cristian Playo" << endl;
    return 0;
}
