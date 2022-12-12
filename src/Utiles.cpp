#include "Utiles.h"

using namespace std;

/* funci�n que genera aleatoriamente los DNI a partir de dos arrays. Array de numeros y otro de letras en may�sculas. Los DNI est�n formados por 8 cifras y una letra al final (MAY�SCULA)
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
/* funci�n que genera los destinos del vuelo del avi�n de forma aleatoria con la funci�n rand()
   a partir de un array con cuatro pa�ses */
    string Util::generar_destino(){ //
        string muestra[]= {"ARGENTINA","ALEMANIA ", "ISLANDIA ", "ALBANIA  "};
        int destino_n = rand()%4;
        string destino = muestra[destino_n];
        return destino;

    };
/*
   genera de forma aleatoria con la funci�n rand() un destino de los cuatro indicados en el array a partir de un array con
   los 4 d�gitos (dicho formato contiene horas y minutos)
*/
    string Util::generar_hora_salida(){
        string muestra[]= {"2147", "2354", "1234","1530"};
        string hora_salida = muestra[rand()%4];
        return hora_salida;

/* genera de forma aleatoria el localizador de la maleta a partir de un array de 10 n�meros con los n�meros del 0 al 9.
   el localizador ha de ser de 4 cifras
*/
    };
    std::string Util::generar_localizador(){
        char numeros[]= "0123456789";
        string localizador = "";

        for (int x=0; x < 4; x++){

            localizador = localizador + numeros[rand()%10];
        }
        return localizador;
    };
/* genera de forma aleatoria los vuelos. Compara los destinos de cada vuelo con el identificador de cada vuelo para obtener
   el idVuelo (identificador del vuelo)
*/
    string Util::Id_Vuelo_aleatorio(string destino) {
        string idVuelo;
        if(destino == "ALEMANIA "){idVuelo = "AC4832";}
        else if(destino == "ARGENTINA"){idVuelo = "IB3412";}
        else if(destino == "ISLANDIA "){idVuelo = "RY2781";}
        else if(destino == "ALBANIA  "){idVuelo = "MS1032";}
        return idVuelo;
    };
/* genera de forma aleatoria los nombres de las personas a las que las corresponde cada maleta a partir de un array de strings de
    nombres y otro array de strings de apellidos.
    hemos introducido 45 nombres asociados a 45 apellidos. De cada maleta se obtendr� un nombre y dos apellidos asociados.
*/
    string Util::generar_nombres(){
        string nombre= "";


        std::string nombres[] = {"Antonio", "David", "Juan", "Francisco", "Daniel", "Jose", "Manuel", "Teresa", "Celia", "Maria", "Lucia", "Rocio", "Ascen", "Loren", "Alvaro", "Lourdes", "Laura", "Sofia", "Mario", "Javier", "Marco", "Lara", "Luisa", "Luis", "Fernando", "Domingo", "Africa", "Andrea", "Sergio", "Adrian", "Pablo", "Sandra", "Marta", "Valeria", "Paula", "Luna", "Diana", "Noelia", "Marcos", "Ivan", "Jaime", "Diego", "Isabel", "Blanca", "Ana"};
        std::string apellido[] = {"Pascual", "Rodriguez", "Polanco", "Nu�ez", "Gonzalez", "Aldea", "Manso", "Perez", "Cebrecos", "Moglovejo", "Fernandez", "Roma", "Ortiz", "Vi�as", "Vaca", "Jarillo", "Cembell�n", "Alberti", "Martinez", "S�nchez", "Garcia", "Gomez", "Lopez", "Martin", "Cuesta", "Mogollo", "Simon", "Pe�a", "Velasco", "Jurado", "Loro", "Blanco", "Honrado", "Gil", "de Cos", "Marquez", "Diaz", "Palomino", "Tesifonte", "Luzdivino", "Dombina", "Calleja", "Ruiz", "Oristila", "Bonifacio"};

        nombre = nombre + " " + nombres[rand()%44] + " " +  apellido[rand()%44] + " " + apellido[rand()%44];
        return nombre;

    };
    /* funci�n que determina si una maleta es sospechosa o no, generando  n�meros aleatorios del 0...14 con la funci�n rand().
       si el n�mero es 7, la maleta es sospechosa
    */
    bool Util::revisar_maleta(){
        return (rand()%15 == 7);

    }

    /* funci�n que genera la maleta a partir de los atributos de la misma (dni, hora de salida, destino, id, origen, localizador, nombre, sospechosa)
        devuelve la maleta generada*/

    TMaleta Util::generar_maleta(){
        TMaleta magen;
        magen.dni = dni_aleat();
        magen.hora = generar_hora_salida();
        magen.destino = generar_destino();
        magen.id = Id_Vuelo_aleatorio(magen.destino);
        magen.origen = "MURCIA";
        magen.localizador = generar_localizador();
        magen.nombre = generar_nombres();
        magen.sospechosa = revisar_maleta();
        return magen;
    };
    /* funci�n que imprime la maleta a partir de los datos de la misma(id, dni, hora de salida, origen, destino, localizador y nombre
    */
    void Util::imprimirMaleta(TMaleta maleta) {
            cout << "|" + maleta.id + "|" + maleta.dni + "|" + maleta.hora + "|" + maleta.origen + "|" + maleta.destino + "|" + maleta.localizador + "|" + maleta.nombre +"|" << endl;

    };
