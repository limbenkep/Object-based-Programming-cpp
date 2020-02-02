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

    Person(const Name &pName, const Address &pAddress, string pPersNr, int pShoeNr);

    virtual ~Person();

    Name getName() const;

    void setName(const Name &pName);

    Address getAddress() const;

    void setAddress(const Address &pAddress);

    string getPersNr() const;

    void setPersNr(const string &pPersNr);

    int getShoeNr() const;

    void setShoeNr(int pShoeNr);

    /*
     * prompts user to enter nemes, address, social security number and shoe size and loads it in an object of type Person
     * returns an object of type Person
     */
    Person readPerson();

    /*
     * receives an object of type Person and prints the information: Name, address, social security number and shoe size
     */
    void Person::showPerson(const Person &pPerson);

};


#endif //LABORATION_2_PERSON_H
