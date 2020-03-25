//
// Created by limbe on 2020-03-25.
//

#include "HousingQ.h"

HousingQ::HousingQ(): sizeOfQueue(0)
{
}

HousingQ::HousingQ(const QList &pHouseQueue, int pSizeOfQueue) : houseQueue(pHouseQueue), sizeOfQueue(pSizeOfQueue)
{
}

HousingQ::~HousingQ()
{

}

void HousingQ::addPersonToQ()
{
    Person newPerson;
    Person me = newPerson.readPerson();
    houseQueue.enque(newPerson);
    sizeOfQueue++;
}

void HousingQ::assignAndDelete()
{
    Person tmpPerson;
    if(houseQueue.deque(tmpPerson))
    {
        sizeOfQueue--;
        tmpPerson.printPerson();
    }
    else
    {
        cout << "\nThe housing queue is empty. House could not be assigned to a person!" << endl;
    }
}

void HousingQ::printQueue()
{
    if(houseQueue.isEmpty())
    {
        cout << "\nThe housing queue is empty!" << endl;
    }
    else
    {
        Person tmpPerson;
        int counter = 0;
        for(auto p = houseQueue.begin(); p!=houseQueue.end(); p++)
        {
            counter++;
            tmpPerson = p.operator*();
            cout<< ".\nTotal number of persons on the housing queue: " << sizeOfQueue << endl;
            cout << "This is a list of all the persons on the queue and their position on the queue;" << endl;
            //cout << "Position\tName\tPersonal Number\tAddress\tShoe size" <<endl;
            cout<<"Number "<< counter;
            tmpPerson.printPerson();

        }
    }
}

void HousingQ::printPersonFromQ()
{
    string tmpPersNr;
    cout <<"Enter the personal number of the person to be printed: ";
    getline(cin, tmpPersNr);
    if(houseQueue.isEmpty())
    {
        cout << "\nThe housing queue is empty!" << endl;
    }
    else
    {
        Person tmpPerson;
        int counter = 0;
        bool found = false;
        for(auto p = houseQueue.begin(); p!=houseQueue.end(); p++)
        {
            counter++;
            tmpPerson = p.operator*();
            if(tmpPerson.getPersNr() ==tmpPersNr)
            {
                cout<<"Position on the queue:  "<< counter;
                tmpPerson.printPerson();
                found = true;
            }
        }
        if(!found)
        {
            cout << "No person with personal number " << tmpPersNr << " was found on the list." <<endl;
        }
    }
}

void HousingQ::deletePersonFromQ()
{
    string tmpPersNr;
    cout <<"Enter the personal number of the person to be printed: ";
    getline(cin, tmpPersNr);
    if(houseQueue.isEmpty())
    {
        cout << "\nThe housing queue is empty!" << endl;
    }
    else
    {
        Person tmpPerson;
        int counter = 0;
        bool found = false;
        for(auto p = houseQueue.begin(); p!=houseQueue.end(); p++)
        {
            counter++;
            tmpPerson = p.operator*();
            if(tmpPerson.getPersNr() ==tmpPersNr)
            {
                houseQueue.del(tmpPerson);
                cout << "The person with personal number " << tmpPerson.getPersNr() << " has been removed from the queue." << endl;
                found = true;
            }
        }
        if(!found)
        {
            cout << "No person with personal number " << tmpPersNr << " was found on the list." <<endl;
        }
    }

}

void HousingQ::saveQueueToFile()
{
    fstream outFile (fileName.c_str(), ios::out);
    for(auto p = houseQueue.begin(); p!=houseQueue.end(); p++)
    {
        outFile<<p.operator*();
    }
    outFile.close();
    cout << "\nHousing queue list has been saved to file " << fileName <<"." <<endl;
}

void HousingQ::readQueueToFile()
{
    Person tmpPerson;
    ifstream inFile(fileName.c_str());
    if(inFile)
    {
        while(!inFile.eof())
        {
            inFile>>tmpPerson;
            houseQueue.enque(tmpPerson);
            sizeOfQueue++;
        }
        inFile.close();
        cout << "\nHousing queue list has been read from file " << fileName <<"." <<endl;
    }
    else
    {
        cout << "The file " << fileName << " was not found!" << endl;
    }
}


