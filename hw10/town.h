//
/*
Programmer:  GEORGE C WARD
Instructor:  CLAYTON PRICE
Date:        19Apr2017
Section:     A
Description: Class town header file for the highwater program
*/

#ifndef  TOWN_H
#define  TOWN_H
#include <iostream>
#include <cstdlib>
using namespace std;
class tailor;
class placement;
const int MAX_W         = 25;
const int MAX_H         = 25;
const int MIN_W         = 0;
const int MIN_H         = 0;
const int NORTH         = 1;
const int SOUTH         = 2;
const int EAST          = 3;
const int WEST          = 4;
const int MIN_TOWN_SIZE = 5; //Minimum allowed value for a town.
const char HOUSE = 'H';

//Des:  constructor town, takes an inputs and fills member var townSize
//Pre:  input must be less than MAX_H.
//Post: takes an input and fills member var townSize.

//Des:  Default constructor for town.
//Pre:  none.
//Post: Sets townSize to max size.

//Des:  prinTown() outputs the grid of 2d array town to the screen.
//Pre:  None.
//Post: Outputs the grid of the 2d array town to the screen.

//Des:  setTown(), getter function for townSize private member var. returns
//      a short.
//Pre:  None.
//Post: Sets the private member var. and returns a short.

//Des:  placeInTown(), inputs a character into the 2d Array townBoarders.
//Pre:  Must be within parameters.
//Post: inputs a character into the 2D array townBoarders.
  
//Des:  checkPlace(), returns the value of occupied space in array.
//Pre:  Must be within pars.
//Post: returns the value of occupied space in array.

//Des:  build(), fills the edge of town with chars
//Pre:  None.
//Post: fills the edge of town with chars.

//Des:  clear(), fills the town with ' ' in spaces.
//Pre:  None.
//Post: fills the town with ' ' in spaces. 

struct loc
{
  char s_charRep;
  bool s_throwPants;
  loc& operator  =(const char c){s_charRep = c; return *this;}
  bool operator !=(const char c){return s_charRep != c;}
  bool operator ==(const char c){return s_charRep == c;}
  friend ostream& operator <<(ostream& out, const loc& l)
          {out << l.s_charRep; return out;}
};

class town
{
  public:

//  cosnstuctors for town.  
    town(const short size, const short num_bullies);
    town(){}
    
//    friend ostream operator << (ostream& os,town& t);
    friend ostream& operator <<(ostream& out, const town& t);
    
    short  getTown() const {return m_townSize;}
    
    void   placeInTown(short x, short y, const char c);
    
    loc    checkPlace(const short x, const short y)
           {return m_townBoarders[x][y];}
    
    
    friend bool operator == (const loc& lhs, const loc& rhs)
                {return lhs.s_charRep == rhs.s_charRep;}
//    friend loc& operator = (char c)
//           {loc lhs.s_charRep = c; return *this;}
        
  private:
    loc   m_townBoarders[MAX_H][MAX_W];
    short m_townSize;
    short m_numHomes;
    short m_numBully;
    void  build(const short num_bullies);
    void  clear();

};

#endif
