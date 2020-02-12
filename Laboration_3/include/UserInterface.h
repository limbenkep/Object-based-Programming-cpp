//
// Created by limbe on 2020-02-11.
//

#ifndef LABORATION_3_USERINTERFACE_H
#define LABORATION_3_USERINTERFACE_H

#include "PersonList.h"

class UserInterface
{
private:
    PersonList personList;

    /*
     * prints menu and prompts user to make a choice
     * returns choice as an integer
     */
    int menuChoice();

    /*
     * Allows the user to enter dat on a person through the keyboard and
     * returns a Person object
     */
    Person readPerson();

    /*
     * allows user to enter data on a Person through keyboard and add the Person object to the vector list.
     */
    void addPersonToList();

    /*
     * prints all Person objects in the list on the screen
     */
    void printPersonList();

    string readFileName();

    /*
     * prompts user for the name of the file and saves list to the file
     */
    void saveToFile();

    /*
     * prompts user for the name of the file and writes list to the file
     */
    void readListFile();

    /*
     * sorts list by name
     */
    PersonList listNameSort();
    /*
     * sorts list by social security number (persNr)
     */
    PersonList listPersNrSort();

    /*
     * sorts list by shoe size
     */
    PersonList listShoeNrSort();
    int listSize();
    void printPerson();
    void nextMoveKey();
    void printListSize();



public:
    UserInterface();

    virtual ~UserInterface();

    void run();

};


#endif //LABORATION_3_USERINTERFACE_H
