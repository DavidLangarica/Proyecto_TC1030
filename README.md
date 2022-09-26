## Project A01708936
## Student Tic Tac Toe Game

This program is the same Tic Tac Toe game we know, just a little different.  The user will play against the computer but, to make the game more challenging, trivia questions will be asked. If the player answers correctly, then he will win a turn and will be able to place his mark on the 9-square board, in case he answers incorrectly he will lose his turn in that round and will skip to the computer's turn. 

_____________

### Phase 1
Program Class Diagram (file DiagramClassDiagram_A01708936.pdf)

In this case, the class 'Cat' adds (depending on the aggregation or composition relationship) to the other classes, and with 'get_turnoinfo()' has the ability to display the questions of the game, the turn they are in and the selected square. In the case of the two players, the existence of attributes and values that can be inherited by the 'Player' class is identified and the class maintains a relationship by aggregation with the 'Cat' class. The user can define the attributes of 'J1' and can make decisions about its moves, in the case of 'CPU' the program takes care of the automation of this and the user does not intercede in it.

The questions for the user are of type 'Trivia', which is the class where the format and how the questions and options are displayed during the game are defined. As this class has a strong relationship with the game in general, because without them the user cannot make moves, a composition relationship is detonated and will be reset with each game. Also, the 'Cat' class has an array where all 9 questions of the 'Trivia' type will be stored.

Similar to the previous case, we have the class 'Board', where the strong relationship with the game is again taken for the same reasons, it is here where the decisions taken by both players will be saved and where, visually, the user will be able to observe the boxes that are free, it is also in charge of defining the application and evaluation of the games, Therefore, 'Board' has as an attribute an arrangement of squares, because our game is formed by 9 squares in total, which must be occupied by the marks of both players during the development of the game in order to carry out the relevant comparisons that lead to the evaluation of the winner when the conditions of a victory are met or, otherwise there is a tie (methods of this class).

_____________

### Phase 2
Please compile the main.cpp file using g++, which was tested on multiple platforms for compatibility.

This preview presents the transition from class diagram to C++ code using object oriented programming. In all files you will find comments describing the operation and purpose of each method (and possibly each line) to ensure full understanding.

In the program, the concept of Inheritance was implemented (as shown in the class diagram) in the Player class (Player.h). In it, the assembly of the constructors for the parent class and the child classes (J1 and CPU) and the getters and setters methods themselves (with a broad focus on the J1 user) can be seen. In the case of the access modifiers, the methods are kept completely 'public' because it is necessary for the Cat class to access the data; the attributes inherited from the parent class are defined as 'protected' so that only the child classes can access them without problem and the other classes can only make use of them through the getters and setters methods.

In the child class 'J1' use is made of the setter for the name, so that the user can edit its name and it can be used during the game. In the case of the CPU it is not necessary, since it will not have a definition for a specific name, so it is defined in the constructor.

Likewise, method overwriting is used with the setter method of the parent class and of the child classes to define the brand to be used in the game, in the case of the parent class the traditional technique for a setter method is used. However, it is necessary that the child class 'J1' has a setter method with a direct interaction with the user so that it can choose between 'X'/'O', based on this, the computer will obtain its mark through an evaluation.
_____________

### Phase 3
For this advancement, the polymorphic method of the class with inheritance 'Player' is identified (in the file Player.h). The 'virtual' reserved word is included to the setMark method to indicate that polymorphism will be used, since it will have different implementations depending on the child class. 

For the 'setMark' method there is a somewhat more complex implementation, while the parent class only implements the method in its generality, the child class 'J1' will make an evaluation to define the desired mark given by the user; while the child class 'CPU' will take the mark defined by the user to define its own (If the user chooses 'X', then the cpu will have 'O' and vice versa).

Then, it is resumed that the players have an aggregation relationship with the class 'Cat' so the child classes 'J1' and 'CPU' are added in the main. To cover what has been mentioned in relation to polymorphism, we first define the array of type 'Player' with pointers (to indicate that there are methods with polymorphism in the class with inheritance and that they are in the heap). Subsequently, to define the objects created with pointers, we apply with the default constructor to the two types of players that intervene in the game (J1 and CPU) with their respective positions in the array of the Player type. This is how the methods are implemented and polymorphism is applied to the method defined as such.
_____________

### Phase 4
From the beginning, it has never been desired to create an object from the Player class, but the purpose of this one is exclusively to detonate the similar characteristics of the J1 and CPU. Therefore, for this last advance, the Player class is made abstract so that it is not possible to create objects from it, for this purpose the class with polymorphism 'setMark' was used where the corresponding equalization to zero was made and this is how the class was converted.

Moreover, since the Player class became abstract, then it was necessary to make adjustments in the Cat class, since objects of that type were "created" there in order to use them in the methods to be applied in the main. Therefore, the arrangement of Player players[2] was converted to an arrangement of pointers of the Player type that could later be replaced by objects of type J1 and CPU directly in the heap so as not to cause errors when making use of an abstract class, hence the need to change the methods in which the players are used so that they were compatible with the pointers.

_____________

For more information, it is possible to go to each code attachment and consider the comments inside the code.


