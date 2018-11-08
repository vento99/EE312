// FILE: deck.h

/* Student information for project:
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

// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck will randomize whatever cards are in the deck
// Do not shuffle if you have less than 2 cards
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//

#ifndef _DECK_H
#define _DECK_H

#include "card.h"


class Deck
{
    static const int SIZE = 52;

public:

    //Default constructor
    //Populates myCards array with a sorted deck of cards
    Deck();

    //Function: shuffle
    //Inputs: None
    //Outputs: None
    //Shuffles the cards in the current deck
    void shuffle();

    //Function: dealCard
    //Inputs: None
    //Outputs: Card from the myCards array
    //Precondition: There is at least one card left in deck
    Card dealCard();

    //Function: size
    //Inputs: None
    //Outputs: Integer that says the # of cards left in the deck
    int  size() const;

private:

    Card myCards[SIZE];
    int myIndex;  // current card to deal
};

#endif