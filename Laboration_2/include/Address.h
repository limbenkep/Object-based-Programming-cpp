//
// Created by limbe on 2020-01-30.
//

#ifndef LABORATION_2_ADDRESS_H
#define LABORATION_2_ADDRESS_H
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


#endif //LABORATION_2_ADDRESS_H
