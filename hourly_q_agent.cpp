#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cfloat>

using namespace std;

//srand((unsigned int)time(0));

const int stateSpace = 28;
const double gamma = 0.7;
const double epsilon = 0.3;
//double temperature = 10.0;
const double alpha = 0.98;
const int actionSpace = 200;
double rndVal;
bool randomValue;
//const int episodes = 1000;

int currentState = 1;
int newState;

vector<vector<double>> Q(stateSpace, vector<double>(actionSpace, 0.0));


int bidIndex = 0;

//vector<double> profits(24, 0.0);

//vector<double> load(24, 0.0);

//vector<double> lmp(24, 0.0);

//vector<double> getActionProbs(int hour, int state);



int generateState(double load, double lmp)
{
	if (load >= 4000 && load <= 4999 && lmp >=0 && lmp <= 5)
	{
		return 0;
	}
	else if (load >= 4000 && load <= 4999 && lmp > 5 && lmp <= 10)
	{
		return 1;
	}
	else if (load >= 4000 && load <= 4999 && lmp >10 && lmp <= 15)
	{
		return 2;
	}
	else if (load >= 4000 && load <= 4999 && lmp >15 && lmp <= 20)
	{
		return 3;
	}
	else if (load >= 4000 && load <= 4999 && lmp >20 && lmp <= 25)
	{
		return 4;
	}
	else if (load >= 4000 && load <= 4999 && lmp >=50 && lmp <= 60)
	{
		return 5;
	}
	else if (load >= 4000 && load <= 4999 && lmp >60 && lmp <= 70)
	{
		return 6;
	}
	else if (load > 4999 && load <= 5999 && lmp >=0 && lmp <= 5)
	{
		return 7;
	}
	else if (load > 4999 && load <= 5999 && lmp >5 && lmp <= 10)
	{
		return 8;
	}
	else if (load > 4999 && load <= 5999 && lmp >10 && lmp <= 15)
	{
		return 9;
	}
	else if (load > 4999 && load <= 5999 && lmp >15 && lmp <= 20)
	{
		return 10;
	}
	else if (load > 4999 && load <= 5999 && lmp >20 && lmp <= 25)
	{
		return 11;
	}
	else if (load > 4999 && load <= 5999 && lmp >=50 && lmp <= 60)
	{
		return 12;
	}
	else if (load >4999 && load <= 5999 && lmp >60 && lmp <= 70)
	{
		return 13;
	}
	
	else if (load >5999 && load <= 6999 && lmp >=0 && lmp <= 5)
	{
		return 14;
	}
	else if (load >5999 && load <= 6999 && lmp >5 && lmp <= 10)
	{
		return 15;
	}
	else if (load >5999 && load <= 6999 && lmp >10 && lmp <= 15)
	{
		return 16;
	}
	else if (load >5999 && load <= 6999 && lmp >15 && lmp <=20)
	{
		return 17;
	}
	else if (load >5999 && load <= 6999 && lmp >20 && lmp <= 25)
	{
		return 18;
	}
	else if (load >5999 && load <= 6999 && lmp >=50 && lmp <= 60)
	{
		return 19;
	}
	else if (load >5999 && load <= 6999 && lmp >60 && lmp <= 70)
	{
		return 20;
	}
	else if (load >6999 && load <= 8500 && lmp >=0 && lmp <= 5)
	{
		return 21;
	}
	else if (load >6999 && load <= 8500 && lmp >5 && lmp <= 10)
	{
		return 22;
	}
	else if (load >6999 && load <= 8500 && lmp >10 && lmp <= 15)
	{
		return 23;
	}
	else if (load >6999 && load <= 8500 && lmp >15 && lmp <= 20)
	{
		return 24;
	}
	else if (load >6999 && load <= 8500 && lmp >20 && lmp <= 25)
	{
		return 25;
	}
	else if (load >6999 && load <= 8500 && lmp >= 50 && lmp <= 60)
	{
		return 26;
	}
	else if (load >6999 && load <= 8500 && lmp >60 && lmp <= 70)
	{
		return 27;
	}
	else
	  {
	    return -1;
	  }
	
}

double findMax(int state)
{
  double max = DBL_MIN;
  for (int i = 0; i < actionSpace; i++)
  {
     if ((Q.at(state).at(i) - max) > 0.001)
     {
	max = Q.at(state).at(i);
     }
	  
  }

	
  return max;
}
	

void updateQ(double reward, int oldState, int newState, int actionIndex)
{
  double newQ = Q.at(oldState).at(actionIndex) + alpha * (reward + gamma * findMax(newState) - Q.at(oldState).at(actionIndex));
	
  Q.at(oldState).at(actionIndex) = newQ;
}
	
	

int getRandomAction(int currentState)
{
  int randomActionIndex = rand() % (actionSpace - 0 );
  //cout << "The action index is: " << randomActionIndex << endl;
  //newState = takeAction(currentState, randomActionIndex);
  return randomActionIndex;
}
  
  

int chooseAction(int currState)
{
  int maxQValIndex = 0;
	
  double maxVal = INT_MIN;
  //double cumulativeProb = 0.0;
  //vector<double> probs(7);
  //probs = getActionProbs(hour, currState);
  
  

 /** for (int i = 0; i < probs.size(); i++)
  {
     cumulativeProb += probs.at(i);
     if (cumulativeProb > rndVal)
     {
	maxQValIndex = i;
	break;
     }
  }**/
  
 if (randomValue)
    {
     maxQValIndex = getRandomAction(currState);
    }
  else
    {
    
      
      for (int i = 0; i < actionSpace; i++)
	{
	  if ((Q.at(currState).at(i) - maxVal) > 0.001)
	    {
	      maxVal = Q.at(currState).at(i);
	      maxQValIndex = i;
	    }
	}
    }

  return maxQValIndex;
}



int getAgentOfferPriceIndices(double loadPred, double lmpPred, double rewards)
{

  int getActionIndex;
	
  rndVal = ((double)rand() / (double)RAND_MAX);

  if (rndVal < epsilon)
  {
    randomValue = true;
  }
  else
  {
    randomValue = false;
  }

  
  
 
   newState = generateState(loadPred, lmpPred);
   updateQ(rewards, currentState, newState, bidIndex);
   currentState = newState;
   getActionIndex = chooseAction(currentState);
   bidIndex = getActionIndex;
      

  return bidIndex;
}

int main()
{
  
  int getAction = getAgentOfferPriceIndices(5932.45, 17.23, -131.34);
  
  cout << getAction << endl;
  
  cout << Q.at(1).at(0) << endl;
  
  return 0;
}
