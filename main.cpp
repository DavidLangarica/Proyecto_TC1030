/* David René Langarica Hernández A01708936
    JUEGO DE GATO ESTUDIANTE
    
    Solución de la dinámica del juego basada superficialmente en el tutorial de Python brindado por Al Sweigart en: 
    http://inventwithpython.com/chapter10.html */

#include "Gato.h" // Se importan todos los datos de Gato.h

#include <limits> // Libreria para que el usuario pueda continuar presionando la tecla enter.

int main(){
    // Se declaran los objetos a utilizar (se incluyen los que tienen una relación de agregación)
    Gato jgato;
    Jugador *players[2]; // Con apuntador para los métodos con polimorfismo, se incluye en el main por la relación de agregación

    // En el arreglo de punteros, se inicializa un lugar para la clase del jugador y otro para la cpu (con constructores por Default), para que obtengan los métodos con polimorfismo correspondientes a cada tipo de jugador.
    players[0] = new J1();
    players[1] = new CPU(); 

    // Declaración de variables de ayuda utilizadas en el main
    string nombrej1; // Variable de ayuda para el nombre del jugador.
    char markj1; // Variable de ayuda para la marca del jugador.
    string turno; // Variable para indicar el jugador que sigue

    // Inicio del programa

    // Se da la bienvenida al usuario y se le mencionan las primeras instrucciones.
    jgato.bienvenidatxt();

    // Nombre del usuario
    cout << "\nIngresa tu nombre: ";
    cin >> nombrej1; players[0]->setName(nombrej1);

    cout << "\nHola " << nombrej1 << "!, continuemos..." << endl;

    // Se pide la marca que utilizará el usuario y así se define consecuentemente la marca de la CPU
    players[0]->setMark(markj1);
    markj1 = players[0]->getMark();
    players[1]->setMark(markj1);

    // Se muestra la segunda parte de las instrucciones
    jgato.instruccionestxt();

    // Los jugadores comienzan a colocar las marcas en las casillas
    // El jugador 1 siempre empieza.
    turno = "j1";

    // Se agregan a los dos jugadores en el juego para cubrir los datos especificados, y así poder comenzar
    jgato.addNew_player(*players[0], 0);
    jgato.addNew_player(*players[1], 1);

    while (jgato.nohay_freespace() == false)
    {
        // El programa se ciclará mientras que existan casillas vacías en el tablero.
        if (turno == "j1")
        {
            // Turno del usuario
            jgato.j1_jugar(0);

            // Desplegar resultados del turno
            jgato.display_turnoinfo();

            /* Hacer una pausa para que el usuario pueda ver si contestó correctamente, se usa un cin que posteriormente se 
            ignora para que pueda digitar el enter, visto en: https://stackoverflow.com/questions/903221/press-enter-to-continue */
            cout << "\nPresiona enter para continuar...";
            cin.get();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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