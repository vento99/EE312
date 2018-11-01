/* UtPod.cpp
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

// This file is the driver that implements methods relating to the UtPod class
// For documentation of methods, see the UtPod.h file
// Date: November 1, 2018

#include "UtPod.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

UtPod::UtPod(){
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size){
    if(size < 0 || size > MAX_MEMORY){
        memSize = MAX_MEMORY;
    }
    else{
        memSize = size;
    }
    songs = NULL;
}

int UtPod::addSong(Song const &s) {
    if(s.getSize() > getRemainingMemory()){
        return NO_MEMORY;
    }
    SongNode *newSong = new SongNode;
    newSong->s = s;
    newSong->next = NULL;
    if(songs == NULL){
        songs = newSong;
    } else{
        SongNode *temp = songs;
        while(temp -> next){
            temp = temp -> next;
        }
        temp -> next = newSong;
    }
    return SUCCESS;
}

int UtPod::removeSong(Song const &s){
    SongNode *current = songs;
    SongNode *previous = NULL;
    while(current){
        if(current->s == s) {
            if (previous != NULL) {
                previous->next = current->next;
            }else{
                songs = current->next;
            }
            delete(current);
            return SUCCESS;
        }
        previous = current;
        current = current->next;
    }
    return NOT_FOUND;
}

void UtPod::shuffle(){
    int numSongs = getNumSongs();
    if (numSongs <= 1){
        return;
    }
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    for(int i = 0; i < 5*numSongs; i++){
        int index1 = rand() % numSongs;
        int index2 = rand() % numSongs;
        SongNode *song1 = songs;
        SongNode *song2 = songs;

        while(index1 != 0){
            song1 = song1->next;
            index1--;
        }
        while(index2 != 0){
            song2 = song2->next;
            index2--;
        }

        Song temp = song1->s;
        song1->s = song2->s;
        song2->s = temp;
    }
}

void UtPod::showSongList(){
    SongNode *temp = songs;
    if(temp == NULL){
        cout << "No Songs in the UTPod :(" << endl;
    }else {
        while (temp != NULL) {
            cout << "- Artist: " << temp->s.getArtist() << ", Song: "
                 << temp->s.getTitle() << ", Size: " << temp->s.getSize()
                 << " MB" << endl;
            temp = temp->next;
        }
    }
    cout << endl;
}

void UtPod::sortSongList(){                     //implemented a selection sort
    SongNode *currentIterator = songs;
    SongNode *innerIterator = NULL;
    SongNode *smallest = NULL;
    while(currentIterator != NULL){
        smallest = currentIterator;
        innerIterator = currentIterator->next;
        while(innerIterator != NULL){           //will find smallest song from the remaining ones
            if(innerIterator->s < smallest->s){
                smallest = innerIterator;
            }
            innerIterator = innerIterator->next;
        }
        if(smallest != currentIterator) {       //if the smallest is not the current, swap
            Song temp = smallest->s;
            smallest->s = currentIterator->s;
            currentIterator->s = temp;
        }
        currentIterator = currentIterator->next;
    }
}

int UtPod::getRemainingMemory(){
    return getTotalMemory() - getMemoryUsed();
};

void UtPod::clearMemory(){
    SongNode *current = songs;
    SongNode *next = NULL;
    while(current!= NULL){
        next = current->next;
        delete(current);
        current = next;
    }
    songs = NULL;
}

UtPod::~UtPod(){
    clearMemory();
}

int UtPod::getNumSongs(){
    int numSongs = 0;
    SongNode *temp = songs;
    while(temp!= NULL){
        numSongs += 1;
        temp = temp->next;
    }
    return numSongs;
}

int UtPod::getMemoryUsed(){
    int memory = 0;
    SongNode *temp = songs;
    while(temp!= NULL){
        memory += temp->s.getSize();
        temp = temp->next;
    }
    return memory;
}