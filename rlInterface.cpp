#include <vector>

using namespace std;

vector<int> getAgentOfferPriceIndices(vector<double>& loadPred, vector<double>& lmpPred, vector<double>& rewards);


vector<double> loadVal(24, 0.0);
vector<double> lmpVal(24, 0.0);
vector<double> profitVal(24, 0.0);


vector<int> startQLearning(vector<double>& loadValPred, vector<double>& lmpValPred, vector<double>& profitValPred)
{

  for (int i = 0; i < 24; i++)
    {
      loadVal.at(i) = loadValPred.at(i);
      lmpVal.at(i) = lmpValPred.at(i);
      profitVal.at(i) = profitValPred.at(i);
    }
      
  return getAgentOfferPriceIndices(loadVal, lmpVal, profitVal);
}
