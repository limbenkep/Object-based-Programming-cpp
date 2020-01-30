//
// Created by limbe on 2020-01-30.
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

const string &Address::getStreetName() const
{
    return streetName;
}

void Address::setStreetName(const string &pStreetName)
{
    streetName = pStreetName;
}

const string &Address::getPostNumber() const
{
    return postNumber;
}

void Address::setPostNumber(const string &pPostNumber)
{
    postNumber = pPostNumber;
}

const string &Address::getCityName() const
{
    return cityName;
}

void Address::setCityName(const string &pCityName)
{
    cityName = pCityName;
}

string Address::fullAddress()
{
    return streetName + "\n" + postNumber + "\n" + cityName;
}