#include "Prototypes.h"
#include <iostream>
using std::cout;
using std::endl;

/*
 * the function receives a vector by referens,
 * reads in data for a person and adds a new person to the vector
 */
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


void assignmentFunction(){}