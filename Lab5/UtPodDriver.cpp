/* UtPodDriver.cpp
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

// This file is the driver that contains test cases for the UtPod
// Date: November 1, 2018

#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]) {
    string value;
    int output;
    UtPod t(256);

    //tests for getting and setting all attributes of song
    cout << "*****Test1: Declare a song object and update attributes*****" << endl;
    Song s1("Beatles", "Hey Jude1", 4);
    s1.setSize(5);
    value = s1.getSize();
    s1.setArtist("Billy Joel");
    s1.getArtist();
    s1.setTitle("Hey Bob");
    s1.getTitle();
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;
    t.showSongList();

    //test for adding and removing a song
    cout << "*****Test2: Add and then remove a song*****" << endl;
    Song s2("Beatles", "Submarine", 4);
    result = t.addSong(s2);
    cout << "Result after add = " << result << endl;
    t.showSongList();
    result = t.removeSong(s2);
    cout << "Result after remove = " << result << endl;
    t.showSongList();

    //test for removing a song that doesnt exist
    cout << "*****Test3: Removing a song that does not exist*****" << endl;
    result = t.removeSong(s2);
    cout << "result = " << result << endl << endl;

    //test for adding a song that is too large
    cout << "*****Test4: Adding a song that is too large*****" << endl;
    Song large("TSwift", "Boo", 300);
    result = t.addSong(large);
    cout << "result = " << result << endl << endl;

    //test for adding a bunch of songs
    cout << "*****Test5: Adding a few songs*****" << endl;
    Song s3("TSwift", "Boo", 4);
    t.addSong(s3);
    Song s4("Bieber", "Baby", 9);
    t.addSong(s4);
    Song s5("Bieber", "Baby", 16);
    t.addSong(s5);
    Song s6("Pharell", "Happy", 4);
    t.addSong(s6);
    Song s7("Pharell", "Hey", 9);
    t.addSong(s7);
    t.showSongList();

    //test for sorting the songs
    cout << "*****Test6: Sorting the songs*****" << endl;
    t.sortSongList();
    t.showSongList();

    //test for shuffling the song list
    cout << "*****Test7: Shuffling the songs*****" << endl;
    t.shuffle();
    t.showSongList();

    //test for shuffling the song list again
    cout << "*****Test8: Shuffling the songs again*****" << endl;
    t.shuffle();
    t.showSongList();

    //test for clearing memory;
    cout << "*****Test9: Clearing the memory*****" << endl;
    t.clearMemory();
    t.showSongList();

    //test for creating another UT Pod and attempt to remove a song that does not exit
    cout << "*****Test10: Creating a new UT pod and attempting to remove a song*****" << endl;
    UtPod pod(-100);
    result = pod.removeSong(s7);
    cout << "result = " << result << endl << endl;

    //add a few songs then test the get remaining memory function
    cout << "*****Test11: Adding songs to new UTPod*****" << endl;
    Song song1("Anthony", "Testing", 100);
    pod.addSong(song1);
    Song song2("Vento", "EE 312 Jam", 101);
    pod.addSong(song2);
    Song song3("Shawn Mendes", "Stitches", 1);
    pod.addSong(song3);
    Song song4("Ed", "Photograph", 2);
    pod.addSong(song4);
    Song song5("Ed", "Photograph2", 2);
    pod.addSong(song5);
    Song song6("Adele", "Rolling in the Deep", 21);
    pod.addSong(song6);
    Song song7("NSYNC", "Bye Bye Bye", 40);
    pod.addSong(song7);
    pod.showSongList();

    //test for get remaining memory
    cout << "*****Test12: Get remaining memory*****" << endl;
    cout << "memory remaining = " << pod.getRemainingMemory() << endl << endl;

    //test for removing first song
    cout << "*****Test13: Removing first song from UtPod*****" << endl;
    result = pod.removeSong(song1);
    pod.showSongList();

    //test for removing last song
    cout << "*****Test14: Removing last song from UtPod*****" << endl;
    result = pod.removeSong(song7);
    pod.showSongList();

    //test for adding duplicate song
    cout << "*****Test15: Adding Duplicate Song*****" << endl;
    pod.addSong(song5);
    pod.showSongList();

    //test for removing duplicate song (will remove first of the two instances)
    cout << "*****Test15: Removing Duplicate Song*****" << endl;
    pod.removeSong(song5);
    pod.showSongList();

}
