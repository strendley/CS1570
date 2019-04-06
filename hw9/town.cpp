//Programmer: Skylar Trendley  Date: 4/13/17
//Instructor: Clayton Price
//Section: CS1570A
//Description: This program builds a design for a town using classes.

#include "header.h"
#include "town.h"

town::town(const short gridSize)
{
  if(gridSize < MIN_SIZE || gridSize > MAX_SIZE)
    townSize = MAX_SIZE;
  else
    townSize = gridSize;
    
  clear();
  build(); 
}

void town::clear()
{
  for(int i = 0; i < townSize; i++)
  {
    for(int j = 0; j < townSize; j++)
    {
      theTown[i][j] = EMPTY_SPACE;
    }
  }
  return;
}

void town::build()
{
  for(int i = 0; i < townSize; i++)
  {
    for(int j = 0; j < townSize; j++)
    {
      if(i == 0 || j == 0 || i == townSize-1 || j == townSize-1)
        theTown[i][j] = WALL;
    }
  }
  return;
}

void town::placeTailor(const short x, const short y)
{  
  theTown[x][y] = DEFAULT_SYMBOL;
       
  return;
}

void town::clearPrevious(const short x, const short y)
{
  theTown[x][y] = EMPTY_SPACE;
  return;
}

bool town::checkSpace(const short x, const short y)
{
  bool isEmpty;
   
  if(theTown[x][y] == EMPTY_SPACE)
    isEmpty = true;
    
  return isEmpty;   
  
}

void town::placeTrees()
{
  theTown[1][2] = TREE;    
  theTown[1][5] = TREE;    
  theTown[2][5] = TREE;    
  theTown[3][2] = TREE;
  theTown[4][1] = TREE;
  theTown[4][3] = TREE;
  
  return; 
}

void town::printTown()
{
  for(int i = 0; i < townSize-1; i++)
    cout << "----";
  cout << "----" << endl;
  
  for(int i = 0; i < townSize; i++)
  {
    for(int j = 0; j < townSize; j++)
    {
      cout <<" | " << theTown[i][j];
    }
    cout << " | " << endl;
   
   for(int i = 0; i < townSize-1; i++)
    cout << "----";
  cout << "----" << endl;

  }
     
  return;
}
