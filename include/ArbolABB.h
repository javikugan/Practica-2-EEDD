#include <iostream>
using namespace std;

class ArbolABB {
  private:
   //// Clase local de Lista para Nodo de ArbolBinario:
   class Nodo {
     public:
      // Constructor:
      Nodo(Pasajero dat, Nodo *izq=NULL, Nodo *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
      // Miembros:
      int dato;
      Nodo *izquierdo;
      Nodo *derecho;
   };

   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;

  public:

   // Constructor y destructor b�sicos:
   ArbolABB() : raiz(NULL), actual(NULL) {}
   ~ArbolABB() { Podar(raiz); }

   // Insertar en �rbol ordenado:
   void Insertar(TMaleta dat);

   // Borrar un elemento del �rbol:
   void Borrar(TMaleta dat);

   // Funci�n de b�squeda:
   bool Buscar(TMaleta dat);

   // Comprobar si el �rbol est� vac�o:
   bool Vacio(Nodo *r) { return r==NULL; }

   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }

   // Contar n�mero de nodos:
   const int NumeroNodos();
   const int AlturaArbol();

   // Calcular altura de un int:
   int Altura(TMaleta dat);
,
   // Devolver referencia al int del nodo actual:
   TMaleta &ValorActual() { return actual->dato; }

   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }

   // Aplicar una funci�n a cada elemento del �rbol:
   void InOrden(void (*func)(TMaleta&) , Nodo *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(TMaleta&) , Nodo *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(TMaleta&) , Nodo *nodo=NULL, bool r=true);


  private:
   // Funciones auxiliares
   void Podar(Nodo* &);
   void auxContador(Nodo*);
   void auxAltura(Nodo*, TMaleta);
};
