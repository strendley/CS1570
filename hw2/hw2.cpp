//Programmer: Skylar Trendley   Date: 2/1/2017
//File: hw2.cpp
//Class: CS1570 Section A
//Instructor: Clayton Price
//Description: Pill Calculator

#include <iostream>
using namespace std;

int main()
{
   //Declarations
   const float SOYMILK = 1.9;
   const float TATPOISON = 3.5;
   float cupsMilk;
   int numClasses;
   int hrsGaming;
   int numPills; //round down using casting
   bool tattoo;
   
   //Input
   cout << "Welcome to the Pill Calculator!" << endl;
   cout << "Please Enter Input for: " << endl;
   
   cout << "# Classes Studied: ";
   cin >> numClasses;
   
   cout << "# Hours Playing Video Games: ";
   cin >> hrsGaming;
   
   cout << "# Cups of Soymilk Consumed: ";
   cin >> cupsMilk;
   
   cout << "Did you wear a tattoo yesterday?";
   cout << " Input 1 for yes, 0 for no: ";
   cin >> tattoo;
   
   //Calculations
   numPills = (((static_cast<float>(numClasses) / hrsGaming)
               + (cupsMilk * SOYMILK)) + (tattoo * TATPOISON));
               
   //Output
   cout << "You will need to take " <<  numPills;
   cout << " pills today. Goodbye!" << endl;            

   return 0;
}

