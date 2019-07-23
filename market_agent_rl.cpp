#include <iostream>
#include <ctime>
#include <vector>

using namespace std;


const int stateSpace = 12;
const double gamma = 0.8;
const double epsilon = 0.2;
const double alpha = 0.1;
const int actionSpace = 10;
const int episodes = 100;

enum actions {bid_0, bid_1, bid_2, bid_3, bid_4, bid_5, bid_6, bid_7, bid_8, bid_9};

int currentState;

vector<int> states {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

vector<vector<double>> Q(stateSpace, vector<double>(actionSpace, 0));

void takeAction(int biddingAction)
{
  double offerPrice;
  
  switch (biddingAction)
    {
    case 0:
      offerPrice = 
  
  

void chooseAction(int currState)
{
  
  double rndVal = (float)(rand() % RAND_MAX);
  
  if (rndVal < epsilon)
    {
      getRandomAction();
    }
  else
    {
      int maxQValIndex = INT_MIN;
      
      for (int i = 0; i < actionSpace; i++)
	{
	  if (Q.at(currState).at(i) > max)
	    {
	      maxQValIndex = i;
	    }
	}
      
      takeAction()
      
      
      
  
  
  
  
  

void startEpisode(int initialState)
{
  
  currentState = initialState;
  
  clock_t timeStart = clock();
  
  do
    {
      chooseAction(currentState);
    } while((clock() - timeStart) / CLOCKS_PER_SEC >= 300);
}
      
  
  
  

int main()
{
  
  for (int i = 0; i < episodes; i++)
    {
      for (int j = 0; j < stateSpace; j++)
	{
	  startEpisode(states.at(j));
	}
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
  
}
  
  



