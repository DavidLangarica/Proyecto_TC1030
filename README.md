# Proyecto A01708936 {TC1030}
## Juego del Gato Estudiante

Este programa es el mismo juego de Gato que conocemos, solo que un poco diferente.  El usuario jugará contra la computadora pero, para hacer más retador el juego, se harán uso de preguntas de trivia. Si el jugador responde correctamente, entonces ganará un turno y podrá colocar su marca en el tablero de 9 casillas, en caso de responder incorrectamente perderá su turno en esa ronda y se saltará al turno de la computadora. 

_____________

### Avance 1
Diagrama de clases del programa (archivo Diagramadeclases_A01708936.pdf)

En este caso, la clase 'Gato' añade (dependiendo de la relación de agregación o composición) a las demás clases, y con 'get_turnoinfo()' tiene la capacidad de mostrar las preguntas del juego, el turno en el que se encuentran y la casilla seleccionada. En el caso de los dos jugadores, se identifica la existencia de atributos y valores que pueden ser heredados por la clase 'Jugador' y la clase mantiene una relación por agregación con la clase 'Gato'. El usuario pueda definir los atributos de 'J1' y puede tomar decisiones sobre sus movidas, en el caso de 'CPU' el programa se encarga de la automatización de este y el usuario no intercede en ello.

Las preguntas para el usuario son del tipo 'Trivia', la cual es la clase en donde se define el formato y el cómo se muestran las preguntas y opciones durante el juego. Como esta clase tiene una relación fuerte con el juego en general, a razón de que sin ellas el usuario no puede realizar jugadas, se le detona una relación de composición y se reiniciarán con cada juego. También, la clase 'Gato' tiene un arreglo en donde se guardarán todas las 9 preguntas del tipo 'Trivia'.

Parecido al caso anterior, tenemos a la clase 'Tablero', en donde se vuelve a tomar la relación fuerte con el juego por las mismas razones, es aquí en donde se estarán guardando las decisiones tomadas por ambos jugadores y en donde, visualmente, el usuario podrá observar las casillas que están libres, también se encarga de definir la aplicación y evaluación de los juegos, por lo cual 'Tablero' tiene como atributo a un arreglo de casillas, pues nuestro juego se forma de 9 casillas en total, las cuales deberán de ser ocupadas por las marcas de ambos jugadores durante el desarrollo del juego para así llevar las comparaciones pertinentes que lleven a la evaluación del ganador cuando se cumplan las condiciones de una victoria ó, que de lo contrario exista un empate (métodos de la presente clase).

_____________

### Avance 2
Favor de compilar el archivo main.cpp, el cual fue probado en múltiples plataformas para comprobar su compatibilidad.

En este avance se presenta la transición del diagrama de clases al código en C++ haciendo uso de la programación orientada a objetos. En todos los archivos se encontrarán con comentarios que describen el funcionamiento y el objetivo de cada método (y posiblemente cada línea) para asegurar la comprensión total del mismo.

En el programa, se implementó el concepto de Herencia (como se mostró en el diagrama de clases) en la clase de Jugador (Jugador.h). En el mismo se puede apreciar el armado de los constructores para la clase padre y las clases hijas (J1 y CPU) y los propios métodos getters y setters (con un amplio enfoque en el usuario J1). En el caso de los modificadores de acceso, los métodos se mantienen completamente 'public' a razón de que es necesario para que la clase Gato pueda ingresar a los datos; los atributos heredados de la clase padre se definen como 'protected' para que únicamente las clases hijas puedan acceder sin problema a los mismos y que las otras clases solo puedan hacer uso de ellos a través de los métodos getters y setters.

En la clase hija 'J1' se agrega un setter para el nombre, para que el usuario pueda editar su nombre y sea usado durante el juego. En el caso de la CPU no es necesario, pues no tendrá un nombre específico como tal, por lo que se define en el constructor.

Asimismo, se ocupa la sobreescritura de métodos con el método setter de la clase padre y de las clases hijas para definir la marca a utilizar en el juego, en el caso de la clase padre se ocupa la técnica tradicional para un método setter. Sin embargo, es preciso que la clase hija 'J1' tenga un método setter con una interacción directa con el usuario para que pueda escoger entre 'X'/'O', con base en ello, la computadora obtendrá su marca a través de una evaluación.

Reiterando, para más información, es posible dirigirse a cada archivo adjunto del código y considerar los comentarios dentro del código realizado.
_____________

### Avance 3
Para este avance, se identifican a los métodos polimórficos de la clase con herencia 'Jugador' (en el archivo Jugador.h). A dos métodos (setName y setMark) se les incluye la palabra reservada 'virtual' para indicar que se hará uso del polimorfismo, pues tendrán implementaciones diferentes dependiendo de la clase hija. En el caso del método 'setName' únicamente el usuario 'J1' podrá cambiar su nombre, por lo que la clase padre indica un nombre por default mientras que la hija lo implementa mediante la definición del nombre dado por el usuario. La clase hija 'CPU' no lo necesita pues usamos el nombre definido en el constructor por default.

Para el método 'setMark' existe una implementación algo más compleja, mientras que la clase padre únicamente implementa el método en su generalidad, la clase hija 'J1' hará una evaluación para definir la marca deseada y dada por el usuario; mientras que la clase hija "CPU" tomará la marca definida por el usuario para definir la propia (Si el usuario escoge 'X', entonces la cpu tendrá 'O' y viceversa).

Después, se retoma que los jugadores poseen una relación de agregación con la clase 'Gato' por lo que las clases hijas 'J1' y 'CPU' se agregan en el main. Para cubrir lo que se ha mencionado con relación al polimorfismo, primero definimos al arreglo del tipo 'Jugador' con punteros (para indicar que existen métodos con polimorfismo en la clase con herencia y que se encuentran en el heap). Posteriormente, para definir a los objetos creados con punteros, se aplica con el constructor por default a los dos tipos de jugadores que interceden en el juego (J1 y CPU) con sus respectivas posiciones en el arreglo del tipo Jugador. Es así, como se implementan los métodos y se aplica el polimorfismo en los métodos que se definieron como tal.
_____________
