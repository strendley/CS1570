

#include "pants.h"
const char EMPTY = ' ';

pants::pants(string p_name, short x, short y, char letter)
{
  name = p_name;
  x_coord = x;
  y_coord = y;
  repChar = letter;
}

void pants::placePants(town &t)
{

  short randX = rand()%t.getTown();
  short randY = rand()%t.getTown();

  while(t.checkPlace(randX,randY) != ' ')
  {
    randX = rand()% t.getTown();
    randY = rand()% t.getTown();
  }
  setX(randX);
  setY(randY);
  t.placeInTown(x_coord, y_coord, repChar);

  return;

}

void pants::chase(town &t, tailor &m)
{
  int randMove = rand() % 100 + 1;
  short pantX = x_coord;
  short pantY = y_coord;
  if(randMove <= 100)
  {
    t.placeInTown(pantX,pantY,EMPTY);
    if(t.checkPlace(pantX+1,pantY) == EMPTY)
    {
      x_coord += 1;
    }
    else if(m.getLocX()<=x_coord && m.getLocX() <= m.getLocY()
           && t.checkPlace(pantX-1,pantY) == EMPTY)
    {
      x_coord -=1;
    }
    else if(m.getLocY()>y_coord && m.getLocY() > m.getLocX()
           && (t.checkPlace(pantX,pantY+1) == EMPTY))
    {
      y_coord +=1;
    }
    else if(m.getLocY()<=y_coord && m.getLocY() < m.getLocX()
         && (t.checkPlace(pantX,pantY-1) == EMPTY))
    {
      y_coord -= 1;
    }
    t.placeInTown(x_coord,y_coord,'K');
  }
   return;
}

void pants::kill(town &t, tailor &m)
{
 if((t.checkPlace(x_coord+1,y_coord) == 'M') ||
     (t.checkPlace(x_coord-1,y_coord) == 'M') ||
     (t.checkPlace(x_coord,y_coord+1) == 'M') ||
     (t.checkPlace(x_coord,y_coord-1) == 'M'))
   m.setHealth(0);

  return;
}
