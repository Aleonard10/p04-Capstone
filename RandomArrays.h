#ifndef RANDOMARRAYS_H
#define RANDOMARRAYS_H

class RandomArrays
{
    public:
        int getArrayValue(int i); //function Protype, this function is used to get the values of each cell of the array out as an integer value passing through int i for iteration
        int checkArray(int x); //This allows the user to see the values of both the current cell and the value within that cell
        RandomArrays(); //constructor, creates an array of size 10 and populates it with random integers between 1-1000
    private:
        int y; //temporary integer value used to store integers
        int array[10]; //array to be used for random numbers
        int randomNumber; //integer to temporarily store random numbers and put them into array
        int sortedArray[10]; //array used to store the values of the first array in order from greatest to least
};
#endif
