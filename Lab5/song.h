/* song.h
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

// This file is the header that defines methods relating for song class
// Date: November 1, 2018

#ifndef LAB5_SONG_H
#define LAB5_SONG_H

#include <string>

using namespace std;

class Song
{
    private:
        string title;
        string artist;
        int size;

    public:

        //Default constructor
        //initialize artist and title to empty string and set size to 0
        Song();

        //Constructor with artist, title, and size parameters
        //The user of the class will pass in an artist, title, and size.
        Song(string songArtist, string songTitle, int songSize);

        /* FUNCTION - string getTitle
         *  returns the title of the song

           input parms - none

           output parms - returns string that contains the title of the song
        */

        string getTitle() const;

        /* FUNCTION - void setTitle
         *  sets the title of the song

           input parms - string for the title you want to set the song as

           output parms - none
        */

        void setTitle(string songTitle);

        /* FUNCTION - string getArtist
         *  returns the artist of the song

           input parms - none

           output parms - returns a string that contains the artist of the song
        */

        string getArtist() const;

        /* FUNCTION - void setArtist
         *  sets the artist of the song

           input parms - string for the artist you want to set the song as

           output parms - none
        */

        void setArtist(string songArtist);


        /* FUNCTION - int getSize
         *  returns the size of the song

           input parms - none

           output parms - returns integer for how the size of the song
        */

        int getSize() const;

        /* FUNCTION - void setSize
         *  sets the size of the song

           input parms - integer for the size you want to update the song with

           output parms - none
        */

        void setSize(int songSize);

        //overload the boolean operator for > when comparing two songs
        //first checks artist, then title, then size
        bool operator >(Song const &rhs);

        //overload the boolean operator for == when comparing two songs
        //checks if artist and title and size are equal
        bool operator ==(Song const &rhs);

        //overload the boolean operator for < when comparing two songs
        //first checks artist, then title, then size
        bool operator <(Song const &rhs);

};



#endif //LAB5_SONG_H


