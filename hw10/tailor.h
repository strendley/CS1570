/*
Programmer:  GEORGE C WARD
Instructor:  CLAYTON PRICE
Date:        19Apr2017
Section:     A
Description: Class tailor for the highwater program
*/

#ifndef TAILOR_H
#define TAILOR_H
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

class town;
class place;
const short DIRECTION    = 4;
const short UP           = 0;
const short DOWN         = 1;
const short RIGHT        = 2;
const short LEFT         = 3;
const short MAX_MONEY    = 40;
const short MIN_MONEY    = 20;
const short START_PANTS  = 20;
const short START_HEALTH = 100;
const short START_X      = -1;
const short START_Y      = -1;
const bool  LIVING       = true;
 
//Des:  Overloaded operator for <<.
//Pre:  None.
//Post: Outputs the values of member variables for name, funds, aliveness, and 
//      represenative char letter.

//Des:  Overlaoded operator for comparing tailor and towns
//Pre:  None.
//Post: Compares a tailor and town.

//Des:  Constructor that takes values for member vairables.
//Pre:  None. 
//Post: Takes vales for assigned member variables. 


//Des:  Setter functions for member variables name, funds,
//      living, representative char, x and y position on grid.
//Pre:  None.
//Post: Sets member variables for the the tailor class
//      private member vars. 

//Des:  Getter functions for the member vars. name,funds, living, rep
//      char, and the x,y positon on the grid
//Pre:  None.
//Post: Returns the values for the primitive var types of the priviate
//      member variables of the tailor class.


//Des:  placeMe() places the tailor class into the middle of grid
//      of town.
//Pre:  None.
//Post: places the tailor class into the grid of town.

//Des:  customPlaceInTown() places the tailor into the grid at 
//      specified location
//Pre:  None.
//Post: places the tailor into the grid at specified location.

//Des:  randWalk() moves the tailor through out the town randomly
//Pre:  None.
//Post: moves the tailor thoughout the town grid randomly.

class town;
class bully;
class tailor
{
  public:
//tailor constructor and default  
    friend   ostream& operator << (ostream& os, const tailor& t);
    tailor   (const string name, const char c);
    tailor() {}
//Character Name 
    void     setName(string n) {m_tailorName = n;}
    string   getName() const {return m_tailorName;}
//character funds 
    void     setCapital(float c) {m_fundsAvailable = c;}
    float    getCapital() const {return m_fundsAvailable;}
//character alive or not
    void     setAlive(const bool a) {m_living = a;}
    bool     getAlive() const{return m_living;}
//characters representaive char
    void     setChar(const char c) {m_repChar = c;}
    char     getChar() const {return m_repChar;}
//characters health
    void     setHealth(const short h) {m_health = h;}
    short    getHealth() const {return m_health;}


//location on grid
    void     setLocX(const short x){m_posX = x;}
    void     setLocY(const short y){m_posY = y;}
    short    getLocX() const {return m_posX;}
    short    getLocY() const {return m_posY;}

//placing and moving functions    
    void     placeMe(town& t);
    void     customPlaceInTown(town& t,const short x, const short y);
    void     randWalk(town& t,bully& b, int hitstuff);
    
//location checking
    bool isNearHouse(town &t);
    bool successfulSale();

    
  private:
    string  m_tailorName;
    float   m_fundsAvailable;
    bool    m_living;
    char    m_repChar;
    short   m_posX;
    short   m_posY;
    short   m_health;
    short   m_numPants;
};

#endif
