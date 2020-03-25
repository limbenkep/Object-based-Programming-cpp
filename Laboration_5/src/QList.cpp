//
// Created by limbe on 2020-03-21.
//

#include "QList.h"

//------------------------------------------------------------------------------
// implementation of Node class
//------------------------------------------------------------------------------
class Node
{
public:
    Node *next; Person data;
    // Konstruktor
    Node(Node *next, Person data)
    :next{next}, data{data}{};

};

//------------------------------------------------------------------------------
// Implementation for QIterator class
//------------------------------------------------------------------------------
QIterator::QIterator(): node(nullptr)
{
}

QIterator::QIterator(Node *n) : node(n)
{
}

Item &QIterator::operator*() const
{
    return node->data;
}

QIterator &QIterator::operator++()
{
    node = node->next;
    return *this;
}

QIterator QIterator::operator++(int)
{
    QIterator tmp(*this);
    node = node->next;
    return tmp;

}

bool QIterator::operator!=(const QIterator &qi) const
{
    return node != qi.node;
}

//------------------------------------------------------------------------------
// Implementation for QList class
//------------------------------------------------------------------------------
QList::~QList()
{
    while(!isEmpty())
    {
        Node *tmp = first;
        first = first->next;
        delete tmp;
    }
}

void QList::enque(Item item)
{
    Node *pNew = new Node(0,item);// a new node is created containing the data to be added
    if(isEmpty())
        first = pNew; // if is empty, let firt point to the new node.
    else
        last->next = pNew; // if the queue is not empty, let last next pointer point to the new node
    last = pNew; // let the new node become the new last
}

bool QList::deque(Item &item)
{
    if(isEmpty())
        return false;

    Node *n = first;
    item = n->data;
    first = first->next;
    if(isEmpty())            // if queue becomes empty
        last = nullptr;
    delete n;
    return true;
}

bool QList::isEmpty() const
{
    return first== nullptr;
}

bool QList::del(Item item)
{
    Node *prev = nullptr;				// keep track of previous item
    Node *itemPtr = nullptr;			// node to the item to be deleted

    // Check whether it is the head node, if so, delete and update the head node
    if (first->data == item)
    {
        itemPtr = first;
        first	= itemPtr->next;
        delete itemPtr;
        return true;
    }

    // if not the head node, traverse the list and check for all the values
    prev	= first;
    itemPtr = first->next;

    while (itemPtr != nullptr)
    {
        if (itemPtr->data == item)
        {
            prev->next = itemPtr->next;   // update the list

            // if it is last node, update the tail
            if (itemPtr == last)
            {
                last = prev;
            }
            delete itemPtr;
            break;				// break and return
        }
        prev	= itemPtr;
        itemPtr = itemPtr->next;
    }

    return true;
}




//------------------------------------------------------------------------------
