/* player.cpp

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

// This file is the cpp file that implements methods relating to the player class
// For documentation of methods, see the player.h file
// Date: November 9, 2018

#include "player.h"
#include <cstdlib>
#include <vector>
#include <ctime>

Player::Player(){
    myName = "";
    myBook.clear();
    myHand.clear();
}

void Player::addCard(Card c){
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

Card Player::chooseCardFromHand() const{
    unsigned int currentTime = (unsigned)time(0);
    srand(currentTime);
    int cardIndex = rand()%myHand.size();
    return myHand.at(cardIndex);
}

//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const{
    vector<Card>::const_iterator i;
    for(i = myHand.begin(); i != myHand.end(); i++){
        if(c == *i){
            return true;
        }
    }
    return false;
}

//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c){
    //remove first card ????
    vector<Card>::const_iterator i;
    int index = 0;
    for(i = myHand.begin(); i != myHand.end(); i++){
        if((*i) == c){
            Card removedCard = *i;
            myHand.erase(myHand.begin() + index);
            return removedCard;
        }
        index++;
    }
}

bool Player::checkHandForBook(Card &c1, Card &c2){
    vector<Card>::const_iterator i;
    vector<Card>::const_iterator j;
    for(i = myHand.begin(); i != myHand.end(); i++){
        for(j = myHand.begin(); j != myHand.end(); j++){
            if(i != j && (*i).getRank() == (*j).getRank()){
                c1 = *i;
                c2 = *j;
                return true;
            }
        }
    }
    return false;
}


string Player::showHand() const{
    string hand = "";
    vector<Card>::const_iterator i;
    for(i = myHand.begin(); i != myHand.end(); i++){
        hand += (*i).toString() + " ";
    }
    return hand;
}

string Player::showBooks() const{
    string books = "";
    vector<Card>::const_iterator i;
    int counter = 1;
    for(i = myBook.begin(); i != myBook.end(); i++){
        if(counter > 0 && counter%2 == 0){
            books += (*i).toString() + "\n";
        }else{
            books += (*i).toString() + ", ";

        }
        counter++;
    }
    return books;
}

int Player::getHandSize() const{
    return myHand.size();
}

int Player::getBookSize() const{
    return myBook.size();
}

bool Player::sameRankInHand(Card c) const{
    vector<Card>::const_iterator i;
    for(i = myHand.begin(); i != myHand.end(); i++){
        if((*i).getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}


