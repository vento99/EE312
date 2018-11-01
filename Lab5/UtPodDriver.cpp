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
    cout << "*****Test1: Declare a song object, update attributes, and add to UT Pod*****" << endl;
    Song s1("Beatles", "Hey Jude1", 4);
    s1.setSize(5);
    value = s1.getSize();
    s1.setArtist("Billy Joel");
    s1.getArtist();
    s1.setTitle("Hey Bob");
    s1.getTitle();
    int result = t.addSong(s1);
    cout << "Result should be 0 and your result = " << result << endl;
    cout << "Showing UT Pod Song List..." << endl;
    t.showSongList();

    //test for adding and removing a song
    cout << "*****Test2: Add and then remove a song*****" << endl;
    Song s2("Beatles", "Submarine", 4);
    result = t.addSong(s2);
    cout << "Result after add should be 0 and your result = " << result << endl;
    cout << "Showing UT Pod Song List..." << endl;
    t.showSongList();
    result = t.removeSong(s2);
    cout << "Result after remove should be 0 and your result = " << result << endl;
    cout << "Showing UT Pod Song List..." << endl;
    t.showSongList();

    //test for removing a song that doesnt exist
    cout << "*****Test3: Removing a song that does not exist*****" << endl;
    result = t.removeSong(s2);
    cout << "Result should be -2 and your result = " << result << endl << endl;

    //test for adding a song that is too large
    cout << "*****Test4: Adding a song that is too large*****" << endl;
    Song large("TSwift", "Boo", 300);
    result = t.addSong(large);
    cout << "Result should be -1 and your result = " << result << endl << endl;

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
    cout << "Showing UT Pod Song List..." << endl;
    t.showSongList();

    //test for sorting the songs
    cout << "*****Test6: Sorting the songs*****" << endl;
    t.sortSongList();
    cout << "Showing UT Pod Song List..." << endl;
    t.showSongList();

    //test for shuffling the song list
    cout << "*****Test7: Shuffling the songs*****" << endl;
    t.shuffle();
    cout << "Showing UT Pod Song List..." << endl;
    t.showSongList();

    //test for shuffling the song list again
    cout << "*****Test8: Shuffling the songs again*****" << endl;
    t.shuffle();
    cout << "Showing UT Pod Song List..." << endl;
    t.showSongList();

    //test for clearing memory;
    cout << "*****Test9: Clearing the memory*****" << endl;
    t.clearMemory();
    cout << "Memory remaining should be 256 MB and your memory remaining = " << t.getRemainingMemory() << " MB" << endl;
    cout << "Showing UT Pod Song List..." << endl;
    t.showSongList();

    //test for creating another UT Pod and attempt to remove a song that does not exit
    cout << "*****Test10: Creating a new UT pod and attempting to remove a song*****" << endl;
    UtPod pod(-100);
    result = pod.removeSong(s7);
    cout << "Showing UT Pod Song List..." << endl;
    cout << "result should be -2 and your result = " << result << endl << endl;

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
    cout << "Showing UT Pod Song List..." << endl;
    pod.showSongList();

    //test for get remaining memory
    cout << "*****Test12: Get remaining memory*****" << endl;
    cout << "Memory remaining should be 245 MB and your memory remaining = " << pod.getRemainingMemory() << " MB" << endl << endl;

    //test for removing first song
    cout << "*****Test13: Removing first song from UtPod*****" << endl;
    result = pod.removeSong(song1);
    cout << "Showing UT Pod Song List..." << endl;
    pod.showSongList();

    //test for removing last song
    cout << "*****Test14: Removing last song from UtPod*****" << endl;
    result = pod.removeSong(song7);
    cout << "Showing UT Pod Song List..." << endl;
    pod.showSongList();

    //test for adding duplicate song
    cout << "*****Test15: Adding Duplicate Song*****" << endl;
    pod.addSong(song5);
    cout << "Showing UT Pod Song List..." << endl;
    pod.showSongList();

    //test for sorting again
    cout << "*****Test16: Sorting songs with a duplicate*****" << endl;
    pod.sortSongList();
    cout << "Showing UT Pod Song List..." << endl;
    pod.showSongList();


    //test for removing duplicate song (will remove first of the two instances)
    cout << "*****Test17: Removing Duplicate Song*****" << endl;
    pod.removeSong(song5);
    cout << "Showing UT Pod Song List..." << endl;
    pod.showSongList();

    //test for calling default song constructor then updating
    cout << "*****Test18: Default song constructor, use set attributes, add to UT Pod*****" << endl;
    Song song8;
    song8.setTitle("Amazing Grace");
    song8.setArtist("Bob Smith");
    song8.setSize(5);
    pod.addSong(song8);
    cout << "Showing UT Pod Song List..." << endl;
    pod.showSongList();

    //test for ==, >, and < for song class
    cout << "*****Test19: Using ==, >, and < for the song class*****" << endl;
    Song song9("Beatles", "Equality", 5);
    Song song10("Beatles", "Equality", 5);
    if(song9 == song10){
        value = "True";
    }else{
        value = "False";
    }
    cout << "Comparing 2 equal songs with ==" << endl;
    cout << "Result should be True and your result = " << value << endl << endl;

    if(song9 > song10){
        value = "True";
    }else{
        value = "False";
    }
    cout << "Comparing 2 equal songs with >" << endl;
    cout << "Result should be False and your result = " << value << endl << endl;

    if(song9 < song10){
        value = "True";
    }else{
        value = "False";
    }
    cout << "Comparing 2 equal songs with <" << endl;
    cout << "Result should be False and your result = " << value << endl << endl;

    Song song11("Beatles", "Equality", 6);

    if(song10 < song11){
        value = "True";
    }else{
        value = "False";
    }
    cout << "Comparing 2 songs with < where the songs have same title/artist but first song has smaller size" << endl;
    cout << "Result should be True and your result = " << value << endl << endl;

    Song song12("Beatles", "Yellow", 6);

    if(song11 > song12){
        value = "True";
    }else{
        value = "False";
    }
    cout << "Comparing 2 songs with > where the songs have same artist/size but first song comes first in alphabet" << endl;
    cout << "Result should be False and your result = " << value << endl;

}
