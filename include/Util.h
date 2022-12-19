#ifndef UTIL
#define UTIL

#include <iostream>
#include <Pasajero.h>
#include <TMaleta.h>
#include <Lista.h>

using namespace std;

namespace Util{

    void imprimirMaleta(TMaleta maleta);
    string dni_aleat();
    TMaleta generar_maleta();
    string generar_PNR_aleat();
    string generar_nombres();
    string generar_hora_salida();
    string generar_destino();

}
#endif
