
#include "tailor.h"
#include "town.h"

class town;
class tailor;

class pants
{
  private:
    string name;
    short x_coord;
    short y_coord;
    char repChar;

  public:
//constructors
    pants(){};
    pants(string p_name, short x, short y, char letter);

//pants name
    void namePants(string n) {name = n;}
    string getPantsName() const {return name;}

//pants representive char
    void setPantsChar(const char p) {repChar = p;}
    char getPantsChar() const {return repChar;}

//location on grid
    void setX(const short x) {x_coord = x;}
    void setY(const short y) {y_coord = y;}
    short getX() const {return x_coord;}
    short getY() const {return y_coord;}

//movement
    void placePants(town &t);
    void chase(town &t, tailor &m);

//damage tailor
    void kill(town &t, tailor &m);

};
