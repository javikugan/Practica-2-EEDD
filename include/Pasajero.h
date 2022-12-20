#include <iostream>
#include "Lista.h"

#ifndef PASAJERO
#define PASAJERO


using namespace std;

struct Pasajero{

    string PNR;
    string nombrecompl;
    string dni;
    string idVuelo;
    string origen;
    string destino;
    string fechavuelo;
    string horasal;
    string nasiento;
    Lista* equipaje;

};

#endif // PASAJERO
