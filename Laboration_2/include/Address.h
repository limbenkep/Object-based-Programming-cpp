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

    const string &getStreetName() const;

    void setStreetName(const string &pStreetName);

    const string &getPostNumber() const;

    void setPostNumber(const string &pPostNumber);

    const string &getCityName() const;

    void setCityName(const string &pCityName);
    /**
     * combines streetName,postNumber and cityName to give  full address
     * @return full address in the form of a string.
     */
    string fullAddress();

};


#endif //LABORATION_2_ADDRESS_H
