# tanksminigame

engine.h -> contains 2 classes; one is used for the engine of the game, whereas the second is an abstract class that will be used to create classes for each type of unit in the game: tank, bomb, wall 

joctanc.h -> contains the classes of each unit used by this game: tank, bomb, wall

input.h -> contains a class that is used to control the input from the players

output.h -> contains a class that is used to display the actual game in the console

board.h -> contains the placement of the walls


In main.cpp, the controls of the two tanks are read and the walls are built. The game's loop will continue until the ESC key is pressed.
