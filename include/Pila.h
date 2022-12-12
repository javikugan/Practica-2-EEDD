#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "Nodo.h"
#include "Utiles.h"
/* clase Pila
    definitud de métodos (apilar, desapilar, length, imprimir_pila, esVacia)


 */
class Pila
{
    public:
        Pila(): cima(NULL){};
        virtual ~Pila();
        void apilar(TMaleta m);
        TMaleta desapilar();
        int length();
        void imprimir_pila();
        bool esVacia();
        void vacia();



    private:
        pNodo cima; // puntero a nodo de la pila

};

#endif
