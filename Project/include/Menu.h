//
// Created by limbe on 2020-03-03.
//
/*
 * The Menu class handles the menus and submenu. This class contains functions load the menu with menuItems for the different menu
 * options that that the user can execute in this program and sets if it is enabled or not. This class contain functions
 * that load the different functions for each menu that load the options the menu should have at start up and the
 * options teh menu shld have after reading from File the first time.
 * At start up for jukeBoxMenu only File and Exit enabled, and for fileMenu only Open and Back to main menu is Enabled.
 * This class also contain functions to print enabled menu option son the screen and read users choice entered n the keyboard.
 */

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include <MenuItem.h>
#include <vector>


class Menu
{
private:
    vector<MenuItem>menuOptions;
    string menuTitle;
    //menuText options
    const string jukeBox{"Juke Box"};
    const string file{"File"};
    const string addAnAlbum{"Add an album"};
    const string deleteAnAlbum{"Delete an album"};
    const string print{"Print"};
    const string exit{"exit"};
    const string open{"Open"};
    const string save{"Save"};
    const string backToMainMenu{"Back to main menu"};
    const string printAlbum{"Print one album"};
    const string printByName{"Print all sorted by album name"};
    const string printByTime{"Print all sorted by album total time"};
    const string printSimpleSortedName{"Print simple sorted by album name"};
    const string printSimpleSortedTime{"Print simple sorted by album total time"};

public:
    Menu();

    Menu(const vector<MenuItem> &menuOptions, const string &menuTitle);

    virtual ~Menu();

    const string &getMenuTitle() const;

    void setMenuTitle(const string  &pMenuTitle);

    const vector<MenuItem> &getMenuOptions() const;
    //adds a menuItem to the vector list
    void addItem(const string &pMenuText, bool pEnabled);
    //prints menu options stored in the vector on the screen
    void printMenuItems() const;
    //prompts user to make a choice and returns an int corresponding to the choice
    int getMenuChoice() const;
    //Loads jukeBoxMenu object with start menuItem options whereby only 'File' and 'Back to main menu' options are true and the rest false
    void startUpJukeBoxMenu();
    //Loads jukeBoxMenu object with menuItem options whereby all options are true
    void enabledJukeBoxMenu();
    //Loads FileMenu object with menuItem options whereby all options are true
    void enabledFileMenu();
    //Loads fileMenu object with start menuItem options whereby 'Open' and 'Back to main menu' options are true and 'Save' is false
    void startUpFileMenu();
    //Loads printMenu object with menuItem options whereby all options are false
    void startUpPrintMenu();
    //Loads printMenu object with menuItem options whereby all options are true
    void enabledPrintMenu();





};


#endif //PROJECT_MENU_H
