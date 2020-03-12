//
// Created by limbe on 2020-03-02.
//

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

};
//Overload constructors to read from and write to fileMenu
ostream &operator<< (ostream &os, Album &album);
istream &operator>> (istream &is, Album &album);

#endif //PROJECT_ALBUM_H
