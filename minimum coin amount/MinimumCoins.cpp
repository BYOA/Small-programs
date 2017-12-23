#include <iostream>
#include <vector>
#include <algorithm> //for swap
#include "coin.h"


int main()
{
    int answer;
    cout << "Input cents amount to find the minimum amount of coins needed to make that amount.\n cents:";
    cin >> answer;
    int res;

    vector<int> coins = {5, 10 , 20 ,50 , 100 ,200}; //coins in cents. 
    vector <int> total(coins.size());

//sorting occurs from ascending order to streamline user input. This is done as a pre-requiste for tallyCalculation function. 
    cout << "\n\nBEFORE SORT\n";
    displayCoinOrder(coins);
    coinSort (coins, ascending);
    cout << "\n\nAFTER SORT\n";
    displayCoinOrder(coins);
    res = tallyCalculation (coins, total, answer);

    cout << "\n\n\nThe minimum amount of coins to obtain " << answer << " cents is: " << res << endl << endl;

    for (int i = 0; i < coins.size() ; i++)
    {
        cout << "\n\n" << total[i] << ' ' << coins[i] << " cent coins.";

    }
}


void coinSort (vector<int> &coins,  bool (*comparision)(int, int))
{
    for (int startIndex = 0; startIndex < coins.size(); startIndex++)
    {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < coins.size();currentIndex++)
        {
            if (comparision(coins[smallestIndex], coins[currentIndex]))
            {
                smallestIndex = currentIndex;
            }
        }
        swap(coins[startIndex], coins[smallestIndex]);
    }
}


bool ascending (int x, int y)
{
 return x < y;
}


void displayCoinOrder (vector<int> coinOrder)
{
    for (int i = 0; i < coinOrder.size(); i++)
    {
        cout << coinOrder[i] << ' ';
    }

    cout << "\n\nSize of vector is: " << coinOrder.size() << "\n";
}


int tallyCalculation (vector<int> coins, vector<int> &total, int value)
{
    int overallAmount = 0;
    for (int i = 0; i < coins.size(); i++)
    {
        total[i] = 0; //intialise to not include garbage in values.

        if (value >= coins[i])
        {
            for (; value >= coins[i] ; total[i]++)
            {
                cout << coins[i] << ' ';
                value -= coins[i];
            }
        }

        if ((value >=3 && value <=4) && coins[i] == 5) //for 5 cent coin
        {
            cout << coins[i] << ' ';
            total[i]++;
            value = 0;
        }
        overallAmount += total[i];
    }
    return overallAmount;
}
