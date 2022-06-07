/* David René Langarica Hernández A01708936
    JUEGO DE GATO ESTUDIANTE */

#include "Gato.h" // Se importan todos los datos de Gato.h

#include <limits> // Libreria para que el usuario pueda continuar presionando la tecla enter.

using std::numeric_limits;
using std::streamsize;

int main(){
    // Se declaran los objetos a utilizar 
    Gato jgato;
    Jugador *players[2]; // Con apuntador para el método con polimorfismo, se incluye en el main por la relación de agregación

    /* En el arreglo de punteros, se inicializa un lugar para la clase del jugador (usuario) y otro para la cpu 
    (con constructores por Default), para que obtengan el método con polimorfismo correspondiente a cada tipo de jugador.*/
    players[0] = new J1();
    players[1] = new CPU(); 

    // Declaración de variables de ayuda utilizadas en el main
    string nombrej1; // Variable de ayuda para el nombre del jugador.
    char markj1; // Variable de ayuda para la marca del jugador.
    string turno; // Variable para indicar el jugador que sigue
    int rand_jugador; // Variable para evaluar aleatoriamente que jugador comenzará

    // ---- Inicio del programa ----

    // Se da la bienvenida al usuario y se le mencionan las primeras instrucciones.
    jgato.bienvenidatxt();

    // Nombre del usuario
    cout << "\nIngresa tu nombre: ";
    cin >> nombrej1; players[0]->setName(nombrej1); // Se guarda el nombre del usuario para usarlo posteriormente

    cout << "\nHola " << nombrej1 << "!, continuemos..." << endl;

    // Se pide la marca que utilizará el usuario (es el método con polimorfismo)
    players[0]->setMark(markj1);
    markj1 = players[0]->getMark();

    // Con base en la marca escogida por el jugador, se escoge la de la CPU
    players[1]->setMark(markj1);

    // Se muestra la segunda parte de las instrucciones
    jgato.instruccionestxt();

    // Se define aleatoriamente cual jugador comenzará, se aplica la misma estrategia usada para las jugadas aleatorias de la cpu.

    cout << "\nAleatoriamente se definio que el jugador que empieza es... ";

    srand((unsigned int) time(NULL));
    // Se escoge entre 0 o 1
    rand_jugador = rand() % 2;

    if (rand_jugador == 0){ 
        // Si fue 0, entonces el usuario empieza
        turno = "j1";
        cout << nombrej1 << endl;
    }
    else{
        // De lo contrario resultó en 1, lo que quiere decir que empieza la CPU
        turno = "cpu";
        cout << "CPU" << endl;
    }
    
    /* Hacer una pausa para que el usuario pueda ver quien comienza, se usa un cin que posteriormente se 
            ignora para que pueda digitar el enter, visto en: https://stackoverflow.com/questions/903221/press-enter-to-continue */
            cout << "\nPresiona enter para continuar...";
            cin.get();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Se agregan a los dos jugadores en el juego para cubrir los datos especificados, y así poder comenzar
    jgato.addNew_player(players[0], 0);
    jgato.addNew_player(players[1], 1);

    // --- Los jugadores comienzan a colocar marcas ---

    // Mientras que haya casillas libres, el juego se continua ciclando, esto será interrumpido en caso de que uno de los jugadores gane.
    while (jgato.nohay_freespace() == false)
    {
        if (turno == "j1")
        {
            // Turno del usuario
            jgato.j1_jugar(0);

            // Desplegar resultados del turno
            jgato.display_turnoinfo();

            // Pausa para que el usuario pueda ver tanto si contestó correctamente como el tablero
            cout << "\nPresiona enter para continuar...";
            cin.get();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Sigue la CPU
            turno = "cpu";

            //Verificar si el usuario ha ganado, de ser así, termina el programa.
            
            if (jgato.def_jugadasganadoras(0) == true)
            {
                cout << "\n"
                     << nombrej1 << " gana, felicidades! :)" << endl;
                     return 0;
            }
            else
            {
                // Revisar si se empató en el turno actual, lo que lleva al termino del programa.
                if (jgato.nohay_freespace() == true)
                {
                    cout << "\nNo queda ninguna casilla, partida empatada. Buen Juego." << endl;
                    return 0;
                }
            }
        }
        else
        {
            // Turno de la computadora
            jgato.cpu_jugar(1);

            jgato.display_turnoinfo();

            // Sigue el usuario
            turno = "j1";

            
            // Verificar si la computadora ha ganado, de ser así, termina el programa.
            if (jgato.def_jugadasganadoras(1) == true)
            {
                cout << "\nLa CPU ha ganado! Suerte para la proxima :(" << endl;
                return 0;
            }
            else
            {
                // Revisar si se empató en el turno actual, lo que lleva al termino del programa.
                if (jgato.nohay_freespace() == true)
                { 
                    cout << "\nNo quedan más espacios, partida empatada. Buen juego." << endl;
                    return 0;
                }
            }
        }
    }
    
    return 0;
}

// Fin del programa