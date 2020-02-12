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
    << "\tTo sort list of persons by Name enter '2' "<<endl
    << "\tTo sort list of persons by social security number enter '3'."<<endl
    << "\tTo sort list of persons by shoe size enter '4'."<<endl
    << "\tTo get number of persons in the list enter '5'."<<endl
    << "\tTo save List of persons in a file, enter '6'."<<endl
    << "\tTo print all persons on the List, enter '7'."<<endl
    << "\tTo read data on a person at a particular position on the list enter '8' "<<endl
    << "\tTo exit program enter '9'"<<endl
    << "\tMake a choice: ";
    int choice = -1;
    cin>>choice;
    cin.ignore(1000, '\n');
    while (choice <0 || choice >9)
    {
        cout << "invalid choice. Choice must lise between 0 and 9.\n Make a choice:";
        cin>>choice;
        cin.ignore(1000, '\n');
    }

    return choice;
}

void UserInterface::addPersonToList()
{
    Person newPerson = readPerson();
    personList.addPerson(newPerson);
}

Person UserInterface::readPerson()
{
    string tmpString;
    Name tmpName;
    Address addr;
    Person pers;
    cout << "\n\nTo add person to the list enter the following data:\nFirst name: ";
    getline(cin, tmpString);
    tmpName.setFirstName(tmpString);

    cout << "\nLast name: ";
    getline(cin, tmpString);
    tmpName.setLastName(tmpString);
    pers.setName(tmpName);

    cout << "\nAddress street name: ";
    getline(cin, tmpString);
    addr.setStreetName(tmpString);

    cout << "\nPost number: ";
    getline(cin, tmpString);
    addr.setPostNumber(tmpString);

    cout << "\nCity name: ";
    getline(cin, tmpString);
    addr.setCityName(tmpString);
    pers.setAddress(addr);

    cout <<"\nSocial security number: ";
    getline(cin, tmpString);
    pers.setPersNr(tmpString);
    cout <<"\nSocial shoe size: ";
    int tmp = 0;
    cin>> tmp;
    pers.setShoeNr(tmp);
    return pers;
}

void UserInterface::printPersonList()
{
    personList.printPeople();
}

string UserInterface::readFileName()
{
    string tmpString;
    cout << "\nEnter the name of the file to which you want to save list of people: ";
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

PersonList UserInterface::listNameSort()
{
    personList.sortPeopleByName();
    return personList;
}

PersonList UserInterface::listPersNrSort()
{
    personList.sortPeopleByPersNr();
    return personList;
}

PersonList UserInterface::listShoeNrSort()
{
    personList.sortPeopleByShoeNr();
    return personList;
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
                listNameSort();
                nextMoveKey();
                break;
            case 3:
                listPersNrSort();
                nextMoveKey();
                break;
            case 4:
                listShoeNrSort();
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
            default:
                cout<< "\nChoose a value between 0 and 9" << endl;
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




