//
/*
Programmer:  GEORGE C WARD
Instructor:  CLAYTON PRICE
Date:        19Apr2017
Section:     A
Description: Function definitions fot the class: town
             in Milhouses highwater program 
*/


#include "town.h"
#include "bully.h"

town::town(const short size, const short num_bullies)
{

  if(size > MAX_W || size < MIN_TOWN_SIZE)
  {
    m_townSize = MAX_W;
  }
  else if (size <= MAX_W && size >= MIN_TOWN_SIZE)
  {
    m_townSize = size;
  }
  clear();
  
  build(num_bullies);
}


void town::clear()
{
//---------Fills town with spaces-------------
  for(int i = 0; i < MAX_W; i++)
  {
    for(int j = 0; j < MAX_W; j++)
      m_townBoarders[i][j] = ' ';
  }

  return;
}

void town::build(const short num_bullies)
{
  short randLocX, randLocY;
  short randX, randY;
  short direction;
  short x, y;  
    
//----------Sets the boarders-----------------
  for(int i = 0; i < m_townSize; i++)
  {
    m_townBoarders[i][m_townSize-1] = 'W';
    m_townBoarders[i][0]            = 'W';
    m_townBoarders[m_townSize-1][i] = 'W';
    m_townBoarders[0][i]            = 'W';
  }
  
//---------------Places Houses---------------- 
  for(int i = 0; i < 20; i++)
  {
    randLocX = rand() % getTown();
    randLocY = rand() % getTown();
   
    while(checkPlace(randLocX,randLocY) != ' ')
    { 
      randLocX = rand() % getTown();
      randLocY = rand() % getTown();
    }
   
    placeInTown(randLocX, randLocY, HOUSE);

    x = randLocX;
    y = randLocY;
   
    do
    {
      direction = rand() % 4 + 1;
  
      if(direction == NORTH)
        y += 1;   //move north
      else if (direction == SOUTH)
        y -= 1;   //move south
      else if(direction == EAST)
        x += 1;   //move east
      else if(direction == WEST)
        x -= 1;   //move west
       
     }while(checkPlace(x, y) != ' ');
   
    randLocX = x;
    randLocY = y;
    placeInTown(randLocX, randLocY, HOUSE);       
}
//---------Place Bullies-----------------------
  for(int i = 0; i < num_bullies; i++)
    {
      randX = rand() % getTown();
      randY = rand() % getTown();
      while(checkPlace(randX,randY) != ' ')
      {
        randX = rand() % getTown();
        randY = rand() % getTown();
      }
      placeInTown(randX,randY,'B');
      cout << "Bully X " << randX << "Bully Y " << randY << endl; 
    }
  
  return;
}

ostream& operator << (ostream& out, const town& t) 
{
//----------Outputs the Boarders-------------
  out << "-";
  for (int i=1; i<t.m_townSize;i++)
    out<<"----";
  out<<"----"<<endl;
  for(int i = 0; i < t.m_townSize; i++)
  {
    for(int j = 0; j < t.m_townSize; j++)
    {
      out <<"| "<< t.m_townBoarders[j][i]<<' ';
    }
    out<<"|" << endl;
     for (int i=1; i<t.m_townSize;i++)
    out<<"----";
  out<<"----"<<endl;
  }
  
  return out;
}

//----places characters into the array
void town::placeInTown(const short x,const short y, const char c)
{
  if(x >= m_townSize || y >= m_townSize || x <= 0 || y <= 0)
  {
    m_townBoarders[m_townSize/2][m_townSize/2] = c;
  }
  else
    m_townBoarders[x][y] = c;
  return;

}
