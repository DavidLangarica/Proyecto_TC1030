#ifndef TRIVIA
#define TRIVIA

// Librerias necesarias
#include <iostream>
#include <string>
#include <sstream>

// Definimos el espacio para no tener que poner std:: y no usar using namespace std
using std::cout;
using std::cin;
using std::endl;
using std::string;

class Trivia{
    private: // Atributos
        int num_pregunta;
        string categoria;
        string pregunta;
        string opcion_a;
        string opcion_b;
        string opcion_c;
        string opcion_d;

    public: // Métodos
        // Constructores
        Trivia(){}; // Constructor por default
        Trivia(int num_pregunta_,string categoria_,string pregunta_,string opcion_a_,string opcion_b_,string opcion_c_,string opcion_d_); // Constructor con parámetros
        
        // Método para definir el formato con el que se despliegan las preguntas del juego.
        string get_preguntainfo();
};

// Implementación de los métodos---------------------------------------------------------------------------------------------

Trivia :: Trivia(int num_pregunta_, string categoria_, string pregunta_,string opcion_a_,string opcion_b_,string opcion_c_,string opcion_d_){
    num_pregunta = num_pregunta_;
    categoria = categoria_;
    pregunta = pregunta_;
    opcion_a = opcion_a_;
    opcion_b = opcion_b_;
    opcion_c = opcion_c_;
    opcion_d = opcion_d_;
};

string Trivia :: get_preguntainfo(){
    // Se define el formato que tendrá el despliegue en consola de cualquier pregunta que se pueda declarar.
    std::stringstream aux;
    aux << "\n" << num_pregunta << ". " << categoria << endl;
    aux << "Pregunta: " << pregunta << endl;
    aux << "a) " << opcion_a << endl;
    aux << "b) " << opcion_b << endl;
    aux << "c) " << opcion_c << endl;
    aux << "d) " << opcion_d << endl;
    return aux.str();
};

#endif