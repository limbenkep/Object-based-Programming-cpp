//
// Created by limbe on 2020-03-03.
//
/*
 *
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
