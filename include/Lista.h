#include <iostream>

#ifndef LISTA_H
#define LISTA_H
#include <NodoLista.h>
#include <Pasajero.h>
#include <TMaleta.h>

class Lista
{
    public:

        Lista(){cabeza = actual = final = NULL;}
        ~Lista();
        void insertarNodo(TMaleta m);
        void borrarNodo(TMaleta m);
        bool listaVacia();
        void esCabeza();
        void esFinal();
        void esSiguiente();
        bool esActual();
        TMaleta valorActual();
        void recorrerLista();

    private:
        pnodo cabeza, actual, final;

};

#endif
