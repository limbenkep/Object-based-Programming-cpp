//
// Created by limbe on 2020-03-01.
//

#ifndef PROJECT_TIME_H
#define PROJECT_TIME_H

#include <iostream>
using namespace std;


class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time();

    Time(int pHours, int pMinutes, int pSeconds);

    virtual ~Time();

    int getHours() const;

    void setHours(int pHours);

    int getMinutes() const;

    void setMinutes(int pMinutes);

    int getSeconds() const;

    void setSeconds(int pSeconds);

    //overload operators
    Time operator+ (const Time &time) const;
    bool operator< (const Time &time) const;
    bool operator== (const Time &time) const;

    //member functions
    // converts Time object to seconds and returns total seconds as int.
    int timeToSeconds ();
    //function receives time as total number of seconds (int) and sets hours, minutes and seconds
    void setTime(int pTotalSec);



};

//overload operators for reading from and writin gto a file
istream &operator>> (istream & is, Time &time);
ostream &operator<< (ostream &os, Time &time);


#endif //PROJECT_TIME_H
