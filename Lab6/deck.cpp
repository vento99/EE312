/* deck.cpp

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

// This file is the cpp file that implements methods relating to the deck class
// For documentation of methods, see the deck.h file
// Date: November 9, 2018


#include "deck.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

Deck::Deck(){
    myIndex = -1;
    int currentIndex = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            Card *c = new Card(j, (Card::Suit)i);
            myCards[currentIndex] = *c;
            currentIndex++;
            delete(c);
        }
    }
}

void Deck::shuffle(){
    if(size() < 2){
        return;
    }
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    for(int i = 0; i < 5*size(); i++){
        int index1 = rand()%size();
        int index2 = rand()%size();
        Card temp = myCards[index1];
        myCards[index1] = myCards[index2];
        myCards[index2] = temp;
    }
}

Card Deck::dealCard(){
    myIndex++;
    return myCards[myIndex];
}

int Deck::size() const{
    return (SIZE - myIndex - 1);
}
