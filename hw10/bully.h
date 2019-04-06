/*
Programmer:  GEORGE C WARD
Instructor:  CLAYTON PRICE
Date:        19Apr2017
Section:     A
Description: Class tailor for the highwater program
*/
#ifndef   BULLY_H
#define   BULLY_H
#include  "town.h"
#include  "tailor.h"
#include  <iostream>
#include  <cstdlib>
#include  <ctime>
#include  <fstream>
using namespace std;

const short BULLY_ATT   = 10;
const char  BULLY_REP   = 'B';
const short NAMES       = 3;
const short PUNCH_RAN1  = 20;
const short PUNCH_RAN2  = 30;
const short PUNCHPROB   = 80;
const short MAX_RAND    = 100;
const short MESSAGE_NUM = 7;


class bully 
{
  public:
    bully();
    friend ostream& operator <<(ostream& os, const bully& b);
    bool   punch();
    void   setProbPunch(const short s){m_probPunch = s;}
    string getName(){return m_bullyName;}
    short  getPower(){return m_punchPower;}
    short  getProb(){return m_probPunch;}
        
  private:
    string m_bullyName;
    short  m_punchPower;
    short  m_probPunch;
};

#endif
