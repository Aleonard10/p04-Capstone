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


/*class RandomArrays //class commented out, class .h and .cpp files used instead
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

void saveRecord(int x) //int x = record time (in seconds) //This function saves the Record 
{
    cout << "Congradulations, you set the new record!" << endl;
    ofstream newRecord("Record.txt"); //Outputs the new record to file Record.txt
    newRecord << x << endl;
}
int loadRecord()//This function loads the Record
{
    int x; //Value used to store the record being brought in
    ifstream oldRecord("Record.txt"); //Opens Record.txt
    oldRecord >> x; //gives x the value stored in Record.txt
    cout <<"Current record: " << x << " seconds." << endl; //Displays the record for the user
    return x;
}
vector <int> arraySorter(vector <int > num)//This function is used to sort the values in the array into a vector of the same size
{
     int i, j; // integers used for iteration
     int temp; // integer used to temporarily store the value of the first array being compared
     int numLength = num.size( ); //Used to get the size of the array (10)
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
     return num; //returns a new vector that is sorted in decending order
}

int main()
{
    int tOld;  //variable used to store old record being brought in
    int count; //variable used to store wether or not to run the main loop
    count = 0; 
    while(count <1) //main while loop, used to determine when the program is finished, and to allow replayability
    {
    tOld = loadRecord(); //executes load function and sets it equal to an integer value
    vector <int> tempVector; //creates a temporary vector
    cout << "Sort the numbers from greatest to least and try for the fastest time." << endl;
    RandomArrays randomArray; //creates an object of class RandomArrays and populates an array of size 10 with random numbers between 1-1000
    for (int i = 0; i < 10; i++) //iterates 10 times
    {
        randomArray.checkArray(i); //gets the values out of the array (private variable) and couts them for the user


    }

    auto t1 = Clock::now(); //Takes the current time and stores it in a variable as part of the chrono library.

    for (int i = 0; i < 10; i++) //iterates 10 times
    {
        int temp = randomArray.getArrayValue(i); //creates an integer to store the value of the array
        tempVector.push_back(temp); //stores the integer value into a vector 

    }
    vector <int> sortedVector = arraySorter(tempVector); //sorts the newly stored integers in order from highest to lowest and stores them in a vector

    int i = 0;
    while(i < 10) //loop tha allows user unlimited chances to guess the order of the 10 numbers
    {
        cout << "Enter your guess for the " << i+1 << "th largest number." << endl;
        int x; //variable to store users guess
        cin >> x;
        if (tempVector[x] == sortedVector[i]) //checks user guess for correctness
        {
            cout << "Correct" << endl;
            i++; //iterates the while loop
        }
        else //condition if the users guess is incorrect
        {
            cout << "Guess again" << endl; //does not iterate allows user to guess again for the (i+1)th term
        }
    }
    auto t2 = Clock::now(); //takes time at current moment and stores it in a variable
    int tNew = chrono::duration_cast<chrono::seconds>(t2 - t1).count(); // calculates the difference between start time and end time and stores it in variable tNew
    cout << "Your time was: " << tNew << " seconds." << endl; //outputs the users time.
    if (tNew < tOld) //checks if the users time was lower than the previous record
    {
        saveRecord(tNew); //saves the new record over the old record in Record.txt by passing tNew into the saveRecord function
        count++; //iterates the main loop

    }
    else //condition if the old record is lower than the new time.
    {
        cout << "You did not set a new record, would you like to play again? (Y/N)" << endl;
        char yesno; 
        cin >> yesno; //user input Y or y to continue or any other key to quit out
        if (yesno == 'Y' || yesno =='y') //checks user input for being a Y or y
        {
            cout << "You selected to play again!." << endl; // does not iterate the while loop
        }
        else //iterates the while loop and closes the program
        {
            count++;
        }
    }
    }

    return 0;
}
