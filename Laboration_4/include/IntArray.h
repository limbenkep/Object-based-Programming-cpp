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
using namespace std;

class IntArray
{
private:
    int*arr; //pointer to array
    size_t size; //actual size of the array
    size_t maxSize; //mazimum array capacity
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

    //member functions
    int randomNumber();
    void fillIntArray();
    void bubbleSort1();
    void bubbleSort2();
    void selectionSort();
    void insertionSort();
    void quickSort1(size_t first, size_t last);
    void quick1();
    void quickSort2(size_t first, size_t last);
    void quick2();
    void swapValue(int &a, int &b);
    void printArray();


};


#endif //LABORATION_4_INTARRAY_H
