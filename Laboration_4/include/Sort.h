//
// Created by limbe on 2020-02-23.
//

#ifndef LABORATION_4_SORT_H
#define LABORATION_4_SORT_H
#include "IntArray.h"


class Sort
{
private:
    IntArray intArray;
    string sortName;
    double sortTime;

public:
    Sort();

    Sort(const IntArray &intArray, const string &sortName, double time);

    virtual ~Sort();

    const IntArray &getIntArray() const;

    const string &getSortName() const;

    double getSortTime() const;
    Sort & operator=(const Sort &pSort);

    void setIntArray(const IntArray &intArray);

    void setSortName(const string &sortName);

    void setSortTime(double sortTime);

};


#endif //LABORATION_4_SORT_H
