#ifndef GATO
#define GATO

// Librerias necesarias para las jugadas aleatorias de la CPU
#include <cstdlib> // Para la función srand() y rand()
#include <time.h> // Para la función time

// Importación de los archivos .h de las clases definidas en UML
#include "Jugador.h"
#include "Trivia.h"
#include "Tablero.h"

class Gato{
    private: // Atributos
    Jugador *jugadores[2]; // Se declara como arreglo de apuntadores porque Jugador es una clase abstracta.
    Trivia preguntas[10];
    Tablero board;

    public: // Métodos
        // Constructores y Destructores.
        Gato(); // Constructor por default
        ~Gato(){cout << "\nTerminando el juego... Hasta luego!\n" << endl;} // Destructor con un cout para indicar el fin del programa

        // Método de agregación, el objeto tiene un apuntador, porque se espera recibir un objeto de "Jugadores" del arreglo de apuntadores del main.
        void addNew_player(Jugador *jugador_, int numplayer){jugadores[numplayer] = jugador_;}

        // Métodos de impresión de texto.
        void bienvenidatxt();
        void instruccionestxt();

        // Métodos de despliegue de información del juego.
        void display_turnoinfo();
        string display_pregunta(int num_pregunta);

        // Métodos de definición y evaluación de casillas libres en el tablero.
        bool def_freespace(int pos);
        bool nohay_freespace();

        // Métodos para el desarrollo del juego, lo que permite a los jugadores tomar decisiones y desarrollar el juego.
        bool preguntacasilla(int pos_);
        void j1_jugar(int num_player);
        void cpu_jugar(int num_player);
        bool def_jugadasganadoras(int num_player);
};

// Implementación de los métodos---------------------------------------------------------------------------------------------

Gato :: Gato(){
    /* El constructor con parámetos inicializa el tablero (que se regenera en cada sesión) y las preguntas, las cuales son declaradas
    como tal en esta parte, ya que son constantes en todo el juego. Como son 9 casillas, declaramos la pregunta correspondiente a cada una
    haciendo uso del constructor con parámetros de la clase TRIVIA */

    Tablero board_;
    board = board_;

    Trivia preguntas_[10];

    Trivia pregunta1(1,"Matematicas","El cateto adyacente de un triangulo rectangulo mide 46.87 cm, y la hipotenusa del mismo mide 74.89 cm. Obten el area de dicho triangulo en metros.","35.10 m","13.68 m","12.89 m","15.02 m");
    preguntas_[1] = pregunta1;

    Trivia pregunta2(2,"Quimica","Que es una mezcla homogenea?","Combinacion de dos o mas sustancias, en las que no se distinguen individualmente y forman una sola fase","Combinacion de dos o mas sustancias, en la que se distinguen individualmente y forman mas de una fase","Combinacion de dos o mas sustancias, que da paso a la vaporizacion de la sustancia","Combinacion de una sustancia con otra sustancia molecularmente similar");
    preguntas_[2] = pregunta2;

    Trivia pregunta3(3,"Literatura","Cual de las siguientes NO es una figura literaria?","Metafora","Prosopopeya","Antifoque","Oximoron");
    preguntas_[3] = pregunta3;

    Trivia pregunta4(4,"Ingles","Cual de las siguientes es la conversion correcta del enunciado -The Government is planning a new road near my house- a voz pasiva?","By The Government, a new road is being planned near my house","The Government plans a new road near my house","Near my house, a new road is being planned","A new road is being planned by The Government near my house");
    preguntas_[4] = pregunta4;

    Trivia pregunta5(5,"Cultura general","Cual es la universidad mas antigua del mundo?","Universidad de Paris","Universidad de Bolonia","Universidad de Oxford","Universidad de Al Qarawiyyin");
    preguntas_[5] = pregunta5;
    
    Trivia pregunta6(6,"Historia de Mexico","Quien fue el ultimo emperador de los aztecas?","Cuauhtemoc","Moctezuma II","Tizoc","Cuitlahuac");
    preguntas_[6] = pregunta6;
    
    Trivia pregunta7(7,"Deportes","Cual de los siguientes atletas posee mas medallas olimpicas?","Usain Bolt","Michael Phelps","Carl Lewis","Matt Biondi");
    preguntas_[7] = pregunta7;

    Trivia pregunta8(8,"Historia Universal","Cual es la civilizacion mas antigua del mundo?","Egipcia","Romana","Sumeria","Griega");
    preguntas_[8] = pregunta8;

    Trivia pregunta9(9,"Geografia","Cual es el rio mas grande del mundo?","Nilo","Misisipi","Yangtze","Amazonas");
    preguntas_[9] = pregunta9;

    // Guardamos las preguntas en el arreglo
    for (int i = 1; i<10; i++){
        preguntas[i] = preguntas_[i];
    }
};

void Gato :: bienvenidatxt(){
    // Primer texto de bienvenida al usuario, compuesto unicamente de cout, por lo tanto no retorna nada.

    cout << "\nBienvenido al Juego del Gato Estudiante\n";
    cout << "\nEste programa es el mismo juego de Gato que ya conoces, solo que un tanto diferente. \n";
    cout << "\nJugaras contra la computadora. Pero, para hacer mas retador el programa, se haran uso de preguntas de trivia. Si respondes correctamente ganaras un turno y podras colocar tu marca, en caso de responder incorrectamente perderas tu turno. Comencemos..." << endl;
};

void Gato :: instruccionestxt(){
    // Segundo texto a desplegar, mismo caso que el anterior.

    cout << "\nEl tablero esta dividido en 9 cuadros. Para escoger una casilla, digita el numero correspondiente a la deseada. La figura de abajo es nuestro tablero, como vez cada casilla tiene un numero, deberas de ingresar el numero correspondiente a la casilla que desees.\n" << endl;
    board.tab_referencia();
};

void Gato :: display_turnoinfo(){
    /* Método para desplegar al usuario el avance del juego. Se despliega en consola el tablero con las casillas ocupadas
    hasta un momento determinado*/
    board.formato();
};

string Gato :: display_pregunta(int num_pregunta){
    // Usamos el formato preestablecido en la clase TRIVIA para mostrar las preguntas de cada casilla en el formato deseado.
    std::stringstream aux;
    aux << preguntas[num_pregunta].get_preguntainfo();
    return aux.str();
};

bool Gato :: def_freespace(int pos){
    // Importamos al tablero y la posición elegida (casilla) por el Jugador en turno para ver si el espacio está disponible
    char tab[10];
    for (int i=1; i<10;i++){
        tab[i] = board.getTablero(i);
    }

    if(tab[pos] == 32){
        // Si todavía hay un espacio en la casilla elegida, el Jugador puede colocar una marca en la casilla.
        return true;
    }
    else{
        // Si la casilla está ocupada, entonces no se puede colocar una marca en ese lugar.
        return false;
    }
};

bool Gato :: nohay_freespace(){
    // Método que pretende retomar lo planteado en la clase TABLERO para verificar que aún existan espacios en blanco.
    return board.check_freespace();
};

void Gato :: j1_jugar(int num_player){
    // Desarrollo de las jugadas del usuario, se contestan las preguntas y se verifican que sean correctas para poder colocar una marca.
    int pos;

    do{
        cout << "\nTurno de: " << jugadores[num_player]->getName() << endl;
        cout << "\nSelecciona una posicion del 1-9 para colocar tu marca: ";
        cin >> pos;

        if (pos>0 && pos<10){
            // Si el usuario ingreso una posicion dentro del rango 1-9, continúa
            if (def_freespace(pos) == true){
                // Si la casilla esta desocupada, continúa
                if (preguntacasilla(pos) == true){
                    // Si respondio correctamente a la pregunta, continúa
                    board.colocar_marcas(pos,jugadores[num_player]->getMark());
                    break;
                }
                else{
                    // No respondio correctamente a la pregunta, pierde el turno y no coloca su marca
                    cout << "\nLamentablemente pierdes este turno :(" << endl;
                    board.colocar_marcas(0,jugadores[num_player]->getMark());
                    break;
                }
            }
            else{
                // La casilla está ocupada, se le pide que ingrese otra
                cout << "\nPosicion ocupada, intenta nuevamente" << endl;
            }
        }
        else{
            // La opcion no está entre el rango 1-9, se le pide que vuelva a intentarlo
            cout << "\nOpcion invalida o fuera de rango, intenta nuevamente" << endl;
        }
    }while(true);
};

void Gato :: cpu_jugar(int num_player){

    /* La computadora decidirá de manera aleatoria una posición de las que estén libres, para eso usamos la función rand(). Sin embargo, por si
    sola arrojaría los mismos valores cada que se corre el programa, por lo que es necesario corregirlo haciendo uso de la solución
    brindada por eHowTech en: https://www.youtube.com/watch?v=7-dAps6Zf2M */

    // Variable para almacenar el número aleatorio generado.
    int n_random;

    // La siguiente estrategia agrega practicamente otra capa aleatoria en la que los números aleatorios generados por rand() se escogen aleatoriamente.
    
    /* Definimos a la variable de partida 'seed', de donde srand() donde comenzará con la muestra aleatoria.
    Usamos unsigned para dar solo valores a partir del cero a los enteros positivos.
    */
    srand((unsigned int) time(NULL));

    cout << "\nTurno de: " << jugadores[num_player]->getName() << endl;

    do{
        n_random = 1 + rand() % 9; // Escoge un numero entre 1 y 9
        if(def_freespace(n_random) == true){
            // Si el espacio aleatorio está desocupado, se pone su marca. De lo contrario vuelve a escoger un número
            board.colocar_marcas(n_random,jugadores[num_player]->getMark());
            break;
        }
    }while (true);
};

bool Gato :: def_jugadasganadoras(int num_player){
    /* Con los datos obtenidos, se verifica cual de los usuarios ha ganado correspondiendo a las condiciones conocidas del juego
    de gato tradicional (tres marcas en diagonal, horizontal o vertical). Se hace uso de dos variables de ayuda (tab y marc) para la comparación
    con las casillas del tablero y las marcas */

    char tab[10];
    for (int i=1; i<10;i++){
        tab[i] = board.getTablero(i);
    }
    char marc = jugadores[num_player]->getMark();

    // Define las posiciones que tienen que ser ocupadas para que uno de los jugadores pueda ganar.

    return ((tab[1]==marc && tab[2]==marc && tab[3]==marc) || 
            (tab[4]==marc && tab[5]==marc && tab[6]==marc) ||
            (tab[7]==marc && tab[8]==marc && tab[9]==marc) ||
            (tab[1]==marc && tab[4]==marc && tab[7]==marc) ||
            (tab[2]==marc && tab[5]==marc && tab[8]==marc) ||
            (tab[3]==marc && tab[6]==marc && tab[9]==marc) ||
            (tab[1]==marc && tab[5]==marc && tab[9]==marc) ||
            (tab[3]==marc && tab[5]==marc && tab[7]==marc));
};

bool Gato :: preguntacasilla(int pos_){
    // Método para mostrar todas las preguntas dependiendo de la casilla y evaluar si son correctas para cada pregunta.

    char ans; // Variable para almacenar la letra de la respuesta del usuario
    
    // Validación de la respuesta correcta de la pregunta 1
    if (pos_ == 1){
        cout << preguntas[1].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'B'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'A' || ans == 'C' || ans == 'D'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                return false;
                break;
            }
            else{
            // No se digito una opcion válida
            cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        }while (true); // Que la respuesta este entre las esperadas a,b,c,d
    } // Termina pregunta 1

    // Validación de la respuesta correcta de la pregunta 2
    else if (pos_ == 2){
        cout << preguntas[2].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'A'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'B' || ans == 'C' || ans == 'D'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                return false;
                break;
            }
            else{
                // No se digito una opcion válida
                cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        } while (true); // Que la respuesta este entre las esperadas a,b,c,d
    }  // Termina pregunta 2

    // Validación de la respuesta correcta de la pregunta 3
    else if (pos_ == 3){
        cout << preguntas[3].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'C'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'A' || ans == 'B' || ans == 'D'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                return false;
                break;
            }
            else{
                // No se digito una opcion válida
                cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        } while (true); // Que la respuesta este entre las esperadas a,b,c,d
    } // Termina pregunta 3

    // Validación de la respuesta correcta de la pregunta 4
    else if (pos_ == 4){
        cout << preguntas[4].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'D'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'A' || ans == 'C' || ans == 'B'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                return false;
                break;
            }
            else{
                // No se digito una opcion válida
                cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        } while (true); // Que la respuesta este entre las esperadas a,b,c,d
    } // Termina pregunta 4

    // Validación de la respuesta correcta de la pregunta 5
    if (pos_ == 5){
        cout << preguntas[5].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'D'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'A' || ans == 'C' || ans == 'B'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                return false;
                break;
            }
            else{
                // No se digito una opcion válida
                cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        } while (true); // Que la respuesta este entre las esperadas a,b,c,d
    } // Termina pregunta 5

    // Validación de la respuesta correcta de la pregunta 6
    if (pos_ == 6){
        cout << preguntas[6].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'A'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'B' || ans == 'C' || ans == 'D'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                return false;
                break;
            }
            else{
                // No se digito una opcion válida
                cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        } while (true); // Que la respuesta este entre las esperadas a,b,c,d
    } // Termina pregunta 6

    // Validación de la respuesta correcta de la pregunta 7
    if (pos_ == 7){
        cout << preguntas[7].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'B'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'A' || ans == 'C' || ans == 'D'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                cout << "\nHaz usado todos tus intentos" << endl;
                return false;
                break;
            }
            else{
                // No se digito una opcion válida
                cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        } while (true); // Que la respuesta este entre las esperadas a,b,c,d
    } // Termina pregunta 7

    // Validación de la respuesta correcta de la pregunta 8
    if (pos_ == 8){
        cout << preguntas[8].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'C'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'A' || ans == 'B' || ans == 'D'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                return false;
                break;
            }
            else{
                // No se digito una opcion válida
                cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        } while (true); // Que la respuesta este entre las esperadas a,b,c,d
    } // Termina pregunta 8

    // Validación de la respuesta correcta de la pregunta 9
    if (pos_ == 9){
        cout << preguntas[9].get_preguntainfo() << endl;
        do{
            cout << "\nDigita tu respuesta solo con la letra de la opcion (Ej. c): ";
            cin >> ans;

            ans = ans & ~32; // Conversión a mayúsculas para la evaluación
            if (ans == 'D'){
                // Respuesta correcta, entonces se respeta su turno
                cout << "\nCorrecto!" << endl;
                return true;
                break;
            }
            else if (ans == 'A' || ans == 'C' || ans == 'B'){
                // No digitó la respuesta correcta
                cout << "\nIncorrecto!" << endl;
                return false;
                break;
            }
            else{
                // No se digito una opcion válida
                cout << "\nOpcion invalida, intenta nuevamente" << endl;
            }
        } while (true); // Que la respuesta este entre las esperadas a,b,c,d
    } // Termina pregunta 9

    return false; // Se declara un return (al que nunca se llegará) para la validación del método
};

#endif