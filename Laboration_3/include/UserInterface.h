//
// Created by limbe on 2020-02-11.
//
/*
 * This class is an interface between the user and Personlist. It provides the user with a menu of different operations
 * that can be carried out and allow the user to make a choice.
 * this class has a single PersonList object as data member and  functions for each option;
        To read List of persons from a file,
        To enter data on a new person,
        To list of persons sorted by Name
        To print list of persons sorted by social security number .
        To list of persons sorted by shoe size,
        To get number of persons in the list,
        To save List of persons in a file,
        To print all persons on the List unsorted, and
        To read data on a person at a particular position on the list.

 *
 */

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
     * sorts list by name and print on the screen
     */
    void printListNameSort();
    /*
     * sorts list by social security number (persNr) and print on the screen
     */
    void printListPersNrSort();

    /*
     * sorts list by shoe size and print on the screen
     */
    void printListShoeNrSort();
    //returns number of Persons in the list
    int listSize();
    //prompts user to enter the index of a Person option and prints that object
    void printPerson();
    //pause waits on user to decide to continue by clicking ENTER
    void nextMoveKey();
    //Prints the current number of Persons in the List
    void printListSize();



public:
    UserInterface();

    virtual ~UserInterface();

    void run();

};


#endif //LABORATION_3_USERINTERFACE_H
