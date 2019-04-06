//Programmer: Skylar Trendley      Date: 3/5/17
//Instructor: Clayton Price
//File: calcFuncts.cpp
//Section: CS1570A
//Description: Menu Driven Function Based Calculator

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "calc.h"
using namespace std;

double getFactInput()
{
  double factInput;
  do
  {
    cout << "Enter a non-negative number greater than " << MIN_PROMPT
    << " and/or equal to " << MAX_FACTORIAL << ": ";
    cin >> factInput;
  } while (factInput < MIN_PROMPT || factInput > MAX_FACTORIAL);

  return factInput;
}

double factorial(const double numFacts)
{
  double fact = 1;
  for (int i = INITIALIZE_I; i <= numFacts; i++)
    fact *= i;

  return fact;
}

double getExpInput()
{
  double expInput;
  do
  {
    cout << "Enter a real number between " << MIN_PROMPT
    << " and " << MAX_EXPONENTIATE << ": ";
    cin >> expInput;
  } while (expInput < MIN_PROMPT || expInput >= MAX_EXPONENTIATE);

  return expInput;
}

double exponent(const double exp_x, const double numTerms)
{
  double exp = 1;

  for (int i = INITIALIZE_I; i <= numTerms; i++)
    exp *= exp_x;
  
  return exp;
}

double exponentiate(const double exp)
{
  double e = 1;

  for (int i = INITIALIZE_I; i <= MAX_EXPONENTIATE; i++)
    e += (exponent(exp,i) / factorial(i));
 
  return e;
}

double getXInput()
{
  double x;

  do
  {
    cout << "Enter a real number: ";
    cin >> x;
  } while (x < MIN_PROMPT);

  return x;
}

double sine(const double x)
{
  double sinX = 0;
  double sign = -1;

  for (int i = INITIALIZE_I; i <= SINE_ACC; i += 2)
  {
    sinX += sign * exponent(x, i) / factorial(i);
    sign *= -1;
  }

  return sinX;
}

double rootOption()
{
  double n;
  do
  {
    cout << "Enter Root (square through fifth): ";
    cin >> n;
  } while (n < MIN_PROMPT || n > MAX_ROOT);

  return n;
}

void getRoot(const double x, const double n)
{
  if (n == OPTION_SQRT)
    sqRt(x);
  else if (n == OPTION_CUBERT)
    cubeRt(x);
  else if (n == OPTION_FOURTHRT)
    fourthRt(x);
  else
    fifthRt(x);

  return;
}

void sqRt(const double x)
{
  double guess = x;
  double sqRoot;

  for (int i = INITIALIZE_I; i <= ITERATE_CONVERGENCE; i++)
  {
    sqRoot = ((guess + (x / guess)) / 2);
    guess = sqRoot;
  }
	
  cout << "sqrt(" << x << ") = " << sqRoot << endl;
  
  return;
}

void cubeRt(const double x)
{
  double guess = x;
  double cubeRoot;

  for (int i = INITIALIZE_I; i <= ITERATE_CONVERGENCE; i++)
  {
    cubeRoot = ((2 * guess) + (x / (guess * guess))) / 3;
    guess = cubeRoot;
  }

  cout << "cbrt(" << x << ") = " << cubeRoot << endl;

  return;
}

void fourthRt(const double x)
{
  double guess = x;
  double fourthRoot;

  for (int i = INITIALIZE_I; i <= ITERATE_CONVERGENCE; i++)
  {
    fourthRoot = ((3 * guess) + (x / (guess * guess * guess))) / 4;
    guess = fourthRoot;
  }

  cout << "4rt(" << x << ") = " << fourthRoot << endl;

  return;
}

void fifthRt(const double x)
{
  double guess = x;
  double fifthRoot;

  for (int i = INITIALIZE_I; i <= ITERATE_CONVERGENCE; i++)
  {
    fifthRoot = ((4 * guess) + (x / (guess * guess * guess * guess))) / 5;
    guess = fifthRoot;
  }

  cout << "5rt(" << x << ") = " << fifthRoot << endl;

  return;
}

double cosh(const double x)
{
  double coshX = 1;

  for (int i = 0; i <= COSINE_ACC; i += 2)
  {
    coshX += exponent(x, i) / factorial(i);
  }

  return coshX;
}

int snarkyRoll(int &opt)
{
  int chance;

  srand(time(NULL));
  chance = rand() % 100+1;
		
  if (chance <= SNARKY_CHANCE)
    opt = OPTION_RUDE;

  return opt;
}

int changeX(double &x)
{
  int chance;

  srand(time(NULL));
  chance = rand() % 100+1;

  if (chance <= CHANGE_INPUT_CHANCE)
  {
    x = rand() % 7 + 3;
    cout << "I don't like that number.. I like " << x << " better." << endl;
  }

  return x;
}

int randComment()
{
  int comment;
  srand(time(NULL));
  comment = rand() % 9+1;

  return comment;
}

void rudeFunction(const int val)
{
  switch (val)
  {
    case 1:
      cout << "No, I'm not going to do that for you." << endl;
      break;

    case 2:
      cout << "That's not something you really need to know." << endl;
      break;

    case 3:
      cout << "Can't you do that on your own? ";
      cout << "Why bother me with your problems?" << endl;
      break;

    case 4: 
      cout << "Perhaps you need to see your psychologist "; 
      cout << "for this problem." << endl;
      break;

    case 5: 
      cout << "What do you think I am? Your patsy?" << endl;
      break;

    case 6:
      cout << "I don't feel like doing that. Come back later.. Maybe." << endl;
      break;

    case 7:
      cout << "GO AWAY!!!" << endl;
      break;

    case 8:
      cout << "That is NOT my problem..." << endl;
      break;

    case 9:
      cout << "Ask Milhouse...surely he knows the answer ";
      cout << "to your stupid questions." << endl;
      break;

  }//end switch

  return;
}





