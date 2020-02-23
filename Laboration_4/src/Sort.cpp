//
// Created by limbe on 2020-02-23.
//

#include "Sort.h"

Sort::Sort(): sortTime(0)
{
}

Sort::Sort(const IntArray &pIntArray, const string &pSortName, double pSortTime) : intArray(pIntArray), sortName(pSortName),
                                                                            sortTime(pSortTime)
{
}

Sort::~Sort()
= default;

const IntArray &Sort::getIntArray() const
{
    return intArray;
}

const string &Sort::getSortName() const
{
    return sortName;
}

double Sort::getSortTime() const
{
    return sortTime;
}

void Sort::setIntArray(const IntArray &intArray)
{
    Sort::intArray = intArray;
}

void Sort::setSortName(const string &sortName)
{
    Sort::sortName = sortName;
}

void Sort::setSortTime(double sortTime)
{
    Sort::sortTime = sortTime;
}


