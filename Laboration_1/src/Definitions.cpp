#include "Prototypes.h"
#include <iostream>
#include <random>
#include <iomanip>
using namespace std;


int getNumber()
{
    int size = 0;
    cout << "Input size of array: ";
    cin >> size;
    while (size < 1)
    {
        cout << "Size must be greater than 1. Input size of array: ";
        cin >> size;
    }
    return size;
}

int randomNumber(const int min, const int max)
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}




int maxValueOfArray(int arr[], int size)
{
    int *arrMax = arr;
    int *e = arr + size;
    for (int *ia = arr; ia < e; ia++) {
        if (*arrMax < *ia) {
            *arrMax = *ia;
        }
    }
    return *arrMax;
}

int minValueOfArray(int arr[], int size)
{
    int *arrMin = arr;
    int *e = arr + size;
    for (int *ia = arr; ia < e; ia++) {
        if (*arrMin > *ia) {
            *arrMin = *ia;
        }
    }
    return *arrMin;
}

int sumOfArray(int arr[], int size)
{
    int *e = arr + size;// e is pointer just pass the last element of the array
    int sum = 0;
    for (int *ia = arr; ia != e; ia++)
    {
        sum += *ia;
    }
    return (sum);
}


void printArray(int arr[], int size)
{
    int *e = arr + size;// e is pointer just pass the last element of the array
    int counter = 0;
    for (int *ia = arr; ia < e; ia++)
    {
        cout << setw(8) << right << *ia;
        counter++;
        if(counter % 10 == 0)
        {
            cout << endl;
        }
        if ((size>200) &&(counter % 200 == 0) )
        {
            cout << "You can view 200 elements at a time." << endl<< "There are " << size - counter
            << "elements left to view." << endl<< "Enter'y' to contimue viewing or 'n' to end veiwing.";
            char ch;
            cin>> ch;
            if (ch == 'y')
            {
                continue;
            }
            else if (ch == 'n')
            {

                break;
            }
            else
            {
                cout << "Invalid choice" << endl;
                break;
            }

        }


    }
    cout << endl;

}


void arrayStatistics(int myArray[], int size)
{
    cout << endl << endl << "Array statistics: "<<endl;
    int largestValue = maxValueOfArray(myArray, size);
    int smallestValue = minValueOfArray(myArray, size);
    int sum = sumOfArray(myArray, size);
    cout << "The maximum number is "<< largestValue << endl;
    cout << "The minimum number is "<< smallestValue << endl;
    cout << "The sum of the array is "<< sum << endl;

}

