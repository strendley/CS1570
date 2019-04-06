//Programmers: Skylar Trendley & George Ward
//Date: 4/3/17
//Instructor: Dr. Clayton Price
//Section: CS1570A
//Description: This program will utilize data files in order to
//             generate randomized and unintellectual speeches.

#ifndef SPEECH_H
#define SPEECH_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

const int BIG_WORD     = 10;
const int FILLER_SIZE  = 10;
const int MAX_CHANCE   = 100;
const int CHANCE1      = 33;
const int CHANCE2      = 66;
const int RAN_LETTER1  = 4;
const int RAN_LETTER2  = 3;
const int RANDO_CHANCE = 80;
const int IMRAND       = 50;
const int RANDNSTUFF   = 70;
const char FILLER1[FILLER_SIZE] = {"-uhh-"};
const char FILLER2[FILLER_SIZE] = {"-err-"};
const char FILLER3[FILLER_SIZE] = {"-umm-"};

//Function Prototypes

//Des:  The run() changes the first punctuation in a file to a null char and
//      returns true after.
//Pre:  Punct must be non_negative.
//Post: Changes the first punctuation in a file to a null char and returns 
//      true after.
bool runOn(char word[], const int punct);

//Des:  The decap() changes the first word after a period to a lowercase 
//      letter.
//Pre:  is_first must be true.
//Post: Changes the first word after a period to a lowercase letter.
void decap(char word[], bool is_first);

//Des:  The randoChange() changes
//Pre:
//Post:
void randoChange(char word[]);

//Des:
//Pre:
//Post:
void veryCat(char word[]);

//Des:
//Pre:
//Post:
void lyStunter(char word[]);

//Des:
//Pre:
//Post:
void errTooMuch(char word[], const int tooBig, const int punct, 
                const int maxpunct);

//Des:
//Pre:
//Post:
void um_rand();

//Des:
//Pre:
//Post:
void iMean();

//Des:
//Pre:
//Post:
void nStuff(char word[]);

void decap2(char index[]);

//Des:
//Pre:
//Post:
void theBreakSwapper(char word[], char index[], const int commas);

#endif
