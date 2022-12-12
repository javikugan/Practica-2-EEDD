#ifndef COLA_H
#define COLA_H
#include <iostream>
#include "Nodo.h"
/*
    clase Cola
    definitud de los métodos utilizados en la clase Cola (encolar, desencolar, length, imprimir_cola, es_vacia)
*/
class Cola{
    public:
    Cola() : principio(NULL), final(NULL){}; // punteros principio y final la cola
    ~Cola();
    void encolar(TMaleta m);
    TMaleta desencolar();
    int length();
    void imprimir_cola();
    bool es_vacia();

private:
    pNodo principio, final;

};

#endif // COLA_H
