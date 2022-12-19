#ifndef UTIL
#define UTIL

#include <iostream>
#include <Pasajero.h>
#include <TMaleta.h>
#include <Lista.h>
#include <ArbolABB.h>

using namespace std;

namespace Util{

    void imprimirMaleta(TMaleta maleta);
    string dni_aleat();
    TMaleta generar_maleta(string pnr, int n);
    string generar_PNR_aleat();
    string generar_nombres();
    string generar_hora_salida();
    string generar_destino();
    Pasajero generar_pasajero();
    void menu_principal(ArbolABB* pasajeros);
    void menu_anadir_Pasajero(ArbolABB* pasajeros);
    void menu_borrar(ArbolABB* pasajeros);
    void menu_modificar(ArbolABB* pasajeros);
    void menu_mostrar_pasajero(ArbolABB* pasajeros);
    void menu_mostrar_equipaje(ArbolABB* pasajeros);
    void menu_borrar_equipaje(ArbolABB* pasajeros);
    void menu_modifica_equipaje(ArbolABB* pasajeros);
    void menu_mover_equipaje(ArbolABB* pasajeros);
    void leerPasajero(Pasajero p);
    void leerEquipaje(Pasajero p);
}

#endif
