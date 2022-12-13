#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <TMaleta.h>

using namespace iostream

namespace Util{

    void imprimirMaleta(TMaleta maleta);
    string dni_aleat();
    string generar_destino();
    string generar_hora_salida();
    string generar_localizador();
    string generar_nombres();
    TMaleta generar_maleta();
}
#endif
