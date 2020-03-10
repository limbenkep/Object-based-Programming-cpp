//
// Created by limbe on 2020-03-07.
//

#ifndef PROJECT_JUKEBOX_H
#define PROJECT_JUKEBOX_H
#include<Menu.h>
#include <Album.h>
#include <fstream>


class Jukebox
{
private:
    vector<Album> albumList;
    Menu jukeBox, file, print;
    const string fileName{"jukebox"};
public:
    Jukebox();

    Jukebox(const vector<Album> &albumList, const Menu &jukeBox, const Menu &file, const Menu &print);

    virtual ~Jukebox();

    /*
     * reads album from a file
     */
    void readAlbumListFromFile();
    /*
     * saves album to a file
     */
    void writeAlbumListToFile();
    /*
     * receives an Album object by reference and adds to the albumList
     */
    void addAlbumToList();
    // prompts user to enter choice and check if it is an integer and it returns the interger if not it prompts user to renter a number
    int getNumber();
    /*
     * prints list of album names and promps user to choose and album, the choice is read as an interger, controlled
     * for that the choice is valid and then returns the index of the choosen album
     */
    int chooseAnAlbum();
    /*
     * calls function chooseAnAlbum that gets index users choices and delete the album at that index
     */
    void deleteAlbumFromList();
    /*
     * prints the albumName of the albums in the list and number them starting from 1
     */
    void printAlbumNamesList();
    /*
     * prints the enabled options of the Juke Box menu of a given object, gets user's choice and execute the
     * action corresponding to the choice
     */
    void executeJukeBoxMenu();
    /*
     * prints the enabled options of the File menu of a given object, gets user's choice and execute the
     * action corresponding to the choice
     */
    void executeFileMenu();
    /*
     * prints the enabled options of the print menu of a given object, gets user's choice and execute the
     * action corresponding to the choice
     */
    void executePrintMenu();
    void printAnAlbum();


};


#endif //PROJECT_JUKEBOX_H
