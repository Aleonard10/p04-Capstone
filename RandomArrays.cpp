#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <fstream>
#include "RandomArrays.h"
using namespace std;
//constructor
RandomArrays::RandomArrays()
{
   srand( time(NULL)); //seeds random numbers
   for (int i = 0; i < 10; i++) //iterates 10 times
   {
       randomNumber = rand() % 1000 + 1; //generates a random number between 1-1000
       array[i] = randomNumber; //puts random number into array
   }
}
//used to get the private value (array) out for the user passes in iteration value 
int RandomArrays::getArrayValue(int i)
{
    int temp = array[i]; //sets temp to the value of an array cell and
    return temp;         //returns it
}
//tells the user the value of the current cell in the array.
int RandomArrays::checkArray(int x)
{
    y = x;
    cout << "Number " << y << ": " << array[y] << endl; //outputs a message that displays the current cell and the current value of that cell
}
