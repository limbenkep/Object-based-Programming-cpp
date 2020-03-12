//
// Created by limbe on 2020-03-02.
//

#include "Song.h"

Song::Song()
= default;

Song::Song(const string &pSongTitle, const string &pArtist, const MyTime &pSongLength) : songTitle(pSongTitle),
                                                                                         artist(pArtist),
                                                                                         songLength(pSongLength)
{
}

Song::~Song()
= default;

const string &Song::getSongTitle() const
{
    return songTitle;
}

void Song::setSongTitle(const string &pSongTitle)
{
    songTitle = pSongTitle;
}

const string &Song::getArtist() const
{
    return artist;
}

void Song::setArtist(const string &pArtist)
{
    artist = pArtist;
}

MyTime Song::getSongLength() const
{
    return songLength;
}

void Song::setSongLength(const MyTime &pSongLength)
{
    songLength = pSongLength;
}

MyTime Song::getlengthFromInt(int pTotalSec)
{
    MyTime tempTime;
    tempTime.setTime(pTotalSec);
    return tempTime;
}

int Song::lengthToSec()
{
    int totalSeconds = songLength.timeToSeconds();
    return totalSeconds;
}

const char DELIM = '|';// '|' is a delimiter that specifies the boundary of each data entry

ostream &operator<< (ostream &os, Song &song)
{
    os << song.getSongTitle() << DELIM;
    os << song.getArtist() << DELIM;
    os << song.getSongLength();
    //os << song.lengthToSec();

    return os;
}

istream &operator>> (istream &is, Song &song)
{
    string tmpString;

    getline(is, tmpString, DELIM);
    song.setSongTitle(tmpString);

    getline(is, tmpString, DELIM);
    song.setArtist(tmpString);

    MyTime time;
    is >> time;
    song.setSongLength(time);
     return is;



}