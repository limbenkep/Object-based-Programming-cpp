//
// Created by limbe on 2020-03-01.
//

#include "Time.h"

Time::Time(): hours(0), minutes(0), seconds(0)
{
}

Time::Time(int pHours, int pMinutes, int pSeconds) : hours(pHours), minutes(pMinutes), seconds(pSeconds)
{
}

Time::~Time()
{

}

int Time::getHours() const
{
    return hours;
}

void Time::setHours(int pHours)
{
    hours = pHours;
}

int Time::getMinutes() const
{
    return minutes;
}

void Time::setMinutes(int pMinutes)
{
    minutes = pMinutes;
}

int Time::getSeconds() const
{
    return seconds;
}

void Time::setSeconds(int pSeconds)
{
    seconds = pSeconds;
}

Time Time::operator+(const Time &time) const
{
    Time sum;
    int totalSec=0;
    int totalMin=0;
    totalSec = seconds + time.seconds;
    sum.seconds = totalSec % 60;
    totalMin = minutes + time.minutes + totalSec/60;
    sum.minutes = totalMin %60;
    sum.hours = hours + time.hours + totalMin/60;

    return sum;
}

bool Time::operator<(const Time &time) const
{
    //converts time to seconds and compare
    return (hours*60*60 + minutes*60 + seconds) < (time.hours*60*60 + time.minutes*60 + seconds);
}

bool Time::operator==(const Time &time) const
{
    return hours==time.hours && minutes==time.minutes && seconds == time.seconds;
}

int Time::timeToSeconds()
{
    return hours*60*60 + minutes*60 + seconds;
}

void Time::setTime(int pTotalSec)
{
    int temp = 0;
    seconds = pTotalSec % 60;
    temp = pTotalSec/60;
    minutes = temp % 60;
    hours = temp/60;
}

ostream &operator<< (ostream &os, Time &time)
{
    os << time.timeToSeconds();
    return os;
}

istream &operator>> (istream & is, Time &time)
{
    int temp = 0;
    is >> temp;
    is.get(); // reads and discards end of line
    time.setTime(temp);

    return is;
}
