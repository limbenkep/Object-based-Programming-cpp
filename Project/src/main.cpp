#include "Prototypes.h"
#include "memstat.hpp"
#include <fstream>
#include <string>
#include <Song.h>
#include <Album.h>
#include <Menu.h>
#include <Jukebox.h>

int main()
{
    /*MyTime class test
    MyTime time;
    time.setSeconds(25);
    time.setMinutes(10);
    time.setHours(10);

    MyTime myTime (25, 30, 19);
    MyTime uTime (25, 30, 19);

    MyTime herTime;
    herTime.setTime(100);

    cout << "Hours:" <<time.getHours() << "\tMinutes: " << time.getMinutes() << "\tSeconds: " << time.getSeconds() << endl;
    cout << "Hours:" <<myTime.getHours() << "\tMinutes: " << myTime.getMinutes() << "\tSeconds: " << myTime.getSeconds() << endl;
    cout << time.timeToSeconds() << endl;
    cout << "her MyTime  Hours:" <<herTime.getHours() << "\tMinutes: " << herTime.getMinutes() << "\tSeconds: " << herTime.getSeconds() << endl;

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

    MyTime time1;
    int temp= 0;
    fstream read ("example.txt", ios::in);
    while (read >> temp)
        time1.setTime(temp);

    cout << "Time1 Hours:" <<time1.getHours() << "\tMinutes: " << time1.getMinutes() << "\tSeconds: " << time1.getSeconds() << endl;

     //***Test for class song***

    MyTime time;
    time.setSeconds(25);
    time.setMinutes(10);
    time.setHours(0);
    Song song("Lost love", "Maria Carrie", time);
    fstream outFile ("songList.txt", ios::out);
    outFile << song << endl;
    outFile.close();

    Song song1;
    fstream inFile ("songList.txt", ios::in);
    inFile >> song1;


    cout << song1.getSongTitle() << song1.getArtist()<< "\tMyTime:" << song.lengthToSec() << endl;
    MyTime time1;
    time1 = song1.getSongLength();
    cout << "Hout: " << time1.getHours()<<"minutes: " << time1.getMinutes() << "Seconds: " << time1.getSeconds() << endl;

    //***Test for Album class
    MyTime time;
    time.setSeconds(40);
    time.setMinutes(1);
    time.setHours(0);
    Song song("Lost love", "Maria Carrie", time);
    Song song1("Found love", "Maria Carrie", time);
    Song song2("Fight song", "Lou lou", time);
    Album album1;
    album1.setAlbumName("My album");
    album1.addSongToList(song);
    album1.addSongToList(song1);
    album1.addSongToList(song2);

    fstream outFile("myList.txt", ios::out);
    outFile << album1 << endl;
    outFile.close();

    cout << "Album name: " << album1.getAlbumName() << "\t Size: " << album1.sizeOfSongList() << "\t Playtime: " << album1.albumLength()
         << endl;

    Album album;
    fstream inFile ("example.txt", ios::in);
    inFile >> album;

    cout << "Album name: " << album.getAlbumName() << "\t Size: " << album.sizeOfSongList() << "\t Playtime: " << album.albumLength()
    << endl;
    if (album1 < album)
        cout << "album 1 < album" << endl;
    if (album < album1)
        cout << "album < album1" << endl;
    */
   /* Menu menu;
    menu.setMenuTitle("Jukebox");
    menu.addItem("File...", true);
    menu.addItem("Add an album", false);
    menu.addItem("Delete an album",false);
    menu.addItem("Print...", true);

    menu.printMenuItems();*/

    Jukebox jkb;
    jkb.run();
    return 0;
}
