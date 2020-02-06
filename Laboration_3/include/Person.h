//
// Created by limbe on 2020-02-05.
//
/*
 * This class contains information about a person's full name(uses class Name), address(uses classAddress),
 * social security number (persNr) and shoes size (shoeNr)
 * functions that get and set the above member data
 * The function showPerson that prints a given person's information on the screen
 * a function read person that reads information about a person and returns an obect of class Person.
 */
#ifndef LABORATION_3_PERSON_H
#define LABORATION_3_PERSON_H

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
     * overloaded operator for equator operator
     */
   bool operator==(const Person &person) const;
    /*
    * overloaded operator for 'less than' operator
    */
    bool operator<(const Person &person) const;


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

/*
 * output operator for printing to a file
 *
 */
ostream &operator<<(ostream &os, const Person &person);

/*
 * input operator for reading from  a file
 */
istream &operator>>(istream &is, Person &person);

#endif //LABORATION_3_PERSON_H
