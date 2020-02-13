//
// Created by limbe on 2020-02-07.
//
/*
 * This class a vector named people of type Person and file name (fileName)  of type string.
 * The class stores Person objects in a the vector people and have function that allows user
 * to read List of persons from a file,
 *to enter data on a new person,
 * to sort Person objects in list by Name,
 * To sort list of Person objects by social security number,
 * To sort list of  Person objects by shoe size,
 * To get number of persons in the list,
 * To save List of persons in a file,
 * To print all persons on the List unsorted, and
 * read data on a person at a particular position on the list.
 */
#ifndef LABORATION_3_PERSONLIST_H
#define LABORATION_3_PERSONLIST_H

#include "Person.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include "Prototypes.h"
class PersonList
{
private:
    vector<Person> people;
    string fileName;

public:
    PersonList(const vector<Person> &people, const string &fileName);

    PersonList();

    virtual ~PersonList();

    string getFileName() const;

    void setFileName(const string &fileName);


    /*
 * the function receives a Person object and adds to the vector
 */
    void addPersonToList(const Person &pPerson);

/*
 * gets the number of persons in the vector and returns it as an int.
 */
    int getListSize();

    /*
     * receives an index and retruns the Person object at the given index in the vector
     */
    Person getPerson(int index);

    void sortPeopleByName();

    void sortPeopleByPersNr();

    void sortPeopleByShoeNr();

    void readFromFile();

    void writeToFile();

    /*
     * prints all persons in the vector people.
     */
    void printPeople();
    /*
     * Allows the user to enter dat on a person through the keyboard and
     * returns a Person object
     */
    Person readNewPerson();
};



#endif //LABORATION_3_PERSONLIST_H
