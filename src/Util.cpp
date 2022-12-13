#include "Util.h"

using namespace std;

    TMaleta generar_maleta(string pnr, int n){

    TMaleta maleta;
    maleta.PNR = pnr;
    maleta.peso = rand()%20;
    maleta.nbulto = n;
    maleta.tipo = "por definir";

    }

    Lista generar_equipaje(string pnr){

        Lista aux = new Lista();
        for (int i; i < rand()%6; i++){

        }

    }
