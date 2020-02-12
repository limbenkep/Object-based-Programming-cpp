//
// Created by limbe on 2020-02-07.
//

#include "PersonList.h"


PersonList::PersonList()
= default;

PersonList::PersonList(const vector<Person> &people, const string &fileName) : people(people), fileName(fileName)
{
}

PersonList::~PersonList()
= default;

string PersonList::getFileName() const
{
    return fileName;
}

void PersonList::setFileName(const string &pFileName)
{
    fileName = pFileName;
}

/*
 * the function receives a vector by referens,
 * reads in data for a person and adds a new person to the vector
 */
void PersonList::addPerson(const Person &pPerson)
{
    people.push_back(pPerson);
}

/*void PersonList::printPeople(vector<Person> &people)
{
    for(auto person: people )
    {
        person.showPerson(person);
    }
}*/

int PersonList::getListSize()
{
    return people.size();
}

Person PersonList::getPerson(int index)
{
    int size = getListSize();
    if (index >= 0 && index < size)
    {
        return people[index];
    } else
    {
        cout << "\nThe given index does not exist. Index must lie between 0 and " << size - 1 << endl;
        return Person();
    }

}

void PersonList::sortPeopleByName()
{
    sort(people.begin(), people.end(), sortByName);

}

void PersonList::sortPeopleByPersNr()
{
    sort(people.begin(), people.end(), sortByPersNr);
}

void PersonList::sortPeopleByShoeNr()
{
    sort(people.begin(), people.end(), sortByShoeNr);
}

void PersonList::readFromFile()
{
    Person tmpPerson;
    fstream inFile (fileName.c_str(), ios::in);
    while (inFile >> tmpPerson)
    {
        people.push_back(tmpPerson);
    }
}

void PersonList::writeToFile()
{
    fstream outFile (fileName.c_str(), ios::out);
    for (auto &idx: people)
    {
        outFile<<idx<<endl;
    }
    outFile.close();
}

void PersonList::printPeople()
{
    for (const auto& person: people)
    {
        cout << person << endl;
    }

}







