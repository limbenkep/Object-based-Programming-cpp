//
// Created by limbe on 2020-03-03.
//

#include "Menu.h"

Menu::Menu()
= default;

Menu::Menu(const vector<MenuItem> &menuOptions, const string &menuTitle) : menuOptions(menuOptions),
                                                                           menuTitle(menuTitle)
{
}

Menu::~Menu()
= default;

const string &Menu::getMenuTitle() const
{
    return menuTitle;
}

void Menu::setMenuTitle(const string &pMenuTitle)
{
    menuTitle = pMenuTitle;
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

void Menu::printMenuItems() const
{
    cout << "\n**** " << menuTitle << " ****" << endl;
    int i = 1;
    for (const auto& idx: menuOptions)
    {
        if (idx.isEnabled())
        {
            cout <<" " << i << ".  " << idx.getMenuText() << endl;
            i++;
        }
    }
}

int Menu::getMenuChoice() const
{
    vector<MenuItem> enabledOptions;
    for (const auto& idx: menuOptions)
    {
        if (idx.isEnabled())
        {
            enabledOptions.push_back(idx);
        }
    }
    int pSize = static_cast<int>(enabledOptions.size());
    printMenuItems();
    cout << "\nMy choice: ";
    int choice = -1;
    cin>>choice;
    while(!cin||choice < 0 || choice >pSize)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid entry. Enter a number between 1 and " << pSize <<endl;
        cout << "\nMy choice: ";
        cin>>choice;
    }
    cin.ignore(1000, '\n');
    auto it = find (menuOptions.begin(), menuOptions.end(), enabledOptions[choice-1]);
    int myIndex = it - menuOptions.begin();
    return myIndex + 1;
}


void Menu::startUpJukeBoxMenu()
{
    menuTitle = jukeBox;
    addItem(file, true);
    addItem(addAnAlbum, false);
    addItem(deleteAnAlbum, false);
    addItem(print, false);
    addItem("Exit", true);
}

void Menu::enabledJukeBoxMenu()
{
    menuTitle = jukeBox;
    menuOptions.clear();
    addItem(file, true);
    addItem(addAnAlbum, true);
    addItem(deleteAnAlbum, true);
    addItem(print, true);
    addItem(exit, true);
}

void Menu::enabledFileMenu()
{
    menuTitle = file;
    menuOptions.clear();
    addItem(open, true);
    addItem(save, true);
    addItem(backToMainMenu, true);
}

void Menu::startUpFileMenu()
{
    menuTitle = file;
    addItem(open, true);
    addItem(save, false);
    addItem(backToMainMenu, true);
}

void Menu::startUpPrintMenu()
{
    menuTitle = print;
}

void Menu::enabledPrintMenu()
{
    menuOptions.clear();
    menuTitle = print;
    addItem(printAlbum, true);
    addItem(printByName, true);
    addItem(printByTime, true);
    addItem(printSimpleSortedName, true);
    addItem(printSimpleSortedTime, true);
    addItem(backToMainMenu, true);
}


