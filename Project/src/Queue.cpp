//
// Created by limbe on 2020-03-07.
//

#include "Queue.h"

Queue::Queue()
{
    arraySize = 5;
    songArray = new Song[arraySize];
    first = 0;
    last = 0;
}

Queue::Queue(int pArraySize) : arraySize(pArraySize)
{
    songArray = new Song[pArraySize];
    first = 0;
    last = 0;
}

Queue::~Queue()
{
    delete [] songArray;

}

void Queue::addToQueue(Song &pSong)
{
    if (last < arraySize)
    {
        songArray[last++] = pSong;
    }
}
