//
// Created by limbe on 2020-03-07.
//

#include "Jukebox.h"



Jukebox::Jukebox()
{
    jukeBox.startUpJukeBoxMenu();
    file.startUpFileMenu();
    print.startUpPrintMenu();


}

Jukebox::Jukebox(const vector<Album> &albumList, const Menu &jukeBox, const Menu &file, const Menu &print)
: albumList(albumList), jukeBox(jukeBox), file(file), print(print)
{
}

Jukebox::~Jukebox()
{

}


void Jukebox::readAlbumListFromFile()
{
    Album tmpAlbum;
    fstream inFile (fileName.c_str(), ios::in);
    while (inFile >> tmpAlbum)
    {
        albumList.push_back(tmpAlbum);
    }
}

void Jukebox::writeAlbumListToFile()
{
    fstream outFile (fileName.c_str(), ios::out);
    for (auto &idx: albumList)
    {
        outFile<<idx<<endl;
    }
    outFile.close();
}

void Jukebox::addAlbumToList()
{
    Album pAlbum;

    albumList.push_back(pAlbum);
}

int Jukebox::chooseAnAlbum()
{
    cout << "\nYour choice: ";
    int choice = 0;
    cin>>choice;
    if (!cin)
    {

        do
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nThe entry must be a number! your choice: ";
            cin>>choice;
        }while(!cin);
    }
    cin.ignore(1000, '\n');
    int listSize= static_cast<int > (albumList.size());
    if (choice < 1 || choice > listSize)
    {
        cout << "\nThe entry must be between 1 and " << listSize;
        chooseAnAlbum();
    }
    return choice-1;// gets index by subtracting 1 from choice since choice is number from 1 and index from 0
}

void Jukebox::deleteAlbumFromList()
{
    printAlbumNamesList();
    cout << "Enter the number of the album you wish to delete." << endl;
    int myIndex = chooseAnAlbum();
    albumList.erase(albumList.begin()+ myIndex)

}

void Jukebox::printAlbumNamesList()
{
    int number = 1;
    for (auto &idx: albumList)
    {
        cout << number<<".  " <<idx.getAlbumName()<<endl;
    }
}
void Jukebox::executeJukeBoxMenu()
{
    bool again = true;
    do
    {
        switch (jukeBox.getMenuChoice())
        {
            case 1:
                executeFileMenu();
                break;
            case 2:
                addAlbumToList();
                break;
            case 3:
                deleteAlbumFromList();
                break;
            case 4:
                executePrintMenu();
                break;
            case 5:
                again = false;
                break;
            default:
                cout << "\nInvalid choice." << endl;
                break;

        }
    }while(again);


}

void Jukebox::executeFileMenu()
{
    switch (file.getMenuChoice())
    {
        case 1:
            readAlbumListFromFile();
            break;
        case 2:
            writeAlbumListToFile();
            break;
        case 3:
            executeJukeBoxMenu();
            break;
        default:
            cout << "\nInvalid choice." << endl;
            break;
    }
}
void Jukebox::executePrintMenu()
{
    switch (print.getMenuChoice())
    {
        case 1:
            printAnAlbum();
            break;
        case 2:
            writeAlbumListToFile();
            break;
        case 3:
            executeJukeBoxMenu();
            break;
        default:
            cout << "\nInvalid choice." << endl;
            break;
    }
}

void Jukebox::printAnAlbum()
{
    printAlbumNamesList();
    cout << "\nEnter the number corresponding to the album you wish to print." << endl;
    int myIndex = chooseAnAlbum();
    cout << albumList[myIndex]<< endl;
}


