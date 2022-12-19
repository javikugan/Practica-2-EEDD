#include "Util.h"
#include <cstdlib>
#include <iostream>


using namespace std;

    TMaleta generar_maleta(string pnr, int n){
    TMaleta maleta;
    maleta.PNR = pnr;
    maleta.peso = rand()%20;
    maleta.nbulto = n;
    maleta.tipo = "por definir";
    return maleta;

    }

    Lista* generar_equipaje(string pnr){

        Lista* aux = new Lista();
        for (int i; i < rand()%6; i++){

            aux->insertarNodo(generar_maleta(pnr, i));
        }
        return aux;

    }
/* funci�n para generar de forma  aleatoria los DNI a partir de dos arrays ( el primero de numeros y el segundo de las letras del abecedario en may�sculas).
DNI - formados por 8 cifras - 1 letra al final (MAY�SCULA)
*/
    string Util::dni_aleat(){
        string dni = "";
        char numeros[]= "0123456789";
        char muestra[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


        for (int x = 0; x < 8; x++) {
            dni = dni + numeros[rand()%10]; // genera n�meros aleatorios del 1...10 para las cifras del DNI
            }


        dni = dni + muestra[rand()%26]; // genera letras de forma aleatoria para las letras en MAY�SCULA del DNI. (Alfabeto tiene 26 letras)
        return dni ;

    };

 /* generar aleatoriamente los nombres y apellidos de las personas a las que las corresponde cada maleta
    a partir de un array de strings de nombres y otro  de apellidos.
    47 nombres asociados a 47 apellidos.
    De cada maleta se obtendr� un nombre y dos apellidos asociados.
*/
    string Util::generar_nombres(){
        string nombre= "";


        std::string nombres[] = {"Antonio", "David", "Juan", "Francisco", "Daniel", "Jose", "Manuel", "Teresa", "Celia", "Maria", "Lucia", "Rocio", "Ascen", "Loren", "Alvaro", "Lourdes", "Laura", "Sofia", "Mario", "Javier", "Marco", "Lara", "Luisa", "Sandra", "Adrian", "Luis", "Fernando", "Domingo", "Africa", "Andrea", "Sergio", "Adrian", "Pablo", "Sandra", "Marta", "Valeria", "Paula", "Luna", "Diana", "Noelia", "Marcos", "Ivan", "Jaime", "Diego", "Isabel", "Blanca", "Ana"};
        std::string apellido[] = {"Pascual", "Rodriguez", "Polanco", "Nu�ez", "Gonzalez", "Aldea", "Manso", "Perez", "Cebrecos", "Moglovejo", "Fernandez", "Roma", "Ortiz", "Vi�as", "Vaca", "Jarillo", "Cembell�n", "Alberti", "Martinez", "S�nchez","Saiz","Arribas", "Garcia", "Gomez", "Lopez", "Martin", "Cuesta", "Mogollo", "Simon", "Pe�a", "Velasco", "Jurado", "Loro", "Blanco", "Honrado", "Gil", "de Cos", "Marquez", "Diaz", "Palomino", "Tesifonte", "Luzdivino", "Dombina", "Calleja", "Ruiz", "Oristila", "Bonifacio"};

        nombre = nombre + " " + nombres[rand()%46] + " " +  apellido[rand()%4] + " " + apellido[rand()%46];
        return nombre;

    };
    string Util:: generar_PNR_aleat(){
        string PNR = " ";
        char alfanumerica[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

        for (int x = 0; x < 6; x++) {
            PNR = PNR + alfanumerica [rand()%36]; // genera secuencia alfanumerica para el PNR
            }



        return PNR ;
    };
    Pasajero Util::generar_pasajero(){

        Pasajero pasajero;
        pasajero.dni = dni_aleat();
        pasajero.destino = "Murcia";
        Pasajero.fechavuelo = "25/12/2022"
        pasajero.horasal= "23:30"
        pasajero.idVuelo = "IB3040"
        pasajero.nombrecompl= generar_nombres();
        pasajero.origen= "Madrid";
        pasajero.PNR = generar_PNR_aleat();
    }
void menu_principal();
void menu_inserta();
void menu_modifica();
void menu_borrar_registro();
void menu_pasajero();
void menu_equipaje();
void menu_añadir_bulto();
void menu_borrar_bulto();
void modificar_equipaje();
void menu cambiar_bulto();

int main()
{

    cin.get();
    cin.get();
    return 0;
}
void menu_principal()
{
    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU PRINCIPAL\n";
        //opciones del menú
        cout << "\n\t1.Insertar nuevo registro con un solo bulto en la lista de equipaje\n "
        cout << "\t2.Modificar los campos de un registro, exceptuando el equipaje\n"
        cout << "\t3.Borrar un registro del árbol\n"
        cout << "\t4.Mostrar los datos de un pasajero\n"
        cout << "\t5.Mostrar los datos del equipaje de un pasajero\n"
        cout << "\t6.Añadir un nuevo bulto al equipaje de un pasajero\n"
        cout << "\t7.Borrar algún bulto del equipaje de un pasajero\n"
        cout << "\t8. Modificar los datos del equipaje de un pasajero\n "
        cout << "\t9.Cambiar un bulto del equipaje de un pasajero a otro distinto\n"
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_inserta();
            break;
        case 2:
            menu_modifica();
            break;
        case 3:
            menu_borrar_registro();
            break;
        case 4:
            menu_pasajero();
            break;
        case 5:
            menu_equipaje();
            break;
        case 6:
            menu_añadir_bulto();
            break;
        case 7:
            menu_borrar_bulto();
            break;
        case 8:
            menu_modificar_equipaje();
            break;
        case 9:
            menu_cambiar_bulto();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void menu_inserta()
{
    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU INSERTA\n";
        //opciones del menú
        cout << "\n\t1.Insertar nuevo registro con un solo bulto en la lista de equipaje\n "
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_inserta();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void menu_modifica()
{
    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU MODIFICA\n";
        //opciones del menú
        cout << "\n\t1.Modificar los campos de un registro, exceptuando el equipaje\n "
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_modifica();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void menu_borrar_registro()
{
    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\tMENU BORRAR REGISTRO\n";
        //opciones del menú
        cout << "\n\t1.Borrar un registro del árbol\n "
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_borrar_registro();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void menu_pasajero()
{

    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\ MENU PASAJERO\n";
        //opciones del menú
        cout << "\n\tMostrar los datos del equipaje de un pasajero"
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_pasajero();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void menu_equipaje()
{

    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\tMENU EQUIPAJE\n";
        //opciones del menú
        cout << "\n\t1.Añadir un nuevo bulto al equipaje de un pasajeroe\n "
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_equipaje();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void menu_añadir_bulto()
{
    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\tMENU AÑADIR\n";
        //opciones del menú
        cout << "\n\t1.Añadir un nuevo bulto al equipaje de un pasajeroe\n "
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_añadir_bulto();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void menu_borrar_bulto()
{
    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\tMENU BORRAR BULTO\n";
        //opciones del menú
        cout << "\n\tBorrar algún bulto del equipaje de un pasajero\n "
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_borrar_bulto();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void modificar_equipaje()
{
    bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\tMENU MODIFICAR DATOS DE EQUIPAJE\n";
        //opciones del menú
        cout << "\n\tModificar los datos del equipaje de un pasajer\n "
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_modificar_equipaje();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}
void menu_cambiar_bulto()
{
     bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\tMENU CAMBIAR BULTO DE EQUIPAJE DE UN PASAJERO\n";
        //opciones del menú
        cout << "\n\t Cambiar un bulto del equipaje de un pasajero a otro distinto\n "
        cout << "\t0.Salir\n"

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_cambiar_bulto();
            break;
        case 0:
            repeticion = false //cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }




    } while(repeticion)
}

















