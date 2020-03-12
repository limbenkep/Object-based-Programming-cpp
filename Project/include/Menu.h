//
// Created by limbe on 2020-03-03.
//

#ifndef PROJECT_MENU_H
#define PROJECT_MENU_H

#include <MenuItem.h>
#include <vector>


class Menu
{
private:
    vector<MenuItem>menuOptions;
    string menuTitle;
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
    //int choiceToInt(const MenuItem &pItem) const;


    void executeMenu();
    void startUpJukeBoxMenu();
    void enabledJukeBoxMenu();
    void enabledFileMenu();
    void startUpFileMenu();
    void startUpPrintMenu();
    void enabledPrintMenu();





};


#endif //PROJECT_MENU_H
