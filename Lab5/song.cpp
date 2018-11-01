/* song.cpp
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

// This file is the cpp file that implements methods relating to the song class
// For documentation of methods, see the song.h file
// Date: November 1, 2018

#include "song.h"

using namespace std;

Song::Song(){
    artist = "";
    title = "";
    size = 0;
};

Song::Song(string songArtist, string songTitle, int songSize){
    artist = songArtist;
    title = songTitle;
    size = songSize;
};

string Song::getTitle() const{
    return title;
}

void Song::setTitle(string songTitle){
    title = songTitle;
}

string Song::getArtist() const{
    return artist;
}

void Song::setArtist(string songArtist){
    artist = songArtist;
}

int Song::getSize() const{
    return size;
}

void Song::setSize(int songSize){
    size = songSize;
}

bool Song::operator >(Song const &rhs){
    if (artist != rhs.artist){
        return artist > rhs.artist;
    }
    if (title != rhs.title){
        return title > rhs.title;
    }
    if (size != rhs.size){
        return size > rhs.size;
    }
    return false;
}

bool Song::operator ==(Song const &rhs){
    return (artist == rhs.artist && title == rhs.title && size == rhs.size);
}

bool Song::operator <(Song const &rhs){
    if (artist != rhs.artist){
        return artist < rhs.artist;
    }
    if (title != rhs.title){
        return title < rhs.title;
    }
    if (size != rhs.size){
        return size < rhs.size;
    }
    return false;
}
