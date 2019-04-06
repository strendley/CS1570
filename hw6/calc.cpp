//Programmer: Skylar Trendley      Date: 3/5/17
//Instructor: Clayton Price
//File: calc.cpp
//Section: CS1570A
//Description: Menu Driven Function Based Calculator
#include <iostream>
#include "calc.h"
using namespace std;

int main()
{
  int option;
  double getFact, getExp, getX, getN;
  double calcFact, calcExponentiate, calcSinX, calcCoshX;
  bool quit = false;

  do
  {
    cout << endl;
    cout << "-----Menu-----" << endl;
    cout << "1. Factorial of x" << endl;
    cout << "2. Exponential of x" << endl;
    cout << "3. Sine of x" << endl;
    cout << "4. Roots of x" << endl;
    cout << "5. Hyperbolic Cosine of x" << endl;
    cout << "6. Quit" << endl;

    cout << "Enter option (" << OPTION_FACT << "-" << OPTION_QUIT << "): ";
    cin >> option;

    snarkyRoll(option);

    switch (option)
    {
      case OPTION_FACT:
      {
        getFact = getFactInput();
        changeX(getFact);
        calcFact = factorial(getFact);
        cout << "fact = " << calcFact << endl;
	break;
      }

      case OPTION_EXP:
      {
	getExp = getExpInput();
	changeX(getExp);
	calcExponentiate = exponentiate(getExp);
	cout << "e = " << calcExponentiate << endl;
	break;
      }

      case OPTION_SINX:
      {
	getX = getXInput();
	changeX(getX);
	calcSinX = sine(getX);

	cout << "sin(X) = " << calcSinX << endl;
	break;
       }

       case OPTION_ROOT:
       {
         getX = getXInput();
	 getN = rootOption();
	 getRoot(getX, getN);
	 break;
       }

       case OPTION_COSH_X:
       {
         getX = getXInput();
	 changeX(getX);
	 calcCoshX = cosh(getX);
	 cout << "cosh(X) = " << calcCoshX << endl;
	 break;
       }

      case OPTION_QUIT:
      {
        quit = true;
	cout << "And don't come back!" << endl;
	break;
      }
	
      case OPTION_RUDE:
      {
        rudeFunction(randComment());
        break;
      }

      default:
        cout << "That option doesn't exist..." << endl;
    }//end switch

  } while (!quit);
  return 0;
}//end main

