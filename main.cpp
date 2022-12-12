#include <iostream>
#include <random>
#include <time.h>
#include "Utiles.h"
#include "BodegaAvion.h"
#define N1 100
#define N2 15
#define N3 10

using namespace std;


int main(){
    srand(time(NULL));
    Cola* cola_inicial = new Cola();
    Cola* cola_sospechosas = new Cola();
    Cola* cola_IB3412 = new Cola();
    Cola* cola_AC4832 = new Cola();
    Cola* cola_RY2781 = new Cola();
    Cola* cola_MS1032 = new Cola();


    BodegaAvion* BodegaAlem = new BodegaAvion();
    BodegaAvion* BodegaArg = new BodegaAvion();
    BodegaAvion* BodegaIsl = new BodegaAvion();
    BodegaAvion* BodegaAlba = new BodegaAvion();
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                               CINTA TRANSPORTADORA GENERAL                                            |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N1; i++){

        TMaleta maleta = Util::generar_maleta();
        cola_inicial->encolar(maleta);
        Util::imprimirMaleta(maleta);
    }
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    for(int i = 0; i<N1; i++){

        TMaleta revisada = cola_inicial->desencolar();
        if(revisada.sospechosa){cola_sospechosas->encolar(revisada);}
        else{
                if(revisada.id == "IB3412"){
                    cola_IB3412->encolar(revisada);
                }
                if(revisada.id == "AC4832"){
                    cola_AC4832->encolar(revisada);
                }
                if(revisada.id == "RY2781"){
                    cola_RY2781->encolar(revisada);
                }
                if(revisada.id == "MS1032"){
                    cola_MS1032->encolar(revisada);
                }
            }
        }

    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                                   MALETAS SOSPECHOSAS                                                 |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cola_sospechosas->imprimir_cola();
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                               CINTA TRANSPORTADORA IB3412                                             |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cola_IB3412->imprimir_cola();
    BodegaArg->Abordar(cola_IB3412,N1,N2);
    //BodegaArg->imprimirBodega();
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                               CINTA TRANSPORTADORA AC4832                                             |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cola_AC4832->imprimir_cola();
    BodegaAlem->Abordar(cola_AC4832,N1,N2);
    //BodegaAlem->imprimirBodega();
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                               CINTA TRANSPORTADORA RY2781                                             |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cola_RY2781->imprimir_cola();
    BodegaIsl->Abordar(cola_RY2781,N1,N2);
    //BodegaIsl->imprimirBodega();
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                               CINTA TRANSPORTADORA MS1032                                             |" << endl;
    cout << " -----------------------------------------------------------------------------------------------------------------------" << endl;
    cola_MS1032->imprimir_cola();
    BodegaAlba->Abordar(cola_MS1032,N1,N2);
    //BodegaAlba->imprimirBodega();


    return 0;
}
