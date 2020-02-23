//
// Created by limbe on 2020-02-23.
//

#include "Program.h"

IntArray Program::loadIntArray()
{

    return IntArray();
}

void Program::run()
{
    IntArray intArray5000(5000);
    intArray5000.fillIntArray();
    ///bubbleRortRun(const IntArray &pIntArr)


}

Program::Program()
{
}

Program::Program(const IntArray &intArray) : intArray(intArray)
{
}

Program::~Program()
{

}
