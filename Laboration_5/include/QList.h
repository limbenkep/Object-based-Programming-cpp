//
// Created by limbe on 2020-03-21.
//

#ifndef LABORATION_5_QLIST_H
#define LABORATION_5_QLIST_H

#include <Person.h>
typedef Person Item;
class Node;
//------------------------------------------------------------------------------
/* QIterator class
 * This iterator is used to iterate through the queue in the Qlist class
 * has a node ad datamember that contains data of type Person
------------------------------------------------------------------------------*/
class QIterator
{
private:
    Node *node;
public:
    QIterator();
    QIterator(Node *n);

    Item &operator* () const;
    QIterator &operator++ (); //prefix ++
    QIterator operator++ (int);//postfix ++
    bool operator!=(const QIterator &qi) const;

};

/*------------------------------------------------------------------------------
 * Qlist class store nodes in a queue list containing data of type Person
 * contain functions to add a person at the end of the list, delete person fron the top of the list and
 * delete a given person within the list
------------------------------------------------------------------------------
 */
class QList{
private:
    Node *first, *last;

public:
    QList():first(nullptr), last(nullptr) {};
    ~QList();

    //Member functions
    /*
     * receives a copy of an Item object (Person object)
     * Adds a node containing the Item as data to the end of the list.
     */
    void enque(Item item);
    /*
     * Deletes a node from the beginning of the list and returns the data on the Item deleted through a referens declared.
     * returns false if list is empty else true
     */
    bool deque(Item &item);
    /*receives an item as a parameter and deletes the node from the queue that contains that item.
     * Returns a bool if the item is deleted or not.
     * */
    bool del (Item item);
    //checks if the queue is empty
    bool isEmpty()const;

    QIterator begin()const {return QIterator(first);}
    QIterator end() const { return QIterator(nullptr);}
};


#endif //LABORATION_5_QLIST_H
