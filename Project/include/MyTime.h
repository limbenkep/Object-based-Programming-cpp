//
// Created by limbe on 2020-03-01.
//

#ifndef PROJECT_MYTIME_H
#define PROJECT_MYTIME_H

#include <iostream>
using namespace std;


class MyTime
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    MyTime();

    MyTime(int pHours, int pMinutes, int pSeconds);

    virtual ~MyTime();

    int getHours() const;

    void setHours(int pHours);

    int getMinutes() const;

    void setMinutes(int pMinutes);

    int getSeconds() const;

    void setSeconds(int pSeconds);

    //overload operators
    MyTime operator+ (const MyTime &time) const;
    bool operator< (const MyTime &time) const;
    bool operator== (const MyTime &time) const;

    //member functions
    // converts MyTime object to seconds and returns total seconds as int.
    int timeToSeconds () const;
    //function receives time as total number of seconds (int) and sets hours, minutes and seconds
    void setTime(const int pTotalSec);



};

//overload operators for reading from and writin gto a fileMenu
istream &operator>> (istream & is, MyTime &time);
ostream &operator<< (ostream &os, const MyTime &time);


#endif //PROJECT_MYTIME_H
