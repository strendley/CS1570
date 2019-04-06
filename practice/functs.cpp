#include "Header.h"


bool runOn(char word[], const int punct)
{
  int length = strlen(word);
  bool is_first_pun = false;

  if((word[length-1] == '.'|| word[length-1] == '!' || word[length-1] == '?')
     && punct == 1)
  {
    word[length-1] = '\0';
    is_first_pun = true;
  }

  return is_first_pun;
}

void decap(char word[], bool is_first)
{
  int i   = 0;

  if(is_first == true)
    word[i] += 32;
    
  return;
}

void decap2(char index[])
{ 
 int i = 0;
 while(index[i] != '\0')
 {
    if(index[i] >= 65 && index[i] <= 90)
      index[i] += 32;
      
    if(index[i-1] == ',')
      index[i-1] = '.';
        
    i++;  
  }
  
}




void theBreakSwapper(char word[], char index[], const int commas)
{

  int i = 0;
  if (commas >= 0 && commas < 2 && word[i-1] != ',')
  {
     strcat(index, word);
     strcat(index," ");
  }

  while(word[i] != '\0')
  {
    if(word[i] == '.')
    {
      word[i] = ',';
    }
      i++;
  }
    
    return;
}

