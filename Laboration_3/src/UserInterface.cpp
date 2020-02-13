//
// Created by limbe on 2020-02-11.
//

#include "UserInterface.h"

UserInterface::UserInterface()
= default;

UserInterface::~UserInterface()
= default;

int UserInterface::menuChoice()
{
    cout << "\n\tTo read List of persons from a file, enter '0'."<<endl
    << "\tTo enter data on a new person, enter '1'."<<endl
    << "\tTo list of persons sorted by Name enter '2' "<<endl
    << "\tTo print list of persons sorted by social security number enter '3'."<<endl
    << "\tTo list of persons sorted by shoe size enter '4'."<<endl
    << "\tTo get number of persons in the list enter '5'."<<endl
    << "\tTo save List of persons in a file, enter '6'."<<endl
    << "\tTo print all persons on the List unsorted, enter '7'."<<endl
    << "\tTo read data on a person at a particular position on the list enter '8' "<<endl
    << "\tTo exit program enter '9'"<<endl
    << "\tMake a choice: ";
    int choice = -1;
    int noChoice = 10;
    cin>>choice;
    if (!cin)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return noChoice;

    }
    cin.ignore(1000, '\n');

    return choice;
}

void UserInterface::addPersonToList()
{
    Person newPerson;
    newPerson = personList.readNewPerson();
    personList.addPersonToList(newPerson);
}

void UserInterface::printPersonList()
{
    personList.printPeople();
}

string UserInterface::readFileName()
{
    string tmpString;
    cout << "\nEnter the name of the file: ";
    getline(cin, tmpString);
    return tmpString;
}

void UserInterface::saveToFile()
{

    personList.setFileName(readFileName());
    string fileName =personList.getFileName();
    personList.writeToFile();
    cout << "Person list has been saved from '" << fileName << "'." << endl;
}

void UserInterface::readListFile()
{
    personList.setFileName(readFileName());
    string fileName =personList.getFileName();
    ifstream fin (fileName.c_str());
    if(fin)
    {
        personList.readFromFile();
        cout << "Person list has been read from '" << fileName << "'." << endl;
    }
    else
    {
        cout <<"No file named '" << fileName << "' was found."<< endl;
    }
}

void UserInterface::printListNameSort()
{
    personList.sortPeopleByName();
    personList.printPeople();
}

void UserInterface::printListPersNrSort()
{
    personList.sortPeopleByPersNr();
    personList.printPeople();
}

void UserInterface::printListShoeNrSort()
{
    personList.sortPeopleByShoeNr();
    personList.printPeople();
}

int UserInterface::listSize()
{
    return personList.getListSize();
}

void UserInterface::run()
{

    bool again = true;
    while(again)
    {
        int choice = menuChoice();
        switch(choice)
        {
            case 0:
                readListFile();
                nextMoveKey();
                break;
            case 1:
                addPersonToList();
                nextMoveKey();
                break;
            case 2:
                printListNameSort();
                nextMoveKey();
                break;
            case 3:
                printListPersNrSort();
                nextMoveKey();
                break;
            case 4:
                printListShoeNrSort();
                nextMoveKey();
                break;
            case 5:
                printListSize();
                nextMoveKey();
                break;
            case 6:
                saveToFile();
                nextMoveKey();
                break;
            case 7:
                printPersonList();
                nextMoveKey();
                break;

            case 8:
                printPerson();
                nextMoveKey();
                break;
            case 9:
                again = false;
                break;
             //case 10
            default:
                cout<< "\nInvalid choice. Choose a value between 0 and 9" << endl;
                break;

        }
    }

}

void UserInterface::nextMoveKey()
{
    cout << "\n\tPress 'ENTER' to continue!";
    cin.get();
}

void UserInterface::printPerson()
{
    int idx = -1;
    cout << "Enter the position on the list of the Person you want to print. counting starts from '0'.";
    cin>>idx;
    cout << "The person at position " << idx<< " on the list is:\n" <<personList.getPerson(idx) << endl;
}

void UserInterface::printListSize()
{
    cout <<"The number of persons stored in the list is "<<listSize()<<endl;
}




