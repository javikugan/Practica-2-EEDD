#ifndef BODEGA
#define BODEGA
#include "Pila.h"
#include "Cola.h"
#include <stdio.h>
#include <conio.h>
/* clase BodegaAvion formada por tres contenedores (tres pilas) y por una cola en la que se almacenan las maletas que no entran
    se usa un contador para determinar cuando un contenedor esta lleno
*/
class BodegaAvion{
    private:
    Pila* contenedor1;
    Pila* contenedor2;
    Pila* contenedor3;
    Cola* noentran;
    int contador;

    public:
        BodegaAvion();
        ~BodegaAvion();
        void Abordar(Cola* cinta, int Maximo, int grupo);
        void imprimirBodega();


};
#endif // BODEGA
