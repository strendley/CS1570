//Programmer: Skylar Trendley    Date: 3/18/2017
//Instructor: Clayton Price
//Class: CS1570A
//File: pantsFuncts.cpp
//Description:Generates random store inventory & makes a sale
//             based upon user waist input & color preference.
#include <iostream>
#include "pantsShop.h"
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

void greeting()
{
  cout << endl;
  cout << "        Welcome to the Milhouse Trousery!" << endl;
  cout << "  --------------------------------------------------" << endl;
  
  return;
}

void generatePants(pant pants[])
{
  for (int i = INITIALIZE_I; i < MAX_PANTS; i++)
  {
    pants[i].waist = genWaist();
    pants[i].inSeam = genInSeam();
    pants[i].color = genColor();
    pants[i].avail = true;
  }

  return;
}

int genWaist()
{
  int randWaist;
  randWaist = rand() % (MAX_WAIST - MIN_WAIST + 1) + MIN_WAIST;
  
  return randWaist;
}

int genInSeam()
{
  int randInSeam;
  randInSeam = rand() % (MAX_INSEAM - MIN_INSEAM + 1) + MIN_INSEAM;

  return randInSeam;
}

int genColor()
{
  int randColor;
  randColor = rand() % (MAX_NUM_COLORS - MIN_NUM_COLORS) + MIN_NUM_COLORS;

  return randColor;
}

void sort(pant pants[])
{
  for (int i = INITIALIZE_I; i < MAX_PANTS; i++)
  {
    for (int j = i + 1; j < MAX_PANTS; j++)
    {
      if (pants[i].waist > pants[j].waist)
      {
        pant temp;
        temp = pants[i];
	pants[i] = pants[j];
	pants[j] = temp;
      }
    }
  }

  return;
}

void print(const pant pants[])
{
  for (int i = INITIALIZE_I; i < MAX_PANTS; i++)
  {
    cout << " | Waist: " << pants[i].waist << " | ";
    cout << "Inseam: " << pants[i].inSeam << " | ";
    cout << "Color: " << COLORS[pants[i].color] << " ";

    cout << endl;
  }

  return;
}
 

void indexStock(pantsOfSize inventory[])
{
  for(int i = INITIALIZE_I; i < MAX_SIZES; i++)
  {
    inventory[i].waist = MIN_WAIST + i;
    for(int j = INITIALIZE_J; j < MAX_NUM_COLORS; j++)
    {
      inventory[i].numColors[j] = 0; 
    }
  } 
  
  return;
}

void sortStock(const pant pants[], pantsOfSize inventory[])
{
  for(int i = INITIALIZE_I; i < MAX_PANTS; i++)
  {
    for(int j = INITIALIZE_J; j < MAX_SIZES; j++)
    {
      if(pants[i].waist == inventory[j].waist)
      {
        inventory[j].numColors[pants[i].color] += 1;
      }
    }
  }

  return;
}

void findMatch(const pantsOfSize inventory[], const int custWaist)
{
      cout << "For size " << custWaist << " we have: ";
      
      for(int i = INITIALIZE_I; i < MAX_NUM_COLORS; i++)
      {
       if(inventory[custWaist - MIN_WAIST].numColors[i] > 0)
       {
         cout << COLORS[i];
         cout << " (enter " << i << ") ";
       } 
      }
      
      cout << endl;

  return;
}

void chooseInseam(const pant pants[], const int colorChoice,
                  const int custWaist)
{
  cout << "For size " << custWaist << " in " << COLORS[colorChoice];
  cout << " we have the inseams of: ";
  
  for(int i = INITIALIZE_I; i < MAX_PANTS; i++)
  {
    if(custWaist == pants[i].waist && colorChoice == pants[i].color)
      cout << pants[i].inSeam << " ";
  }    
  
  cout << endl;
  
  return; 
}

void makeSale(const pant pants[], const int inSeamChoice, const int custWaist)
{
  int price;
  int bonusCharge = 0;

  for (int i = INITIALIZE_I; i < MAX_PANTS; i++)
  {
    if (pants[inSeamChoice].inSeam <= ((HWTRATE * pants[i].waist)
         - INSEAM_RATIO))
    	bonusCharge = CHARGE;

    price = pants[custWaist].waist + pants[inSeamChoice].inSeam + bonusCharge;
      
  }
  
  cout << "Price: $" << price << endl;
  cout << "TRANSACTION SUCCESSFUL! Thank you for your business!" << endl;

  return;
}

void adjustStock(pant pants[], pantsOfSize inventory[], 
                 const int colorChoice, const int inSeamChoice,
                 const int custWaist)
{
  for(int i = INITIALIZE_I; i < MAX_PANTS; i++)
  {
   if (pants[i].waist == custWaist &&
            pants[i].color == colorChoice &&
            pants[i].inSeam == inSeamChoice)
        {
          for(int j = INITIALIZE_J; j < MAX_SIZES; j++)
          {
            if(pants[i].waist == inventory[j].waist)
            {
              inventory[j].numColors[pants[i].color] -= 1;
              pants[j].avail = false;
            }
          }
        }     
  }
  return;
}
