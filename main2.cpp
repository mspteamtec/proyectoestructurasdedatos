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

}*LisCarrera;


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
    string profesor;
    struct Cursos *sig, *ant;// Los punteros antes y siguiente
};

/************************************************************************/
//Función para buscar la carrera
struct Carrera *BuscarCarrera(string carrera){

 struct Carrera *tempC = LisCarrera;
 if(tempC==NULL)
      return NULL;
      do {
          if(tempC->carrera == carrera)
              return tempC;
          tempC = tempC->sig;
      } while( tempC != LisCarrera);

return NULL;
}


/************************************************************************/
//Función para insertar en la lista Carrera
void InsertarFinalCarrera(string carrera)
{
    struct Carrera *nuevo;// Se declara el temp y nuevo
    nuevo = new Carrera();// Creamos memoria

    nuevo->carrera = carrera;//Le damos el nombre
    nuevo->sig = NULL;//Le declaramos el puntero a NULL

    if(LisCarrera == NULL)
    {
        LisCarrera = nuevo;
    }
    else
    {
        struct Carrera *temp;
        temp = LisCarrera;
        while(temp->sig != NULL)//Recorremos la lista hasta el ultimo nodo
        {
            temp = temp->sig;
        }
        temp->sig = nuevo;
    }
}

/************************************************************************/
//Función para Modificar una Carrera
void ModificarCarrera(string carrera, string nuevacarrera)
{
    struct Carrera *temp;
    temp = LisCarrera;
    if(LisCarrera!=NULL)
    {
        while(temp != NULL) //Recorrido de todos los nodos de la lista
        {
            if(temp->carrera == carrera) //Busqueda de la carrera que se desea modificar
            {
                temp->carrera=nuevacarrera;//La modificamos
                break;
            }
            else
            {
                temp = temp->sig;
            }
        }
        if(temp == NULL)
        {
            cout<<"La carrera no esta registrada\n";
        }
    }
    else
    {
      cout<<"La lista de Carreras esta NULL\n";
    }
}

/************************************************************************/
//Función para eliminar una carrera
void EliminarCarrera(string carrera)
{
    struct Carrera *temp, *ant;
    temp = LisCarrera;

    if(LisCarrera != NULL) //La lista debe contener valores para poder eliminar un nodo
    {
        while(temp != NULL) //Recorrido de todos los nodos de la lista
        {
            if(temp->carrera == carrera) //Busqueda de la carrera que se desea eliminar
            {
                if(temp == LisCarrera) //Validaciòn para eliminar el primer elemento de la lista
                {
                    LisCarrera = LisCarrera->sig;
                }
                else
                {
                    ant->sig = temp->sig; //Quitar el enlace del nodo por eliminar
                }

                delete(temp); //Se elimina de la memoria el nodo
                return; //Se sale del ciclo, una vez eliminado el nodo
            }
            ant = temp; //en el caso de no haber encontrado y eliminado el nodo de la lista, se procede actualizar los punteros anterior y temporal
            temp = temp->sig;
        }
        cout<<"La carrera no esta registrada\n";
    }
    else
    {
        cout<<" No hay carreras registradas\n";
    }
}

/************************************************************************/

//Metodo para imprimir todos los elementos de una lista simple de Carrera
void ImprimirCarrera()
{
    struct Carrera *temp;
    temp= LisCarrera;
    if (temp != NULL)
    {
       while(temp != NULL) //Se recorren todos los nodos de conforman la lista
       {
            if(temp->sig != NULL)
            {
                cout << temp->carrera << "->"; //Se imprimen los nombres de la lista en pantalla, excepto el ùltimo
            }
            else // Es el ultimo
            {
                cout << temp->carrera << "->NULL\n"; //Se imprime el último valor del nodo de la lista
            }

            temp = temp->sig; //Se continua con el recorrido de la lista por medio del puntero temporal
        }

    }
    else
    {
        cout<<"No hay carrerar registradas";
    }
}

/************************************************************************/
//Función Para insertar el curso enlazado a la carrera
void InsertarCurso(string carrera, string codigo, string materia, int grupo, int creditos, string restricciones, string  horario, string profesor)
{

    struct Carrera *tempC= BuscarCarrera(carrera);

    if((tempC!=NULL))
    {
        struct Cursos *nuevo= new Cursos();
        nuevo->codigo=codigo;
        nuevo->creditos=creditos;
        nuevo->grupo=grupo;
        nuevo->horario=horario;
        nuevo->materia=materia;
        nuevo->restriccion=restricciones;
        nuevo->profesor=profesor;
        nuevo->sig=NULL;
        nuevo->ant=NULL;
        if(tempC->PrimeroCurso == NULL)
        {
            tempC->PrimeroCurso=nuevo;
        }
        else if(nuevo->codigo < tempC->PrimeroCurso->codigo)
        {
            nuevo->sig = tempC->PrimeroCurso;
            tempC->PrimeroCurso->ant = nuevo;
            tempC->PrimeroCurso = nuevo;
        }
        else if(tempC->PrimeroCurso->sig == NULL)
        {
            nuevo->ant = tempC->PrimeroCurso;
            tempC->PrimeroCurso->sig = nuevo;
        }
        else
        {
            struct Cursos *temp, *ant;
            temp = tempC->PrimeroCurso;
            ant = temp;
            while( ant != NULL)
            {
                if( ant->sig == NULL)
                {
                    ant->sig = nuevo;
                    nuevo->ant = temp;
                    ant = nuevo->sig;
                }
                else if (ant->codigo <= nuevo->codigo  && ant->sig !=NULL)
                {
                    temp = ant->sig;
                    if (nuevo->codigo < temp->codigo)
                    {
                        nuevo->sig = temp;
                        temp->ant = nuevo;
                        ant->sig = nuevo;
                        nuevo->ant = ant;
                        break;
                    }
                }

                else
                {
                    ant = temp;
                }
            }
        }
    }

}

/************************************************************************/
//Función para imprimir los cursos de la carrera
void ImprimirCursos(string carrera)
{
 struct Carrera *tempC=BuscarCarrera(carrera);//busca la carrera respectiva
       if(tempC!=NULL && tempC->PrimeroCurso !=NULL)
        {
            cout<< "La Carrera:    "<<tempC->carrera << "\n";
            cout<< "| Codigo |      Materia     |Grupo|Creditos|    Horario    |   Profesor  |""\n";

            while(tempC->PrimeroCurso != NULL)
            {
                if(tempC->PrimeroCurso == tempC->PrimeroCurso && tempC->PrimeroCurso->sig == NULL) //La lista solo contiene un nodo
                {
                    cout<< "| "<<tempC->PrimeroCurso->codigo<<" |     "<<tempC->PrimeroCurso->materia<<"    |  "<<tempC->PrimeroCurso->grupo<<" |    "<<tempC->PrimeroCurso->creditos<<"   | "<<tempC->PrimeroCurso->horario<<" |    "<<tempC->PrimeroCurso->profesor<<"   |\n";

                }
                else if(tempC->PrimeroCurso == tempC->PrimeroCurso && tempC->PrimeroCurso->sig != NULL && tempC->PrimeroCurso->ant == NULL) //La lista contiene mas de un nodo
                {
                    cout<< "| "<<tempC->PrimeroCurso->codigo<<" |     "<<tempC->PrimeroCurso->materia<<"    |  "<<tempC->PrimeroCurso->grupo<<" |    "<<tempC->PrimeroCurso->creditos<<"   | "<<tempC->PrimeroCurso->horario<<" |    "<<tempC->PrimeroCurso->profesor<<"   |\n";
                }
                else if(tempC->PrimeroCurso->sig != NULL && tempC->PrimeroCurso->ant != NULL) //La lista contiene mas de un nodo
                {
                    cout<< "| "<<tempC->PrimeroCurso->codigo<<" |     "<<tempC->PrimeroCurso->materia<<"    |  "<<tempC->PrimeroCurso->grupo<<" |    "<<tempC->PrimeroCurso->creditos<<"   | "<<tempC->PrimeroCurso->horario<<" |    "<<tempC->PrimeroCurso->profesor<<"   |\n";
                }
                else // Es el ultimo
                {
                    cout<< "| "<<tempC->PrimeroCurso->codigo<<" |     "<<tempC->PrimeroCurso->materia<<"    |  "<<tempC->PrimeroCurso->grupo<<" |    "<<tempC->PrimeroCurso->creditos<<"   | "<<tempC->PrimeroCurso->horario<<" |    "<<tempC->PrimeroCurso->profesor<<"   |\n";
                   //Se imprime el último valor del nodo de la lista
                }
                tempC->PrimeroCurso = tempC->PrimeroCurso->sig;
            }
        }
        else
        {
            cout<< "La Carrera no tiene cursos registrados";
        }
}
void Menu(){
cout<<"Opciones"<<"\n";


}


/************************************************************************/


int main()
{
    Menu();
    InsertarFinalCarrera("Computacion");
    /*InsertarFinalCarrera("Agronomia");
    InsertarFinalCarrera( "Produccion Indistrial");
    InsertarFinalCarrera("Electronica");
    InsertarFinalCarrera("Turismo");
    ImprimirCarrera();*/

    /*ificarCarrera("Computacion", "Lo mejor");
    ImprimirCarrera();
    ModificarCarrera("Agronomia", "Mierda");
    ImprimirCarrera();
    ModificarCarrera("Produccion Indistrial", "Pasa");
    ImprimirCarrera();
    ModificarCarrera("Electronica", "Buena");
    ImprimirCarrera();*/

    /*EliminarCarrera("Agronomia");
    ImprimirCarrera();
    EliminarCarrera("Produccion Indistrial");
    ImprimirCarrera();
    EliminarCarrera("Electronica");
    ImprimirCarrera();
    EliminarCarrera("Turismo");
    ImprimirCarrera();
    EliminarCarrera("sdbdv");
    ImprimirCarrera();
    EliminarCarrera("Computacion");
    ImprimirCarrera();*/


    InsertarCurso("Computacion", "CA4", "Elementos", 50, 3, "Ninguna", "K 12:30-14:15", "Marlen");
    InsertarCurso("Computacion", "CA4", "Fundament", 50, 3, "Ninguna", "K 12:30-14:15", "Huber ");
    InsertarCurso("Computacion", "CA3", "Arquitect", 50, 3, "Ninguna", "K 12:30-14:15", "Jorge ");
    InsertarCurso("Computacion", "CA2", "SistemasO", 50, 3, "Ninguna", "K 12:30-14:15", "Vera  ");


    ImprimirCursos("Computacion");


    return 0;
}
