#include <iostream>
#include "Pila.h"
using namespace std;


Pila::~Pila()
{
    while(cima) desapilar(); // mientras sigan quedando elementos en la pila, desapila (quita elemento de la pila a medida que se recorre la pila)
    //destructor
}
void Pila::apilar(TMaleta m) // introduce elementos en la pila detrás del último elemento que se hubiera introducido y el nuevo elemento pasa a ser la cima de la pila
{
    pNodo nuevo = new Nodo();

    nuevo->maleta = m;
    nuevo->siguiente=NULL;
    //cout<<"puntero "<<nuevo->siguiente<<endl;
    if (cima == NULL) {
        cima = nuevo;
        Util::imprimirMaleta(m);
    }
    else {
        nuevo ->siguiente = cima;
        cima = nuevo; // cima apunta al nuevo nodo
    }
}


TMaleta Pila::desapilar() // quita de la pila el el elemento situado en la cima de la misma (el último elemento introducido en la pila)
{
    pNodo nodo; //
    TMaleta m;

    nodo = cima;
    cima= nodo->siguiente;
    m = nodo->maleta;
    delete nodo;
    return m;
}

int Pila::length() // indica cuántos elementos hay en la pila, devuelve un entero
{
    int cont = 0;
    pNodo nodo = cima;
    while (nodo != NULL) {
        nodo = nodo->siguiente;
        cont++;
    }
    return cont;
}


bool Pila::esVacia(){ // comprueba si la pila está vacía. Devuelve un valor de verdad(true) en caso de estar vacía
    return cima == NULL;}

void Pila::vacia(){ //inicializa la pila vacia
cima=NULL;}

void Pila::imprimir_pila(){ // imprime la pila por pantalla. Cada pila es un contenedor de maletas. Imprime de cada maleta los atributos(id, dni, hora de salida, localizador,  nombre)
    pNodo nodo = cima;
    int n=1;
    cout << "Imprimiendo Pila: "<<endl;
    while (nodo != NULL) {
        //cout << "voy a por " << n <<" "<<nodo->siguiente<<" ";
        TMaleta maleta = nodo->maleta ;
        std::cout << "|" + maleta.id + "|" + maleta.dni + "|" + maleta.hora + "|" + maleta.origen + "|" + maleta.destino + "|" + maleta.localizador + "|" + maleta.nombre +"|"<< endl ;
        //std::cout << n << "|" + maleta.id + "|" + maleta.dni<< endl ;
        nodo = nodo->siguiente;
        n++;
    }

}
