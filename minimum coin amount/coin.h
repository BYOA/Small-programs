using namespace std;
void coinSort (vector<int> &coins,  bool (*comparision)(int, int));
void displayCoinOrder (vector<int> coinOrder);
bool ascending (int x, int y);
int tallyCalculation (vector<int> coins, vector<int> &total, int value);
