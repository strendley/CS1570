#include "Header.h"


int main()
{
	char var[1000];
	char index[1000];
	ifstream fin;
	int maxPunct = 0;
	int countPunct = 0;
	int commaCounter = 0;
	bool isFirst = false;


	fin.open("Input.txt");

	while (fin >> var)
	{
		int length = strlen(var);

		if (var[length - 1] == '.' || var[length - 1] == '?' || var[length - 1] == '!')
			maxPunct++;

		//if ((maxPunct >= 2 && maxPunct < 3) && var[length - 1] == ',')
			//commaCounter++;

		//cout << var << " ";
	}
	
	cout << endl;
	//cout << endl << endl << "Commas detected: " << commaCounter << endl << endl;

	fin.close();

	fin.open("Input.txt");

	while (fin >> var)
	{
		int length = strlen(var);

		if (var[length - 1] == '.' || var[length - 1] == '?' || var[length - 1] == '!')
			countPunct++;

		decap(var, isFirst);
		isFirst = runOn(var, countPunct);

		if ((countPunct == 2 && var[length - 1] != '.') || (countPunct == 3  && var[length - 1] == '.'))
		{
		  if (var[length - 1] == ',')
		  commaCounter++;
		
		
		  if(commaCounter <= 1)
		  {		
		    decap2(index);		
		    theBreakSwapper(var, index, commaCounter);
//		    cout << index << " ";
		  }
		
		}

		 // cout << var << " ";
	}

 //       cout << index << " ";
	cout << endl;

 
 
	return 0;
}
