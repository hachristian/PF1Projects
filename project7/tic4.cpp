
//---------------------------------------------------
// Purpose:     Implementation of the Tic4 class
//
// Author:      John Gauch - Created skeleton program.
//              Julio Sibrian - Completed implementation.
//---------------------------------------------------

#include "tic4.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

//---------------------------------------------------
// Constructor function
//---------------------------------------------------
Tic4::Tic4()
{
   ClearBoard();
}

//---------------------------------------------------
// Destructor function
//---------------------------------------------------
Tic4::~Tic4()
{
   // Intentionally empty
}

//---------------------------------------------------
// Clear the Tic4 board
//---------------------------------------------------
void Tic4::ClearBoard()
{
   // Initialize Tic4 board
   for (int c = 0; c < SIZE; c++)
   for (int r = 0; r < SIZE; r++)
      board[r][c] = ' ';
}

//---------------------------------------------------
// Set value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::SetBoard(const int row, const int col, const char player)
{
   // Error checking
   if ((row < 0) || (row >= SIZE) || 
       (col < 0) || (col >= SIZE) ||
       (board[row][col] != ' '))
      return false;

   // Set value of board
   board[row][col] = player;
   return true;
}

//---------------------------------------------------
// Get value of board at location [row][column] 
//---------------------------------------------------
bool Tic4::GetBoard(const int row, const int col, char & player)
{
   // Error checking
   if ((row < 0) || (row >= SIZE) || 
       (col < 0) || (col >= SIZE) ||
       (board[row][col] != ' '))
      return false;

   // Get value of board
   player = board[row][col];
   return true;
}

//---------------------------------------------------
// Check to see if player has won the game
//---------------------------------------------------
bool Tic4::CheckWin(const char player)
{
   // Check all the rows
   for (int r = 0; r < SIZE; r++)
   {
      // Count player pieces
      int count = 0;
      for (int c = 0; c < SIZE; c++)
         if (board[r][c] == player)
            count++;
      if (count == SIZE)
         return true;
   }

   // Check all the cols
   for (int c = 0; c < SIZE; c++)
   {
      // Count player pieces
      int count = 0;
      for (int r = 0; r < SIZE; r++)
         if (board[r][c] == player)
            count++;
      if (count == SIZE)
         return true;
   }

   // Check first diagonal
   int count = 0;
   for (int r = 0; r < SIZE; r++)
   {
      int c = r;
      if (board[r][c] == player)
         count++;
   }
   if (count == SIZE) 
      return true;
    
   // Check second diagonal
   count = 0;
   for (int r = 0; r < SIZE; r++)
   {
      int c = SIZE-1-r;
      if (board[r][c] == player)
         count++;
   }
   if (count == SIZE) 
      return true;
    
   // The player did not win
   return false;
}

//---------------------------------------------------
// Print the Tic4 board
//---------------------------------------------------
void Tic4::PrintBoard()
{
   // Draw column numbers
   cout << "\n     ";
   for (int c = 0; c < SIZE; c++)
      cout << c << "   ";
   cout << "\n";

   // Print the Tic4 board
   for (int r = 0; r < SIZE; r++)
   {
      // Draw dashed line
      cout << "   +";
      for (int c = 0; c < SIZE; c++)
         cout << "---+";
      cout << "\n";

      // Draw board contents
      cout << " " << r << " | ";
      for (int c = 0; c < SIZE; c++)
         cout << board[r][c] << " | ";
      cout << "\n";
   }

   // Draw dashed line
   cout << "   +";
   for (int c = 0; c < SIZE; c++)
      cout << "---+";
   cout << "\n\n";
}

//---------------------------------------------------
// Check if board is full
//---------------------------------------------------
bool Tic4::IsFull()
{
   return (board_count == SIZE * SIZE);
}

//---------------------------------------------------
// Simple AI
//---------------------------------------------------
bool Tic4::SimpleAI(const char player)
{
   bool move = false;
   for(int r = 0; r < SIZE; r++)
   {
      for(int c = 0; c < SIZE; c++)
      {
         if(move == false)
         {
            if(board[r][c] == ' ')
            {
            	cout << r << " " << c;
                board[r][c] = player;
                move = true;
                return true;
            }
         }
      }
   }
   return false;
}

//---------------------------------------------------
// Random AI
//---------------------------------------------------
bool Tic4::RandomAI(const char player)
{
   // providing a seed for srand
	srand(time(NULL));
   // initializing local variables
	int R = rand() % SIZE;
	int C = rand() % SIZE;
	bool move = false;
   // checking if the board is has an empty space
   for(int r = 0; r < SIZE; r++)
   {
      for(int c = 0; c < SIZE; c++)
      {
         if(board[r][c] == ' ')
         {
            move = true;
         }
      }
   }
   if(move == false)
   {
      return false;
   }
   move = false;
   // scanning the board
	while(move != true)
	{
		if(move == false)
		{
			if(board[R][C] == ' ')
			{
				cout << R << " " << C;
				board[R][C] = player;
				move = true;
            return true;
			}
			else
			{
				R = rand() % SIZE;
				C = rand() % SIZE;
			}
		}
	}
   return false;
}

//---------------------------------------------------
// Clever AI
//---------------------------------------------------
bool Tic4::CleverAI(const char player)
{
   bool move = false;
   // checking first diagnal
   for(int r = 0; r < SIZE; r++)
   {
      int c = r;
      if(move != true)
      {
         if(board[r][c] == ' ')
         {
            cout << r << " " << c;
            board[r][c] = player;
            move = true;
            return true;
         }
      }
   }
   // checking the other diagnal 
   for(int r = 0; r < SIZE; r++)
   {
      int c = SIZE - 1 - r;
      if(move != true)
      {
         if(board[r][c] == ' ')
         {
            cout << r << " " << c;
            board[r][c] = player;
            move = true;
            return true;
         }
      }
      
   }
   // checking rows
   for(int r = 0; r < SIZE; r++)
   {
      for(int c = 0; c < SIZE; c++)
      {
         if (move != true)
         {
            if(board[r][c] == ' ')
            {
               cout << r << " " << c;
               board[r][c] = player;
               move = true;
               return true;
            }
         }
      }
   }
   // checking cols
   for(int c = 0; c < SIZE; c++)
   {
      for(int r = 0; r <SIZE; r++)
      {
         if(move != true)
         {
            if(board[r][c] == ' ')
            {
               cout << r << " " << c;
               board[r][c] = player;
               move = true; 
               return true;
            }
         }
      }
   }
   return false;
}
//---------------------------------------------------
// Fancy AI
//---------------------------------------------------
bool Tic4::FancyAI(const char player)
{
   //seed for srandom
   srand(time(NULL));
   int foo = rand() % 3;

   cout << foo << endl;
   if(foo == 0)
   {
      this -> SimpleAI(player);
   }
   else if(foo == 1)
   {
     this -> RandomAI(player);
   }
   else if(foo == 2)
   {
      this -> CleverAI(player);
   }
    return true;
}
	

