//
// Created by limbe on 2020-02-23.
//

#ifndef LABORATION_4_PROGRAM_H
#define LABORATION_4_PROGRAM_H


#include "IntArray.h"

class Program
{
private:
    IntArray intArray;

    IntArray loadIntArray();
    /*
     * receives an IntArray object, gets array, calls
     */
     //bubbleRortRun(const IntArray &pIntArr);



public:
    virtual ~Program();

public:
    Program(const IntArray &intArray);

public:
    Program();


public:
   void run();

};


#endif //LABORATION_4_PROGRAM_H
