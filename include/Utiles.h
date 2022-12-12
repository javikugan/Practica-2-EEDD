#ifndef UTILES
#define UTILES
#include <iostream>
#include <Cola.h>
#include <TMaleta.h>
/* namespace Util
    contenedor de todas las funciones asociadas, bloque al cual hemos asignado como nombre Util para identificarlo
    contiene todas las funciones sobre la generación de las maletas (dni_aleat, generar_destino, generar_hora_salida,
    generar_localizador, Id_vuelo_aleatorio, generar_nombres, revisar_maleta)

*/

namespace Util{

    void imprimirMaleta(TMaleta maleta);
    std::string dni_aleat();
    std::string generar_destino();
    std::string generar_hora_salida();
    std::string generar_localizador();
    std::string Id_Vuelo_aleatorio(std::string destino);
    std::string generar_nombres();
    bool revisar_maleta();
    TMaleta generar_maleta();
}
#endif //UTILES
