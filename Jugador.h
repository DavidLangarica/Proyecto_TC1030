#ifndef JUGADOR
#define JUGADOR

// Librerias necesarias.
#include <iostream>
#include <string>
#include <stdlib.h>

// Definimos el espacio para no tener que poner std:: y no usar using namespace std
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Clase padre (Abstracta)
class Jugador{
    protected: // Atributos 
        string nombre;
        char marca;

    public: // Métodos 
        Jugador(): nombre("Jugador"),marca('Z') {};
        ~Jugador(){};
        Jugador(string nombre_,char marca_);
        string getName() {return nombre;}
        char getMark(){return marca;};
        void setName(string nombre_) {nombre = nombre_;}

        /* Método con polimorfismo, declarado con las características para convertir a la clase en clase abstracta.
            Polomorfismo porque tendrá sobrescritura, el usuario escoge su marca, mientras que la computadora la obtiene
            "automaticamente" con base en la marca del usuario.*/
        virtual void setMark(char marca_) = 0;

};

// Implementación de los métodos de la clase padre Jugador-------

Jugador :: Jugador(string nombre_, char marca_){
    nombre = nombre_;
    marca = marca_;
};

// Fin clase Jugador---------------------------------------

// De la clase Jugador, hereda la clase J1
class J1 : public Jugador{
    public: // Métodos
        J1(): Jugador() {};
        J1(string nombre_,char marca_): Jugador(nombre_,marca_){};
        void setMark(char mark); // Método polimórfico

};

// Implementación de los métodos de la clase hija J1-------

/**
 * setMark() define la marca deseada por el usuario, se ocupa una variable de ayuda para la evaluación
 * e implementación en el método. El resultado define la marca de J1 como X/O
 *
 * @param char variable de ayuda que identificará a la marca escogida usuario
 * @return 
 */

void J1 :: setMark(char mark){

    while (true){
        cout << "\nQue marca te gustaria usar X / O?: ";
        cin >> mark;

        // Conversión de char a mayúsculas usando código ASCII
        mark = mark & ~32;
        
        if (mark == 'X'){
            // Retornamos a la letra 'X' si el usuario escogio dicha letra
            cout << "\nMuy bien " << getName() << ", tu jugaras con X, y la CPU con O" << endl;
            marca = mark;
            break;
        }
        else if (mark == 'O'){
            // Retornamos a la letra 'O' si el usuario escogio dicha letra
            cout << "\nMuy bien " << getName() << ", tu jugaras con O, y la CPU con X" << endl;
            marca = mark;
            break;
        }
        else{
            cout << "Opcion invalida, intenta nuevamente" << endl;
        }
    }
};

// Fin clase J1-------------------------------------------

// De la clase Jugador, también hereda CPU
class CPU : public Jugador{
    public: // Métodos
        CPU(): Jugador("CPU",'O') {};
        CPU(string nombre_,char marca_): Jugador(nombre_,marca_){};
        void setMark(char mark); // Método polimórfico
};

// Implementación de los métodos de la clase hija CPU-------

/**
 * setMark() define la marca por la computadora con base en lo escogido por
 * el usuario.
 *
 * @param char variable de ayuda que identificará a la marca escogida usuario
 * @return 
 */

void CPU :: setMark(char mark){
    /* Con base a la marca escogida por el jugador, se define la marca de la computadora. Si el usuario utiliza la 
    marca 'X' entonces se usa la marca definida en el constructor por default.*/
    if (mark=='O'){
        marca = 'X';
    }
};

#endif