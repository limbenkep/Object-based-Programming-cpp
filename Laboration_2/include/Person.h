//
// Created by limbe on 2020-01-31.
//

#ifndef LABORATION_2_PERSON_H
#define LABORATION_2_PERSON_H
#include "Name.h"
#include "Address.h"
#include <iostream>
#include <string>


class Person
{
private:
    Name name;
    Address address;
    string persNr;
    int shoeNr;

public:
    Person();

    Person(const Name &pName, const Address &pAddress, const string &pPersNr, int pShoeNr);

    virtual ~Person();

    const Name &getName() const;

    void setName(const Name &pName);

    const Address &getAddress() const;

    void setAddress(const Address &pAddress);

    const string &getPersNr() const;

    void setPersNr(const string &pPersNr);

    int getShoeNr() const;

    void setShoeNr(int pShoeNr);

};


#endif //LABORATION_2_PERSON_H
