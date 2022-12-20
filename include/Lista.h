#include <iostream>

#ifndef LISTA_H
#define LISTA_H

#include "NodoLista.h"

class Lista
{
    public:

        Lista(){cabeza = actual = finall = NULL;}
        ~Lista();
        void insertarNodo(TMaleta m);
        void borrarNodo(TMaleta m);
        bool listaVacia();
        void esCabeza();
        void esFinal();
        void esSiguiente();
        bool esActual();
        TMaleta* valorActual();
        TMaleta* buscarMaleta(cin PNR);
        void recorrerLista();
        int longitudLista();
        void borrarNodoString(cin PNR);

    private:
        NodoLista *cabeza;
        NodoLista *finall;
        NodoLista *actual;

};

#endif
