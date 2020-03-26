//
// Created by limbe on 2020-03-21.
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



void Person::printPerson() const
{
    name.printName();
    address.printAddress();
    cout << "\nSocial security number: " << persNr << "\nShoe size:" <<shoeNr<<endl;
}

void Person::readPerson()
{
    name.readName();
    address.readAddress();

    cout << "\nEnter social security number: ";
    getline(cin, persNr);

    cout << "\nEnter shoe size: ";
    cin >> shoeNr;
}
