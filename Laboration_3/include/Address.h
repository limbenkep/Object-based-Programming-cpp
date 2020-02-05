//
// Created by limbe on 2020-02-05.
//
/*
 * This class stores information about a person's address. It contains information on;
 * the name of the street the person lives in (streetName )
 * The post number (postNumber)
 * the name of the city (cityName)
 * functions to get and set the above member data
 * A function that returns the full addrees as a single string and
 * A function that reads informtion about a person's address and returns the information in object of type Address
 */
#ifndef LABORATION_3_ADDRESS_H
#define LABORATION_3_ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
    string streetName;
    string postNumber;
    string cityName;

public:
    Address();

    Address(const string &pStreetName, const string &pPostNumber, const string &pCityName);

    virtual ~Address();

    string getStreetName() const;

    void setStreetName(const string &pStreetName);

    string getPostNumber() const;

    void setPostNumber(const string &pPostNumber);

    string getCityName() const;

    void setCityName(const string &pCityName);

    /**
     * combines streetName,postNumber and cityName to give  full address
     * @return full address in the form of a string.
     */
    string fullAddress();

    /**
     * prompts user for street name, post number and city name
     * @return returns an object of type Address
     */
    Address readAddress();

};


#endif //LABORATION_3_ADDRESS_H
