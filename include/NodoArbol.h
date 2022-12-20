#ifndef NODOARBOL_H
#define NODOARBOL_H
#include <Pasajero.h>

class NodoArbol
{
    public:
        NodoArbol(Pasajero* p);
        virtual ~NodoArbol();
        Pasajero* pasajero;
        NodoArbol *izq;
        NodoArbol *der;

        friend class Arbol;

};
typedef NodoArbol* pnodoAbb;
#endif // NODOARBOL_H
