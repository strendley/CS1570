//Programmers: Skylar Trendley & George Ward
//Date: 4/3/17
//Instructor: Dr. Clayton Price
//Section: CS1570A
//Description: This program will utilize data files in order to
//             generate randomized and unintellectual speeches.

#include "speech.h"



bool runOn(char word[], const int punct)
{
  int length = strlen(word); //identifies the length of the word
  bool is_first_pun = false; 
  
  //conditional to identify the first punctuation in the datafile
  if((word[length-1] == '.'|| word[length-1] == '!' || 
     word[length-1] == '?') && punct == 1)  
  {
    word[length-1] = '\0'; //changes the punctuation to a null char
    is_first_pun = true;   //is false until the first punctuation
  }
  
  return is_first_pun;    //returns true if it is the first punctuation
}

void decap(char word[], bool is_first) //the function decaps first word
                                       //of the second sentence.
{
  int i   = 0;
  
  if(is_first == true)  // conditional that only works when is first is 
    word[i] += 32;      // is true.
    
  return;
}

void randoChange(char word[])  // changes certain words randomly
{
  int randChance;
   
  randChance = rand() % MAX_CHANCE; 
  
  if(randChance <= RANDO_CHANCE)
  {
    if(!strcmp(word,"is"))
      strcpy(word,"are");
    else if(!strcmp(word,"isn't"))
      strcpy(word,"ain't");
    else if(!strcmp(word,"has"))
      strcpy(word,"have");
    else if(!strcmp(word,"she"))
      strcpy(word,"her");
    else if(!strcmp(word,"he"))
      strcpy(word,"him");     
  }
  
  return;
}

void veryCat(char word[])  
{
  if(!strcmp(word,"very"))
    strcat(word," very");

  return;
}

void lyStunter(char word[])  //finds a word ending in ly and erases the ly
{
  int len = strlen(word);
  if(word[len-2] == 'l' && word[len-1] == 'y')
  {
    word[len-2] = '\0';
  }
  return;
}

void errTooMuch(char word[], const int tooBig ,const int punct, const int maxpunct)  
{
  int len = strlen(word);  //finds length of the word
  
  if(len > tooBig)         //compares to see if the word is larger than 
  {                        //BIG_WORD.
    
    //Randomly chooses a data in the word to concationate another word 
    //into the data
    int randNum = rand() % RAN_LETTER1 + RAN_LETTER2;
      
    for(int i = 0; i <= randNum; i++)
    {
      cout << word[i];  //reads out until the insertion spot
    }
   
    um_rand();         //insertes word into the randomly selected spot in
                       //in the data.
    for(int i = randNum+1; i < len; i++)
    {
      if(punct == maxpunct)
      {
      }
      else if(punct<maxpunct)
        cout << word[i];
    }  
    cout << " ";       
  }
  return;
}

void um_rand()
{
  int rando = rand()% MAX_CHANCE;
  if(rando <= CHANCE1)
   cout << FILLER1;
  else if(rando <= CHANCE2)
   cout << FILLER2;
  else 
   cout << FILLER3;
  
  return;
}

void iMean() 
{
  
  int random = rand() % MAX_CHANCE;
  
  if(random <= IMRAND)
  {
    cout << "I mean.. ";
  }

  return;   

}

void nStuff(char word[])
{
  int random = rand() % MAX_CHANCE;
  int len = 0;

  while(word[len] != '\0')
    len++;
  
  
  if(random <= RANDNSTUFF)
  {
    word[len-1] = '\0';
    cout << word << "... and stuff." << endl;
  }  
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
  
  return;
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
      // cout << index;
    }
    i++;
  }//end while

  if(commas >= 2)
  {
    cout << word << " ";
  }
  
  return;
}
