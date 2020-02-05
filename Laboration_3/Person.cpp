//
// Created by limbe on 2020-02-05.
//

#include "Person.h"
#include <utility>

Person::Person()
{
    shoeNr = 0;
}

Person::Person(const Name &pName, const Address &pAddress, string pPersNr, int pShoeNr) : name(pName),
                                                                                          address(pAddress),
                                                                                          persNr(std::move(pPersNr)),
                                                                                          shoeNr(pShoeNr)
{
}

Person::~Person()
= default;

Name Person::getName() const
{
    return name;
}

void Person::setName(const Name &pName)
{
    name = pName;
}

Address Person::getAddress() const
{
    return address;
}

void Person::setAddress(const Address &pAddress)
{
    address = pAddress;
}

string Person::getPersNr() const
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
void Person::showPerson(const Person &pPerson)
{
    cout<< "\nFull names:\n" << pPerson.getName().fullName() << "\nAddress:\n" << pPerson.getAddress().fullAddress()
        << "\nSocial security number:\n" << pPerson.getPersNr() << "\nShoe size:\n" <<pPerson.getShoeNr()<<endl;
}

Person Person::readPerson()
{
    Person pers;
    Name myName;
    myName = myName.readName();
    pers.setName(myName);

    Address myAddress;
    myAddress = myAddress.readAddress();
    pers.setAddress(myAddress);

    string pPersNr;
    int pShoeNr = 0;

    cout << "\nEnter social security number: ";
    getline(cin, pPersNr);
    pers.setPersNr(pPersNr);

    cout << "\nEnter shoe size: ";
    cin >> pShoeNr;
    pers.setShoeNr(pShoeNr);

    return pers;
}