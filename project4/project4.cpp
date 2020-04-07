//------------------------------------------------------------
// Purpose: To implement an interactive horoscope generator.  
//          The user will enter their birthdate and answer a few
//          questions, and the program will print some advice.
//
// Author:  John Gauch - Created skeleton program.
// Author:  ADD YOUR NAME HERE - Finished implementation of program.
//------------------------------------------------------------
#include <cstdlib>
#include <iostream>
using namespace std;

//------------------------------------------------------------
// Purpose: To prompt the user to enter their birthdate.
// Input:   None.
// Output:  The user's birth year, month, day.
//------------------------------------------------------------
void GetBirthDate(int & year, string & month, int & day)
{
   // Prompt user for birth year
   year = 0;
   while ((year < 1900) || (year > 2019))
   {
      cout << "Enter the year you were born [1900..2019]: ";
      cin >> year;
   }

   // Prompt user for birth month
   month = "";
   while (month != "Jan" && month != "Feb" && month != "Mar" && 
          month != "Apr" && month != "May" && month != "Jun" && 
          month != "Jul" && month != "Aug" && month != "Sep" && 
          month != "Oct" && month != "Nov" && month != "Dec")
   {
      cout << "Enter the month you were born [Jan..Dec]: ";
      cin >> month;
   }

   // Prompt user for birth day
   day = 0;
   while ((day < 1) || (day > 31))
   {
      cout << "Enter the day you were born [1..31]: ";
      cin >> day;
   }
}

//------------------------------------------------------------
// Purpose: To calculate the user's karma.
// Input:   None.
// Output:  The user's karma score.
//------------------------------------------------------------
int GetKarma()
{
   int answer = 0;
   cout << "How many people have you said hello to today? ";
   cin >> answer;
   
   // Silly karma calculation
   if (answer <= 0)
      return 0;
   else if (answer == 42)
      return 100;
   else 
      return (answer / 2) + (random() % 5);
}

//------------------------------------------------------------
// Purpose: Calculate the user's astrological sign.
// Input:   The user's birth month, day.
// Output:  The user's astrological sign.
//------------------------------------------------------------
string GetSign(const string month, const int day)
{
   if ((month == "Mar" && day >= 21) || (month == "Apr" && day <= 20))
      return "Aries";
   if ((month == "Apr" && day >= 21) || (month == "May" && day <= 21))
      return "Taurus";
   if ((month == "May" && day >= 22) || (month == "Jun" && day <= 21))
      return "Gemini";
   if ((month == "Jun" && day >= 22) || (month == "Jul" && day <= 22))
      return "Cancer";
   if ((month == "Jul" && day >= 23) || (month == "Aug" && day <= 22))
      return "Leo";
   if ((month == "Aug" && day >= 23) || (month == "Sep" && day <= 23))
      return "Virgo";
   if ((month == "Sep" && day >= 24) || (month == "Oct" && day <= 23))
      return "Libra";
   if ((month == "Oct" && day >= 24) || (month == "Nov" && day <= 22))
      return "Scorpio";
   if ((month == "Nov" && day >= 23) || (month == "Dec" && day <= 21))
      return "Sagittarius";
   if ((month == "Dec" && day >= 22) || (month == "Jan" && day <= 20))
      return "Capricorn";
   if ((month == "Jan" && day >= 21) || (month == "Feb" && day <= 19))
      return "Aquarius";
   if ((month == "Feb" && day >= 20) || (month == "Mar" && day <= 20))
      return "Pisces";
   return "";
}

//------------------------------------------------------------
// Purpose: Romance prediction
// Input:   The user's karma score.
// Output:  Prediction message.
//------------------------------------------------------------
string Romance(const int karma)
{
   int choice = (karma * 17) % 5;
   string message = "";
   switch(choice)
   {
   case 0:
      message = "Maybe your date would like to see a romantic comedy?";
      break;
   case 1:
      message = "I think it is singles night at the local pub.";
      break;
   case 2:
      message = "You should sit by the fire and read a good romance novel.";
      break;
   case 3:
      message = "Searching online for the perfect date seldom works.";
      break;
   case 4:
      message = "Love is not in the air tonight, time to play video games.";
      break;
   default:
      message = "Romance prediction is impossible.";
      break;
   }
   return message;
}

//------------------------------------------------------------
// Purpose: Money prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
void Money(const int year, string & message)
{
   int choice = (2019 - year) / 10;
   switch(choice)
   {
   case 0:
      message = "Ask your parents for their spare change.";
      break;
   case 1:
      message = "This is a good time to your parents for a bigger allowance.";
      break;
   case 2:
      message = "You can save more money by buying less beer.";
      break;
   case 3:
      message = "Try to save a little extra for a down payment on a house.";
      break;
   case 4:
      message = "Yikes, your children's tuition bills are due soon.";
      break;
   default:
      message = "Money prediction is impossible.";
      break;
   }
}

//------------------------------------------------------------
// Purpose: Job prediction
// Input:   The user's birth year.
// Output:  Prediction message.
//------------------------------------------------------------
string Job(const int day, const int karma)
{
   string message = "";
   if ((day < 15) && (karma > 5))
      message = "Your boss looks generous today, time to ask for a raise.";
   else if ((day > 15) && (karma < 5))
      message = "Prepare for bad news, your company profits are down.";
   else if ((day == 15) && (karma == 5))
      message = "Bad news, your company is declaring bankruptcy.";
   else if (karma > day)
      message = "Great news, your company just went public!";
   else if (karma <= day)
      message = "It looks like a chance for some overtime.";
   else
      message = "Money prediction is impossible.";
   return message;
}

//------------------------------------------------------------
// Purpose: Family prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
string family(const int year, const int karma){
   string message;
   if (year == 1969 && karma > 0){
      message = "You will set the world record for the biggest family in the world.";
   }
   else if(year < 1995 && karma <= 2){
      message = "You will have no wife and kids";
   }
   else if(year < 1995 && karma > 2){
      message = "You will have a wife and no kids";
   }
   else if(year > 1995 && karma <= 2){
      message = "You will have no wife and 1 kid";
   }
   else if(year > 1995 && karma > 2){
      message = "You will have a wonderful wife and two very successful kids";
   }
   else {
      message = "You will adopt a turtle that you will spend the rest of your life with.";
   }
   return message;
}

//------------------------------------------------------------
// Purpose: Health prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
string Health(const string month, const int day, const int year){
   string message;
   if(month == "Jul" && day == 13 && year == 1996){
      message = "You might want to start going to the gym because if you dont you'll grow a beer belly!";
   }
   else if (month == "Apr" && day <= 14){
      message = "Very Healthy future ahead!";
   }
   else if (month == "Jan" && day == 1){
      message = "Don't forget to get the flu shot every flu season!";
   }
   else if (month == "Feb" && day == 31){
      message = "You will be immortal.";
   }
   else if (month == "Dec" && day <= 23){
      message = "Don't go out on days that have a 7 because you'll catch a cold!";
   }
   else  {
      message = "Make sure to stock up on sick days.";
   }
   return message;

}

//------------------------------------------------------------
// Purpose: Silly prediction
// Input:   TO BE ADDED 
// Output:  Prediction message.
//------------------------------------------------------------
string Silly(const int karma, const int day, const string month){
   string message;
   if (karma > 2 && month == "Jul" && day == 13 ){
      message = "A random stranger will suddenly become your best friend.";
   }
   else if (karma <= 2 && month == "Apr" && day < 23){
      message = "You will lose all your money in one go.";
   }
   else if (karma > 2 && month == "Nov" && day < 9){
      message = "Look in your mailbox every tuesday there's a 20 percent chance that there's a taco there.";
   }
   else if (karma <= 2 && month == "Mar" && day > 18){
      message = "If you run into a black cat make sure you raise it as your own or you will have bad luck.";
   }
   else if (karma <= 2 && day > 23) {
      message = "If you smell vanilla at a bakery that bakery is corrupt and cursed run away!";
   }
   else if (karma > 2 && day < 12){
      message = "If you see an old lady running from an alligator dont help its a trap!";
       
   }
   else if(day == 13){
       message = "Make sure to turn the lights off and on 3 times in a row  before going to sleep.";
   }
   else {
       message = "If you step on a crack dont worry you're immune to breaking your mothers back.";
   }

   return message;
}
//------------------------------------------------------------
// Purpose: Print user's horoscope.
// Input:   The user's birth year, month, day, karma.
// Output:  None.
//------------------------------------------------------------
void PrintHoroscope(const int year, const string month, 
   const int day, const int karma)
{
   // setting local variables 
   string sign;
   string romance;
   string moneymsg;
   string job;
   string familymsg;
   string health;
   string silly;
   // Print user's sign
   sign = GetSign(month, day);
   cout << "Your sign is " << sign << endl;
   // Print romance prediction
   romance = Romance(karma);
   cout << "Romance prediction: " << romance << endl;
   // Print money prediction
   Money(year, moneymsg);
   cout << "Money prediction: " << moneymsg << endl;
   // Print job prediction
   job = Job(day, karma);
   cout << "Job prediction: " << job << endl;
   // Print family prediction
   familymsg = family(year, karma);
   cout << "Family prediction: " << familymsg << endl;
   // Print health prediction
   health = Health(month, day, year);
   cout << "Health prediction: " << health << endl;
   // Print silly prediction
   silly = Silly(karma, day, month);
   cout << "An important prediction: " << silly << endl;
}

//------------------------------------------------------------
// Purpose: The main program.
// Input:   None.
// Output:  None.
//------------------------------------------------------------
int main()
{
   // Initialize random number generator
   srandom(time(NULL));

   // Local variables
   int year, day;
   string month;
   int karma;

   // Get user's birthday
   GetBirthDate(year, month, day);
   // Get user's karma points
  karma =  GetKarma();
   // Print horoscope
  PrintHoroscope(year, month, day, karma);
   
}