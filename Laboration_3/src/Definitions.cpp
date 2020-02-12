#include "Prototypes.h"
#include <iostream>
using std::cout;
using std::endl;



bool sortByName(const Person &lhs, const Person &rhs){
    return lhs.getName() < rhs.getName();
}
bool sortByPersNr(const Person &lhs, const Person &rhs)
{
    return lhs.getPersNr() < rhs.getPersNr();
}
bool sortByShoeNr(const Person &lhs, const Person &rhs)
{
    return lhs.getShoeNr() < rhs.getShoeNr();
}