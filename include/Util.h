#ifndef UTIL
#define UTIL

#include <iostream>
#include <Pasajero.h>
#include <TMaleta.h>
#include <Lista.h>
#include <ArbolABB.h>
#include <array>
#include "Asiento.h"
using namespace std;

namespace Util{

    void imprimirMaleta(TMaleta maleta);
    string dni_aleat();
    TMaleta generar_maleta(string pnr, int n);
    string generar_PNR_aleat();
    string generar_nombres();
    string generar_hora_salida();
    string generar_destino();
    array<Asiento,150> generarAsiento();
    void imprimirAsiento(array<Asiento,150> asiento){
    Pasajero generar_pasajero();
    void menu_principal();
    void menu_anadir_Pasajero();

}

#endif
