#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;


const int stateSpace = 12;
const double gamma = 0.8;
const double epsilon = 0.2;
const double alpha = 0.1;
const int actionSpace = 3;
const int episodes = 1000;

//enum actions {bid_0, bid_1, bid_2, bid_3, bid_4, bid_5, bid_6, bid_7, bid_8, bid_9};

int currentState;

//vector<int> states {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

vector<vector<double>> Q(stateSpace, vector<double>(actionSpace, 0));

int generateState(double load, double lmp)
{
	if (load >= 4000 && load <= 4600 && lmp >=1 && lmp <= 6)
	{
		return 0;
	}
	else if (load >= 4601 && load <= 5000 && lmp >=7 && lmp <= 15)
	{
		return 1;
	}
	else if (load >= 5001 && load <= 5400 && lmp >=16 && lmp <= 23)
	{
		return 2;
	}
	else if (load >= 5401 && load <= 5900 && lmp >=24 && lmp <= 30)
	{
		return 3;
	}
	else if (load >= 5901 && load <= 6300 && lmp >=31 && lmp <= 36)
	{
		return 4;
	}
	else if (load >= 6301 && load <= 6700 && lmp >=37 && lmp <= 44)
	{
		return 5;
	}
	else if (load >= 6701 && load <= 7100 && lmp >=45 && lmp <= 52)
	{
		return 6;
	}
	else if (load >= 7101 && load <= 7400 && lmp >=53 && lmp <= 60)
	{
		return 7;
	}
	else if (load >= 7401 && load <= 7700 && lmp >=61 && lmp <= 65)
	{
		return 8;
	}
	else if (load >= 7701 && load <= 8000 && lmp >=66 && lmp <= 72)
	{
		return 9;
	}
	else if (load >= 8001 && load <= 8300 && lmp >=73 && lmp <= 78)
	{
		return 10;
	}
	else
		return 11;
}

int getState()
{
	//Haotian please get the LMP and the Load
	
	int currentState = generateState(/*load, lmp */);
		
	return currentState;
}
	

void updateQ(double reward, int oldState, int newState, int actionIndex)
{
	double newQ = (1 - alpha) * Q.at(oldState).at(actionIndex) + alpha * (reward + gamma * newState );
	
	Q.at(oldState).at(actionIndex) = newQ;
}
	
	

int takeAction(int currentState, int actionIndex)
{
  	double profit;
	
	double nextLoad;
	double nextLMP;
	
	int oldState = currentState;
	int newState;
	
	  switch(actionIndex)
	  {
		  case 0:
			  profit = //Haotian generate the MCP and send the value to the Environment;
		          nextLoad = // ""
			  nextLMP = // ""
			  break;
		  case 1:
			  profit = //Generate next 10% and send to the simulator
			  nextLoad = //
			  nextLMP = //
			  break;
		  case 2:
			  profit  = //Generate next 20%...
			  nextLoad = //
			  nextLMP = //
			  break;
	  }
	
	newState = generateState(nextLoad, nextLMP);
	
	updateQ(profit, oldState,newState, actionIndex);
	
	return newState;
	
	
}

int getRandomAction(int currentState)
{
	int newState;
  	int randomActionIndex = rand() % (actionSpace - 0 + 1);
	newState = takeAction(currentState, randomActionIndex);
	return newState;
}
  
  

int chooseAction(int currState)
{
  int newState;
  
  double rndVal = (float)(rand() % RAND_MAX);
  
  if (rndVal < epsilon)
    {
     newState =  getRandomAction(currState);
    }
  else
    {
      int maxQValIndex = 0;
      
      for (int i = 0; i < actionSpace; i++)
	{
	  if (Q.at(currState).at(i) > maxQValIndex)
	    {
	      maxQValIndex = i;
	    }
	}
    }
	
      
     newState = takeAction(currState, maxQValIndex);
	  
     return newState;
  }
      
      
      
  
  
  
  
  

void startEpisode()
{
  currentState = getState(); 
  int newState;
  
  clock_t timeStart = clock();
  
  do
    {
      
      newState = chooseAction(currentState);
      currentState = newState;
    } while((clock() - timeStart) / CLOCKS_PER_SEC >= 300);
}
      
  
  
  

int main()
{
  
  for (int i = 0; i < episodes; i++)
    {

	  startEpisode();
    }
  
  //Printing the Q-table
  
  for (int i = 0; i < stateSpace; i++)
    {
      for (int j = 0; j < actionSpace; j++)
	{
	  cout << setw(5) << Q.at(i).at(j);
	}
      cout << endl;
    }
  
  
  cout << endl;
	
  return 0;
  
}
  
  



