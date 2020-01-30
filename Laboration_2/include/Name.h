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
    Name(const string &firstName, const string &lastName);

    virtual ~Name();

    string getFirstName() const;

    void setFirstName(const string &firstName);

    string getLastName() const;

    void setLastName(const string &lastName);
};


#endif //LABORATION_2_NAME_H
