#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <fstream>
#include "RandomArrays.h"
using namespace std;
typedef chrono::high_resolution_clock Clock;

/*class RandomArrays
{
    public:
//===================================================================//
        RandomArrays()
        {
            srand( time(NULL));
            for (int i = 0; i < 10; i++)
            {
                randomNumber = rand() % 1000 + 1;
                array[i] = randomNumber;
            }
        }
//===================================================================//
        int getArrayValue(int i)
        {
            int temp = array[i];
            return temp;
        };
//===================================================================//
        int checkArray(int x)
        {
            y = x;
            cout << "Number " << y << ": " << array[y] << endl;
        }

    private:
        int y;
        int array[10];
        int randomNumber;
        int sortedArray[10];
}; */

void saveRecord(int x)
{
    cout << "Congradulations, you set the new record!" << endl;
    ofstream newRecord("Record.txt");
    newRecord << x << endl;
}

int loadRecord()
{
    int x;
    ifstream oldRecord("Record.txt");
    oldRecord >> x;
    cout <<"Current record: " << x << " seconds." << endl;
    return x;
}
vector <int> arraySorter(vector <int > num)
{
     int i, j;
     int temp;
     int numLength = num.size( );
    for (i=0; i< (numLength -1); i++)
    {
         for(j = (i+1); j < numLength; j++)
         {
               if (num[i] < num[j])
               {
                        temp= num[i];
                        num[i] = num[j];
                        num[j] = temp;
               }
          }
     }
     return num;
}

int main()
{
    int tOld;
    int count;
    count = 0;
    while(count <1)
    {
    tOld = loadRecord();
    vector <int> tempVector;
    cout << "Sort the numbers from greatest to least and try for the fastest time." << endl;
    RandomArrays randomArray;
    for (int i = 0; i < 10; i++)
    {
        randomArray.checkArray(i);


    }

    auto t1 = Clock::now();

    for (int i = 0; i < 10; i++)
    {
        int temp = randomArray.getArrayValue(i);
        tempVector.push_back(temp);

    }
    vector <int> sortedVector = arraySorter(tempVector);

    int i = 0;
    while(i < 10)
    {
        cout << "Enter your guess for number " << i << endl;
        int x;
        cin >> x;
        if (tempVector[x] == sortedVector[i])
        {
            cout << "Correct" << endl;
            i++;
        }
        else
        {
            cout << "Guess again" << endl;
        }
    }
    auto t2 = Clock::now();
    int tNew = chrono::duration_cast<chrono::seconds>(t2 - t1).count();
    cout << "Your time was: " << tNew << " seconds." << endl;
    if (tNew < tOld)
    {
        saveRecord(tNew);
        count++;

    }
    else
    {
        cout << "You did not set a new record, would you like to play again? (Y/N)" << endl;
        char yesno;
        cin >> yesno;
        if (yesno == 'Y' || yesno =='y')
        {
            cout << "You selected to play again!." << endl;
        }
        else
        {
            count++;
        }
    }
    }

    return 0;
}
