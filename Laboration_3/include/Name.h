//
// Created by limbe on 2020-02-05.
//
/*
 * The Class Name contains information about a persons name. It contains;
 * Person's first name(firstName),
 * Person's last Name (lastName),
 * functions to get and set the above member data,
 * A function that returns full name as a single string, and
 * And a function that reads the first and last name from the keyboard and return an obkect of type Name
 */

#ifndef LABORATION_3_NAME_H
#define LABORATION_3_NAME_H

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
    Name(const string &pFirstName, const string &pLastName);

    virtual ~Name();

    string getFirstName() const;

    void setFirstName(const string &pFirstName);

    string getLastName() const;

    void setLastName(const string &pLastName);


    /*
     * overloaded operator for equator operator
     */
    bool operator==(const Name &name) const;
    /*
    * overloaded operator for 'less than' operator
    */
    bool operator<(const Name &name) const;

    string fullName ();
    /*
     * prompts user for first and last name and load in an object of type Name
     * returns an object of type Name.
     */
    Name readName();
};

/*
* output operator for printing to a file
*
*/
ostream &operator<<(ostream &os, const Name &name);

/*
* input operator for printing to a file
*
*/
istream &operator>>(istream &is, Name &name);

#endif //LABORATION_3_NAME_H
