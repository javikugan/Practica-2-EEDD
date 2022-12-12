#include <iostream>
#include "Cola.h"

Cola::~Cola()
{
    //destructor
}
void Cola::encolar(TMaleta m) //crea un nodo y encola ese nodo, metiendo las maletas en una cola
{
    pNodo nuevo;
    nuevo = new Nodo(m);
    nuevo->siguiente=NULL;
    if(final) final->siguiente = nuevo;
    final= nuevo;
    if(!principio) principio = nuevo;
};
TMaleta Cola::desencolar() // quita las maletas de la cola, desencola un nodo y devuelve la maleta que tiene ese nodo
{
    TMaleta vacia;
    pNodo nodo;
    TMaleta m;
    nodo = principio;
    if(!nodo) return vacia;
    principio = nodo->siguiente;
    m = nodo->maleta;
    delete nodo;
    if(!principio) final = NULL;
    return m;
};



int Cola::length() // cuenta los elementos que hay en una cola y devuelve un entero. Longitud de la cola.
{
    int cont = 0;
    pNodo nodo = principio;
    while (nodo != NULL) {
        nodo = nodo->siguiente;
        cont++;
    }
    return cont;
};
bool Cola::es_vacia(){ //comprueba si una cola está vacía
    return principio == NULL;
}

void Cola::imprimir_cola(){ //imprime la cola  con las maletas, cada una con sus atributos(id, dni, hora de salida, origen, destino, localizador, nombre)
    pNodo nodo = principio;
    while (nodo != NULL) {
        TMaleta maleta = nodo->maleta ;
        std::cout << "|" + maleta.id + "|" + maleta.dni + "|" + maleta.hora + "|" + maleta.origen + "|" + maleta.destino + "|" + maleta.localizador + "|" + maleta.nombre +"|" << std::endl;
        nodo = nodo->siguiente;

    }
};
