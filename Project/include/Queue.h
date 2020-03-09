//
// Created by limbe on 2020-03-07.
//

#ifndef PROJECT_QUEUE_H
#define PROJECT_QUEUE_H


#include "Song.h"

class Queue
{
private:
    Song*songArray;
    int arraySize;
    int first, last;

public:
    Queue();

    Queue(int arraySize);

    virtual ~Queue();

    void addToQueue(Song &pSong);
    void removeFromQueue();


};


#endif //PROJECT_QUEUE_H
