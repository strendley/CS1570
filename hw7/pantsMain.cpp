//Programmer: Skylar Trendley    Date: 3/18/2017
//Instructor: Clayton Price
//Class: CS1570A
//File: pantsMain.cpp
//Description: Generates random store inventory & makes a sale
//             based upon user waist input & color preference.
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "pantsShop.h"
using namespace std;


int main()
{
  srand(time(NULL));
  int custWaist, colorChoice, inSeamChoice;
  char customers;
  bool isMoreCustomers = true;
	
  pant pants[MAX_PANTS];
  pantsOfSize inventory[MAX_SIZES];

  //Set Up
  greeting();
  generatePants(pants);
  sort(pants);
  print(pants);
  indexStock(inventory);
  sortStock(pants, inventory);

  cout << "  --------------------------------------------------" << endl;
  cout << endl;

  //User Input Interaction
  do
  {
    cout << "Please enter your waist measurement: ";
    cin >> custWaist;
    
    if (custWaist < MIN_WAIST || custWaist > MAX_WAIST)
      {
        cout << "Sorry, we only sell for waist sizes 20-40. ";
	cout << "We suggest you find another store." << endl;
      }
    else
    {
       findMatch(inventory, custWaist);
       cout << "Enter your choice (-1 for none): ";
       cin >> colorChoice;
       
       if(colorChoice != -1)
       {
               
         chooseInseam(pants, colorChoice, custWaist);
         cout << "Enter your inSeam choice: ";
         cin >> inSeamChoice;

         makeSale(pants, inSeamChoice, custWaist);
         adjustStock(pants, inventory, colorChoice, inSeamChoice, custWaist);
       }
       
       else if(colorChoice > MAX_NUM_COLORS)
         cout << "Sorry, that option is not available." << endl;
       
       else
         cout << "Sorry we couldn't find your perfect color!" << endl;
    }
     

    do
    {
      cout << "Are there more customers? (y/n): ";
      cin >> customers;
      
      if (customers == 'y')
        isMoreCustomers = true;
      else if (customers == 'n')
        isMoreCustomers = false;
      else
        cout << "Sorry, we didn't get that." << endl;
    } while (customers != 'y' && customers != 'n');

  } while (isMoreCustomers);

  cout << endl;
  cout << "-------CLOSED FOR THE DAY-------" << endl;

  return 0;
}
