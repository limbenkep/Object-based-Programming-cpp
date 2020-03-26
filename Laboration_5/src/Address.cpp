//
// Created by limbe on 2020-03-21.
//

#include "Address.h"

Address::Address()
{
}

Address::Address(const string &pStreetName, const string &pPostNumber, const string &pCityName) : streetName(pStreetName),
                                                                                                  postNumber(pPostNumber),
                                                                                                  cityName(pCityName)
{
}

Address::~Address()
{

}

string Address::getStreetName() const
{
    return streetName;
}

void Address::setStreetName(const string &pStreetName)
{
    streetName = pStreetName;
}

string Address::getPostNumber() const
{
    return postNumber;
}

void Address::setPostNumber(const string &pPostNumber)
{
    postNumber = pPostNumber;
}

string Address::getCityName() const
{
    return cityName;
}

void Address::setCityName(const string &pCityName)
{
    cityName = pCityName;
}

void Address::printAddress()const
{
    cout << "\nAddress: " << streetName << ", " << postNumber
         << ", " << cityName;
}

bool Address::operator==(const Address &address) const
{
    return address.streetName == streetName && address.postNumber == postNumber && address.cityName == cityName;
}

bool Address::operator<(const Address &address) const
{
    if (address.cityName == cityName )
    {
        return address.streetName < streetName;
    }
    else
    {
        return address.cityName < cityName;
    }
}


const char DELIM = '|';// '|' is a delimiter that specifies the boundary of each data entry

ostream &operator<<(ostream &os, const Address &address)
{
    os << address.getStreetName() << DELIM;
    os << address.getPostNumber() << DELIM;
    os << address.getCityName();
    return os;
}

istream &operator>>(istream &is, Address &address)
{
    Address myAddress;
    string myStreetName;
    string myPostNumber;
    string myCityName;
    cout << "\nEnter street name: ";
    getline (is, myStreetName);
    myAddress.setStreetName(myStreetName);

    cout << "\nEnter post number: ";
    getline (is, myPostNumber);
    myAddress.setPostNumber(myPostNumber);

    cout << "\nEnter city name: ";
    getline (is, myCityName);
    myAddress.setCityName(myCityName);

    return is;
}


void Address::readAddress()
{
    cout << "\nEnter street name: ";
    getline (cin, streetName);

    cout << "\nEnter post number: ";
    getline (cin, postNumber);

    cout << "\nEnter city name: ";
    getline (cin, cityName);
}



