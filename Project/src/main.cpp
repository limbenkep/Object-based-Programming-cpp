/*Author: Lima Honorine
 * Course: Objektbaserad Programmering i C++
 * Course Instructor: Awais Ahmad

 * Description:
 * This project is done as a requirement for C- grade.
 * This program to handle information about songs in an album and many albums are found in the album list.
 * This program allows the user to read an albumList from a file specified in the program, after which the user can add
 * an album, delete an album, go to print submenu which provide different options for print album on the screen,
 * and go to File submenu which provide options to save album list to the same file it read from
 * This project makes use classes Song, Time, Album, Jukebox, Menu and MenuItem
*/
#include "Prototypes.h"
#include "memstat.hpp"
#include <Jukebox.h>

int main()
{
    Jukebox jkb;
    jkb.run();
    return 0;
}
