#include "Util.h"

using namespace std;

    TMaleta generar_maleta(string pnr, int n){

    TMaleta maleta;
    maleta.PNR = pnr;
    maleta.peso = rand()%20;
    maleta.nbulto = n;
    maleta.tipo = "por definir";

    }

    Lista generar_equipaje(string pnr){

        Lista aux = new Lista();
        for (int i; i < rand()%6; i++){

        }

    }
/* función para generar de forma  aleatoria los DNI a partir de dos arrays ( el primero de numeros y el segundo de las letras del abecedario en mayúsculas).
DNI - formados por 8 cifras - 1 letra al final (MAYÚSCULA)
*/
    string Util::dni_aleat(){
        string dni = "";
        char numeros[]= "0123456789";
        char muestra[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


        for (int x = 0; x < 8; x++) {
            dni = dni + numeros[rand()%10]; // genera números aleatorios del 1...10 para las cifras del DNI
            }


        dni = dni + muestra[rand()%26]; // genera letras de forma aleatoria para las letras en MAYÚSCULA del DNI. (Alfabeto tiene 26 letras)
        return dni ;

    };
/*
     función utilizada para generar a partir de un array con cuatro países, los destinos del vuelo del avión aleatoriamente empleando la  función rand()

*/
    string Util::generar_destino(){ //
        string muestra[]= {"ARGENTINA","ALEMANIA ", "ISLANDIA ", "ALBANIA  "};
        int destino_n = rand()%4;
        string destino = muestra[destino_n];
        return destino;

    };
/*
genera de forma aleatoria una hora de salida  de entre 4 horas distintas establecidas previamente en el array con formato "HH:mm"
*/
    string Util::generar_hora_salida(){
        string muestra[]= {"12:32", "14:40", "21:12","17:19"};
        string hora_salida = muestra[rand()%4];
        return hora_salida;

 };
 /* generar aleatoriamente los nombres y apellidos de las personas a las que las corresponde cada maleta
    a partir de un array de strings de nombres y otro  de apellidos.
    47 nombres asociados a 47 apellidos.
    De cada maleta se obtendrá un nombre y dos apellidos asociados.
*/
    string Util::generar_nombres(){
        string nombre= "";


        std::string nombres[] = {"Antonio", "David", "Juan", "Francisco", "Daniel", "Jose", "Manuel", "Teresa", "Celia", "Maria", "Lucia", "Rocio", "Ascen", "Loren", "Alvaro", "Lourdes", "Laura", "Sofia", "Mario", "Javier", "Marco", "Lara", "Luisa", "Sandra", "Adrian", "Luis", "Fernando", "Domingo", "Africa", "Andrea", "Sergio", "Adrian", "Pablo", "Sandra", "Marta", "Valeria", "Paula", "Luna", "Diana", "Noelia", "Marcos", "Ivan", "Jaime", "Diego", "Isabel", "Blanca", "Ana"};
        std::string apellido[] = {"Pascual", "Rodriguez", "Polanco", "Nuñez", "Gonzalez", "Aldea", "Manso", "Perez", "Cebrecos", "Moglovejo", "Fernandez", "Roma", "Ortiz", "Viñas", "Vaca", "Jarillo", "Cembellín", "Alberti", "Martinez", "Sánchez","Saiz","Arribas", "Garcia", "Gomez", "Lopez", "Martin", "Cuesta", "Mogollo", "Simon", "Peña", "Velasco", "Jurado", "Loro", "Blanco", "Honrado", "Gil", "de Cos", "Marquez", "Diaz", "Palomino", "Tesifonte", "Luzdivino", "Dombina", "Calleja", "Ruiz", "Oristila", "Bonifacio"};

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


    bool running = true;
Menu menus[MENUS_MAX] = {
    {1, "Insertar nuevo registro manualmente con un solo bulto en su lista de equipaje.\
     Elegir asiento mientras queden asientos libres.                           ", menuInsertarAB},
    {2, "Modificar los campos de un registro salvo el de  equipaje.            ", menuModificarCA},
    {3, "Borrar un registro dado del árbol                                     ", menuBorrarAB},
    {4, "Mostrar los datos de un pasajero concreto buscando por su PNR         ", menudatosPA},
    {5, "Mostrar los datos del equipaje de un pasajero identificado por su PNR.", menuEquipajePA},
    {6, "Añadir un nuevo bulto al equipaje de un pasajero dado.                ", menuAñadirBultoEQ},
    {7, "Borrar algún bulto del equipaje de un pasajero dado.                  ", menuBorrarBulto},
    {8, "Modificar los datos del equipaje de un pasajero dado                  ", menuModificarDatosPA},
    {9, "Cambiar bulto del equipaje de un pasajero a otro pasajero diferente \
        identificados por su PNR.                                              ", menuCambiarBultoPasajero},
    {0, "Salir del programa                                                    ", menuExit},
};
    TMaleta Util::generar_maleta()
