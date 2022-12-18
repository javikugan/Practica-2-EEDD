#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include "TMaleta.h"
#include "Lista.h"

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
