//Programmers: Skylar Trendley & George Ward
//Date: 4/3/17
//Instructor: Dr. Clayton Price
//Section: CS1570A
//Description: This program will utilize data files in order to 
//             generate randomized and unintellectual speeches.

#include "speech.h"

int main()
{

  srand(time(NULL));
  ifstream fin;
  ifstream fout;
  
  char var[1000];
  char index[1000];
  int countPunct   = 0;
  int maxPunct     = 0;
  int wordlength   = 0;
  int commacounter = 0;
  bool isFirst     = false;
  
  fin.open("speech.dat");
      
  while (fin >> var)
  {
    int length = strlen(var);

    if(var[length-1] == '.' || var[length-1] == '?' || var[length-1] == '!')
      maxPunct++;
  }
  
  fin.close();
  
  fin.open("speech.dat");
  
  while (fin >> var)
  {
  
   iMean();
    wordlength = strlen(var);
    
    if(var[wordlength-1] == '.' || var[wordlength-1] == '?' || 
       var[wordlength-1] == '!')
      countPunct++;
    
                                       
    decap(var, isFirst);               //Decaptializes the first letter 
                                       //in a word
    isFirst = runOn(var, countPunct);  
    
     if (countPunct >= 3 || countPunct <= 4)
     {
       if (var[wordlength - 1] == ',')
          commacounter++;

       //decap2(index);
       //theBreakSwapper(var, index, commacounter);
     }      
        
    randoChange(var); 
    veryCat(var);     //This function concationates very onto very
    lyStunter(var);   //This function removes ly from words
    
    if(wordlength > BIG_WORD)
    {
      errTooMuch(var,BIG_WORD,countPunct,maxPunct);  
    
      if(countPunct == maxPunct)
        nStuff(var);
    } 
     
    else if(wordlength <= BIG_WORD)
    {
      
      cout << var << " ";    // Outputs the data to the screen when conditions 
      
      if(countPunct == maxPunct)
        nStuff(var);
    } 
    //if(countPunct == maxPunct)
     // nStuff(var);

  }//end while  
  cout << endl;
  
  return 0;
}
