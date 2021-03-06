/*
Programmer:  GEORGE C WARD
Instructor:  CLAYTON PRICE
Date:        19Apr2017
Section:     A
Description: Milhouses highwater program main() aka. DRIVER
*/

#include "town.h"
#include "tailor.h"
#include "bully.h"
#include "pants.h"
#include <unistd.h>
#include <ctime>
#include <cstdlib>

int main()
{
  srand(time(NULL));

  bully drPrice;                              //declare bully
  tailor millyboy("millhouse",'M');           //declare tailor
  town t(17,10);                              //declare town
  pants p[3] = {
                            pants("khakis", -1, -1, 'K'),
                            pants("cargos", -1, -1, 'C'),
                            pants("shorts", -1, -1, 'S')
                          };




  cout << t << endl;				//print town

  int i = 0;
  int j = 0;
  int numMoves = 30;
  int stuffhit = 0;
  int counter = 1;

  millyboy.placeMe(t);				//place millhouse in town

  while(i != numMoves)
  {
    if (counter % 3 == 0 && counter <= 9)           //pants come alive every 3 turns
    {
      p[j].placePants(t);
      j++;
    }
    usleep(500000);
    millyboy.randWalk(t,drPrice,stuffhit);
    
    for(int i = 0; i < 2; i++)
    {
       if(p[0].getX() != -1 && p[0].getY() != -1)
       {
          p[0].chase(t, millyboy);
       }
        if(p[1].getX() != -1 && p[1].getY() != -1)
       {
          p[1].chase(t, millyboy);
       }
       if(p[2].getX() != -1 && p[2].getY() != -1)
       {
          p[2].chase(t, millyboy);
       }

    }
    
    cout << t << endl;
    i++;
    counter++;
  }

  return 0;
}
