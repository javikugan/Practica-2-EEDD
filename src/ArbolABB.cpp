#include <iostream>

#include "ArbolABB.h"

using namespace std;



// Insertar un int en el �rbol ABB
void ArbolABB::Insertar(Pasajero p)
{
    NodoArbol* padre = NULL;
    actual = raiz;
    while(!Vacio(actual) && p.PNR != actual->pasajero.PNR){
        padre = actual;
        if(p.PNR > actual->pasajero.PNR) actual = actual->der;
        else if(p.PNR < actual->pasajero.PNR) actual = actual->izq;
    }
    if(!Vacio(actual)) return;
    if(Vacio(padre)) raiz = new NodoArbol(p);
    else if(p.PNR < padre->pasajero.PNR) padre->izq = new NodoArbol(p);
    else if(p.PNR > padre->pasajero.PNR) padre->der = new NodoArbol(p);
}


// Eliminar un elemento de un Arbol ABB
void ArbolABB::Borrar(string PNRPas)
{
   NodoArbol *padre = NULL;
   NodoArbol *nodo;
   string aux;

   actual = raiz;
   // Mientras sea posible que el valor est� en el �rbol
   while(!Vacio(actual)) {
      if(PNRPas == actual->pasajero.PNR) { // Si el valor est� en el nodo actual
         if(EsHoja(actual)) { // Y si adem�s es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->der == actual) padre->der = NULL;
               else if(padre->izq == actual) padre->izq = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor est� en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo m�s izquierdo de rama derecha
            if(actual->der) {
               nodo = actual->der;
               while(nodo->izq) {
                  padre = nodo;
                  nodo = nodo->izq;
               }
            }
            // O buscar nodo m�s derecho de rama izquierda
            else {
               nodo = actual->izq;
               while(nodo->der) {
                  padre = nodo;
                  nodo = nodo->der;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que s�lo se eliminan nodos hoja.
            aux = actual->pasajero.PNR;
            actual->pasajero.PNR = nodo->pasajero.PNR;
            nodo->pasajero.PNR = aux;
            actual = nodo;
         }
      }
      else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
         padre = actual;
         if(PNRPas > actual->pasajero.PNR) actual = actual->der;
         else if(PNRPas < actual->pasajero.PNR) actual = actual->izq;
      }
   }
}

void ArbolABB::PreOrden(NodoArbol* nodo, bool (*callback)(Pasajero, void*), void* args){
    if (nodo != nullptr) {
        if (callback(nodo->pasajero, args))
            return;
        PreOrden(nodo->izq, callback, args);
        PreOrden(nodo->der, callback, args);
    }
}


void ArbolABB::InOrden(NodoArbol* nodo, bool (*callback)(Pasajero, void*), void* args){
    if (nodo != nullptr) {
        InOrden(nodo->izq, callback, args);
        if (callback(nodo->pasajero, args))
            return;
        InOrden(nodo->der, callback, args);
    }
}
// Buscar un valor en el �rbol
Pasajero ArbolABB::Buscar(string PNRPas){
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(PNRPas == actual->pasajero.PNR) return actual->pasajero; // int encontrado
      else if(PNRPas > actual->pasajero.PNR) actual = actual->der; // Seguir
      else if(PNRPas < actual->pasajero.PNR) actual = actual->izq;
   }
    // No est� en �rbol
}


