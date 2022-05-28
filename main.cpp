/* David René Langarica Hernández A01708936
    JUEGO DE GATO ESTUDIANTE 
    
    Solución de la dinámica del juego basada superficialmente en el tutorial de Python brindado por Geoffrey Mariette en: 
    https://betterprogramming.pub/tic-tac-toe-with-python-8fb6d666b13f */

#include "Gato.h"

int main(){
    // Se declaran los objetos a utilizar (se incluyen los que tienen una relación de agregación)
    Gato gatoestudiante;
    J1 j1;
    CPU cpu;

    // Declaración de variables de ayuda utilizadas en el main
    string nombrej1;
    char markj1 = 'X'; // Variable de ayuda para la marca del jugador.
    string turno;
    int pos;

    // Inicio del programa

    // Se da la bienvenida al usuario y se le mencionan las primeras instrucciones.
    gatoestudiante.bienvenidatxt();

    // Nombre del usuario
    cout << "\nIngresa tu nombre: ";
    cin >> nombrej1; j1.setName(nombrej1);

    cout << "\nHola " << nombrej1 << "!, continuemos..." << endl;

    // Se pide la marca que utilizará el usuario y así se define consecuentemente la marca de la CPU
    j1.setMark(markj1);
    markj1 = j1.getMark();
    cpu.setMark(markj1);

    // Se muestra la segunda parte de las instrucciones
    gatoestudiante.instruccionestxt();

    // Los jugadores comienzan a colocar las marcas en las casillas
    // El jugador 1 siempre empieza.
    turno = "j1";

    // Se agregan a los dos jugadores para cubrir los datos especificados, y así poder comenzar el juego
    gatoestudiante.addNew_player(j1, 0);
    gatoestudiante.addNew_player(cpu, 1);

    while (gatoestudiante.nohay_freespace() == false)
    {
        // El programa se ciclará mientras que existan casillas vacías en el tablero.
        if (turno == "j1")
        {
            // Turno del usuario
            gatoestudiante.j1_jugar(0);

            // Desplegar resultados del turno
            gatoestudiante.display_turnoinfo();

            // Sigue la CPU
            turno = "cpu";

            //Verificar si el usuario ha ganado, de ser así, termina el programa.
            
            if (gatoestudiante.def_jugadasganadoras(0) == true)
            {
                cout << "\n"
                     << nombrej1 << " gana, felicidades! :)" << endl;
                     return 0;
            }
            else
            {
                // Revisar si se empató en el turno actual, lo que lleva al termino del programa.
                if (gatoestudiante.nohay_freespace() == true)
                {
                    cout << "\nNo quedan más espacios, partida empatada. Buen Juego." << endl;
                    return 0;
                }
            }
        }
        else
        {
            // Turno de la computadora
            gatoestudiante.cpu_jugar(1);

            gatoestudiante.display_turnoinfo();
            turno = "j1";

            
            // Verificar si la computadora ha ganado, de ser así, termina el programa.
            if (gatoestudiante.def_jugadasganadoras(1) == true)
            {
                cout << "\nLa CPU ha ganado! Suerte para la proxima :(" << endl;
                return 0;
            }
            else
            {
                // Revisar si se empató en el turno actual, lo que lleva al termino del programa.
                if (gatoestudiante.nohay_freespace() == true)
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