//
// Created by limbe on 2020-03-21.
//

/*
 * This class stores information about a person's address. It contains information on;
 * the name of the street the person lives in (streetName )
 * The post number (postNumber)
 * the name of the city (cityName)
 * functions to get and set the above member data
 * overload operators for <, ==, << and >>
 * A function that prints full address
 * A function that reads data about a person's address and returns an Address object
 */
#ifndef LABORATION_5_ADDRESS_H
#define LABORATION_5_ADDRESS_H

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


    /*
     * overloaded operator for equator operator
     */
    bool operator==(const Address &address) const;

    /*
   * overloaded operator for 'less than' operator.
     * This function checks if the city names are the same,
    * if so it checks if the street name of the given object is less than the current street name and returns true or false
    * if the city names are not the same, it checks if the city name of the given object is less than the current and returns bool.
   */
    bool operator<(const Address &address) const;


    /**
     * receives an Address prints  full address
     */
    void printAddress(const Address &pAddress)const;

    /**
     * prompts user for street name, post number and city name
     * @return returns an object of type Address
     */
    Address readAddress();
};
/*
 * output operator for printing to a file
 *
 */
ostream &operator<<(ostream &os, const Address &address);

/*
 * input operator for reading from  a file
 */
istream &operator>>(istream &is, Address &address);


#endif //LABORATION_5_ADDRESS_H
