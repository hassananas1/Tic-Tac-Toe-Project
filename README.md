# Tic-Tac-Toe-Project
Develop a Tic Tac Toe game that will match a player against the computer.


Function List, Signatures, and Purpose

int checkUserMove(char input1,char input2,string storeMoves)
return type: integer
parameters: 2 characters and a string (in this all board moves are stored)
function name: checkUserName
Purpose: this function will check the user entered move if move is valid
 it’ll return the index of that move on board if move is not valid
 it’ll ask the user again to enter valid move and will check again
 if move is valid or not, it’ll ask the user to entered the move
 until user won’t enter valid move.

int checkComputerMove(int index,string storeMoves)
return type: integer
parameters: one integer and a string (in this all board moves are stored)
function name: checkComputerMove
Purpose: this function will check the computer randomly selected move if
 move is valid it’ll return the index of that move on board if
 move is not valid it’ll ask the computer again to generate valid
 move and will check again if move is valid or not, it’ll ask the
 computer to generate the move until computer won’t generate valid
 move.

bool checkWin(char player,string storeMoves)
return type: boolean
parameters: character and a string
function name: checkWin
Purpose: this function will check if there’s a winner or draw or nothing
 if there’s a winner it’ll return false, if there’s a draw it’ll
 return false else it’ll return true

void DisplayBox(string storeMoves)
return type: void
parameters: a string
function name: DisplayBox
Purpose: this function will display the whole board on screen
int whoMoveFirst()
return type: integer
parameters: none
function name: whoMoveFirst
Purpose: this function will generate and return the random number

void displayComputerMove(int randomMove)
return type: void
parameters: integer
function name: displayComputerMove
Purpose: this function will display the computer move using computer
 randomly generated board index number and display the move in the
 form of first Alphabet and second digit like A1 or B3 or C2
