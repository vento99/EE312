// FILE:  player.h

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

// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include "card.h"

using namespace std;

class Player
{
  public:

    //Default constructor. Initializes name to null
    Player();

    //Constructor
    Player(string name) {
       myName = name;
    }

    //Function: getName
    //Inputs: None
    //Outputs: String that corresponds to the name of the players
    string getName() const {
       return myName;
    }

    //Function: addCard
    //Inputs: Card for the card you want to add to hand
    //Outputs: None
    //Adds a card c to the hand
    void addCard(Card c);

    //Function: bookCards
    //Inputs: Two cards for the card you want to add to book
    //Outputs: None
    //Puts 2 cards in books
    void bookCards(Card c1, Card c2);


    //Function: checkHandForBook
    //Inputs: Reference to two cards
    //Outputs: Boolean variable saying if there is a book or not
    //This function will check a players hand for a pair.
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    bool checkHandForBook(Card &c1, Card &c2);

    //OPTIONAL
    // comment out if you decide to not use it    
    //Does the player have a card with the same rank as c in her hand?
    //bool rankInHand(Card c) const;
    

    //Function: chooseCardFromHand
    //Inputs: None
    //Outputs: Card from the player's hand
    //Randomly choose a card from the player's hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const; 

    //Function: cardInHand
    //Inputs: Card
    //Outputs: Boolean variable that says if the player has the card c in their hand
    bool cardInHand(Card c) const; 

    //Function: removeCardFromHand
    //Inputs: Card
    //Outputs: Card - removes the card c from the hand and return it to the caller
    //Precondition: User must have Card c in the hand
    Card removeCardFromHand(Card c); 

    //Function: showHand
    //Inputs: None
    //Outputs: String of the player's hand that will be able to be printed out to screen/file
    string showHand() const;

    //Function: showBooks
    //Inputs: None
    //Outputs: String of the player's books that will be able to be printed out to screen/file
    string showBooks() const;

    //Function: getHandSize
    //Inputs: None
    //Outputs: Integer that corresponds to the size of the player's hand
    int getHandSize() const;

    //Function: getHandSize
    //Inputs: None
    //Outputs: Integer that corresponds to the size of the player's books
    int getBookSize() const; 
       
    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.
    //bool checkHandForPair(Card &c1, Card &c2);

    //Function: sameRankInHand
    //Inputs: Card
    //Outputs: Boolean that says if the player has a card with the same rank as the Card c in the hand
    bool sameRankInHand(Card c) const;

    
  private:
          
    vector <Card> myHand;
    vector <Card> myBook;
    
    string myName;     
   
};


#endif
