#include <iostream>
#include <fstream> /*file stream. needed to read data from the program into a file */

using namespace std;

struct test {
    string name;
    int score;
    char result;
};

typedef struct test Test;

int main ()

{
    cout << "           Score dictionary\n\n\n";
    cout << "This program will keep the score of student's results.\n";
    cout << "Select the amount of students that you are going to input the score of.\n";
    cin.ignore();

    system ("CLS");

    int number;
    cout << "How many students are you going to input in the system?\n";
    cin >> number;


    Test *students; //initalize a pointer variable of type Test (user-defined type)


    students = new(nothrow) Test[number]; //initliaze students pointer with dyanmic array of type Test.
    if (!students) //means if students == nullptr || students == 0;
    {
        std::cout << "Could not allocate memory. Please close the program and try again.";
        return 0;
    }
    else
        cout << "Memory address of students array is: " << &students  << endl;
    cin.ignore();
    system ("CLS");

    for (int i = 0; i < number ; i++)
    {
        cout << "Enter the details for student " << i + 1 << endl;
        cout << "Name of student: ";
        cin >> students[i].name;
        cout << "Student Score: ";
        cin >> students[i].score;

        if (students[i].score >= 90)
            students[i].result = 'A';
        else if (students[i].score >= 80 )
            students[i].result = 'B';
        else if (students[i].score >= 70 )
            students[i].result = 'C';
        else if (students[i].score >= 60 )
            students[i].result= 'D';
        else
            students[i].result = 'F';
    }

    system ("CLS");
    for (int i = 0; i < number ; i++)
    {
        cout << "Details for student " << i + 1 << endl;
        cout << "Name of student: " << students[i].name << endl;
        cout << "Student Score: " << students[i].score << endl;
        cout << "Student result: " << students[i].result << endl;
        cout << endl << endl << endl;

    }

    char choice;
    do
    {

        cout << "Would you like to save these record on a txt file? (y/n)";
        cin >> choice;
        if (!(choice == 'y' )|| (choice == 'n')) //NOTE: choice != 'y' || choice != 'n' won't work as it will always be true. You need to put a bracket and a '!' symbol instead.
        {
            cout << "Sorry come again. Please only write 'y' or 'n' next time.\n";
        }

    } while (!(choice == 'y' || choice == 'n'));

    if (choice == 'y')
    {
        ofstream studentsfile;
        studentsfile.open ("studentdata.txt");
        for (int i = 0; i < number ; i++)
            {
                studentsfile << "Details for student " << i + 1 << endl;
                studentsfile << "Name of student: " << students[i].name << endl;
                studentsfile << "Student Score: " << students[i].score << endl;
                studentsfile << "Student result: " << students[i].result << endl;
                studentsfile << endl << endl << endl;
            }
        studentsfile.close();
        cout << "File created.\n";
    }

    delete[] students; //this allows the memory allocated to the program to be deallocated and to be allowed to be used as memory for other applications in the operating system.
    return 0;
}
