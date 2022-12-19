#include <iostream>
#include "TMaleta.h"
#include "Pasajero.h"
#ifndef ARBOL
#define ARBOL

using namespace std;
class NodoArbol {
    private:
        Pasajero pasajero;
        NodoArbol* izq;
        NodoArbol* der;
        friend class ArbolABB;
    public:
        NodoArbol(Pasajero pas, NodoArbol* izquierdo = nullptr, NodoArbol* derecho = nullptr) {
            pasajero = pas;
            izq = izquierdo;
            der = derecho;
        }
};


class ArbolABB {

  private:
   // Punteros de la lista, para cabeza y nodo actual:
   NodoArbol *raiz;
   NodoArbol *actual;
   int contador;
   int altura;

  public:

   // Constructor y destructor b�sicos:
   ArbolABB() : raiz(NULL), actual(NULL) {}
   ~ArbolABB() { Podar(raiz); }

   // Insertar en �rbol ordenado:
   void Insertar(Pasajero p);

   // Borrar un elemento del �rbol:
   void Borrar(string PNRPas);

   // Funci�n de b�squeda:
   Pasajero Buscar(string PNRPas);

   // Comprobar si el �rbol est� vac�o:
   bool Vacio(NodoArbol *r) { return r==NULL; }

   // Comprobar si es un nodo hoja:
   bool EsHoja(NodoArbol *r) { return !r->der && !r->izq; }

   // Contar n�mero de nodos:
   const int NumeroNodos();
   const int AlturaArbol();

   // Calcular altura de un int:
   int Altura(Pasajero dat);


   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }

   // Aplicar una funci�n a cada elemento del �rbol:
    void PreOrden (NodoArbol* nodo, bool (*callback)(Pasajero, void*), void* args);
    void InOrden(NodoArbol* nodo, bool (*callback)(Pasajero, void*), void* args);


  private:
   // Funciones auxiliares
   void Podar(NodoArbol* &);

};

#endif // Arbol
