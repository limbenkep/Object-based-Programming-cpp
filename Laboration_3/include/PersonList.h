//
// Created by limbe on 2020-02-07.
//

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
    void addPerson(const Person &pPerson);

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
};



#endif //LABORATION_3_PERSONLIST_H
