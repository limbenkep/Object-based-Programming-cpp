//
// Created by limbe on 2020-02-19.
//
/*
 * The class IntArray has an array , maximum size and size of the array as member data. This class has functions to
 * load the array with random numbers and functions to sort the array using two variants of quick sort method,
 * two variants of bubble sort, selection sort and insertion sort
 * it also has assigment,equal to, not eual to and less than overload constructors
 */
#ifndef LABORATION_4_INTARRAY_H
#define LABORATION_4_INTARRAY_H


#include <cstddef>
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <numeric>
#include <fstream>
#include <vector>

using namespace std;

class IntArray
{
private:
    int*arr; //pointer to array
    size_t size; //actual size of the array
    size_t maxSize; //mazimum array capacity

    //Const declaration
    const int numberOfRuns = 10;
    const char TAB = '\t';
    const string fileName{"result.txt"};

    //member functions
    //generates a random integer between 0 to maxSize-1 and returnn the integer
    int randomNumber();
    // fills array with randomly generated numbers
    void fillIntArray();
    //Sort the array by bubble sort without taking consideration if array is sorted or not
    void bubbleSort1();
    //sort the array by bubble sort taking consideration if array is sorted or not
    void bubbleSort2();
    //sort array by selection sort
    void selectionSort();
    //sort array by insertion sort
    void insertionSort();

    void printArray();
    //print stats on screen and save to file
    void printAndSave(const string &sortName, double meanSortTime);
    //compute average time from vector and returns the avergae
    double computeMeanTime(const vector<double>&sortDuration);
    // function that calls quickSort function
    void quick(int *a, int n);
    //sort array by quick sort algorithm
    void quickSort(int *a, int first, int last);
    //calls function to fill array, start clock, calls function to sort by bubbleSort1, stop clock, compute time,  call
    // function to print and save save stats
    void bubbleAlgorithm1();
    //calls function to fill array, start clock, calls function to sort by bubbleSort2, stop clock, compute time,  call
    // function to print and save save stats
    void bubbleAlgorithm2();
    //calls function to fill array, start clock, calls function to sort by quickSort, stop clock, compute time,  call
    // function to print and save save stats
    void quickAlgorithm();
    //calls function to fill array, start clock, calls function to sort by selectionsort, stop clock, compute time,  call
    // function to print and save save stats
    void selectionAlgorithm();
    //calls function to fill array, start clock, calls function to sort by insertionSort, stop clock, compute time,  call
    // function to print and save save stats
    void insertionAlgorithm();

public:
    IntArray();
    explicit IntArray(size_t pMaxSize);

    virtual ~IntArray();


    //getters and setters
    int *getArr() const;

    size_t getSize() const;

    void setSize(size_t size);
    //asssignment overload operator
    IntArray& operator=(const IntArray &pIntArr);
    //Index operator
    int& operator[] (int index);
    //overloaded operator for equal to operator
    bool operator==(const IntArray &pIntArr)const;
    //overloaded operator for not equal to  operator
    bool operator!=(const IntArray &pIntArr)const;
    //overloaded operator for less operator
    bool operator<(const IntArray &pIntArr)const;


    //calls functions for all the sorting algorithms; insertionAlgorithm, bubbleAlgorithm1, bubbleAlgorithm2,
    // selectionAlgorithm,quickAlgorithm
    void allSortAlgorithm();




};


#endif //LABORATION_4_INTARRAY_H
