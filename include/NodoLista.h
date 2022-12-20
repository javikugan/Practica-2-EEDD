#include <iostream>
#ifndef NODOLISTA
#define NODOLISTA

#include <TMaleta.h>



class NodoLista
{
    public:
        NodoLista(TMaleta m, NodoLista *sig = NULL)
            {
            maleta = m;
            siguiente = sig;
            }

        virtual ~NodoLista();

    protected:

    private:
        TMaleta maleta;
        NodoLista *siguiente;
        friend class Lista;
};

typedef NodoLista *pnodo;


#endif //
