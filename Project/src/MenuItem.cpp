//
// Created by limbe on 2020-03-03.
//

#include "MenuItem.h"

MenuItem::MenuItem()
{
}

MenuItem::MenuItem(const string &pMenuText, bool pEnabled) : menuText(pMenuText), enabled(pEnabled)
{
}

const string &MenuItem::getMenuText() const
{
    return menuText;
}

void MenuItem::setMenuText(const string &pMenuText)
{
    menuText = pMenuText;
}

bool MenuItem::isEnabled() const
{
    return enabled;
}

void MenuItem::setEnabled(bool pEnabled)
{
    enabled = pEnabled;
}

bool MenuItem::operator==(const MenuItem &menuItem)
{
    return menuText == menuItem.menuText && enabled == menuItem.enabled;
}

MenuItem::~MenuItem()
= default;
