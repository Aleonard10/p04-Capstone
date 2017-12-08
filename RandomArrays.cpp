#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <fstream>
#include "RandomArrays.h"
using namespace std;

RandomArrays::RandomArrays()
{
   srand( time(NULL));
   for (int i = 0; i < 10; i++)
   {
       randomNumber = rand() % 1000 + 1;
       array[i] = randomNumber;
   }
}

int RandomArrays::getArrayValue(int i)
{
    int temp = array[i];
    return temp;
}
int RandomArrays::checkArray(int x)
{
    y = x;
    cout << "Number " << y << ": " << array[y] << endl;
}
