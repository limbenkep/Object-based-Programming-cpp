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
    string sortName ("bubbleSort1");
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
    string sortName ("bubbleSort2");
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
    cout << "Attempting to do quick sort1" << endl;
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        intArray.fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        cout << " Array filled for quick sort 2" << endl;
        intArray.quick2();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    int arraySize = intArray.getSize();
    string sortName ("quickSort");
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
    string sortName ("selectionSort");
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
    string sortName ("insertionSort");
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
    cout << "Sorting everything....\n";
    //quickAlgorithm1();
    //cout << "After quick sort1\n";
    //quickAlgorithm2();
    //cout << "After quick sort2\n";

    selectionAlgorithm();
    cout << "After selection sort1\n";

    insertionAlgorithm();
    cout << "After INSERtion sort\n";
    bubbleAlgorithm1();
    cout << "After bubble sort1\n";

    bubbleAlgorithm2();
    cout << "After bubble sort2\n";
}


