#ifndef NODO_H
#define NODO_H
#include <iostream>
#include "Nodo.h"
#include "TMaleta.h"
/* clase Nodo

*/
class Nodo{
    public:
        Nodo();
        virtual ~Nodo();
        Nodo(TMaleta m, Nodo *sig = nullptr){
        maleta = m; // valor --elemento maleta--
        siguiente = sig; // puntero a nodo
        };


    private:
        TMaleta maleta;
        Nodo *siguiente; // puntero siguiente
        friend class Pila;
        friend class Cola;

};
typedef Nodo *pNodo; // puntero aux para manipular el nodo

#endif //NODO_H
