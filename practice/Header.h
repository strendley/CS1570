

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool runOn(char word[], const int punct);

void decap(char word[], bool is_first);

void decap2(char index[]);

void theBreakSwapper(char word[], char index[], const int commas);


#endif
