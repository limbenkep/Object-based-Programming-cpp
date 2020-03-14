//
// Created by limbe on 2020-03-07.
//

#include "Jukebox.h"



Jukebox::Jukebox()
{
    jukeBoxMenu.startUpJukeBoxMenu();
    fileMenu.startUpFileMenu();
    printMenu.startUpPrintMenu();


}

Jukebox::~Jukebox()
= default;

void Jukebox::readAlbumListFromFile()
{
    if(!albumList.empty())
    {
        albumList.clear();
    }
    Album tmpAlbum;
    ifstream inFile (fileName.c_str());
    if(inFile)
    {

        do
        {
            if (inFile.eof())
            {
                EXIT_SUCCESS;
            }
            inFile >> tmpAlbum;
            albumList.push_back(tmpAlbum);
        }while (!inFile.eof());
        inFile.close();
        cout << "\nAlbum list has been read from file. " << endl;
    }
    else
    {
        cout << "File not found"<<endl;
        EXIT_FAILURE;
    }

}

void Jukebox::writeAlbumListToFile()
{
    fstream outFile (fileName.c_str(), ios::out);
    for (auto &idx: albumList)
    {
        outFile<<idx;
    }
    outFile.close();
    cout << "\nAlbum list has been saved to file." << endl;
}

void Jukebox::addAlbumToList()
{
    Album newAlbum;
    string tmpString;
    Song tmpSong;
    int tmpInt = -1;
    cout << "\nEnter the following data on the album you wish to add"<< endl;
    cout<< "\tAlbum title: ";
    getline(cin, tmpString);
    auto it = find_if(albumList.begin(),albumList.end(), [tmpString] (const Album & pAlbum){return pAlbum.getAlbumName() == tmpString;} );
    while (it != albumList.end() || tmpString.empty())
    {
        if(tmpString.empty())
        {
            cout << "No album title was entered. All albums must have an album title."<< endl;
        }
        if(it != albumList.end())
        {
            cout << "\nThere is already an album with title name '" << tmpString << "' in the album list. Choose a unique name."<< endl;
        }
        cout<< "\tAlbum title: ";
        getline(cin, tmpString);
        it = find_if(albumList.begin(),albumList.end(), [tmpString] (const Album & pAlbum){return pAlbum.getAlbumName() == tmpString;} );
    }
    newAlbum.setAlbumName(tmpString);
    cout<< "\nEnter the number of songs in the album";
    tmpInt = getNumber();
    while(tmpInt==-1)
    {
        cout << "\nInvalid entry. The number of songs must be an integer greater than 0. \nEnter the number of songs in the album";
        tmpInt=getNumber();
    }


    for (int i=0; i < tmpInt; i++)
    {
        cout<< "\n\tEnter the details of song number " << i+1<<endl;
        cout<< "\tSong's title :";
        getline(cin, tmpString);
        while(tmpString.empty())
        {
            cout << "\tInvalid entry. You did not enter a song title. \n\tEnter song's title: ";
            getline(cin, tmpString);
        }
        tmpSong.setSongTitle(tmpString);

        cout<< "\n\tSong's artist :";
        getline(cin, tmpString);
        while(tmpString.empty())
        {
            cout << "\n\tInvalid entry. You did not enter an artist name. \n\tEnter song's artist: ";
            getline(cin, tmpString);
        }
        tmpSong.setArtist(tmpString);

        cout<< "\n\tSong's length in seconds";
        int tmpSecs = getNumber();
        while(tmpSecs==-1)
        {
            cout << "\n\tInvalid entry. The song's length must be an integer greater than 0."<< "\n\tSong's length in seconds";
            tmpSecs=getNumber();
        }
        tmpSong.setSongLength(tmpSong.getlengthFromInt(tmpSecs));

        newAlbum.addSongToList(tmpSong);
    }

    albumList.push_back(newAlbum);
}

int Jukebox::getNumber()
{
    cout << ": ";
    int choice = 0;
    cin>>choice;
    if (!cin||choice<1)// this control ensures that number of albums, number of songs, song length for which is function is used to get can not be 0
    {
        cin.clear();
        cin.ignore(1000, '\n');
        return -1;
    }
    cin.ignore(1000, '\n');
    return choice;
}

int Jukebox::chooseAnAlbum()
{
    cout << "\nYour choice";
    int choice = getNumber();
    int listSize= static_cast<int > (albumList.size());
    while (choice ==-1 || choice > listSize)
    {
        cout << "\nInvalid choice. Your album choice must be an integer between 1 and " << listSize;
        choice = getNumber();
    }
    return choice-1;// gets index by subtracting 1 from choice since choice is number from 1 and index from 0
}

void Jukebox::deleteAlbumFromList()
{
    printAlbumNamesList();
    cout << "Enter the number of the album you wish to delete." << endl;
    int myIndex = chooseAnAlbum();
    albumList.erase(albumList.begin()+ myIndex);
}

void Jukebox::printAlbumNamesList()
{
    int number = 1;
    for (auto &idx: albumList)
    {
        cout << number<<".  " <<idx.getAlbumName()<<endl;
        number++;
    }
}


void Jukebox::run()
{
    if (!albumList.empty())
    {
        jukeBoxMenu.enabledJukeBoxMenu();
        fileMenu.enabledFileMenu();
        printMenu.enabledPrintMenu();

    }
    while(jukeboxRunning)
    {
        const int val = jukeBoxMenu.getMenuChoice();
        cout<< "\nVal is " << val << endl;
        //switch (jukeBoxMenu.getMenuChoice())
        switch(val)
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
                jukeboxRunning = false;
                break;
            default:
                cout << "\nInvalid choice." << endl;
                break;

        }
    }//while(again);
}


void Jukebox::executeFileMenu()
{
    bool again = true;
    while (again)
    {
        switch (fileMenu.getMenuChoice())
        {
            case 1:
                readAlbumListFromFile();
                break;
            case 2:
                writeAlbumListToFile();
                break;
            case 3:
                run();
                again = false;
                break;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }

    }

}
void Jukebox::executePrintMenu()
{
    bool again = true;
    while (again)
    {
        switch (printMenu.getMenuChoice())
        {
            case 1:
                printAnAlbum();
                break;
            case 2:
                printAllSortByAlbumName();
                break;
            case 3:
                printAllSortByAlbumTime();
                break;
            case 4:
                printSortedAlbumNames();
                break;
            case 5:
                printTimeSortedNameAndTime();
                break;
            case 6:
                run();
                again = false;
                break;
            default:
                cout << "\nInvalid choice." << endl;
                break;
        }
    }

}


void Jukebox::printAlbum(const Album &pAlbum)
{
    vector<Song> songList = pAlbum.getSongList();
    cout << "\nAlbum Name: " << pAlbum.getAlbumName() << "\nNumber of songs in album: " << pAlbum.sizeOfSongList()
    <<"\nAlbum total play time:" << pAlbum.albumLength()<<"s"
    << "\nAlbum song List in order count, song title, artist, length of song(hour:min:sec:"<<endl;
    int number = 1;
    for(const auto& idx : songList)
    {
        MyTime tmpTime = idx.getSongLength();
        if(tmpTime.getHours()>0)
        {
            cout << number <<"\t" << idx.getSongTitle() << "\t" << idx.getArtist() << "\t" << tmpTime.getHours()
            << ":"<< tmpTime.getMinutes() << ":" << tmpTime.getSeconds() << endl;
        }
        else
        {
            cout << number <<"\t" << idx.getSongTitle() << "\t" << idx.getArtist() << "\t"<< tmpTime.getMinutes()
            << ":" << tmpTime.getSeconds() << endl;
        }
        number++;
    }

}

void Jukebox::printAnAlbum()
{
    printAlbumNamesList();
    cout << "\nEnter the number of the album on the list you wish to print." << endl;
    int myIndex = chooseAnAlbum();
    printAlbum(albumList[myIndex]);
}


bool Jukebox::compareNamesOfAlbum(const Album &album1, const Album &album2)
{
    return album1.getAlbumName() < album2.getAlbumName();
}

bool Jukebox::compareTotalTimeOfAlbum(const Album &album1, const Album &album2)
{
    return album1.albumLength() > album2.albumLength();
}

void Jukebox::printAlbumList()
{
    for(const auto& idx : albumList)
    {
        printAlbum(idx);
    }
}

void Jukebox::printAllSortByAlbumName()
{
    sort(albumList.begin(), albumList.end(), compareNamesOfAlbum);
    cout << "\n\nThis is a list of all albums sorted by album name in alphabetical order." << endl;
    printAlbumList();
}

void Jukebox::printAllSortByAlbumTime()
{
    sort(albumList.begin(), albumList.end(), compareTotalTimeOfAlbum);
    cout << "\n\nThis is a list of all albums sorted by album total play time:" << endl;
    printAlbumList();
}

void Jukebox::printSortedAlbumNames()
{
    sort(albumList.begin(), albumList.end(), compareNamesOfAlbum);
    cout << "\n\nThis is a list of the names of all albums in the list in alphabetical order:" << endl;
    printAlbumNamesList();
}

void Jukebox::printTimeSortedNameAndTime()
{
    sort(albumList.begin(), albumList.end(), compareTotalTimeOfAlbum);
    int number = 1;
    cout << "\n\nList of all album names and lengths in the list sorted by album total time starting with the longest:" << endl;
    for(const auto& idx : albumList)
    {
        MyTime totalTime;
        totalTime.setTime(idx.albumLength());
        if (totalTime.getHours() > 0)
        {
            cout << number <<"\t" << idx.getAlbumName() << "\t"<< totalTime.getHours() << ":" << totalTime.getMinutes()<<":"
                 << totalTime.getSeconds() << endl;
        }
        else
        {
            cout << number <<"\t" << idx.getAlbumName() << "\t"<< totalTime.getMinutes()<<":"
            << totalTime.getSeconds() << endl;
        }
        number++;
    }
}

Jukebox::Jukebox(const vector<Album> &albumList, const Menu &jukeBoxMenu, const Menu &fileMenu, const Menu &printMenu,
                 const string &fileName) : albumList(albumList), jukeBoxMenu(jukeBoxMenu), fileMenu(fileMenu),
                                           printMenu(printMenu), fileName(fileName)
{
}









