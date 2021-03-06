//Programmer: Skylar Trendley     Date: 2/8/17
//File: hw3.cpp
//Class: cs1570 Section A
//Instructor: Clayton Price
//Description: Prescription Lens Generator

#include <iostream>
using namespace std;

int main()
{
  //Declarations
  const int MAX_EYE = 20;
  const int MIN_EYE = 1; 
  const int MAX_CHART = 9;
  const int MIN_CHART = 1;
  const int LOW_CHART = 2;
  const int MED_EYE = 6;
  const int LARGE_EYE = 11;
  const string CODE_P = "P";
  const string CODE_B = "B";
  const string CODE_C = "C";
  const string CODE_iN = "iN";
  const string CODE_Li = "Li";
  const string CODE_N = "N";
  const string CODE_Ke = "Ke";
  const string CODE_d = "d";
  const string CODE_ky = "ky";
  const string CODE_h = "h";
  const string CODE_ye = "ye";
  int start;
  int x1, x2, x;
  int eyeMeasure, chartReading;
  string name;
  string firstLetter, secondLetter, thirdLetter, fourthLetter;
    
  //Inputs & Greetings
  cout << "Please enter your name: ";
  cin >> name;
  cout << endl;
  cout << "Welcome, " << name << ", to the GLASS-O-MATIC!" << endl;
  cout << "Please provide the following inputs... " << endl;
  cout << endl;
   
  do
  {
    cout << "Enter the length of your right cornea (in mm): ";
    cin >> eyeMeasure;
       
  } while (eyeMeasure < MIN_EYE || eyeMeasure > MAX_EYE);
    
  do 
  {
    cout << "Enter your Snellen Chart reading results (by line): ";
    cin >> chartReading;
  } while (chartReading < MIN_CHART || chartReading > MAX_CHART);
    
  //Calculations
   
  //First letter of prescription
  if(eyeMeasure >= LARGE_EYE)
    firstLetter = CODE_C;
  else if(eyeMeasure >= MED_EYE)
    firstLetter = CODE_B;
  else
    firstLetter = CODE_P;
  
  //Second letter of prescription
  if(firstLetter == CODE_P)
    start = 1;
  else if(firstLetter == CODE_B)
    start = 2;
  else
    start = 3;
   
  x1 = ((start * 7919 + 104729)) % 101 + 150;
  x2 = ((x1 * 7919 + 104729)) % 101 + 150;
  x = (x1 + x2) / 2;
   
  if (x >= 150 && x <= 200)
    secondLetter = CODE_iN;
  else
    secondLetter = CODE_Li;
       
  //Third letter(s) of prescription
  if (chartReading == MIN_CHART)
    thirdLetter = CODE_N;
  else if (chartReading == LOW_CHART)
    thirdLetter = CODE_Ke;
  else
    thirdLetter = CODE_ye;
   
  //Fourth letter(s) of prescription
  if((firstLetter == CODE_P || firstLetter == CODE_B )
      && thirdLetter == CODE_N)
    fourthLetter = CODE_d;
  else if(firstLetter == CODE_C && thirdLetter == CODE_N)
    fourthLetter = CODE_ky;
  else if (secondLetter == CODE_iN && thirdLetter == CODE_P)
    fourthLetter = CODE_h;
  else
    fourthLetter = CODE_ye;
   
  //Output        
  cout << endl;
  cout << name << "--your prescription is: " 
       << firstLetter << secondLetter << thirdLetter << fourthLetter;
  cout << endl << "Please take these results to your nearest"
       << " lens grinder. Goodbye!" << endl;
  return 0;
}

