#include "Prototypes.h"



void addPerson(vector<Person> &people)
{
    Person newPerson;
    newPerson = newPerson.readPerson();
    people.push_back(newPerson);
}

void printPeople(vector<Person> &people)
{
    for(auto person: people )
    {
        person.showPerson(person);
    }
}
