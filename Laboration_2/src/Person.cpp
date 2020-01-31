//
// Created by limbe on 2020-01-31.
//

#include "Person.h"

Person::Person()
{
}

Person::Person(const Name &pName, const Address &pAddress, const string &pPersNr, int pShoeNr) : name(pName),
                                                                                             address(pAddress),
                                                                                             persNr(pPersNr),
                                                                                             shoeNr(pShoeNr)
{
}

Person::~Person()
{

}

const Name &Person::getName() const
{
    return name;
}

void Person::setName(const Name &pName)
{
    name = pName;
}

const Address &Person::getAddress() const
{
    return address;
}

void Person::setAddress(const Address &pAddress)
{
    address = pAddress;
}

const string &Person::getPersNr() const
{
    return persNr;
}

void Person::setPersNr(const string &pPersNr)
{
    persNr = pPersNr;
}

int Person::getShoeNr() const
{
    return shoeNr;
}

void Person::setShoeNr(int pShoeNr)
{
    shoeNr = pShoeNr;
}
