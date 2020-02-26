//
// Created by limbe on 2020-02-19.
//

#include "IntArray.h"
IntArray::IntArray(): size(0), maxSize(0)
{
    arr = nullptr;
}

IntArray::IntArray( size_t pmaxSize) : size(0), maxSize(pmaxSize)
{
    arr = new int[maxSize];
}

IntArray::~IntArray()
{
    delete [] arr;
    arr = nullptr;
    cout << __func__ <<"I am destroyed\n";
}

int *IntArray::getArr() const
{
    return arr;
}

size_t IntArray::getSize() const
{
    return size;
}

void IntArray::setSize(size_t pSize)
{
    size = pSize;
}

IntArray& IntArray::operator=(const IntArray &pIntArr)
{
    {
        if (this != &pIntArr)
        {
            delete[]arr;
            arr = new int[pIntArr.maxSize];
            size = pIntArr.size;
            for (size_t i = 0; i < pIntArr.size; i++)
                arr[i] = pIntArr.arr[i];
        }

        return *this;
    }
}


bool IntArray::operator==(const IntArray &pIntArr) const
{
    if (size != pIntArr.size)
        return false;
    for (size_t i=0; i<size; i++)
        if (arr[i] != pIntArr.arr[i])
            return false;
    return true;
}

bool IntArray::operator<(const IntArray &pArr) const
{
    return false;
}

bool IntArray::operator!=(const IntArray &pArr) const
{
    return !((*this)==pArr);
}
int& IntArray::operator[] (int index)
{
    return arr[index];
}

void IntArray::fillIntArray()
{
    for(size_t i=0; i<maxSize; i++)
    {
        const int num = randomNumber();
        arr[i] = num;
    }
    size = maxSize;
}

int IntArray::randomNumber()
{
    int maxNumber = static_cast<int>(maxSize);

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<int> distribution(0,maxNumber-1);
    int number = distribution(gen);
    return number;
}

void IntArray::bubbleSort1()
{
    for (size_t pass=0; pass < size; pass++)
    {
        for (size_t i=0; i < size-1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swapValue(arr[i], arr[i + 1]);
            }
        }
    }
}

void IntArray::bubbleSort2()
{
    bool sorted = false;
    for (size_t pass=0; pass < size-1 && !sorted ; pass++)
    {
        sorted = true;
        for (size_t i=0; i < size-1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swapValue(arr[i], arr[i + 1] );
                sorted = false;
            }
        }
    }

}

void IntArray::selectionSort()
{
    for (size_t i=0; i < size-1; i++)
    {
        int smallIdx = i; // Index of the first unsorted element to the right of the last sorted elements.
        for (size_t j=i+1; j < size; j++) //iterates through the rest of the elements to the right of smallIdx
        {
            if (arr[j] < arr[smallIdx])
            {
                smallIdx=j;// saves the index of the smallest element in the unsorted part of the array
            }
        }
        if (smallIdx !=i)// checks if there is any element small than the ith element and if so switch places
        {
            swapValue(arr[i], arr[smallIdx]);
        }
    }
}


void IntArray::insertionSort()
{

    int pSize = static_cast<int>(size);
    if(pSize > 1)
    {
        int key, j;
        for(int k = pSize - 1; k >= 0; k--)
        {
            j = k+1;
            key = arr[k];
            while(j < pSize && key > arr[j])
            {
                arr[j - 1] = arr[j];
                j++;
            }
            arr[j - 1] = key;
        }
    }

}


void IntArray::swapValue(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void IntArray::printArray()
{
    for(size_t i = 0; i<size; i++ )
    {
        cout << arr[i] << endl;
    }
    cout<< "end of array"<< endl;


}

double IntArray::computeMeanTime(const vector<double> &sortDuration)
{
    double meanTime = accumulate(sortDuration.begin(), sortDuration.end(), 0.0)/numberOfRuns;
    return meanTime;
}

void IntArray::bubbleAlgorithm1()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        bubbleSort1();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    string sortName ("bubbleSort1");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, meanTime);


}

void IntArray::printAndSave(const string &sortName, double meanSortTime)
{
    cout << "Algorithm name: " << sortName << TAB  << " array size: " << size << TAB << " average time: " << meanSortTime << " s" << endl;

    ofstream myfile(fileName.c_str() , std::fstream::in | std::fstream::app);

    myfile << sortName << TAB  << size << TAB << meanSortTime << endl;
    myfile.close();

}

void IntArray::bubbleAlgorithm2()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        bubbleSort2();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    string sortName ("bubbleSort2");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, meanTime);
}


void IntArray::quickAlgorithm()
{
    cout << "Attempting to do quick sort1" << endl;
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        quick(arr, maxSize);
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    string sortName ("quickSort");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, meanTime);
}

void IntArray::selectionAlgorithm()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        selectionSort();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    string sortName ("selectionSort");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, meanTime);
}

void IntArray::insertionAlgorithm()
{
    vector<double>time;

    for (int i = 0; i<numberOfRuns; i++)
    {
        fillIntArray();
        auto timeStart = std::chrono::high_resolution_clock::now();
        insertionSort();
        auto timeEnd = std::chrono::high_resolution_clock::now();
        // calculate duration by subtracting start time from end time
        size_t duration = std::chrono::duration_cast<std::chrono::milliseconds>(timeEnd - timeStart).count();
        double sortTime = 1.0 * duration / 1000;// gives time in seconds
        time.push_back(sortTime);
    }
    string sortName ("insertionSort");
    double meanTime = computeMeanTime(time);
    printAndSave(sortName, meanTime);
}


void IntArray::allSortAlgorithm()
{
    quickAlgorithm();
    cout << "After quick sort2\n";

    selectionAlgorithm();
    cout << "After selection sort1\n";

    insertionAlgorithm();
    cout << "After INSERtion sort\n";
    bubbleAlgorithm1();
    cout << "After bubble sort1\n";

    bubbleAlgorithm2();
    cout << "After bubble sort2\n";
}


void IntArray:: quickSort(int *a, int first, int last) {
    int low = first;// set low to be the starting index
    int high = last;// set low to be the ending index
    int x = a[(first+last)/2];      // choose the mddle value to be the pivot element

    do {
        while(a[low] < x) {  // search from the the starting index for the first value that is greater than the pivot
            low++;
        }
        while(a[high] > x) {  // search from the ending index backwards for the first value that is less than the pivot value
            high--;
        }

        if(low<=high) {
            swap(a[low],a[high]);
            low++;
            high--;
        }
    } while(low <= high);

    if(first < high)
        quickSort(a, first, high);
    if(low < last)
        quickSort(a, low, last);
}

void IntArray:: quick(int *a, int n) {
    quickSort(a, 0, n - 1);
}
