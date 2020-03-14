# Final Project

## Environment & Tools
windows Operating system, CLion 2019.3.3 IDE, Microsoft C++ (MSVC) compiler, CMake version: 3.15.6, Git version: 2.25.0.windows.1
## Purpose
The aim of this project is to show that I can  create and use classes, use STL containers and their algorithms,create 
and use a queue with dynamic allocated arrays, save to and read from file, create good program structure and present a 
written and oral presentation for a bigger project.
## Procedures
To achieve these goals, 1 have written a working program according to the specifications on the project description 
document which i submit together with this report. 
My program was built to meet the requirements for the C grade. 
This program is a program to handle information about songs in an album and many albums are found in the album list. At 
the start of the program, the user is allowed to read an albumList from a file specified in the program or exit the program. 
Once the file has been read, the other menu options are enabled and the user can add, an album, delete an album, go to 
print submenu which provide different options for print album on the screen,
and go to File submenu which provide options to save album list to the same file it read from.
 This project makes use classes; Song class that contains and handles information about a song (name, artist and length), 
 Time class that handles time in form of hours, minutes, seconds, Album class that handles album's name and a number of songs
 Jukebox class that contains an album list containing a number of albums and is the different menus and functions to
 execute the different menu choices.It serves as a user interface for this program, Menu class that contains the main menu and the submenus.
 MenuItem class which is a helper class to Menu class and contains the text options for the menuItem and if there are enabled or not.
## Discussion
In this project, I show skills in creating and using classes by creating the classes Song, Time, Album, Jukebox, 
Menu, MenuItem. I show correct use of constructors and destructor, getters and setters, initialisations of data member,
encapsulation and the use of member functions for actions that are requires out of the class. I also show 
skills in using a class object as a data member of another class as in the case of Song class with Time object as a 
data member,Album with Song as a data member and JukeBox class with Album as a data member. Given the size of the project I 
made an effort to use explicit naming to be able to keep track of the different functions and what they do.
In this project I showed skills of use of STL containers and their algorithms by using Vectors  as data member in 
JukeBox, Album and Menu classes. I also made use of some of  vector's member functions like push_back() to load song list, album list and menu list with an object, 
size() to get number of items in song list, album list and menu list, erase() in my function to delete album from list and begin() and end().
I also made use of algorithms like find_if to find an album in the list using the album name, 
clear() to empty song list and album list before reading fromm file, and sort to for my different sort functions for print menu.
I have also written functions that save to and read from a file in JukeBox class making use of << and >> overload constructors from Song, Time and Album classes.
However, my program does not read if the txt file ends with a new line. So I had to manually delete newline reading the file. All other methods to sove this problem did not work.
My program code is writtten in a way that it is eligible with the use of empty lines to show different sections of cods and comments were necessary.
I have not use queue in this project as it was a requirement for grades above C.
I have achieved the goals of this projects with the exeption of the oral presentation which is planned after submisssion of this report.  