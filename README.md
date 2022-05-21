# Proyecto A01708936 {TC1030}
## Juego del Gato Estudiante

Este programa es el mismo juego de Gato que conocemos, solo que un poco diferente.  El usuario jugará contra la computadora pero, para hacer más retador el juego, se harán uso de preguntas de trivia. Si el jugador responde correctamente (tiene 2 oportunidades), entonces ganará un turno y podrá colocar su marca en el tablero de 9 casillas, en caso de responder incorrectamente las 2 oportunidades, perderá su turno en esa ronda y se saltará al turno de la computadora. 

_____________

### Avance 1
Diagrama de clases del programa (archivo Diagramadeclases_A01708936.pdf)

En este caso, la clase 'Gato' añade (dependiendo de la relación de agregación o composición) a las demás clases, y con 'get_turnoinfo()' tiene la capacidad de mostrar las preguntas del juego, le tunro en el que se encuentran y la casilla seleccionada. En el caso de los dos jugadores, se identifica la existencia de atributos y valores que pueden ser heredados por la clase abstracta 'Jugador' es preciso que dicha clase sea agregada pues, en el caso de que el usuario quiera jugar nuevamente, se requiere que los atributos sean guardados en el sistema para no volverlos a pedir (mientras que el juego en sí se reiniciará). El usuario pueda definir los atributos de 'J1' y puede tomar decisiones sobre sus movidas, en el caso de 'CPU' el programa se encarga de la automatización de este y el usuario no intercede en ello.

Las preguntas para el usuario son del tipo 'Trivia', la cual es la clase en donde se define el formato y el cómo se muestran las preguntas y opciones durante el juego. Como esta clase tiene una relación fuerte con el juego en general, a razón de que sin ellas el usuario no puede realizar jugadas, se le detona una relación de composición y se reiniciarán con cada juego. También, la clase 'Gato' tiene un arreglo en donde se guardarán todas las 9 preguntas del tipo 'Trivia'.

Parecido al caso anterior, tenemos a la clase 'Tablero', en donde se vuelve a tomar la relación fuerte con el juego por las mismas razones, es aquí en donde se estarán guardando las decisiones tomadas por ambos jugadores y en donde, visualmente, el usuario podrá observar las casillas que están libres, también se encarga de definir la aplicación y evaluación de los juegos, por lo cual 'Tablero' tiene como atributo a un arreglo de casillas, pues nuestro juego se forma de 9 casillas en total, las cuales deberán de ser ocupadas por las marcas de ambos jugadores durante el desarrollo del juego para así llevar las comparaciones pertinentes que lleven a la evaluación del ganador cuando se cumplan las condiciones de una victoria ó, que de lo contrario exista un empate (métodos de la presente clase).

_____________
