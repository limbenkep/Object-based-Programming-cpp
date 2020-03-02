//
// Created by limbe on 2020-03-02.
//

#ifndef PROJECT_SONG_H
#define PROJECT_SONG_H

#include <string>
#include <Time.h>

class Song
{
private:
    string songTitle;
    string artist;
    Time songLength;

public:
    Song();

    Song(const string &songTitle, const string &artist, const Time &songLength);

    virtual ~Song();

    //getters and setters
    const string &getSongTitle() const;

    void setSongTitle(const string &songTitle);

    const string &getArtist() const;

    void setArtist(const string &artist);

    Time getSongLength() const;

    void setSongLength(const Time &songLength);

    //member functions
    Time getlengthFromInt(int pTotalSec);
    int lengthToSec();


};

ostream &operator<< (ostream &os, Song &song);
istream &operator>> (istream &is, Song &song);

#endif //PROJECT_SONG_H
