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

        }
    }
}

void Deck::shuffle(){
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);
    for(int i = 0; i < 5*SIZE; i++){
        int index1 = rand()%SIZE;
        int index2 = rand()%SIZE;
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
