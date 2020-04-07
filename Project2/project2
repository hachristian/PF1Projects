


//---------------------------------------------------
// Purpose: experience input and output commands as well as if statements Project 2
// Author:  Julio Sibrian
//---------------------------------------------------



#include <iostream>

using namespace std;

int main()
{

    // declaring and initializing

    int meat = 0;
    int veg = 0;
    int pasta = 0;
    int potatoes = 0;
    int chocolate = 0;
    int fruit = 0;
    double budget = 0.0;

    // requesting input from user
   cout << "Welcome to John's kitchen!" << endl;
   cout << "How much do you like meat on scale 1-100 ";
   cin >> meat;

   cout << "How much do you like vegetables on scale 1-100 ";
   cin >> veg;

   cout << "How much do you like pasta on scale 1-100 ";
   cin >> pasta;

   cout << "How much do you like potatoes on scale 1-100 ";
   cin >> potatoes;

   cout << "How much do you like chocolate on scale 1-100 ";
   cin >> chocolate;

   cout << "How much do you like fruit on scale 1-100 ";
   cin >> fruit;

   cout << "Finally, what is your budget? (dollars) ";
   cin >> budget;

   // if statements correcting incorrect input

   if (meat < 1)
       {
           meat = 1;
       }
   if (veg < 1)
       {
           veg = 1;
       }
  if (pasta < 1)
       {
           pasta = 1;
       }
  if (potatoes < 1)
       {
           potatoes = 1;
       }
  if (chocolate < 1)
       {
           chocolate = 1;
       }
  if (fruit < 1)
       {
           fruit = 1;
       }


   if (meat > 100)
       {
           meat = 100;
       }
   if (veg > 100)
       {
           veg = 100;
       }
   if (pasta > 100)
       {
           pasta = 100;
       }
   if (potatoes > 100)
       {
           potatoes = 100;
       }
   if (chocolate > 100)
       {
           chocolate = 100;
       }
   if (fruit > 100)
       {
           fruit = 100;
       }

 // variables for the meal
    string appetizer;
    string mainCourse;
    string desert;


     // if statements figuring out appetizer

     if (meat > veg)
      {
         appetizer = "Chicken Wings";
      }
     if (meat < veg)
     {
       appetizer = "Garden Salad";
     }

     if ((meat <= 10) && (veg <= 10))
     {
         appetizer = "Garlic bread";
     }
     if (meat == veg)
     {
         appetizer = "Garlic bread";
     }
     // if statements figuring out mainCourse

    if (meat && potatoes < meat && pasta ){
        mainCourse = "Spaghetti and meat sauce";
    }
    else {
        mainCourse = "Steak and potatoes";
    }
    if (veg > meat){
        mainCourse = "Pasta primavera";
    }
     else if (veg == meat){
        mainCourse = "Cheese omelet";
    }
     if((meat <= 10) && (veg <= 10)){
        mainCourse = "Cheese omelet";
    }

    // deciding which desert to take with if statements

    if (fruit > chocolate){
        desert = "Fruit";
    }
    else if (fruit < chocolate){
        desert = "Chocolate";
    }
    else if ( fruit = chocolate){
        desert = "Ice Cream";
    }
    else {
        desert = "Ice Cream";
    }
    if (fruit <= 10 && chocolate <= 10){
        desert = "Ice Cream";
    }

    // now for the budget gonna make if statements for it
     bool rich;
     bool middle;
     bool poor;
     bool broke;
     cout << endl << "Your chef has chosen your meal!" << " they've selected";
    if (budget >= 20){
        budget = rich;
         cout << endl <<appetizer << " as an appetizer, " << mainCourse <<
         " as your main course, and " << desert << " as your tasty desert!";
    }
    else if (budget >= 15){
        budget = middle;
        cout << " " << appetizer << " as an appetizer and " << mainCourse << " as your delicious main Course!";
    }
    else if (budget >= 10){
        budget = poor;
        cout << mainCourse << " as a main Course!";
    }
    else {
        budget = broke;
        cout << "... Wait a minute! Come back with some more money!";
    }
    // ringing up the bill
   double total = 0;
   double tax = 0.070;

 if (budget == broke){
    cout << "";
 }
 else if (budget != broke) {
    cout << endl << endl<< "Now, that will be ";

    if (budget == rich){
        total = 20 + (20 * tax) + 0.00;
        cout << "$" << total << " with tax." << endl;
    }
    else if (budget == middle){
        total = 15 + (15 * tax) + 0.00;
        cout << "$" << total << " with tax." << endl;
    }
    else {
        total = 10 + (10 * tax) + 0.00;
        cout << "$" << total << " with tax." << endl;
    }


 }

    return 0;
}
