/*
 * This program Uses classes Name, Address and Person to handle information about a person. The program preloads vectpr
 * People of type Person with three persons. It then prompts the user to enter information about a person and a person
 * is created and added to the vector using the function. All the members of the vector are the printed.
 */


#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include "memstat.hpp"
#include "Name.h"
#include "Address.h"
#include "Person.h"
#include <iostream>
#include <string>
#include <vector>


/*
 * the function receives a vector by referens,
 * reads in data for a person and adds a new person to the vector
 */
void addPerson(vector<Person> &people);

/*
 * the function receives a vector by referens,
 * and prints out all the persons in the vector on the screen
 */
void printPeople(vector<Person> &people);

#endif  // Laboration_2_PROTOTYPES_H
