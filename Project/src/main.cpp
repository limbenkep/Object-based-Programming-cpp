#include "Prototypes.h"
#include "memstat.hpp"
#include <fstream>
#include <string>

int main()
{
    Time time;
    time.setSeconds(25);
    time.setMinutes(10);
    time.setHours(10);

    Time myTime (25, 30, 19);
    Time uTime (25, 30, 19);

    Time herTime;
    herTime.setTime(100);

    cout << "Hours:" <<time.getHours() << "\tMinutes: " << time.getMinutes() << "\tSeconds: " << time.getSeconds() << endl;
    cout << "Hours:" <<myTime.getHours() << "\tMinutes: " << myTime.getMinutes() << "\tSeconds: " << myTime.getSeconds() << endl;
    cout << time.timeToSeconds() << endl;
    cout << "her Time  Hours:" <<herTime.getHours() << "\tMinutes: " << herTime.getMinutes() << "\tSeconds: " << herTime.getSeconds() << endl;

    if (time == myTime)
    {
        cout << "time == myTime" << endl;
    } else if (time < myTime)
    {
        cout << "time < myTime" << endl;
    } else
    {
        cout << "time > myTime" << endl;
    }
    if (uTime == myTime)
    {
        cout << "uTime == myTime" << endl;
    }

    fstream outFile("example.txt", ios::out);

    outFile << time << endl;
    outFile.close();

    Time time1;
    int temp= 0;
    fstream read ("example.txt", ios::in);
    while (read >> temp)
        time1.setTime(temp);

    cout << "Time1 Hours:" <<time1.getHours() << "\tMinutes: " << time1.getMinutes() << "\tSeconds: " << time1.getSeconds() << endl;


    return 0;
}
