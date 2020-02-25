//
// Created by limbe on 2020-02-23.
//
/*
 * That clas has an IntArray object for data member and have functions to for each sort type in IntArray class
 * (two variants of quick sort method, two variants of bubble sort, selection sort and insertion sort) which runs and
 * record the time for sorts for 10 different randomly filled arrays and computes the average time for each sort time
 * and prints the sort name, size of array and mean sort time on the screen and to a file
 * The function member  ' void allSortAlgorithm()' the above sort functions that allows the sorts and printing and
 * saving of results for all the different sort methods from one function
 */
#ifndef LABORATION_4_SORT_H
#define LABORATION_4_SORT_H
#include "IntArray.h"
#include <chrono>
#include <numeric>
#include <fstream>
#include <vector>

class Sort
{
private:
    IntArray intArray;
    //Const declaration
    const int numberOfRuns = 10;
    const char TAB = '\t';
    const string fileName{"result.txt"};

    /*void setIntArray(const IntArray &intArray);
    void printAndSave(const string &sortName, int pSize, double meanSortTime);
    double computeMeanTime(const vector<double>&sortDuration);
    void bubbleAlgorithm1();
    void bubbleAlgorithm2();
    void quickAlgorithm1();
    void quickAlgorithm2();
    void selectionAlgorithm();
    void insertionAlgorithm();*/

public:
    Sort();

    explicit Sort(const IntArray &intArray);

    virtual ~Sort();
    const IntArray &getIntArray() const;
    void allSortAlgorithm();

    void setIntArray(const IntArray &intArray);
    void printAndSave(const string &sortName, int pSize, double meanSortTime);
    double computeMeanTime(const vector<double>&sortDuration);
    void bubbleAlgorithm1();
    void bubbleAlgorithm2();
    void quickAlgorithm1();
    void quickAlgorithm2();
    void selectionAlgorithm();
    void insertionAlgorithm();
};



#endif //LABORATION_4_SORT_H
