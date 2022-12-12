#include <iostream>
#include "BodegaAvion.h"
using namespace std;
BodegaAvion::BodegaAvion(){
//constructor
contenedor1 = new Pila();
contenedor1->vacia();
contenedor2 = new Pila();
contenedor2->vacia();
contenedor3 = new Pila();
contenedor3->vacia();
noentran = new Cola();

int contador = 0;


};

BodegaAvion::~BodegaAvion(){
//destructor
};
/*función a la que le pasamos un puntero a una cola que apunta a la cinta transportadora del vuelo,
con un máximo de maletas por contenedor y una cantidad de maletas (por vuelo)
 */
void BodegaAvion::Abordar(Cola* cinta, int maximo, int grupo){
    while ((!cinta->es_vacia())and(contador< grupo*3)){ //mientras la pila no esté vacía y el avión esté lleno


            cout<< "Presiona Una Tecla Para Abordar las Maletas" << endl;
            getch();
            contenedor1->imprimir_pila();
            for (int i = 0; i < grupo; i++){
                if  (!(cinta->es_vacia()))
                {
                TMaleta maleta = cinta->desencolar();
                if (contador < grupo*1){ //contador es menor o igual que el máximo de maletas de un contenedor
                    contenedor1->apilar(maleta);
                    //cout<<"apilo en contenedor1"<<maleta.dni<<endl;
                    //cout<<"imprimo pila "<<endl;
                    //contenedor1->imprimir_pila();
                    contador = contador + 1;
                }
                else if (contador < grupo*2){ //es mayor que un contenedor, menor que 2 contenedores (mayor que 15 maletas y menor que 30)
                    contenedor2->apilar(maleta);
                    //cout<<"apilo en contenedor2"<<maleta.dni<<endl;
                    contador = contador + 1;

                }
                else if ((contador < grupo *3)){ // contador mayor que 2 contenedores(total de 30 maletas), menor que 3 contenedores (45 maletas)
                    contenedor3->apilar(maleta);
                    //cout<<"apilo en contenedor3"<<maleta.dni<<endl;
                    contador = contador + 1;
                }else{   // maletas que no entran en la estructura cola
                    cout<< "la Maleta no Entra"<<endl;
                    noentran->encolar(maleta);
                }
                }
            }
    }

}
void BodegaAvion::imprimirBodega(){ // imprime la bodega del avión, contiene los 3 contenedores y las maletas que no entran en la estructura cola
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                      CONTENEDOR 1                                                     |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    contenedor1->imprimir_pila();
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                      CONTENEDOR 2                                                     |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    contenedor2->imprimir_pila();
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                      CONTENEDOR 3                                                     |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    contenedor3->imprimir_pila();
    //noentran->imprimir_cola();
}
