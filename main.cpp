#include <iostream>
#include "ArbolABB.h"
#include "Util.h"
int main() {
    std::cout << "Hello World!";
    ArbolABB* Avion = new ArbolABB();
    Util::menu_principal();
    Avion->Insertar(Util::generar_pasajero());

    return 0;
}
void printMenu();
