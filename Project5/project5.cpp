//---------------------------------------------------------------------------
// Purpose:  To simulate the lives of rabbits and foxes in the forest.
//
// Author:   John Gauch - Created skeleton program.
// Author:   Julio Sibrian  - Completed implementation.
//
// Change:   Fixed animal loss bug in move_board function -- 11/03 JMG
// Change:   Fixed infinite loop bug in choose_move function -- 11/03 JMG
// Change:   Removed second board from main function -- 11/03 JMG
// Change:   Printed animal counts in draw_board -- 11/03 JMG
//---------------------------------------------------------------------------

#include <cstdlib>
#include <iostream>
using namespace std;

// Global Variables
const int SIZE = 20;

//---------------------------------------------------------------------------
// Purpose: To initialize the board with rabbits and foxes.
// Inputs:  The board, the number of rabbits, the number of foxes.
// Outputs: None
//---------------------------------------------------------------------------
void init_board(char board[SIZE][SIZE],
                const int num_rabbits, const int num_foxes)
{
   // Init board
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
         board[r][c] = ' ';

   // Add rabbits at random locations
   int count = 0;
   while (count < num_rabbits)
   {
      int r = random() % SIZE;
      int c = random() % SIZE;
      if (board[r][c] == ' ')
      {
         board[r][c] = 'R';
         count++;
      }
   }

   // Add foxes at random locations
   count = 0;
   while (count < num_foxes)
   {
      int r = random() % SIZE;
      int c = random() % SIZE;
      if (board[r][c] == ' ')
      {
         board[r][c] = 'F';
         count++;
      }
   }
}

//---------------------------------------------------------------------------
// Purpose: To draw the board with rabbits and foxes.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void draw_board(char board[SIZE][SIZE])
{
   system("sleep 1");
   system("clear");

   // Initialize animal counts
   int num_rabbits = 0;
   int num_foxes = 0;

   // Draw top of board
   cout << "+";
   for (int c = 0; c < SIZE; c++)
      cout << "--";
   cout << "+\n";

   // Draw board
   for (int r = 0; r < SIZE; r++)
   {
      cout << "|";
      for (int c = 0; c < SIZE; c++)
      {
         cout << board[r][c] << " ";

         // Increment animal counts
         if (board[r][c] == 'R')
            num_rabbits++;
         if (board[r][c] == 'F')
            num_foxes++;
      }
      cout << "|\n";
   }

   // Draw bottom of the board
   cout << "+";
   for (int c = 0; c < SIZE; c++)
      cout << "--";
   cout << "+\n";

   // Print animal counts
   cout << "Number of rabbits: " << num_rabbits << endl;
   cout << "Number of foxes:   " << num_foxes << endl;
}

//---------------------------------------------------------------------------
// Purpose: To choose a random direction to move.
// Inputs:  The board and the current row and column location.
// Outputs: The new row and column location on the board.
//---------------------------------------------------------------------------
void choose_move(char board[SIZE][SIZE],
                 const int row, const int col, int &new_row, int &new_col)
{
   // Loop until a valid move is found
   for (int loop = 0; loop < 10; loop++)
   {
      // Take a random step to adjacent location
      new_row = row + (random() % 3) - 1;
      new_col = col + (random() % 3) - 1;

      // Check if location is in bounds and board is empty
      if ((new_row >= 0) && (new_row < SIZE) &&
          (new_col >= 0) && (new_col < SIZE) &&
          (board[new_row][new_col] == ' '))
         return;
   }

   // Use current location if other move is possible
   new_row = row;
   new_col = col;
}

//---------------------------------------------------------------------------
// Purpose: To move the rabbits and foxes on the board.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void move_animals(char board[SIZE][SIZE])
{
   // Loop over board to find and move animals
   int new_row = 0;
   int new_col = 0;
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
         if (isupper(board[r][c]))
         {
            // Find empty location for move
            choose_move(board, r, c, new_row, new_col);

            // Move animal into empty location
            board[new_row][new_col] = tolower(board[r][c]);

            // Make old location empty
            if ((new_row != r) || (new_col != c))
               board[r][c] = ' ';
         }

   // Loop over board to change letters to upper case
   for (int r = 0; r < SIZE; r++)
      for (int c = 0; c < SIZE; c++)
         board[r][c] = toupper(board[r][c]);
}

//---------------------------------------------------------------------------
// Purpose: To reproduce the rabbits and foxes on the board.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void reproduce_animals(char board[SIZE][SIZE])
{
   for (int r = 0; r < SIZE; r++)
   {
      //declaring local variables
      int R = random() % SIZE;
      int C = random() % SIZE;
      int coin = random() % 2;
      // scanning the array with a for loop
      for (int c = 0; c <= SIZE; c++)
      {
         // checking if a rabbit is to the right of one
         // making sure i dont go out of bounds
         if (c + 1 < SIZE)
         {
            if (board[r][c] == 'R' && board[r][c + 1] == 'R')
            {
               if (board[R][C] == ' ')
               {
                  board[R][C] = 'R';
               }
            }
         }

         // checking if a Fox is above another fox
         // making sure i dont go out of bounds
         if (r + 1 < SIZE)
         {
            if (board[r][c] == 'F' && board[r + 1][c] == 'F')
            {
               if (coin == 1)
               {
                  if (board[R][C] == ' ')
                  {
                     board[R][C] = 'F';
                  }
               }
            }
         }
      }
   }
}
//---------------------------------------------------------------------------
// Purpose: To battle the rabbits and foxes on the board.
// Inputs:  The board.
// Outputs: None
//---------------------------------------------------------------------------
void animal_battle(char board[SIZE][SIZE])
{
   //scanning through array
   for (int r = 0; r < SIZE; r++)
   {
      for (int c = 0; c < SIZE; c++)
      {
         //declaring variable to calculate the percentage chance.
         int foo;
         foo = random() % 100;
         // checking if there is a rabbit to the right of the fox
         if (c + 1 < SIZE)
         {
            if (board[r][c] == 'F' && board[r][c + 1] == 'R')
            {
               if (foo < 10)
               {
                  board[r][c + 1] = ' ';
               }
            }
         }
         // checking if there's a rabbit to the left of the fox
         if (c - 1 > SIZE)
         {
            if (board[r][c] == 'F' && board[r][c - 1] == 'R')
            {
               if (foo < 10)
               {
                  board[r][c - 1] = ' ';
               }
            }
         }
         // checking if there's a rabbit above the fox
         if (r + 1 < SIZE)
         {
            if (board[r][c] == 'F' && board[r + 1][c] == 'R')
            {
               if (foo < 10)
               {
                  board[r + 1][c] = ' ';
               }
            }
         }
         // checking if ther's a rabbit below the fox
         if (r - 1 > SIZE)
         {
            if (board[r][c] == 'F' && board[r - 1][c] == 'R')
            {
               if (foo < 10)
               {
                  board[r - 1][c] = ' ';
               }
            }
         }
      }
   }
}
//---------------------------------------------------------------------------
// Purpose: The main program.
// Inputs:  None.
// Outputs: None.
//---------------------------------------------------------------------------
int main()
{
   // Seed the random number generator
   srandom(time(NULL));

   // Prompt user
   cout << "Welcome to the fox and rabbit simulation\n\n";
   int num_rabbits = 0;
   cout << "Enter the number of rabbits: ";
   cin >> num_rabbits;
   int num_foxes = 0;
   cout << "Enter the number of foxes: ";
   cin >> num_foxes;
   int num_steps = 0;
   cout << "Enter the number of simulation steps: ";
   cin >> num_steps;

   // Initialize board
   char board[SIZE][SIZE];
   init_board(board, num_rabbits, num_foxes);

   // Draw the board
   draw_board(board);
   cout << "Start " << endl;

   // Run the simulation
   for (int step = 1; step <= num_steps; step++)
   {
      // Move the animals
      move_animals(board);

      // reproduce animals
      reproduce_animals(board);

      // animal battle
      animal_battle(board);

      // Draw the board
      draw_board(board);
      cout << "Step " << step << endl;
   }
   return 0;
}