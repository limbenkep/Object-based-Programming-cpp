//
// Created by limbe on 2020-03-21.
//
/*
 * The Class Name contains information about a persons name. It contains;
 * Person's first name(firstName),
 * Person's last Name (lastName),
 * functions to get and set the above member data,
 * overload operators for <, ==, << and >>
 * A function thats prints full name on the screen, and
 * And a function that reads the first and last name from the keyboard and return a Name object
 */
#ifndef LABORATION_5_NAME_H
#define LABORATION_5_NAME_H

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
    * overloaded operator for 'less than' operator. This function checks if the first names are the same,
     * if so it checks if the last name of the given object is less than the current last name and returns true or false
     * if the lastnames are not the same, it checks if the last name of the given object is less than the current and returns bool.
    */
    bool operator<(const Name &name) const;

    string fullName ();
    /*
     * prompts user for first and last name and load in an object of type Name
     * returns an object of type Name.
     */
    void readName();
    //prints name in the order first name then last name on the screen
    void printName() const;

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

#endif //LABORATION_5_NAME_H
