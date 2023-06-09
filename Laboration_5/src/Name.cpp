//
// Created by limbe on 2020-03-21.
//

#include "Name.h"

Name::Name()
{
    firstName = "";
    lastName = "";
}

Name::Name(const string &pFirstName, const string &pLastName) : firstName(pFirstName), lastName(pLastName)
{

}

Name::~Name()
= default;

string Name::getFirstName() const
{
    return firstName;
}

void Name::setFirstName(const string &pFirstName)
{
    firstName = pFirstName;
}

string Name::getLastName() const
{
    return lastName;
}

void Name::setLastName(const string &pLastName)
{
    lastName = pLastName;
}

bool Name::operator==(const Name &name) const
{
    return name.firstName == firstName && name.lastName == lastName;
}

bool Name::operator<(const Name &name) const
{
    if (name.lastName == lastName)
    {
        return name.firstName < firstName;
    }
    else
    {
        return name.lastName < lastName;
    }
}

void Name::printName() const
{
    cout << "\nName: "<< firstName << " " << lastName;
}


const char DELIM = '|';// '|' is a delimiter that specifies the boundary of each data entry

ostream &operator<<(ostream &os, const Name &name)
{
    os << name.getFirstName() << DELIM;
    os << name.getLastName();
    return os;
}

istream &operator>>(istream &is, Name &name)
{
    string tmpString;
    getline (is, tmpString, DELIM);// read with getline till the THE aharacter '|' (DELIM)
    name.setFirstName(tmpString);

    getline (is, tmpString); // continue reading with getline till it reads DELIM
    name.setLastName(tmpString);

    return is;
}

string Name::fullName()
{
    return firstName + " " + lastName;
}

void Name::readName()
{


    cout << "\nEnter person first name: ";
    getline (cin, firstName);

    cout << "\nEnter person last name: ";
    getline (cin, lastName);
}


