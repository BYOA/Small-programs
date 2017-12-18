#include <iostream>
#include <utility>

using namespace std;


bool ascending (int x, int y);


int main ()
{
    const int MAX = 5;
    int numberArray [MAX] = {4,3, 2, 1 ,5};

    for (int startIndex = 0; startIndex < MAX ; startIndex++)
    {
        
        int smallestIndex = startIndex;
        //find the smallest number and its element placement. 
        for (int currentIndex = startIndex + 1; currentIndex < MAX; currentIndex++)
        {
            if (ascending (numberArray[smallestIndex], numberArray[currentIndex]))
            {
                smallestIndex = currentIndex;
            }
        }

        // Swap our start element with our smallest element
        std::swap(numberArray[startIndex], numberArray[smallestIndex]);
    }

    for (int index = 0; index < MAX; index++)
    {
        cout << numberArray[index];
    }
}


bool ascending (int x, int y)
{
    return x > y;
}
