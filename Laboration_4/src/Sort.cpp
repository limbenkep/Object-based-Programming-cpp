//
// Created by limbe on 2020-02-23.
//

#include "Sort.h"

Sort::Sort()
{
}

Sort::Sort(const IntArray &pIntArray) : intArray(pIntArray)
{
}

Sort::~Sort()
= default;

const IntArray &Sort::getIntArray() const
{
    return intArray;
}



void Sort::setIntArray(const IntArray &pIntArray)
{
    intArray = pIntArray;
}


void Sort::bubbleAlgorithm1()
{
   vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
   {
       intArray.fillIntArray();
       auto timeStart = std::chrono::high_resolution_clock::now();
       intArray.bubbleSort1();
       auto timeEnd = std::chrono::high_resolution_clock::now();
       // calculate duration by subtracting start time from end time
       size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
       double sortTime = 1.0 * duration / 1000;// gives time in seconds
       time.push_back(sortTime);
   }
    int arraySize = intArray.getSize();
    string sortName ("bubble sort 1");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, arraySize, meanTime);


}

void Sort::bubbleAlgorithm2()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        intArray.fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        intArray.bubbleSort2();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    int arraySize = intArray.getSize();
    string sortName ("bubble sort 2");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, arraySize, meanTime);


}

void Sort::quickAlgorithm1()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        intArray.fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        intArray.quick1();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    int arraySize = intArray.getSize();
    string sortName ("Quick sort 1");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, arraySize, meanTime);
}

void Sort::quickAlgorithm2()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        intArray.fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        intArray.quick2();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    int arraySize = intArray.getSize();
    string sortName ("Quick sort 2");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, arraySize, meanTime);
}

void Sort::selectionAlgorithm()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        intArray.fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        intArray.selectionSort();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    int arraySize = intArray.getSize();
    string sortName ("Selection sort");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, arraySize, meanTime);
}

void Sort::insertionAlgorithm()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        intArray.fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        intArray.insertionSort();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    int arraySize = intArray.getSize();
    string sortName ("Insertion sort");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, arraySize, meanTime);
}


void Sort::printAndSave(const string &sortName, const int pSize, double meanSortTime)
{
    cout << "Algorithm name: " << sortName << TAB  << " array size: " << pSize << TAB << " average time: " << meanSortTime << " s" << endl;

    ofstream myfile(fileName.c_str() , std::fstream::in | std::fstream::app);

    myfile << sortName << TAB  << pSize << TAB << meanSortTime << endl;
    myfile.close();
}

double Sort::computeMeanTime(const vector<double> &sortDuration)
{
    double meanTime = accumulate(sortDuration.begin(), sortDuration.end(), 0.0)/numberOfRuns;
    return meanTime;
}

void Sort::allSortAlgorithm()
{
    quickAlgorithm1();
    quickAlgorithm2();
    selectionAlgorithm();
    insertionAlgorithm();
    bubbleAlgorithm1();
    bubbleAlgorithm2();
}


