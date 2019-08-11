#include <cmath>
#include <vector>

using namespace std;

extern int temperature;

extern int actionSpace;

extern vector<vector<vector<double>>> Q;

vector<double> actionProbs(7, 0.0);

vector<double> getActionProbs(int hour, int state)
{
  double total = 0.0;
  double 

  for (int i = 0; i < actionSpace; i++)
    {
      total += exp(Q.at.(hour).at(state).at(i) / temperature);
    }

  for (int i = 0; i < actionSpace; i++)
    {
      actionProbs.at(i) = exp(Q.at(hour).at(state).at(i)) / total;
    }

  return actionProbs;
}

  
