#include <iostream>
#include <vector>

using namespace std;


extern vector<vector<vector<double>>> Q;

void printQTable()
{
  
  for(int i = 0; i < 24; i++)
    {
      cout << "Hour" << " " << (i + 1) << ":" << "\t";
      for(int j = 0; j < 12; j++)
	{
	  for (int k = 0; k < 3; k++)
	    {
	      cout << setw(5) << Q.at(i).at(j).at(k);
	    }
	  cout << endl;
	  cout << "       " << "\t";
	}
      cout << endl;
      cout << endl;

    }

  cout << endl;
}
