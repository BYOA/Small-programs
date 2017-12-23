#include <iostream>
#include <vector>

using namespace std;
/*breakup into functions.*/

int main()
{
    int answer;
    cout << "Input coin amount in cents to find the minimum amount of coins to become the equivlant of it.\n cents:";
    cin >> answer;
    double copyAnswer = answer;

    vector<int> coins = {50, 20, 10, 5}; //coins in cents. 
            vector <int> total(4);
    int overall = 0;


    for (int i = 0; i < coins.size() ; i++)
    {
        int tally = 0;
        if (answer >= coins[i])
        {
            for (;answer >=coins[i];tally++)
            {
                cout << coins[i] << ' ';
                answer -= coins[i];
            }

        }
        /*different if statements to account for numbers that need multiple different types of coins*/
        if ((answer >=3 && answer <=4) && coins[i] == 5) //accounting for rounding
           {
                cout << coins[i] << ' ';
               tally++;
           }

        overall += tally;
        total[i] = tally;
    }

cout << "\n\n\nThe minimum amount of coins to obtain " << copyAnswer << " cents is: " << overall << endl << endl;

    for (int i = 0; i < coins.size() ; i++)
    {
        cout << "\n\n" << total[i] << ' ' << coins[i] << " cent coins.";

    }
}
