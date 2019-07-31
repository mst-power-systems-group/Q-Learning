#include <vector>

using namespace std;

int generateState(double load, double lmp);

extern vector<vector<vector<double>>> Q;
extern const int actionSpace;

vector<int> actions(24, 0);

int findMaxAction(int hour, int state)
{
  int maxIndex = 0;
  double maxVal = 0.0;

  for (int i = 0; i < actionSpace; i++)
    {
      if ((Q.at(hour).at(state).at(i) - maxVal) > 0.001)
	{
	  maxVal = Q.at(hour).at(state).at(i);
	  maxIndex = i;
	}

    }

  return maxIndex;
}

vector<int> getResult(vector<int>& loadValue, vector<int>& lmpValue)
{
  int state;
  for (int i = 0; i < 24; i++)
    {
      state = generateState(loadValue.at(i), lmpValue.at(i));
      actions.at(i) = findMaxAction(i, state);
    }

  return actions;
}
