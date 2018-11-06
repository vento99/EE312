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
    vector<Card>::const_iterator i;
    for(i = myHand.begin(); i != myHand.end(); i++){
        if(*i == c){
            Card removedCard = *i;
            myHand.erase(i);
            return removedCard;
        }
    }
    //default return?
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
    int counter = 0;
    for(i = myBook.begin(); i != myBook.end(); i++){
        if(counter > 0 && counter%2 == 0){
            books += (*i).toString() + "\n";
        }else{
            books += (*i).toString() + ", ";

        }
        counter ++;
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
    int rank = c.getRank();
    for(i = myHand.begin(); i != myHand.end(); i++){
        if((*i).getRank() == rank){
            return true;
        }
    }
    return false;
}

Card Player::findRankInHand(Card c) const{
    vector<Card>::const_iterator i;
    int rank = c.getRank();
    for(i = myHand.begin(); i != myHand.end(); i++){
        if((*i).getRank() == rank){
            return (*i);
        }
    }
}

