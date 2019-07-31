#include <iostream>
#include <fstream>

using namespace std;

ofstream dataFile;

void writeFile(double profit, int timeSteps)
{
  if (!dataFile.is_open())
    {
      dataFile.open("rl_data.dat");
    }

  dataFile << timeSteps << "\t" << profit << endl;

}

void closeFile()
{
  if (dataFile.is_open())
    {
      dataFile.close();
    }
  else
    {
      cout << "No open file exists. First create one and then try to close it!\n";
    }
}





  


  


  
