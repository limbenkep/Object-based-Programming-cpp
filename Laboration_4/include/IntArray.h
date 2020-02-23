//
// Created by limbe on 2020-02-19.
//

#ifndef LABORATION_4_INTARRAY_H
#define LABORATION_4_INTARRAY_H


#include <cstddef>
#include <iostream>
#include <string>
#include <iomanip>
#include <random>
using namespace std;

class IntArray
{
private:
    int*arr; //pointer to array
    size_t size; //actual size of the array
public:
    IntArray();

    explicit IntArray(size_t pSize);

    virtual ~IntArray();

    //getters and setters
    int *getArr() const;

    size_t getSize() const;

    void setSize(size_t size);

    IntArray& operator=(const IntArray &pIntArr);
    //Index operator
    int& operator[] (int index);
    //overloaded operator for equator operator
    bool operator==(const IntArray &pIntArr)const;
    //overloaded operator for equator operator
    bool operator!=(const IntArray &pIntArr)const;
    //overloaded operator for equator operator
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


};
//output operator for printing to a file
//ostream &operator<<(ostream &os, const int &pArray);

//input operator for reading from  a file
//istream &operator>>(istream &is, int &pArray);

#endif //LABORATION_4_INTARRAY_H
