# Proyecto A01708936 {TC1030}
## Juego del Gato Estudiante

Este programa es el mismo juego de Gato que conocemos, solo que un poco diferente.  El usuario jugará contra la computadora pero, para hacer más retador el juego, se harán uso de preguntas de trivia. Si el jugador responde correctamente (tiene 2 oportunidades), entonces ganará un turno y podrá colocar su marca en el tablero de 9 casillas, en caso de responder incorrectamente las 2 oportunidades, perderá su turno en esa ronda y se saltará al turno de la computadora. 

_____________

### Avance 1
Diagrama de clases del programa (archivo Diagramaclases_A01708936.pdf)

En este caso, la clase 'Gato' se encarga de definir la aplicación y evaluación de los juegos como un todo por parte de cada jugador. En el caso de los dos jugadores, es preciso que estos sean agregados cada que se inicie el juego y tengan características externas, en donde el usuario pueda definir los atributos de 'Jugador' y pueda tomar desiciones sobre sus movidas, en el caso de 'CPU' el programa se encarga de la automatización del mismo y el usuario no intercede en ello.

Las preguntas para el usuario son del tipo 'Trivia', la cual es la clase en donde se define el formato y el cómo se muestran durante el juego. Como esta clase tiene una relación fuerte con el juego en general, a razón de que sin ellas el usuario no puede realizar jugadas, se le detona una relación de composición y la clase 'Gato' tiene un arreglo en donde se guardan todas las preguntas del tipo 'Trivia'.

Parecido al caso anterior, tenemos a la clase 'Tablero', en donde se vuelve a tomar la relación fuerte con el juego, pues es en donde se estarán guardando las decisiones tomadas por ambos jugadores y en donde, visualmente, el usuario podrá observar las casillas que están libres. 'Tablero' tiene un arreglo de casillas, pues nuestro juego se compone de 9, y que deberán de ser ocupadas por las marcas de ambos jugadores durante el desarrollo del juego para así llevar las comparaciones pertinentes que lleven a la evaluación del ganador cuando se cumplan las condiciones de una victoria o exista un empate.

_____________
