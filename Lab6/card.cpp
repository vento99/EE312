/* card.cpp

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

// This file is the cpp file that implements methods relating to the card class
// For documentation of methods, see the card.h file
// Date: November 9, 2018

#include "card.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const{
    string suit = suitString(mySuit);
    string rank = rankString(myRank);
    return rank + suit;
}

bool Card::sameSuitAs(const Card& c) const{
    return (mySuit == c.mySuit);
}

int  Card::getRank() const{
    return myRank;
}

string Card::suitString(Suit s) const{
    string suit;
    switch(s){
        case spades:
            suit = "s";
            break;
        case hearts:
            suit = "h";
            break;
        case diamonds:
            suit = "d";
            break;
        case clubs:
            suit = "c";
            break;
    }
    return suit;
}

string Card::rankString(int r) const{
    string rank;
    switch(r){
        case 11:
            rank = "J";
            break;
        case 12:
            rank = "Q";
            break;
        case 13:
            rank = "K";
            break;
        case 1:
            rank = "A";
            break;
        case 2:
            rank = "2";
            break;
        case 3:
            rank = "3";
            break;
        case 4:
            rank = "4";
            break;
        case 5:
            rank = "5";
            break;
        case 6:
            rank = "6";
            break;
        case 7:
            rank = "7";
            break;
        case 8:
            rank = "8";
            break;
        case 9:
            rank = "9";
            break;
        default:
            rank = "10";
            break;
    }

    return rank;
}

bool Card::operator == (const Card& rhs) const{
    return (myRank == rhs.myRank && mySuit == rhs.mySuit);
}

bool Card::operator != (const Card& rhs) const{
    return (myRank != rhs.myRank || mySuit != rhs.mySuit);
}

ostream& operator << (ostream& out, const Card& c) {
    out << c.toString();
    return out;
}