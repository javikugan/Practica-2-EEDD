#ifndef TMALETA
#define TMALETA
#include <iostream>
#include <string.h>
/*
    Forma de agrupar un conjunto de datos de distinto tipo como
    una variable.
    atributos de TMaleta: id, dni, destino, origen, localizador, nombre, hora, sospechosa*/
struct TMaleta{
    std::string id;
    std::string dni;
    std::string destino;
    std::string origen;
    std::string localizador;
    std::string nombre;
    std::string hora;
    bool sospechosa;
};
#endif
