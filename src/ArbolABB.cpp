#include <iostream>

#include "ArbolABB.h"

using namespace std;



// Insertar un int en el �rbol ABB
void ArbolABB::Insertar(Pasajero* p)
{
    NodoArbol* padre = NULL;
    actual = raiz;
    while(!Vacio(actual) && p->PNR != actual->pasajero->PNR){
        padre = actual;
        if(p->PNR > actual->pasajero->PNR) actual = actual->der;
        else if(p->PNR < actual->pasajero->PNR) actual = actual->izq;
    }
    if(!Vacio(actual)) return;
    if(Vacio(padre)) raiz = new NodoArbol(p);
    else if(p->PNR < padre->pasajero->PNR) padre->izq = new NodoArbol(p);
    else if(p->PNR > padre->pasajero->PNR) padre->der = new NodoArbol(p);
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
      if(PNRPas == actual->pasajero->PNR) { // Si el valor est� en el nodo actual
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
            aux = actual->pasajero->PNR;
            actual->pasajero->PNR = nodo->pasajero->PNR;
            nodo->pasajero->PNR = aux;
            actual = nodo;
         }
      }
      else { // Todav�a no hemos encontrado el valor, seguir busc�ndolo
         padre = actual;
         if(PNRPas > actual->pasajero->PNR) actual = actual->der;
         else if(PNRPas < actual->pasajero->PNR) actual = actual->izq;
      }
   }
}

void ArbolABB::PreOrden(NodoArbol* nodo, bool (*callback)(Pasajero*, void*), void* args){
    if (nodo != nullptr) {
        if (callback(nodo->pasajero, args))
            return;
        PreOrden (nodo->izq, callback, args);
        PreOrden (nodo->der, callback, args);
    }
}

void ArbolABB::PostOrden(NodoArbol* nodo, bool (*callback)(CentralPaqueteria*, void*), void* args){
    if (nodo != nullptr) {
        PostOrden (nodo->izq, callback, args);
        PostOrden (nodo->der, callback, args);
        if (callback(nodo->pasajero, args))
            return;
    }
}

void ArbolABB::InOrden(NodoArbol* nodo, bool (*callback)(Pasajero*, void*), void* args){
    if (nodo != nullptr) {
        InOrden(nodo->izq, callback, args);
        if (callback(nodo->pasajero, args))
            return;
        InOrden(nodo->der, callback, args);
    }
}
// Buscar un valor en el �rbol
bool ArbolABB::Buscar(string PNRPas)
{
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(PNRPas == actual->pasajero->PNR) return true; // int encontrado
      else if(PNRPas > actual->pasajero->PNR) actual = actual->der; // Seguir
      else if(PNRPas < actual->pasajero->PNR) actual = actual->izq;
   }
   return false; // No est� en �rbol
}

// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(string PNRPas)
{
   int altura = 0;
   actual = raiz;

   // Todav�a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(PNRPas == actual->pasajero->PNR) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(PNRPas > actual->pasajero->PNR) actual = actual->der;
         else if(PNRPas < actual->pasajero->PNR) actual = actual->izq;
      }
   }
   return -1; // No est� en �rbol
}

// Contar el n�mero de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnci�n auxiliar
   return contador;
}

// Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(NodoArbol *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izq) auxContador(nodo->izq);
   if(nodo->der)   auxContador(nodo->der);
}

// Calcular la altura del �rbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Funci�n auxiliar
   return altura;
}

// Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
// postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
// altura de la m�xima actual

