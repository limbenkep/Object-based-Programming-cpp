#include "Prototypes.h"
#include "memstat.hpp"
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

int main()
{
    int size = getNumber();

    int *myArray = new int[size];

    // FILL ARRAY ELEMENTS
    for (int i = 0; i < size; i++)
    {
        myArray[i] = randomNumber(MIN_VALUE, MAX_VALUE);
    }

    printArray(myArray, size);
    arrayStatistics(myArray, size);

    delete[]myArray;
    return 0;
}
