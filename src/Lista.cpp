#include "Lista.h"



Lista::~Lista(){
    pnodo aux;
    while(cabeza){
        aux = cabeza;
        cabeza = cabeza->siguiente;
        delete aux;
    }
    actual = NULL;
    }

void Lista::insertarNodo(TMaleta m) {
    pnodo aux;
    if (listaVacia()){

        cabeza = new NodoLista(m, NULL);
        finall=cabeza;

    }else{

        aux= new NodoLista(m,NULL);
        finall->siguiente=aux;
        finall=aux;
    }
}
void Lista::borrarNodo(TMaleta m) {
    pnodo anterior;
    actual = cabeza;
    while (actual->maleta.PNR!=m.PNR && (actual->siguiente)!=NULL){
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==cabeza) cabeza = actual->siguiente;

    else{

        anterior->siguiente = actual->siguiente;
        if(actual==finall) finall=anterior;

    }
    actual->siguiente=NULL;
    delete actual;
    }


bool Lista::listaVacia(){

    return cabeza == NULL;
}
void Lista::esCabeza(){

    actual = cabeza;
}
void Lista::esFinal(){

    esCabeza();
    if(!listaVacia()) // M�s sencillo
        while(actual->siguiente) // actual = final;
            esSiguiente();
}

void Lista::esSiguiente(){
    if(actual) actual = actual->siguiente;
}

bool Lista::esActual(){
    return actual != NULL;
}

TMaleta Lista::valorActual(){

    return actual->maleta;
}

void Lista::recorrerLista(){
    pnodo aux;
    aux = cabeza;
    while(aux){
        cout << "\n \tPNR Maleta: ";
        cout << aux->maleta.PNR;
        cout << "\n \tnumero de bulto: ";
        cout << aux->maleta.nbulto;
        cout << "\n \tPeso: ";
        cout << aux->maleta.peso;
        cout << "\n \tPeso: ";
        cout << aux->maleta.tipo;
        cout << "\n";

        aux = aux->siguiente;
    }
    cout << endl;

}
int Lista::longitudLista(){
    pnodo aux;
    aux = cabeza;
    int cont = 0;
    while(aux){
    cont +=1;
    aux = aux->siguiente;

    }
    cout << endl;

}
