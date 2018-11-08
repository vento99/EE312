//File Name: card.h

/*
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

//Written by Owen Astrachan and Roger Priebe
// This class represents a playing card, i.e., "ace of spades"
// a Card is constructed from a rank (int in range 1..13)
// and a suit (Card::spades, Card::hearts, Card::diamonds,
// Card::clubs)
//
// Cards should be created by a Deck (see deck.h), a Deck returns
// good cards
// The function toString() converts a card to a string, e.g., to print
//
// Accessor functions include
//
// int GetRank()      -- returns 1, 2, ..., 13 for ace, two, ..., king
//
// bool SameSuitAs(c) -- returns true if same suit as Card c
//
// string suitString() -- returns "s", "h", "d" or "c"
//
// Note that the Ace is represented by 1 and the King by 13


#ifndef _CARD_H
#define _CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
  public:


    enum Suit {spades, hearts, diamonds, clubs};

    //Default constructor
    //Sets card to ace of spades
    Card();

    //Constructor with rank and suit
    //User of class will pass in a rank and a suit.
    Card(int rank, Suit s);


    //function: toString
    //inputs: none
    //outputs: string version e.g. Ac 4h Js
    string toString() const;

    //function: sameSuitAs
    //inputs: constant reference to a card
    //outputs: boolean true if Card c is same suit as given instance, else false
    bool sameSuitAs(const Card& c) const;

    //function: getRank
    //inputs: none
    //outputs: integer for the rank (1-13)
    int  getRank() const;

    //function: suitString
    //inputs: suit
    //outputs: string corresponding to "s", "h",...
    string suitString(Suit s) const;

    //function: rankString
    //inputs: integer
    //outputs: string corresponding to "A", "2", ..."Q"
    string rankString(int r) const;
    
    //overloads the == operator
    //Checks if suit and rank are same for both cards
    bool operator == (const Card& rhs) const;

    //overloads the != operator
    //Checks if suit and rank are not the same
    bool operator != (const Card& rhs) const;
    

    
  private:

    int myRank;
    Suit mySuit;

    
};

//overloads the ofstream output by outputing the tostring for the card
ostream& operator << (ostream& out, const Card& c);



#endif
