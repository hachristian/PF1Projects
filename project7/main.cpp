
//---------------------------------------------------
// Purpose:     Main program for the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              Julio Sibrian - Completed implementation.
//---------------------------------------------------

#include "tic4.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//---------------------------------------------------
// Main program to play Tic4 game
//---------------------------------------------------
// function to get location
void Getlocation(int &row, int &col)
{
	row = 0;
	col = 0;
	bool entry = false;
	cin >> row >> col;
	while(entry != true)
	{
		if(row <= 3 && col <= 3)
		{
			entry = true;
		}
		else
		{
			cout << "Incorrect range, please enter numbers between 0 and 3. ";
			cin >> row >> col;
		}
	}
}
// function for restarting the game if necessary
void PlayAgain(Tic4 &board, bool &win, int &move)
{
	string answer;
	cout << endl << "Would you like to play again? y/n ";
	cin >> answer;
	if (answer == "y" || answer == "Y")
	{
		board.ClearBoard();
		move = 0;
	}
	else if(answer == "n" || answer == "N")
	{
		cout << endl << "Thanks for playing!" << endl;
		win = true;
	}
	else if (answer == "yes" || answer == "Yes")
	{
		board.ClearBoard();
		move = 0;
	}
	else if(answer == "no" || answer == "No")
	{
		cout << endl << "Thanks for playing!" << endl;
		win = true;
	}
	else
	{
		cout << "Please enter y or n ";
		PlayAgain(board, win, move);
	}
}
//function to check if location has been taken
void CheckLocation(Tic4 board, int & row, int & col, char player)
{
	bool check = false;
	while(check != true)
	{
        if(board.GetBoard(row, col, player) == true)
		{
			row = row;
			col = col;
			check = true;
			break;
		}
		else if(board.GetBoard(row, col, player) == false)
		{
			cout << "Location has been taken, please choose another.";
			Getlocation(row, col);
			CheckLocation(board, row, col, player);		
		}
	}
}

int main()
{
	// initializing local variables
	bool win = false;
	bool multi = false;
	bool check = false;
	int row = 0;
	int col = 0;
	int move = 0;
	int numPlayers = 0;
	char player1 = 'X';
	char player2 = 'O';
	Tic4 board;
	// asking for number of players
	cout << "Welcome to tic tac toe." << endl;
	cout << "How many players? 1 or 2? ";
	cin >> numPlayers;
	// checking if they are within range
	while(check != true)
	{
		if(numPlayers == 1 || numPlayers == 2)
		{
			check = true;
		}
		else
		{
			cout << "Please choose 1 or 2 players!" << endl;
			cin >> numPlayers;
		}
	}
	if(numPlayers == 2)
	{
		multi = true;
	}
	board.PrintBoard();
	// game loop
	while(win != true)
	{
		cout << "Player 1's turn. ";
		// function to get rows and columns
		Getlocation(row, col);
		// checking if location has been taken
		CheckLocation(board, row, col, player1);
		board.SetBoard(row, col, player1);
		board.PrintBoard();
		move++;
		//checking if player 1 won
		board.CheckWin(player1);
		if(board.CheckWin(player1) == true)
		{
			cout << "Player 1 Wins!" << endl;
			PlayAgain(board, win, move);
			if(win == true)
			{
				break;
			}
		}
		// max moves exits the while loop
		if(move == 16 && win != true)
		{
			cout << "Cat!";
			PlayAgain(board, win, move);
			if(win == true)
			{
				break;
			}
		}

		cout << "Player 2's turn. ";
		// checking if one or two players
		if(multi == true)
		{
			// function to get rows and columns reduces clutter
			Getlocation(row, col);
			// check if the location is taken
			CheckLocation(board, row, col, player2);
			board.SetBoard(row, col, player2);
			board.PrintBoard();
			move++;
		}
		else
		{
			board.FancyAI(player2);
			board.PrintBoard();
			move++;
		}
		// checking if player 2 won
		board.CheckWin(player2);
		if(board.CheckWin(player2) == true)
		{
			cout << "Player 2 Wins!" << endl;
			PlayAgain(board, win, move);
		}
		// max moves exits the while loop
		if(move == 16 && win != true)
		{
			cout << "Cat!";
			PlayAgain(board, win, move);
		}
	}
    return 0;
}