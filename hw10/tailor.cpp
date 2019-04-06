/*
Programmer:  GEORGE C WARD
Instructor:  CLAYTON PRICE
Date:        19Apr2017
Section:     A
Description: Function definiton file for the
             class tailor: 
*/

#include "town.h"
#include "tailor.h"
#include "bully.h"

tailor::tailor(const string name, const char letter)
{
//assigns values to the object tailor's member vars.
  m_tailorName     = name;
  m_fundsAvailable = rand() %MIN_MONEY + MIN_MONEY;
  m_living         = LIVING;
  m_repChar        = letter;
  m_numPants       = START_PANTS;
  m_health         = START_HEALTH;
  m_posX           = START_X;
  m_posY           = START_Y;
}

ostream& operator << (ostream& os, const tailor& t)
{
  t.m_living == true?

/*terinary opperator for outputting characters information.*/

    os << t.m_tailorName << " is alive at (" << t.m_posX << "/" << t.m_posY
       << ") with $" << t.m_fundsAvailable << " and health: " << t.m_health:
    os << t.m_tailorName << " is dead at (" << t.m_posX << "/" << t.m_posY
       << ") with $" << t.m_fundsAvailable << " and health: " << t.m_health;

  return os;
}

void tailor::placeMe(town& t)
{
//sets location the center of the town if inputs are over the towns
//max value.
  short randX = rand()%t.getTown();
  short randY = rand()%t.getTown();
  while(t.checkPlace(randX,randY) != ' ')
  {
    randX = rand()%t.getTown();
    randY = rand()%t.getTown();
  }
  setLocX(randX);
  setLocY(randY);
  t.placeInTown(m_posX,m_posY,m_repChar);
    
  return;
}

bool tailor::isNearHouse(town &t)
{
  bool isNear;
  
  if((t.checkPlace(m_posX-1,m_posY) == 'H') ||
     (t.checkPlace(m_posX+1,m_posY) == 'H') ||
     (t.checkPlace(m_posX,m_posY+1) == 'H') ||
     (t.checkPlace(m_posX,m_posY-1) == 'H'))
    isNear =  true;
     
  else
    isNear = false;
    
  return isNear;     
}

bool tailor::successfulSale()
{
  int randChance;
  bool success;
   
  randChance = rand() % 100 + 1;
  
  if(randChance <= 70 && m_numPants > 0)  //eventually will check for if loc == true
    success = true;
    
  else
    success = false;
    
  return success;    
}

void tailor::randWalk(town& t,bully& b, int stuffhit)
{
//variables to control loop and to count objects hit while in loop
  short xPos      = m_posX;
  short yPos      = m_posY;
  int   randMove  = 0;
  short punchProb = rand() % 100;
  short percentCut = 100/b.getPower();
  short randX = rand()%t.getTown();
  short randY = rand()%t.getTown();

 
//----Fills in previously occupied space with ' '.   
  t.placeInTown(m_posX,m_posY,' ');

  while((xPos==m_posX) && (yPos==m_posY))
  {
   //-----Randomly chooses a movement------ 
    randMove = rand() % DIRECTION;

   //----Move tailor about and counts objects hit------  
   switch(randMove)
   {

//MOVES LEFT
     case LEFT:
       if(t.checkPlace(m_posX-1,m_posY) == ' ')
       {  
         cout << "Before X: " << m_posX << " Y: " << m_posY << endl;
         m_posX -= 1;
         cout << "After X: " << m_posX << " Y: "<< m_posY << endl;
         t.placeInTown(m_posX,m_posY,m_repChar);
       }
       
       if(isNearHouse(t) == true && successfulSale() == true)
       {
         m_numPants -= 1;
         m_fundsAvailable += 10;
       } 
       
       break;

//MOVES RIGHT    
      case RIGHT:
        
        if(t.checkPlace(m_posX+1,m_posY) == ' ')
        {
          cout << "Before X: " << m_posX << " Y: " << m_posY << endl;
          m_posX += 1;
          cout << "After X: " << m_posX << " Y: " << m_posY << endl;
          t.placeInTown(m_posX,m_posY,m_repChar);
        }
        
         if(isNearHouse(t) == true && successfulSale() == true)
       {
         m_numPants -= 1;
         m_fundsAvailable += 10;

       }
       
       break;
     
//MOVES DOWN    
      case DOWN:

        if(t.checkPlace(m_posX,m_posY+1) == ' ')
        {
          cout << "Before X: " << m_posX << " Y: " << m_posY << endl;
          m_posY += 1;
          cout << "After X: " << m_posX << " Y: " << m_posY << endl;
          t.placeInTown(m_posX,m_posY,m_repChar);
          break;
        }
        
         if(isNearHouse(t) == true && successfulSale() == true)
       {
         m_numPants -= 1;
         m_fundsAvailable += 10;
       }
       
       break;        

//MOVES UP
      case UP:

        if(t.checkPlace(m_posX,m_posY-1) == ' ')
        {
          cout << "Before X: " << m_posX << " Y: " << m_posY << endl;  
          m_posY -= 1;
          cout << "After X: " << m_posX << " Y: " << m_posY << endl;  
          t.placeInTown(m_posX,m_posY,m_repChar);
        }
        
         if(isNearHouse(t) == true && successfulSale() == true)
       {
         m_numPants -= 1;
         m_fundsAvailable += 10;
 
       }
        break;     
   }//end switch

  }//end while

//----Places movement character in avalible space---
  t.placeInTown(m_posX,m_posY,m_repChar);

  return;
}//end randwalk()


