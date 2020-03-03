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

public:
    Menu();

    Menu(const vector<MenuItem> &menuOptions, const string &menuTitle);

    virtual ~Menu();

    const string &getMenuTitle() const;

    void setMenuTitle(const string &menuTitle);

    const vector<MenuItem> &getMenuOptions() const;
    //adds a menuItem to the vector list
    void addItem(const string &pMenuText, bool pEnabled);
    //prints menu options stored in the vector on the screen
    void printMenuItems();
    //prompts user to make a choice and returns an int corresponding to the choice
    int getMenuChoice();


};


#endif //PROJECT_MENU_H
