// Include statements
#include <cstdlib>
#include <iostream>
using namespace std;
   
// Main function
int main() 
{
   // Declare variables
   int *data;
   int number = 0;

   // Get user input
   cout << "Enter number of values:\n";
   cin >> number;
   if (number < 0)
      number = 0;
   data = new int[number];

   // Process data
   cout << "number = " << number << endl;
   for (int i = 0; i < number; i++)
   {
      data[i] = random() % 100;
      cout << data[i] << " ";
   }
   cout << endl;
   cout << "number = " << number << endl;
   
   return 0 ;
}