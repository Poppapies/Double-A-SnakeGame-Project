README - Double A
Written in C++ by Double A Group Ahmed_Abdalraouf & Ahmed_Walid).
This file is NOT a full cover for the code but a simplification of the main highlights of it.

purposes & Control:
This game is a simple console-based snake game written as a part of the second-year Object-Oriented Programming Final project.
The game control is listed as the following:
-> Lower case 'w' to move the Snake up.
-> Lower case 's' to move the Snake down.
-> Lower case 'a' to move the Snake left.
-> Lower case 'd' to move the Snake right.
So make sure to turn the CapLock OFF.

source Code:-
The game consists of two files: test.cpp which includes the main & HEADERS.h which contains three classes Food, Snake & Game, & a defined type Point.

1-HEADERS.h:-
1.1 Global variables ("bool Stop", "int Density", "int Score").

1.2 Point type:
Point Type is a type defined by struct in order to identify points inside the grid of the game more conveniently. Each point variable created has two attributes:
1- integers x, y to contain the location of the variable point.
2- A boolean override to the "==" operator in the type to make comparison between the points easier.
The user-defined constructor in Point has two integer parameters to initialize the values of x, y.

1.3 Food Class:-
It's a simple class that is designed to generate random food positions in different locations inside the grid. This class consists of:
1- int food positions x, y.
2- setter and getter functions to set and return new positions to other parts of the code.

1.4 Snake Class:-
This class is the most important class in the game. It consists of:

1.4.1 Points vector "body", which is the main vector to store the positions of all the points that are part of the Snake body.
1.4.2 Default defined constructor with two integer parameters to push them in the vector "body" in order to be the first part of the snake's segments.
1.4.3 The vector 'body' has a const point vector function "getBody()" to return all "body" points values. This function is to make various parts of the code able to read the positions of the Snake segments without modifying any parts of it by returning by reference rather than by value. The "const" at the end of "getBody" is to force this method to not mess with any parts of the Snake object.
1.4. 4 Point "getHead()" is a simple function to return the value of the leading snake segment.
1.4.5  void "move()" modifies the head position.
          void "grow()" gives the bool "growNextMove" a true value.

1.5 Game Class:-
1.5.1 void "snakeControl()" that switches the enum names and each case is to make "move()" able to modify the position of the head.
1.5.2 void "Display()" which takes three snake objects passed by reference and the food position as parameters and prints the whole game.
1.5.3 void "Flow()" which takes a snake object passed by reference and also a food object passed by reference.
 This function checks if the snake's head coordinates match the food object coordinates and increases the size of the snake if so by calling Snake's "grow()".
 It also ensures that the food isn't printed at any part of the snake's segments.

2 test.cpp:-
This file contains the main function, void "clearScreen()"
2.1- Void "clearScreen()" is a void function that clears the player's screen immediately when called. It has been defined to be a replacement for the system("cls") command in order to provide a better experience by minimizing the flickering issue.
2.2 int main(), starts with the declaration of Game, Snake, and Food objects then a while loop that uses the Game object to access Game's methods.
This while loop won't break unless the global bool "Stop" is set to true and this shall print the score of the player in this exact trial.

Additional information:-
.The code used the "windows.h" library in two things:-
1- To color the terminal output by using the Windows API.
2- The Sleep function with an integer parameter "Density" to make the game more difficult as the snake segments become longer.
.This game used the <conio.h> library to handle the control using the functions "_kbhit()" & "_getch()".

All testing was done using an external Microsoft PowerShell terminal.
We highly recommend building the executable and then run it manually via an external terminal (e.g., PowerShell or Command Prompt) for the best experience.
