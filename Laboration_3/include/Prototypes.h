#ifndef DT018G_PROTOTYPES_H
#define DT018G_PROTOTYPES_H

#include "Person.h"
#include <vector>

/**
 * This is a dummy prototype used only to enforce proper file structure,
 * as Git doesn't allow empty folders to be pushed to remote origin.
 * Remove this dummy function before submission.
 */
void assignmentFunction();

bool sortByName(const Person &lhs, const Person &rhs);
bool sortByPersNr(const Person &lhs, const Person &rhs);
bool sortByShoeNr(const Person &lhs, const Person &rhs);
struct SortByShoeSize
{
    bool operator()(const Person &lhs, const Person &rhs)
    {
        return lhs.getShoeNr() < rhs.getShoeNr();
    }
} ;

#endif  // DT018G_PROTOTYPES_H
