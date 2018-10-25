//
// Created by avento on 10/24/2018.
//

#include "UtPod.h"
#include <iostream>
#include <fstream>
#include <string>

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
};

int UtPod::addSong(Song const &s) {
    //size < 1 ??
    if(s.getArtist() == "" || s.getTitle() == ""){
        return NOT_FOUND;
    }
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
            return SUCCESS;
        }
        previous = current;
        current = current->next;
    }
    return NOT_FOUND;
}

void UtPod::shuffle(){

}
void UtPod::showSongList(){
    SongNode *temp = songs;
    if(temp == NULL){
        cout << "No Songs in the UTPod :(" << endl;
    }else {
        while (temp != NULL) {
            cout << "Artist: " << temp->s.getArtist() << ", Song: "
                 << temp->s.getTitle() << ", Size: " << temp->s.getSize() << endl;
            temp = temp->next;
        }
    }
}
void UtPod::sortSongList(){
    int numSongs = getNumSongs();

}


int UtPod::getRemainingMemory(){
    return memSize - getMemoryUsed();
};

UtPod::~UtPod(){
    SongNode *current = songs;
    SongNode *next = NULL;
    while(current!= NULL){
        next = current->next;
        delete(current);
        current = next;
    }
}

int UtPod::getNumSongs(){
    int numSongs = 0;
    SongNode *temp = songs;
    while(temp!= NULL){
        numSongs += 1;
        temp = temp->next;
    }
    return numSongs;
};

int UtPod::getMemoryUsed(){
    int memory = 0;
    SongNode *temp = songs;
    while(temp!= NULL){
        memory += temp->s.getSize();
        temp = temp->next;
    }
    return memory;
}