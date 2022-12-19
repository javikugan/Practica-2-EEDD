#include "NodoArbol.h"

NodoArbol::NodoArbol(Pasajero* p)
{
    this->pasajero = p;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol()
{

}
