/*
Programmer:  GEORGE C WARD
Instructor:  CLAYTON PRICE
Date:        19Apr2017
Section:     A
Description: Bully funciton defintions for the highwater program
*/
#include "bully.h"
#include "town.h"
#include "tailor.h"

bully::bully()
{
//randomly generates a value that is used to choose a name from bully.dat
  short randname = rand()%NAMES;
//randomly generates punch power between 30 and 50
  short randPow  = rand()%PUNCH_RAN1 + PUNCH_RAN2;
  string var;
  ifstream fin;
  fin.open("bully.dat");

//-----Randomly selects bully name from file ---------
  int i =0;
  while(i <= randname)
  {
    fin >> var;
    i++;
  }

  m_bullyName = var;
  fin.close();
  m_punchPower = randPow;
  m_probPunch  = PUNCHPROB;
}

ostream& operator <<(ostream& os, const bully& b)
{
  os << "Bully name is: " << b.m_bullyName << " with a punch power of: "
     << b.m_punchPower << " you have an " << b.m_probPunch <<"% chance of getting"
     << " smacked!" << endl;
  return os;
}

bool bully::punch()
{
  bool hasRan;
  short punchProb  = rand()%MAX_RAND;
  short messRand   = rand()%MESSAGE_NUM;
  int i            = 0;
  char message[500];
  ifstream fin;
  fin.open("bully.dat");

  if(punchProb <= m_probPunch)
  {
    hasRan = true;
  }
  else if(punchProb > m_probPunch)
  {
    hasRan = false;
    fin.ignore(500, '\0');
   fin.close();       
  }
  return hasRan;
}
