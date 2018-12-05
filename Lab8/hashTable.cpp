#include "hashTable.h"
#include <cmath>
#include <iostream>

hashTable::hashTable() {
    for(int i = 0; i < SIZE; i++){
        table[i] = NULL;
    }
}

int hashTable::hashingFunction(string value) {
    unsigned int result = 0;
    int length = value.length();
    //may need to change
    for(int i = length-1; i >= 0; i--){  //used from Priebe and class
        result += (unsigned int)value[length - i - 1] * (unsigned int)pow(37, i);
    }
    result = (result+SIZE) % SIZE;
    return result;
}

void hashTable::put(string word, int fileIndex){
    int hashIndex = hashingFunction(word);
    HashNode *current = table[hashIndex];
    HashNode *previous = NULL;
    HashNode *newNode = new HashNode;
    newNode->fileIndex = fileIndex;
    newNode->next = NULL;
    if(!current){
        table[hashIndex] = newNode;
    }else {
        while(current) {
            if (current->fileIndex == fileIndex) {
                return;
            }
            previous = current;
            current = current->next;
        }
        previous->next = newNode;
    }
}

void hashTable::determineCollisions(int *matrix[]){
    for(int i = 0; i < SIZE; i++){
        HashNode *current = table[i];
        HashNode *innterIterator = NULL;
        if(current != NULL && current->next != NULL){
           while(current){
               int currentFileNum = current->fileIndex;
               innterIterator = current->next;
               while(innterIterator){
                   int innerFileNum = innterIterator->fileIndex;
                   int bigger = currentFileNum > innerFileNum ? currentFileNum : innerFileNum;
                   int smaller = currentFileNum < innerFileNum ? currentFileNum : innerFileNum;
                   matrix[smaller][bigger] += 1;
                   innterIterator = innterIterator->next;
               }
               current = current->next;
           }
        }
    }
}

hashTable::~hashTable(){
    for(int i = 0; i < SIZE; i++){
        if(table[i] != NULL){
            HashNode *current = table[i];
            HashNode *next = NULL;
            while(current != NULL){
                next = current->next;
                delete(current);
                current = next;
            }
            table[i] = NULL;
        }
    }
}
