//
// Created by limbe on 2020-01-30.
//

#ifndef LABORATION_2_NAME_H
#define LABORATION_2_NAME_H

#include <iostream>
#include <string>

using namespace std;

class Name
{
private:
    string firstName;
    string lastName;

public:
    Name();
    Name(const string &pFirstName, const string &pLastName);

    virtual ~Name();

    string getFirstName() const;

    void setFirstName(const string &pFirstName);

    string getLastName() const;

    void setLastName(const string &pLastName);
    string fullName ();
    /*
     * prompts user for first and last name and load in an object of type Name
     * returns an object of type Name.
     */
    Name readName();
};

#endif //LABORATION_2_NAME_H
