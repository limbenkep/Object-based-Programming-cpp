//
// Created by limbe on 2020-03-02.
//
/*
 * This class store songs to a list to form an album with a given name.
 * The data members are a string for the name and a vector that stores objects of class Song in an list
 * the class contains functions to constructors and destructor, getters and setters for the data member and
 * <, <<, and >> overload operators for comparison, writing to file and reading from file respectively
 * It also contain member funtions to add a song to the list, get the total play time of the list and to get the number
 * of songs in a list
 */
#ifndef PROJECT_ALBUM_H
#define PROJECT_ALBUM_H

#include <Song.h>
#include <vector>
#include <algorithm>



class Album
{
private:
    string albumName;
    vector<Song> songList;
public:
    Album();
    Album(const string &albumName, const vector<Song> &songList);
    virtual ~Album();

    const string &getAlbumName() const;

    void setAlbumName(const string &albumName);
    /*
     * receives a song as parameter and adds the song to the vector<Song>songList
     */
    void addSongToList(const Song &pSong);
    // returns the number of Song objects stored in the album's songList
    int sizeOfSongList() const;
    //function writes an album to a fileMenu; album, number of songs, songs information.
    void writeToFile(ostream &os);
    // computes the total play time in seconds of all the songs in the album and returns it as an int.
    int albumLength() const;
    // Less than overload operator compares the album's total play time.
    bool operator< (const Album &album) const;

    const vector<Song> &getSongList() const;
    void clearSongList();

};
//Overload constructors to read from and write to fileMenu
ostream &operator<< (ostream &os, Album &album);
istream &operator>> (istream &is, Album &album);

#endif //PROJECT_ALBUM_H
