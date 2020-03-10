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
    Album newAlbum;
    string tmpString;
    Song tmpSong;
    int tmpInt = -1;
    cout << "\nEnter the following data on the album you wish to add"<< endl;
    cout<< "Album title: ";
    getline(cin, tmpString);
    auto it = find_if(albumList.begin(),albumList.end(), [tmpString] (const Album & pAlbum){return pAlbum.getAlbumName() == tmpString;} );
    if (it != albumList.end())
    {
        cout << "\nThere is already an album with title name '" << tmpString << "' in the album list. Choose a unique name.";
        addAlbumToList();
    }
    newAlbum.setAlbumName(tmpString);
    cout<< "\nEnter the number of songs in the album";
    tmpInt = getNumber();
    for (int i=0; i < tmpInt; i++)
    {
        cout<< "\nenter the details of song number" << i+1<<endl;
        cout<< "Song's title :";
        getline(cin, tmpString);
        tmpSong.setSongTitle(tmpString);

        cout<< "Song's artist :";
        getline(cin, tmpString);
        tmpSong.setArtist(tmpString);

        cout<< "Song's length in seconds :";
        tmpInt = getNumber();
        tmpSong.setSongLength(tmpSong.getlengthFromInt(tmpInt));

        newAlbum.addSongToList(tmpSong);
    }

    albumList.push_back(newAlbum);
}

int Jukebox::getNumber()
{
    cout << ": ";
    int choice = 0;
    cin>>choice;
    if (!cin||choice<1)// This control ensures that no empty albums or song can be store in the list
    {

        do
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid entry. Enter a positive integer greater than 0! Your choice: ";
            cin>>choice;
        }while(!cin||choice<1);
    }
    cin.ignore(1000, '\n');
    return choice;
}

int Jukebox::chooseAnAlbum()
{
    cout << "\nYour choice";
    int choice = getNumber();
    int listSize= static_cast<int > (albumList.size());
    if (choice < 1 || choice > listSize)
    {
        cout << "\nInvalid choice. Your album choice must lie between 1 and " << listSize;
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




