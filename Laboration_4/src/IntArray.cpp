//
// Created by limbe on 2020-02-19.
//

#include "IntArray.h"

IntArray::IntArray() : size(0)
{
    arr = nullptr;
}

IntArray::IntArray( size_t pSize) : size(pSize)
{
    arr = new int[size];
}

IntArray::~IntArray()
{
    delete [] arr;
    arr = nullptr;
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
            arr = new int[pIntArr.size];
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

    for(size_t i=0; i<size ; i++)
        arr[i] = randomNumber();
}

int IntArray::randomNumber()
{
    int max = static_cast<int>(size);
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, max-1);
    return dis(gen);
}

void IntArray::bubbleSort1()
{
    for (size_t pass=0; pass < size; pass++)
    {
        for (size_t i=0; i < size-1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
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
                swap(arr[i], arr[i + 1] );
                sorted = false;
            }
        }
    }

}

void IntArray::selectionSort()
{

    int smallIdx = 0;
    for (size_t i=0; i < size-1; i++)
    {
        smallIdx = i; // Index of the first unsorted element to the right of the last sorted elements.
        for (size_t j=i+1; i < size; j++) //iterates through the rest of the elements to the right of smallIdx
        {
            if (arr[i] < arr[smallIdx])
            {
                smallIdx=j;// saves the index of the smallest element in the unsorted part of the array
            }
            if (smallIdx !=i)// checks if there is any element small than the ith element and if so switch places
            {
                swap(arr[i], arr[smallIdx]);
            }
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

void IntArray::quickSort1(size_t first, size_t last)
{
    if (first < last)
    {
        size_t low = first;
        size_t high = last;
        if (arr[first] > arr[last])
        {
            swap(arr[first], arr[last]);
            do
            {
                do{low++;} while (arr[low] < arr[first]);
                do{high--;} while (arr[high] > arr[first]);
                if (low <= high)
                    swap(arr[low], arr[high]);

            }while (low<=high);
            swap (arr[first], arr[high]);
            quickSort1(first, high - 1); //sort left hand part of the list
            quickSort1(first, high - 1); //sort right hand part of the list
        }

    }
}
void IntArray::quick1()
{
    quickSort1(0,size-1);
}


void IntArray:: quickSort2(size_t first, size_t last)
{

    size_t low = first;
    size_t high = last;
    int x = arr[(first + last) / 2];      // choose middle value to be pivot value
    do
    {
        while(arr[low] < x) // search from beginning until a value that is greater than x is met
        {
            low++;
        }
        while(arr[high] > x)
        {  // search from the end backwards until a value less than x is found
            high--;
        }
        if(low<=high)
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    }while(low <= high);
    if(first < high)
        quickSort2(first, high);
    if(low < last)
        quickSort2(low, last);
}

void IntArray::quick2()
{

    quickSort2(0,size-1);
}
/*
const char DELIM = '|';// '|' is a delimiter that specifies the boundary of each data entry
ostream &operator<<(ostream &os, const IntArray &pArray)
{
    size_t pSize = pArray.getSize();
    int *pArr = new int[pSize];
    pArr = pArray.getArr();
    for (int i=0; i<pSize; i++)
        os << pArr[i]<<DELIM;
    return os;
}
istream &operator>>(istream &is, IntArray &pArray)
{
    string tmpString;
    for (int i)

}*/
