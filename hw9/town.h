//Programmer: Skylar Trendley  Date: 4/13/17
//Instructor: Clayton Price
//Section: CS1570A
//Description: This program builds a design for a town using classes.

#include "header.h"

class town
{
  private:
    //Member variables
    char theTown[MAX_SIZE][MAX_SIZE];
    short townSize;
     
    //Member functions
    void clear();
    void build();
    
  public:
    //Description: constructor for class town
    //Pre: None
    //Post: townSize is set and town is initialized
    town(const short gridSize = MAX_SIZE);
    short getSize() const {return townSize;} //accessor for townSize
    
    //Description: the placeTrees() places trees at specified coordinates
    //             within the town
    //Pre: None
    //Post: Trees are placed at coordinates
    void placeTrees();
    
    //Description: the placeTailor() places the tailor at specified
    //               coordinates within the town
    //Pre: x and y must contain a value
    //Post: tailor is placed at coordinates
    void placeTailor(const short x, const short y);
    
    //Description: the clearPrevious() clears the previous coordinates
    //             of the tailor where his symbol was located
    //Pre: x and y must contain a value
    //Post: symbol of previous coordinate location are cleared from the town
    void clearPrevious(const short x, const short y);
    
    //Description: the checkSpace() checks if the designated coordinates
    //             contain an object or are empty
    //Pre: x and y must contain a value
    //Post: isEmpty is returned true or false 
    bool checkSpace(const short x, const short y);    
    
    //Description: the printTown() prints the town's walls
    //Pre: None
    //Post: the town walls are output to the screen
    void printTown(); 
};
