#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

//srand((unsigned int)time(0));

const int stateSpace = 12;
const double gamma = 0.7;
const double epsilon = 0.3;
//double temperature = 10.0;
const double alpha = 0.2;
const int actionSpace = 3;
double rndVal;
bool random;
//const int episodes = 1000;

vector<int> currentState(24, 1);
vector<int> newState(24, 1);

vector<vector<vector<double>>> Q(24, vector<vector<double>>(stateSpace, vector<double>(actionSpace, 0.0)));


vector<int> bidIndex(24, 0);

//vector<double> profits(24, 0.0);

//vector<double> load(24, 0.0);

//vector<double> lmp(24, 0.0);

//vector<double> getActionProbs(int hour, int state);



int generateState(double load, double lmp)
{
	if (load >= 4000 && load <= 4900 && lmp >=0 && lmp <= 7)
	{
		return 0;
	}
	else if (load >= 4901 && load <= 5300 && lmp >=6 && lmp <= 18)
	{
		return 1;
	}
	else if (load >= 5301 && load <= 5600 && lmp >=5 && lmp <= 21)
	{
		return 2;
	}
	else if (load >= 5601 && load <= 5900 && lmp >=12 && lmp <= 24)
	{
		return 3;
	}
	else if (load >= 5901 && load <= 6600 && lmp >=10 && lmp <= 20)
	{
		return 4;
	}
	else if (load >= 6601 && load <= 6800 && lmp >=10 && lmp <= 20)
	{
		return 5;
	}
	else if (load >= 6801 && load <= 7300 && lmp >=12 && lmp <= 24)
	{
		return 6;
	}
	else if (load >= 7301 && load <= 7400 && lmp >=10 && lmp <= 20)
	{
		return 7;
	}
	else if (load >= 7401 && load <= 7500 && lmp >=8 && lmp <= 30)
	{
		return 8;
	}
	else if (load >= 7501 && load <= 7700 && lmp >=10 && lmp <= 25)
	{
		return 9;
	}
	else if (load >= 7701 && load <= 7900 && lmp >=12 && lmp <= 30)
	{
		return 10;
	}
	else
		return 11;
}

double findMax(int hour, int state)
{
  double max = DBL_MIN;
  for (int i = 0; i < actionSpace; i++)
  {
     if ((Q.at(hour).at(state).at(i) - max) > 0.001)
     {
	max = Q.at(hour).at(state).at(i);
     }
	  
  }

	
  return max;
}
	

void updateQ(int hour, double reward, int oldState, int newState, int actionIndex)
{
  double newQ = Q.at(hour).at(oldState).at(actionIndex) + alpha * (reward + gamma * findMax(hour, newState) - Q.at(hour).at(oldState).at(actionIndex));
	
  Q.at(hour).at(oldState).at(actionIndex) = newQ;
}
	
	

int getRandomAction(int currentState)
{
  int randomActionIndex = rand() % (actionSpace - 0 );
  //cout << "The action index is: " << randomActionIndex << endl;
  //newState = takeAction(currentState, randomActionIndex);
  return randomActionIndex;
}
  
  

int chooseAction(int hour, int currState)
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
  
 if (random)
    {
     maxQValIndex = getRandomAction(currState);
    }
  else
    {
    
      
      for (int i = 0; i < actionSpace; i++)
	{
	  if ((Q.at(hour).at(currState).at(i) - maxVal) > 0.001)
	    {
	      maxVal = Q.at(hour).at(currState).at(i);
	      maxQValIndex = i;
	    }
	}
    }

  return maxQValIndex;
  }



vector<int> getAgentOfferPriceIndices(vector<double>& loadPred, vector<double>& lmpPred, vector<double>& rewards)
{

  int getActionIndex;
	
  rndVal = ((double)rand() / (double)RAND_MAX);

  if (rndVal < epsilon)
  {
    random = true;
  }
  else
  {
    random = false;
  }

  
  
  for (int i = 0; i < 24; i++)
    {
      newState.at(i) = generateState(loadPred.at(i), lmpPred.at(i));
      updateQ(i, rewards.at(i), currentState.at(i), newState.at(i), bidIndex.at(i));
	  


      currentState.at(i) = newState.at(i);
      getActionIndex = chooseAction(i, currentState.at(i));
      bidIndex.at(i) = getActionIndex;
      
    }

  return bidIndex;
}

  
      
  
