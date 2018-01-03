#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void userPrompt (vector<string> &n, vector<double> &a);
void vectorCopy (vector<string> &name, vector<double> &age);
void display (const vector<string> &n, const vector<double> &a);

int main()
{
    vector<string>name(5);
    vector<double>age(5);

    userPrompt (name, age);
    vectorCopy (name, age);
    display (name, age);



    return 0;
}

void userPrompt (vector<string> &n, vector<double> &a)
{
    for (int i = 0; i < n.size(); i++)
    {
        cout << "Enter name and age for user " << i+1 << '\n' << "Name: ";
        cin >> n[i];
        cout << "\nAge: ";
        cin >> a[i];

    }
}


void vectorCopy (vector<string> &name, vector<double> &age)
{
    vector<string>nameCopy(5);
    vector<double>ageCopy(5);

    for (int i = 0; i < name.size(); i++)
    {
        cout << "\nName: " << name[i];
        cout << "\nAge: " << age[i];
        cout << "\n\n";

        nameCopy[i]= name[i];
        ageCopy[i]= age[i];
    }

    sort(name.begin(),name.end());

    for ( int i = 0; i < name.size(); i++)
    {
        for (int j = 0; j < name.size(); j++)
        {
            if (nameCopy[j]== name[i])
            {
                age[i] = ageCopy[j];
                break;
            }
        }
    }
}

void display (const vector<string> &n, const vector<double> &a)
{
    for (int i = 0; i < n.size(); i++)
    {
        cout << "\nName: " << n[i];
        cout << "\nAge: " << a[i];
        cout << "\n\n";
    }
}
