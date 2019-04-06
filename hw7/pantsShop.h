//Programmer: Skylar Trendley    Date: 3/18/2017
//Instructor: Clayton Price
//Class: CS1570A
//File: pantsShop.h
//Description: Generates random store inventory & makes a sale
//             based upon user waist input & color preference.

#include <iostream>
using namespace std;

#ifndef PANTSSHOP_H
#define PANTSSHOP_H

//Global Constants
const int MAX_NUM_COLORS = 7;
const int MAX_SIZES = 21;
const int MAX_PANTS = 100;
const int MIN_WAIST = 20;
const int MAX_WAIST = 40;
const int MIN_INSEAM = 14;
const int MAX_INSEAM = 45;
const int MIN_NUM_COLORS = 0;
const int CHARGE = 40;
const int INSEAM_RATIO = 2; 
const float HWTRATE = 0.9;
const int INITIALIZE_I = 0;
const int INITIALIZE_J = 0;
const string COLORS[MAX_NUM_COLORS] = { "black","blue",
                                        "red","rainbow","checkered",
	                                    "electric green", "polka dot" };
//Structure Definitions

struct pant
{
  int waist;
  int inSeam;
  int color;
  bool avail;
};

struct pantsOfSize
{
  int waist;
  short numColors[MAX_NUM_COLORS];
};

//Function Prototypes

//Description: The greeting() outputs a message to the screen.
//Pre: None.
//Post: Message is output to the screen.
void greeting();

//Description: The generatePants() randomizes variables for pants
//Pre: 
//Post: member variables recieve randomized data
void generatePants(pant pants[]);

//Description: The genWaist() generates a random waist measurement
//Pre: None.
//Post: Random waist measurement is returned.
int genWaist();

//Description: The genInSeam() generates a random inSeam measurement
//Pre: None.
//Post: Random inSeam measurement is returned.
int genInSeam();

//Description: the genColor() generates a random integer value to assign color.
//Pre: None.
//Post: Random integer color is returned.
int genColor();

//Description: The print() outputs the pants inventory to the screen.
//Pre: None.
//Post: Inventory is output to the screen.
void print(const pant pants[]);

//Description: The availability() checks the availability for pants.
//Pre: None.
//Post: a boolean is returned.
bool availability();

//Description: The sort() sorts the pants according to waist measurement.
//Pre: array must be of size
//Post: The pants are sorted low to high by waist measurement.
void sort(pant pants[]);

//Description: The findMatch() searches for matching pants based on
//             waist size and outputs all available pants with matching colors
//Pre: array must be of size, custWaist must be within MIN_WAIST & MAX_WAIST.
//Post: if match is found, pants are output, user is prompted for purchase.
void findMatch(const pantsOfSize inventory[], const int custWaist);

//Description: the chooseInseam() searches for matching pants based on
//             inSeam and outputs all available pants with matching inseams
//Pre: array must be of size, custWaist must be within MIN_WAIST & MAX_WAIST.
//Post: pant inseams are output, match is searched.
void chooseInseam(const pant pants[], const int colorChoice, 
                  const int custWaist);

//Description: the indexStock() sets the indexes of each pant color to zero.
//Pre: array must be of size
//Post: color indexes are set to zero.
void indexStock(pantsOfSize inventory[]);

//Description: The sortStock() records the existence of waist size and
//             counts the stock for each color according to waist size.
//Pre: array must be of size
//Post: color stock is accumulated.
void sortStock(const pant pants[], pantsOfSize inventory[]);

//Description: The makeSale() calculates pants price, decrements stock
//             and changes availability.
//Pre: arrays must be of size
//Post: Price is calculated, stock is decremented, availability is changed.
void makeSale(const pant pants[], const int inSeamChoice, const int custWaist);

//Description: The adjustStock() adjusts the pants stock based on if a
//             purchase was completed
//Pre: array must be of size.
//Post: if sale was made, stock is decremented accordingly.
void adjustStock(pant pants[], pantsOfSize inventory[],
                 const int colorChoice, const int inSeamChoice, 
                 const int custWaist);

#endif
