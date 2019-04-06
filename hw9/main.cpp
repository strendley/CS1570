//Programmer: Skylar Trendley  Date: 4/13/17
//Instructor: Clayton Price
//Section: CS1570A
//Description: This program builds a design for a town using classes.

#include "header.h"
#include "tailor.h"


int main()
{
  srand(time(NULL));
  int i = 0;
  
  town Springfield(TOWN_SIZE);        //create & initialize town
  tailor Millhouse("Millhouse");      //create & initialize tailor
  Springfield.placeTrees();           //create & place trees
  
  cout << "Here, Millhouse's journey begins in ";
  cout << "the middle of Springfield... " << endl;
  Millhouse.placeMiddle(Springfield); //Millhouse is placed in middle
  Springfield.printTown();            //Millhouse is printed in the middle
  Millhouse.printTailor();
  
  cout << "Oh no! Millhouse forgot his inhaler!" << endl;
  cout << "Millhouse's journey begins again, this time from ";
  cout << "his home at (2,3)..." << endl;
  Millhouse.placeMe(Springfield);  //Millhouse placed at (2,3).
  Springfield.printTown();        //Millhouse printed at (2,3).
  Millhouse.printTailor();

  
  while (i < 12)                //Millhouse walks random directions 12 times
  {
    Millhouse.randWalk(Springfield); 
    Springfield.printTown();
    Millhouse.printTailor();
    
    i++;
  }
  
  return 0;
}
