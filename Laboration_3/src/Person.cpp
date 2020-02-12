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

bool Person::operator==(const Person &person) const
{
    return person.name == name && person.address == address && person.persNr == persNr && person.shoeNr == shoeNr;
}

bool Person::operator<(const Person &person) const
{
    if (person.name == name)
    {
        return person.address < address;
    }
    else
    {
        return person.name < name;
    }
}

const char DELIM = '|';// '|' is a delimiter that specifies the boundary of each data entry

ostream &operator<<(ostream &os, const Person &person)
{
    os << person.getName() << DELIM;
    os << person.getAddress() << DELIM;
    os << person.getPersNr() << DELIM;
    os << person.getShoeNr();
    return os;
}

istream &operator>>(istream &is, Person &person)
{

    Name name;
    Address addr;

    string tmpString;

    getline (is, tmpString, DELIM);// read with getline till the THE aharacter '|' (DELIM)
    name.setFirstName(tmpString);

    getline (is, tmpString, DELIM);
    name.setLastName(tmpString);

    person.setName(name);

    getline (is, tmpString, DELIM); // continue reading with getline till it reads DELIM
    addr.setStreetName(tmpString);

    getline (is, tmpString, DELIM);
    addr.setPostNumber(tmpString);

    getline (is, tmpString, DELIM);
    addr.setCityName(tmpString);

    person.setAddress(addr);

    getline (is, tmpString, DELIM);
    person.setPersNr(tmpString);

    int tmpShoeNr = 0;
    is >> tmpShoeNr;
    is.get(); //reads and discard the remaining end of line character.
    person.setShoeNr(tmpShoeNr);

    return is;

}


/*
void Person::showPerson(const Person &pPerson)
{
    cout<< "\nFull names:\n" << pPerson.getName().fullName() << "\nAddress:\n" << pPerson.getAddress().fullAddress()
        << "\nSocial security number:\n" << pPerson.getPersNr() << "\nShoe size:\n" <<pPerson.getShoeNr()<<endl;
}*/

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
