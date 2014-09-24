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
                cout << temp->carrera << "->NULL\n\n"; //Se imprime el último valor del nodo de la lista
            }

            temp = temp->sig; //Se continua con el recorrido de la lista por medio del puntero temporal
        }

    }
    else
    {
        cout<<"No hay carrerar registradas\n\n";
    }
}

/************************************************************************/
bool comparadorDeStrings(string codigo1, string codigo2)
{
    if (codigo1.compare(codigo2)!=0)
    {
        if(codigo1.compare(codigo2)>0)
        {
                return (false);
        }
        else
        {
            return(true);
        }
    }
    else
    {
        return (true);
    }

}

/************************************************************************/
//Función Para insertar el curso enlazado a la carrera
void InsertarCurso(string carrera, string codigo, string materia, int grupo, int creditos, string restricciones, string  horario, string profesor)
{

    struct Carrera *tempC= BuscarCarrera(carrera);

    if((tempC!=NULL))
    {
        struct Cursos *nn= new Cursos();
        nn->codigo=codigo;
        nn->creditos=creditos;
        nn->grupo=grupo;
        nn->horario=horario;
        nn->materia=materia;
        nn->restriccion=restricciones;
        nn->profesor=profesor;
        nn->sig=NULL;
        nn->ant=NULL;

        if(tempC->PrimeroCurso == NULL)
            {
                tempC->PrimeroCurso = nn;
                tempC->PrimeroCurso->sig=NULL;
                tempC->PrimeroCurso->ant = NULL;
            }
        else
        {
            struct Cursos* temp = tempC->PrimeroCurso;
            for(;(comparadorDeStrings((temp->codigo),(codigo))==true)&&(temp->sig!=NULL);temp = temp->sig);

            if((comparadorDeStrings((tempC->PrimeroCurso->codigo),(codigo))==false))
                {//inserta al inicio
                    nn->sig = temp;
                    //nn->ant = temp->ant;
                    temp->ant=nn; //duda
                    temp->sig=NULL;
                    tempC->PrimeroCurso = nn;
                }
            if(comparadorDeStrings((codigo),(temp->codigo))==true)
                {//si es menor
                    temp->ant->sig=nn;
                    nn->sig = temp;
                    nn->ant = temp->ant;
                    temp->ant=nn;
                }
                    else{// es mayor que todos los que estan en la lista y lo inserta al final
                            temp->sig = nn;
                            nn->ant = temp;
                        }
        }
        return;


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

/***********************************************************************/

void MenuCarrera(){
string opcion;
cout<<"-----Seleccione una opcion-----"<<"\n";
cout<<"1-Insertar Carrera"<<"\n";
cout<<"2-Modificar Carrera"<<"\n";
cout<<"3-Eliminar Carrera"<<"\n";
cout<<"4-Ver las Carreras"<<"\n";
cout<<"5-Menu Principal"<<"\n";
cin >>opcion;
if(opcion=="1"){
    string carrerainsertar;
    cout<<"Ingrese la carrera que desea insertar:  ";
    cin >>carrerainsertar;
    InsertarFinalCarrera(carrerainsertar);
    MenuCarrera();
}

else if(opcion=="2"){
    string carreramodificar;
    string nuevacarrera;
    cout<<"Ingrese la carrera que desea modificar:  ";
    cin >>carreramodificar;
    cout<<"Ingrese el nuevo nombre de la carrera:  ";
    cin >>nuevacarrera;
    ModificarCarrera(carreramodificar, nuevacarrera);
    MenuCarrera();
}
else if(opcion=="3")
{
    string carreraeliminar;
    cout <<"Ingrese la carrera que desea eliminar:  ";
    cin>>carreraeliminar;
    EliminarCarrera(carreraeliminar);
    MenuCarrera();
}
else if(opcion=="4")
{
    ImprimirCarrera();
    MenuCarrera();
}
/*else if(opcion=="5")
{
    MenuPrincipal1();
}*/
else{
    cout<<"La opcion es invalida";
}
}

/************************************************************************/
void MenuPrincipal()
{
    string opcion;
    cout<<"-----Seleccione una opcion-----"<<"\n";
    cout<<"1-Menu de Carreras"<<"\n";
    cout<<"2-Menu de Cursos"<<"\n";
    cout<<"3-Menu de Aulas"<<"\n";
    cout<<"4-Salir"<<"\n";
    cin >>opcion;

    if (opcion =="1")
    {
        MenuCarrera();
    }
}




/************************************************************************/


int main()
{
    InsertarFinalCarrera( "Produccion Indistrial");
    InsertarFinalCarrera("Computacion");
    MenuPrincipal();
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


    /*InsertarCurso("Computacion", "CA2125", "Elementos", 50, 3, "Ninguna", "K 12:30-14:15", "Marlen");
    InsertarCurso("Computacion", "IC3101", "Arquitect", 50, 4, "Ninguna", "K 12:30-16:50", "Jorge ");
    InsertarCurso("Computacion", "IC1802", "Introduci", 50, 3, "Ninguna", "K 7:55-9:40  ", "Vera  ");
    InsertarCurso("Computacion", "IC2001", "Estructur", 50, 4, "Ninguna", "K 7:55-11:30 ", "Lorena");
    InsertarCurso("Computacion", "IC1400", "Fundament", 50, 3, "Ninguna", "K 12:30-16:50", "Vera  ");
    InsertarCurso("Computacion", "IC1803", "TallerDeP", 50, 3, "Ninguna", "L 7:00-8:45  ", "Efren ");
    InsertarCurso("Computacion", "IC3002", "AnalisisA", 50, 4, "Ninguna", "K 12:30-16:50", "Lorena");*/


    //ImprimirCursos("Computacion");


    return 0;
}
