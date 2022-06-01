#ifndef TABLERO
#define TABLERO

// Librerias necesarias
#include <iostream>
#include <stdlib.h>

// Definimos el espacio para no tener que poner std:: y no usar using namespace std
using std::cout;
using std::endl;

class Tablero{
    private: // Atributos
        char casillas[10];

    public: // Métodos
        // Constructor por default.
        Tablero();

        // Métodos para el despliegue del tablero en consola
        void formato();
        void tab_referencia();

        // Método getter para obtener lo almacenado en el arreglo de las casillas.
        char getTablero(int posicion) {return casillas[posicion];}

        // Método para reemplazar los espacios en blanco del tablero con las marcas de los jugadores.
        char colocar_marcas(int posicion,char marca);

        // Método para verificar si existe un espacio en blanco.
        bool check_freespace();
};

// Implementación de los métodos---------------------------------------------------------------------------------------------

Tablero :: Tablero(){
    /* Comenzaremos por reemplazar inicialmente a los espacios vacíos de las casillas con espacios vacíos. Se usa la igualdad a 32 
    ya que es el valor en código ASCII del espacio en blanco, siendo así como podremos manejar al arreglo de casillas del tipo char a lo 
    largo del juego. */

    for (int i=1; i<=10; i++)
    {
        casillas[i] = 32;
    }
};

void Tablero :: formato(){
    // Este es el formato del tablero del juego, se compone de líneas que separan a las casillas y de un arreglo que va definiendo los números que corresponden a cada casilla.
    cout << "_________________" << endl;
    cout << "     |     |" << endl;
    cout << "  "<<casillas[1]<<"  |  "<<casillas[2]<<"  |  "<<casillas[3]<<"  " << endl;
    cout << "     |     |" << endl;
    cout << "_________________" << endl;
    cout << "     |     |" << endl;
    cout << "  "<<casillas[4]<<"  |  "<<casillas[5]<<"  |  "<<casillas[6]<<"  " << endl;
    cout << "     |     |" << endl;
    cout <<"_________________" << endl;
    cout <<"     |     |     " << endl;
    cout << "  "<<casillas[7]<<"  |  "<<casillas[8]<<"  |  "<<casillas[9]<<"  " << endl;
    cout << "     |     |" << endl;
    cout << "_________________" << endl;
};

void Tablero :: tab_referencia(){
    // Este es el formato de referencia para el usuario del juego, en donde podrá ver inicialmente los números correspondientes para cada casilla.
    cout << "_________________" << endl;
    cout << "     |     |" << endl;
    cout << "  "<<"1"<<"  |  "<<"2"<<"  |  "<<"3"<<"  " << endl;
    cout << "     |     |" << endl;
    cout << "_________________" << endl;
    cout << "     |     |" << endl;
    cout << "  "<<"4"<<"  |  "<<"5"<<"  |  "<<"6"<<"  " << endl;
    cout << "     |     |" << endl;
    cout <<"_________________" << endl;
    cout <<"     |     |     " << endl;
    cout << "  "<<"7"<<"  |  "<<"8"<<"  |  "<<"9"<<"  " << endl;
    cout << "     |     |" << endl;
    cout << "_________________" << endl;
};


char Tablero :: colocar_marcas(int posicion, char marca){
    // En est método se reemplaza el contenido de las casillas por el de la marca del usuario en turno. Retornamos el arreglo actualizado para su despliegue.
    casillas[posicion] = marca;
    return casillas[10];
}


bool Tablero :: check_freespace(){
    /* En este método se evalua si todas las casillas guardan alguna marca, para verificar cuando exista un empate. Usamos a la variable
    auxiliar j para llevar el contador de las casillas libres*/
    
    int j=0;

    for (int i=1; i<10; i++){
        if (casillas[i] == 32){
            j++; 
        }
    }
    if (j == 0){
        return true;
    }
    else{
        return false;
    }
};

#endif