/*
* Written By: Christian Vargas
*/


// Implementation file for a Tic-Tac-Toe program.
//  The program lets two players play the tic-tac-toe game on a 3 by 3 board.

#include <iostream>
#include <iomanip>
#include "TicTacToe.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

void ticTacToe::play(){
    bool complete = false;
    char player = 'X';
    displayBoard();

    while (!complete){
        complete = getXOMove(player);
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

/* The following restarts the game. If  the person playing inputs 'Y' or 'y' the game will restart. If the person inputs 'N' or 'n' the game will end and the user will be prompted 'Thank you for playing! Bye!' Similarly, if the user enters anything that is not 'Y' or 'y' then the game ends. 
*/

	    string again; 
	    cout << "Would you like to play again(Y / N)? "; cin >> again;
      cout<<"Thank you for playing.\n";
	    if(again != "Y" && again != "y") return;
	    reStart(); // The reStart ends here
}

void ticTacToe::displayBoard() const{
    cout << "   1   2    3\n" << endl;// The heading for the board
    for (int row = 0; row < 3; row++)
    {
        cout << row + 1; // The left part of the board
        for (int column = 0; column < 3; column++)
        {
            cout << std::setw(3) << board[row][column];
            if (column != 2)
                cout << " |";
        }
        cout << endl;

        if (row != 2)
            cout << " ____|____|____" << endl << "     |    |    " << endl;
    }
    cout << endl;
}

bool ticTacToe::isValidMove(int x, int y) const{
  // This step makes sure that the move called for is within the board range AND not already filled.
  if (0 <= x && x <= 2 && 0 <= y && y <= 2 && board[x][y] == ' ')
        return true;
  else
      std::cout << "Move out of bounds or already filled.\n" << endl;
        return false;
}

bool ticTacToe::getXOMove(char moveSymbol){
   int row,column;
   while(true)
   {
			cout << "Player " << moveSymbol << " enter move (row column): ";
			cin >> row >> column;
      cout << endl;
   
    if(isValidMove(row - 1,column - 1)){
		row--;
		column--;
		noOfMoves++;
        break;
       }
       else
           cout<<"Invalid move, please try another move.\n"<<endl;
   }

    board[row][column] = moveSymbol;
    displayBoard();
    status theGameStatus = gameStatus();

    if (theGameStatus == WIN){
        cout << "Player " << moveSymbol << " wins!\n" << endl;
        return true;
    }
    else if (theGameStatus == DRAW){
        cout << "This game is a Draw!\n" << endl;
        return true;
    }
    else
        return false;
}

status ticTacToe::gameStatus(){
    // Inspects rows for a win
    for (int row = 0; row < 3; row++)
        if (board[row][0] != ' ' && (board[row][0] == board[row][1]) && (board[row][1] == board[row][2]))
             return WIN;

    // Inspects columns for a win
    for (int column = 0; column < 3; column++)
        if (board[0][column] != ' ' && (board[0][column] == board[1][column]) && (board[1][column] == board[2][column]))
             return WIN;

    // Inspects diagonals for a win
    if (board[0][0] != ' ' && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
        return WIN;

    // Inspects diagonals for a win (this time the top right to bottom left)
    if (board[2][0] != ' ' && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
        return WIN;

    // Inspect for no wins and no Draw
    if (noOfMoves < 9)
        return CONTINUE;
    return DRAW;
}

void ticTacToe::reStart(){
   system("clear"); // Clears the screen for the new restarted game.
   cout<<"The game has restarted:\n";
   for(int row=0;row<3;row++)
   {
       for(int column=0;column<3;column++)
       {
           board[row][column]=' ';
       }
   }
   noOfMoves=0;
   play();
}

ticTacToe::ticTacToe(){
    // Initializes the game board
    for (int row = 0; row < 3; row++)
        for (int column = 0; column < 3; column++)
            board[row][column] = ' ';
    noOfMoves = 0;
}
