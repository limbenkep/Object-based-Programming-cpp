//
// Created by limbe on 2020-03-07.
//
/*
 * This class is a userinterface class that allows the user to choose what to be executed and contains functions
 * that execute the various options. This class functions to add and delete an album, read from and save to file,
 * print an album, print all details of albumList sorted by Name in alphabetical order, print detailed  albumList
 * sorted by total time from longest, print album names in alphabetical order and print album name and total play time
 * sorted by total play time See comments on the different functions how they work.
 * This class also contain functions that run the different menu and submenus.
 */
#ifndef PROJECT_JUKEBOX_H
#define PROJECT_JUKEBOX_H
#include<Menu.h>
#include <Album.h>
#include <fstream>

class Jukebox
{
private:
    vector<Album> albumList;
    Menu jukeBoxMenu, fileMenu, printMenu;
    const string fileName{"jukebox.txt"};
    bool jukeboxRunning = true;
    /*
    * reads album from a fileMenu
    */
    void readAlbumListFromFile();
    /*
     * saves album to a fileMenu
     */
    void writeAlbumListToFile();
    /*
     * receives an Album object by reference and adds to the albumList
     */
    void addAlbumToList();
    // prompts user to enter choice and check if it is an integer greater than 0 and returns the interger if not it prompts user to renter a number
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
     * prints the enabled options of the File menu of a given object, gets user's choice and execute the
     * action corresponding to the choice
     */
    void executeFileMenu();
    /*
     * prints the enabled options of the printMenu menu of a given object, gets user's choice and execute the
     * action corresponding to the choice
     */
    void executePrintMenu();
    /*
     * this function calls the function choose album that prompts the user to choose the album to be deleted and then deletes theh album
     */
    void printAnAlbum();
    /*
     * compares the albumNames of two albums and returns true of false if left is less than right
     */
    static bool compareNamesOfAlbum(const Album &album1, const Album &album2);
    /*
     * compares the album's total time of two albums and returns true of false if left is greater than right
     */
    static bool compareTotalTimeOfAlbum(const Album &album1, const Album &album2);
    /*
     * Receives an album by reference and prints it to the screen
     */
    void printAlbum(const Album &pAlbum);
    /*
     * prints all the albums in the list
     */
    void printAlbumList();
    /*
     * prints the details of all the albums in the list sorted by Album names in alphabetical order
     */
    void printAllSortByAlbumName();
    /*
     * prints the details of all the albums in the list sorted by Album's total time starting from the longest album
     */
    void printAllSortByAlbumTime();
    /*
     * prints the names of all the albums in the list sorted by Album names in alphabetical order
     */
    void printSortedAlbumNames();
    /*
     * prints the names and total time of all the albums in the list sorted by Album's total time starting from the longest album
     */
    void printTimeSortedNameAndTime();

    void nextMoveKey();

public:
    Jukebox();

    Jukebox(const vector<Album> &albumList, const Menu &jukeBoxMenu, const Menu &fileMenu, const Menu &printMenu,
            const string &fileName);

    virtual ~Jukebox();

    /*
      * prints the enabled options of the Juke Box menu of a given object, gets user's choice and execute the
      * action corresponding to the choice
      */
    void run();

};


#endif //PROJECT_JUKEBOX_H
