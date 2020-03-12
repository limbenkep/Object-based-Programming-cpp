//
// Created by limbe on 2020-03-02.
//

#include "Album.h"

Album::Album()
= default;

Album::Album(const string &pAlbumName, const vector<Song> &pSongList) : albumName(pAlbumName), songList(pSongList)
{
}

Album::~Album()
{

}

const string &Album::getAlbumName() const
{
    return albumName;
}

void Album::setAlbumName(const string &pAlbumName)
{
    albumName = pAlbumName;
}

const vector<Song> &Album::getSongList() const
{
    return songList;
}

void Album::addSongToList(const Song &pSong)
{
    songList.push_back(pSong);
}

int Album::sizeOfSongList() const
{
    return songList.size();
}
int Album::albumLength() const
{
    int totalSec = 0;
    for (auto idx : songList)
    {
        totalSec =totalSec + idx.lengthToSec();
    }
    return totalSec;
}

void Album::writeToFile(ostream &os)
{
    for (auto &idx: songList)
    {
        os << idx << endl;
    }

}

bool Album::operator<(const Album &album) const
{
    return albumLength() < album.albumLength();
}

ostream &operator<< (ostream &os, Album &album)
{
    os << album.getAlbumName() << endl;
    os << album.sizeOfSongList() << endl;
    album.writeToFile(os);
    return os;
}

istream &operator>> (istream &is, Album &album)
{
    string tmpString;
    getline(is, tmpString);
    album.setAlbumName(tmpString);
    getline(is, tmpString);
    int albumSize = stoi(tmpString);
    for (int i = 0; i < albumSize; i++)
    {
        Song tmpSong;
        is >> tmpSong;
        album.addSongToList(tmpSong);
    }
    return is;
}