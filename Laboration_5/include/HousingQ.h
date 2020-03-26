//
// Created by limbe on 2020-03-25.
//
/*
 * This class' data members are a Qlist object stores the persons on the housing queue in a list, and
 * an interger that stores the number of persons on the queue.
 * This class is a userinterface that allows users to choose options from the menu and contains member functions
 * that execute the actions specified by the options
 */

#ifndef LABORATION_5_HOUSINGQ_H
#define LABORATION_5_HOUSINGQ_H

#include <QList.h>
#include <fstream>



class HousingQ
{
private:
    QList houseQueue;
    int sizeOfQueue;

    const string fileName{"housingQueue.txt"};

public:

    //Member functions
    // prompts user to enter data on a Person and adds the person to the queue
    void addPersonToQ();
    /*
     * Delete person from queue when person is offered a house and prints the person data on the screen.
     * prints a message when queue if empty
     */
     void assignAndDelete();
     /*
      * Print all persons on the housing queue together with their position on the queue and number of persons on the queue
      * prints a message if the queue is empty.
      */
     void printQueue();
     /*
      * Prompts the user to enter the personal number of the person to be printed, search for the person in the list and
      * prints data on that person and the persons position on the list
      */
     void printPersonFromQ();
     /*
      * Prompts the user to enter the personal number of the person to be deleted, search for the person in the list and
      * Deletes person from the queue.
      */
     void deletePersonFromQ();
     /*
      * safes queue to the file HousingQueue.txt specified in the program
      */
     void saveQueueToFile();
    /*
    * reads queue to the file HousingQueue.txt specified in the program
    */
    void readQueueToFile();
    int getChoice();

public:
    HousingQ();
    HousingQ(const QList &houseQueue, int sizeOfQueue);
    virtual ~HousingQ();

    //Member functions
    void run();



};


#endif //LABORATION_5_HOUSINGQ_H
