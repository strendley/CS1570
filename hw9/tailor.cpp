//Programmer: Skylar Trendley  Date: 4/13/17
//Instructor: Clayton Price
//Section: CS1570A
//Description: This program builds a design for a town using classes.

#include "header.h"
#include "tailor.h"

void tailor::placeMe(town &t)
{ 
  t.clearPrevious(x_coord, y_coord);

  x_coord = 2; //defaulted x position
  y_coord = 3; //defaulted y position
  
  t.placeTailor(x_coord, y_coord);
     
  return;
}

void tailor::placeMiddle(town &t)
{  
  x_coord = t.getSize() / 2;
  y_coord = x_coord;
  
  t.placeTailor(x_coord, y_coord);

  return;
}

void tailor::randWalk(town &t)
{
  int direction;
  int x = x_coord;
  int y = y_coord;
      
  direction = rand() % 4 + 1;
  
  if(direction == NORTH)
    y += STEPS_TAKEN;   //move 1 step north
  else if (direction == SOUTH)
    y -= STEPS_TAKEN;   //move 1 step south
  else if(direction == EAST)
    x += STEPS_TAKEN;   //move 1 step east
  else if(direction == WEST)
    x -= STEPS_TAKEN;   //move 1 step west
  
  if(t.checkSpace(x, y))
   {     
     t.clearPrevious(x_coord, y_coord);
     x_coord = x;
     y_coord = y;
     t.placeTailor(x_coord, y_coord);
   }
   
   else 
    cout << "Millhouse hit something!" << endl;

   
  return;
}

void tailor::printTailor()
{
  cout << name << " has $";
  cout << funds << " and ";
  
  if(isAlive)
    cout << "is alive at ";
  else
    cout << "has perished at ";
  
  cout << "(" << x_coord << ", " << y_coord << ").";
  cout << endl << endl;
  return;
}

