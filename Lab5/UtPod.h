/* UtPod.h
Anthony Vento

 Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Anthony Vento, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Anthony Vento
 * email address: anthony.vento@utexas.edu
 * UTEID: amv2987
 * Section 5 digit ID: 16235
 *
 */

// This file is the header that defines methods relating for UtPod class
// Date: November 1, 2018

#ifndef UTPOD_H
#define UTPOD_H
#include "song.h"

//UtPod class declaration
class UtPod
{
    private:
        static const int MAX_MEMORY = 512;
        static const int SUCCESS = 0;
        static const int NO_MEMORY = -1;
        static const int NOT_FOUND = -2;

        struct SongNode
        {
            Song s;
            SongNode *next;
        };

        SongNode *songs;  //the head pointer

        int memSize;

        /* FUNCTION - int getNumSongs
         *  returns the total amount of songs in the UT POD

           input parms - none

           output parms - returns integer for how many songs there are
        */

        int getNumSongs();

        /* FUNCTION - int getMemoryUsed
         *  returns the amount of memory used

           input parms - none

           output parms - returns integer for how much memory is used
        */

        int getMemoryUsed();

    public:
        //Default constructor
        //set the memory size to MAX_MEMORY
        UtPod();

        //Constructor with size parameter
        //The user of the class will pass in a size.
        //If the size is greater than MAX_MEMORY or less than or equal to 0,
        //set the size to MAX_MEMORY.
        UtPod(int size);

        /* FUNCTION - int addSong
         * attempts to add a new song to the UtPod
             o returns a 0 if successful
             o returns -1 if not enough memory to add the song

         precondition: s is a valid Song

         input parms - pointer to a Song object s

         output parms - Int: 0 if the song was successfully added, or -1 if not enough memory to add the song;
        */

        int addSong(Song const &s);


        /* FUNCTION - int removeSong
         * attempts to remove a song from the UtPod
         * removes the first instance of a song that is in the the UtPod multiple times
             o returns 0 if successful
             o returns -2 if nothing is removed


           input parms - pointer to a Song object s

           output parms - return int: 0 if the song was successfully removed or return -2 if song was not removed
        */

        int removeSong(Song const &s);


        /* FUNCTION - void shuffle
         *  shuffles the songs into random order
            o will do nothing if there are less than two songs in the current list

           input parms - none

           output parms - none
        */

        void shuffle();


        /* FUNCTION - void showSongList
         * prints the current list of songs in order from first to last to standard output
         * format - Title, Artist, size in MB (one song per line)

           input parms - none

           output parms - none
        */

        void showSongList();


        /* FUNCTION - void sortSongList
         *  sorts the songs in ascending order
            o will do nothing if there are less than two songs in the current list

           input parms - none

           output parms - none
        */

        void sortSongList();


        /* FUNCTION - void clearMemory
         * clears all the songs from memory

           input parms - none

           output parms - none
        */
        void clearMemory();


        /* FUNCTION - int getTotalMemory
         *  returns the total amount of memory in the UtPod
            o will do nothing if there are less than two songs in the current list

           input parms - none

           output parms - returns int: the memSize of the UTPod
        */

        int getTotalMemory() {
            return memSize;
        }


        /* FUNCTION - int getRemainingMemory
         *  returns the amount of memory available for adding new songs

           input parms - none

           output parms - returns int: how much memory is avaiable for newSongs
        */

        int getRemainingMemory();


        /* FUNCTION - ~UtPod
         *  destructor that frees all dynamically allocated memory

           input parms - none

           output parms - none
        */

        ~UtPod();

};



#endif
