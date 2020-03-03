//
// Created by limbe on 2020-03-03.
//

#include "Menu.h"

Menu::Menu()
{
}

Menu::Menu(const vector<MenuItem> &menuOptions, const string &menuTitle) : menuOptions(menuOptions),
                                                                           menuTitle(menuTitle)
{
}

Menu::~Menu()
{

}

const string &Menu::getMenuTitle() const
{
    return menuTitle;
}

void Menu::setMenuTitle(const string &menuTitle)
{
    Menu::menuTitle = menuTitle;
}

const vector<MenuItem> &Menu::getMenuOptions() const
{
    return menuOptions;
}

void Menu::addItem(const string &pMenuText, bool pEnabled)
{
    MenuItem item(pMenuText, pEnabled);
    menuOptions.push_back(item);
}

void Menu::printMenuItems()
{
    cout << "**** " << menuTitle << " ****" << endl;
    int i = 1;
    for (const auto& idx: menuOptions)
    {
        cout <<" " << i << ".  " << idx.getMenuText() << endl;
        i++;
    }
}

int Menu::getMenuChoice()
{
    cout << "\nEnter the number corresponding to the option you like to execute: ";
    int choice = -1;
    int noChoice = 0;
    cin>>choice;
    if (!cin)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return noChoice;

    }
    cin.ignore(1000, '\n');

    return choice;

    return 0;
}
