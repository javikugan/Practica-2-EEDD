#include <Util.h>
#include <cstdlib>
#include <iostream>
using namespace std;

    TMaleta Util::generar_maleta(string pnr, int n){
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

            aux->insertarNodo(Util::generar_maleta(pnr, i));
        }
        return aux;

    }




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


        string nombres[] = {"Antonio", "David", "Juan", "Francisco", "Daniel", "Jose", "Manuel", "Teresa", "Celia", "Maria", "Lucia", "Rocio", "Ascen", "Loren", "Alvaro", "Lourdes", "Laura", "Sofia", "Mario", "Javier", "Marco", "Lara", "Luisa", "Sandra", "Adrian", "Luis", "Fernando", "Domingo", "Africa", "Andrea", "Sergio", "Adrian", "Pablo", "Sandra", "Marta", "Valeria", "Paula", "Luna", "Diana", "Noelia", "Marcos", "Ivan", "Jaime", "Diego", "Isabel", "Blanca", "Ana"};
        string apellido[] = {"Pascual", "Rodriguez", "Polanco", "Nu�ez", "Gonzalez", "Aldea", "Manso", "Perez", "Cebrecos", "Moglovejo", "Fernandez", "Roma", "Ortiz", "Vi�as", "Vaca", "Jarillo", "Cembell�n", "Alberti", "Martinez", "S�nchez","Saiz","Arribas", "Garcia", "Gomez", "Lopez", "Martin", "Cuesta", "Mogollo", "Simon", "Pe�a", "Velasco", "Jurado", "Loro", "Blanco", "Honrado", "Gil", "de Cos", "Marquez", "Diaz", "Palomino", "Tesifonte", "Luzdivino", "Dombina", "Calleja", "Ruiz", "Oristila", "Bonifacio"};

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
        pasajero.PNR = generar_PNR_aleat();
        pasajero.nombrecompl= generar_nombres();
        pasajero.dni = dni_aleat();
        pasajero.idVuelo = "IB3040";
        pasajero.origen= "Madrid";
        pasajero.destino = "Murcia";
        pasajero.fechavuelo = "25/12/2022";
        pasajero.horasal= "23:30";
        pasajero.equipaje = generar_equipaje(pasajero.PNR);
        return pasajero;
    }





void Util::menu_principal(ArbolABB* pasajeros){
     bool repeticion = true;
    int opcion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU PRINCIPAL\n";
        //opciones del menú
        cout << "\n\t1.Insertar nuevo registro con un solo bulto en la lista de equipaje\n ";
        cout << "\t2.Modificar los campos de un registro, exceptuando el equipaje\n";
        cout << "\t3.Borrar un registro del árbol\n";
        cout << "\t4.Mostrar los datos de un pasajero\n";
        cout << "\t5.Mostrar los datos del equipaje de un pasajero\n";
        cout << "\t6.Añadir un nuevo bulto al equipaje de un pasajero\n";
        cout << "\t7.Borrar algún bulto del equipaje de un pasajero\n";
        cout << "\t8. Modificar los datos del equipaje de un pasajero\n ";
        cout << "\t9.Cambiar un bulto del equipaje de un pasajero a otro distinto\n";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            menu_anadir_Pasajero(pasajeros);
            break;
        case 2:
            menu_modificar(pasajeros);
            break;
        case 3:
            menu_borrar(pasajeros);
            break;
        case 4:
            menu_mostrar_pasajero(pasajeros);
            break;
        case 5:
            menu_mostrar_equipaje(pasajeros);
            break;
        case 6:
            menu_anadir_equipaje(pasajeros);
            break;
        case 7:
            menu_borrar_equipaje(pasajeros);
            break;
        case 8:
            menu_modifica_equipaje(pasajeros);
            break;
        case 9:
            menu_mover_equipaje(pasajeros);
            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    } while(repeticion);
}

void Util::menu_anadir_Pasajero(ArbolABB* pasajeros){
    bool repeticion = true;
    int opcion;
    string dniinp;
    string nombreimp;
    string asiento;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU INSERTA\n";
        //opciones del menú
        cout << "\n\t1.Insertar nuevo registro con un solo bulto en la lista de equipaje\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tNombre y Apellidos: ";
            cin >> nombreimp;
            cout << "\n \tDNI: ";
            cin >> dniinp;
            cout << "\n \tNumero de Asiento: ";
            cin >> opcion;
            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);

}

void Util::menu_modificar(ArbolABB* pasajeros){

    bool repeticion = true;
    int opcion;
    Pasajero paux;
    string PNRimp;
    string dniinp;
    string nombreimp;
    string asiento;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU INSERTA\n";
        //opciones del menú
        cout << "\n\t1.Modificar un Pasajero\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tPNR del Pasajero: ";
            cin >> PNRimp;
            paux = pasajeros->Buscar(PNRimp);
            cout << "\n \t(Si no desea Modificar un Campo dejelo en blanco)";
            cout << "\n \tDNI Nuevo: ";
            cin >> dniinp;
            if (dniinp != ""){
            paux.dni = dniinp;
            }
            cout << "\n \tNombre y Apellidos nuevos";
            cin >> nombreimp;
            cout << "\n \tElige el Asiento";
            cin >> asiento;
            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);

}


void Util::menu_borrar(ArbolABB* pasajeros){

    bool repeticion = true;
    int opcion;
    string PNRimp;
    string eleccion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU BORRAR\n";
        //opciones del menú
        cout << "\n\t1.Borrar un Pasajero\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tPNR del pasajero: ";
            cin >> PNRimp;
            cout << "\n \tESTAS SEGURO? y/n: ";
            cin >> eleccion;
            if (eleccion == "y"){
             pasajeros->Borrar(PNRimp);
            }

            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);

}
void Util::menu_mostrar_pasajero(ArbolABB* pasajeros){

    bool repeticion = true;
    int opcion;
    string PNRimp;
    string eleccion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU MOSTRAR EQUIPAJE\n";
        //opciones del menú
        cout << "\n\t1.Borrar un Pasajero\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tPNR del pasajero: ";
            cin >> PNRimp;
            Util::leerPasajero(pasajeros->Buscar(PNRimp));
            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);
}

void Util::menu_mostrar_equipaje(ArbolABB* pasajeros){
    bool repeticion = true;
    int opcion;
    string PNRimp;
    string eleccion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU MOSTRAR EQUIPAJE\n";
        //opciones del menú
        cout << "\n\t1.Mostrar equipaje\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tPNR del pasajero: ";
            cin >> PNRimp;


            break;
        case 0:
            repeticion = false;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);
}
void Util::menu_borrar_equipaje(ArbolABB* pasajeros){
    bool repeticion = true;
    int opcion;
    string PNRimp;
    string eleccion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU MOSTRAR\n";
        //opciones del menú
        cout << "\n\t1.Borrar un Pasajero\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tPNR del pasajero: ";
            cin >> PNRimp;
            cout << "\n \tESTAS SEGURO? y/n: ";
            cin >> eleccion;
            if (eleccion == "y"){
             pasajeros->Borrar(PNRimp);
            }

            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);
}
void Util::menu_modifica_equipaje(ArbolABB* pasajeros){
    bool repeticion = true;
    int opcion;
    string PNRimp;
    string eleccion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU MOSTRAR\n";
        //opciones del menú
        cout << "\n\t1.Borrar un Pasajero\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tPNR del pasajero: ";
            cin >> PNRimp;
            cout << "\n \tESTAS SEGURO? y/n: ";
            cin >> eleccion;
            if (eleccion == "y"){
             pasajeros->Borrar(PNRimp);
            }

            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);
}
void Util::menu_mover_equipaje(ArbolABB* pasajeros){
    bool repeticion = true;
    int opcion;
    string PNRimp;
    string eleccion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU MOSTRAR\n";
        //opciones del menú
        cout << "\n\t1.Borrar un Pasajero\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tPNR del pasajero: ";
            cin >> PNRimp;
            cout << "\n \tESTAS SEGURO? y/n: ";
            cin >> eleccion;
            if (eleccion == "y"){
             pasajeros->Borrar(PNRimp);
            }

            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);
}

void Util::leerPasajero(Pasajero p){
    cout << "\n \tPNR del pasajero: ";
    cout << p.PNR;
    cout << "\n \tNombre del pasajero: ";
    cout << p.nombrecompl;
    cout << "\n \tDNI del pasajero: ";
    cout << p.dni;
    cout << "\n \tID de Vuelo del pasajero: ";
    cout << p.idVuelo;
    cout << "\n \torigen del pasajero: ";
    cout << p.origen;
    cout << "\n \tdestino del pasajero: ";
    cout << p.destino;
    cout << "\n \tAsiento del pasajero: ";
    cout << p.nasiento;

}
void Util::leerEquipaje(Pasajero p){
    p.equipaje->recorrerLista();
}

void Util::menu_anadir_equipaje(ArbolABB* pasajeros){
    TMaleta aux;
    Pasajero paux;
    bool repeticion = true;
    int opcion;
    string PNRimp;
    string eleccion;

    do {
        //limpiar la pantalla
        system("cls");

        //titulo del menu
        cout << "\n\t\t\tMENU ANADIR\n";
        //opciones del menú
        cout << "\n\t1.Añadir un Bulto\n ";
        cout << "\t0.Salir\n";

        //leer opcion elegida por el usuario
        cout << "\n \tOpcion: ";
        cin >> opcion;
        //Alternativas
        switch (opcion) {
        case 1:
            cout << "\n \tPNR del pasajero: ";
            cin >> PNRimp;
            paux = pasajeros->Buscar(PNRimp);
            aux.tipo = "Por definir";
            aux.PNR = paux.PNR;
            aux.peso = 15;
            aux.nbulto = paux.equipaje->longitudLista() + 1;
            paux.equipaje->insertarNodo(aux);


            break;
        case 0:
            repeticion = false ;//cuando se quiera salir, la variable que controla el bucle do while (repeticion) pasará a false
            break;
        }
    }while(repeticion);

}

