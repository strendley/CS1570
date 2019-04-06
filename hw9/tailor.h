//Programmer: Skylar Trendley  Date: 4/13/17
//Instructor: Clayton Price
//Section: CS1570A
//Description: This program builds a design for a town using classes.

#include "header.h"
#include "town.h"

class tailor
{
  private:
    string name;    //Member variables for class tailor
    double funds;
    char symbol;
    bool isAlive;
    short x_coord;
    short y_coord;
  
  public:
    //Description: constructor for tailor class
    //Pre: None
    //Post: member variables set to default values
    tailor(string name, char symbol = DEFAULT_SYMBOL): name(name),
    funds(DEFAULT_MONEY), symbol(symbol), isAlive(true){}
    
    //Description: the placeMe() places the tailor into the town
    //Pre: None
    //Post: member variables of x_coord & y_coord are manipulated 
    void placeMe(town &t);
    
    //Description: the placeMiddle() places the tailor into the middle 
    //             of the town.
    //Pre: None
    //Post: member variables of x_coord & y_coord are manipulated
    void placeMiddle(town &t);
    
    //Description: the randWalk() moves the tailor in a random direction
    //Pre: None
    //Post: member variables for coordinates are manipulated and the tailor 
    //      symbol is relocated
    void randWalk(town &t);
    
    //Description: the printTailor() prints the tailor's member variables
    //Pre: None
    //Post: member variables are output to screen
    void printTailor();
  
};
