#ifndef PASAJERO
#define PASAJERO
#include "Lista.h"

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
    string locequip;
    Lista equipaje;
};

#endif // PASAJERO