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
};

#endif //LABORATION_2_NAME_H
