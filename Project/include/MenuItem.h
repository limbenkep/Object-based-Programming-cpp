//
// Created by limbe on 2020-03-03.
//
/*
 * This a helper class to Memu class which handles the menu text and the choice if the enabled or not.
 * it has data members menuText (string) and enabled (bool).
 */
#ifndef PROJECT_MENUITEM_H
#define PROJECT_MENUITEM_H

#include <iostream>
#include <string>
using namespace std;


class MenuItem
{
private:
    string menuText;
    bool enabled;

public:
    MenuItem();

    MenuItem(const string &menuText, bool enabled);

    virtual ~MenuItem();

    const string &getMenuText() const;

    void setMenuText(const string &menuText);

    bool isEnabled() const;

    void setEnabled(bool enabled);

    bool operator== (const MenuItem &menuItem) const;


};


#endif //PROJECT_MENUITEM_H
