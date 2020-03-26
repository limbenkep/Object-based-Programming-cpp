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
    newPerson.readPerson();
    houseQueue.enque(newPerson);
    sizeOfQueue++;
}

void HousingQ::assignAndDelete()
{
    Person tmpPerson;
    if(houseQueue.deque(tmpPerson))
    {
        sizeOfQueue--;
        cout << "\nThe following person has been offered housing and removed from the queue"<<endl;
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
        cout<< ".\nTotal number of persons on the housing queue: " << sizeOfQueue << endl;
        cout << "This is a list of all the persons on the queue and their position on the queue;" << endl;
        Person tmpPerson;
        int counter = 0;
        for(auto p = houseQueue.begin(); p!=houseQueue.end(); p++)
        {
            counter++;
            tmpPerson = p.operator*();
            cout<<"Number "<< counter;
            tmpPerson.printPerson();
        }
    }
}

void HousingQ::printPersonFromQ()
{

    if(houseQueue.isEmpty())
    {
        cout << "\n\nThe housing queue is empty!" << endl;
    }
    else
    {
        string tmpPersNr;
        cout <<"Enter the personal number of the person to be printed: ";
        getline(cin, tmpPersNr);
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

    if(houseQueue.isEmpty())
    {
        cout << "\nThe housing queue list is empty!" << endl;
    }
    else
    {
        string tmpPersNr;
        cout <<"Enter the personal number of the person to be removed: ";
        getline(cin, tmpPersNr);
        Person tmpPerson;
        int counter = 0;
        bool hittat = false;
        auto p = houseQueue.begin();
        while(!houseQueue.isEmpty() && p!=houseQueue.end())
        {
            counter++;
            tmpPerson = p.operator*();
            if(tmpPerson.getPersNr() ==tmpPersNr)
            {
                houseQueue.del(tmpPerson);
                sizeOfQueue--;
                cout << "The person with personal number " << tmpPerson.getPersNr() << " has been removed from the queue." << endl;
                hittat = true;
            }
            p++;
        }
        if(!hittat)
        {
            cout << "No person with personal number " << tmpPersNr << " was found on the list." <<endl;
        }
    }

}

void HousingQ::saveQueueToFile()
{
    if(houseQueue.isEmpty())
    {
        cout << "\nYou are saving an empty list ";
    }
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

int HousingQ::getChoice()
{
    cout << "\nMenu options for housing queue list: \n\t1. Add a person to queue.\n\t2. Offer a person housing.\n\t3. Print housing queue list."
    <<"\n\t4. Print data on a person in the queue.\n\t5. Remove a person from the queue.\n\t6. Save queue to file.\n\t7. Exit";
    cout << "\nYour choice: ";
    int choice = -1;
    cin>>choice;
    while(!cin||choice < 1 || choice >7)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid entry. Enter a number between 1 and 7" <<endl;
        cout << "\nYour choice: ";
        cin>>choice;
    }
    cin.ignore(1000, '\n');
    return choice;
}

void HousingQ::run()
{
    bool again = true;
    while (again)
    {
        switch (getChoice())
        {
            case 1:
                addPersonToQ();
                break;
            case 2:
                assignAndDelete();
                break;
            case 3:
                printQueue();
                break;
            case 4:
                printPersonFromQ();
                break;
            case 5:
                deletePersonFromQ();
                break;
            case 6:
                saveQueueToFile();
                break;
            case 7:
                again = false;
                break;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }

    }
}




