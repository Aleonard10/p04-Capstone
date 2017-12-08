#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
typedef chrono::high_resolution_clock Clock;

class RandomArrays
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
};

vector <int> arraySorter(vector <int > num)
{
     int i, j;
     int temp;   // holding variable
     int numLength = num.size( ); 
     for (i=0; i< (numLength -1); i++)    // element to be compared
    {
          for(j = (i+1); j < numLength; j++)   // rest of the elements
         {
                if (num[i] < num[j])          // descending order
               {
                        temp= num[i];          // swap
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
    ifstream oldRecord("Record.txt");
    oldRecord >> tOld;
    cout << tOld << endl;
    
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
        cout << "Congradulations, you set the new record!" << endl;
        ofstream newRecord("Record.txt");
        newRecord << tNew << endl;
        
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

    return 0;
}
