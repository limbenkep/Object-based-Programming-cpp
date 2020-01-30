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


