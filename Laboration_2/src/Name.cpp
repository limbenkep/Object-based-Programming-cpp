//
// Created by limbe on 2020-01-30.
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
{

}

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

string Name::fullName()
{
    return firstName + " " + lastName;
}

Name Name::readName()
{
    Name myName;
    string myFirstName;
    string myLastName;

    cout << "\nEnter person first name: ";
    getline (cin, myFirstName);
    myName.setFirstName(myFirstName);

    cout << "\nEnter person last name: ";
    getline (cin, myLastName);
    myName.setLastName(myLastName);

    return myName;
}