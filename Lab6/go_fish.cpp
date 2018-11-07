/* go_fish.cpp

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

// This file is the main cpp driver that implements the go fish game for 2 players
// Date: November 9, 2018

#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used:
void dealHand(Deck &d, Player &p, int numCards);
void noCardsInHand(Deck &d, Player &p, ofstream &myfile, int *playersTurn);
void takeTurn(Deck &d, Player &user, Player &opponent, ofstream &myfile, int *playersTurn);
void checkForBookings(Deck &d, Player &p, ofstream &myfile);
void findWinner(Player &p1, Player &p2, ofstream &myfile);


int main( ) {

    int numCards = 7;
    int playersTurn = 1;    //which playersTurn it is

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
    ofstream myfile ("gofish_results.txt");
    if(!myfile.is_open()){
        cout << "File error";
        return 1;
    }
    myfile << p1.getName() << " and " << p2.getName() << " are going to play Go Fish!" << endl << endl;

    myfile << p1.getName() <<" has : " << p1.showHand() << endl;
    myfile << p2.getName() <<" has : " << p2.showHand() << endl << endl;

    int sizeBefore, sizeAfter;

    for(int i = 0; i < 2; i++){         //for each of the two players, check to see if they drew up to floor(numCards/2) bookings
        bool foundBook = false;
        for(int j = 0; j < numCards/2; j++){
            if(i == 0){
                sizeBefore = p1.getHandSize();
                checkForBookings(d, p1, myfile);
                sizeAfter = p1.getHandSize();
            }else{
                sizeBefore = p2.getHandSize();
                checkForBookings(d, p2, myfile);
                sizeAfter = p2.getHandSize();
            }
            if(sizeAfter != sizeBefore){
                foundBook = true;
            }
        }
        if(foundBook) {
            myfile << endl;
        }
    }

    while(p1.getHandSize() != 0 || p2.getHandSize() != 0){
        if(playersTurn == 1){
            if(p1.getHandSize() < 1){
                noCardsInHand(d, p1, myfile, &playersTurn);     //draw Card if no Cards in Hand
            }else{
                takeTurn(d, p1, p2, myfile, &playersTurn);
            }
            myfile << endl;
        }else{
            if(p2.getHandSize() < 1){
                noCardsInHand(d, p2, myfile, &playersTurn);
            }else{
                takeTurn(d, p2, p1, myfile, &playersTurn);
            }
            myfile << endl;
        }
        //myfile << p1.getName() <<" has : " << p1.showHand() << endl;
        //myfile << p2.getName() <<" has : " << p2.showHand() << endl << endl;
    }

    findWinner(p1, p2, myfile);
    myfile.close();

    return EXIT_SUCCESS;
}

//Function: dealHand
//Inputs: Reference to the deck and a player, and the num of cards
//Outputs: None
//Deals a hand of numCards to the player from the deck
void dealHand(Deck &d, Player &p, int numCards) {
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

//Function: dealHand
//Inputs: Constant reference to the deck, a player, and the file output stream, and pointer to the players Turn
//Outputs: None
//Player draws a card and check if there are bookings because of the draw, updates playersTurn
void noCardsInHand(Deck &d, Player &p, ofstream &myfile, int *playersTurn){
    myfile << p.getName() << " does not have any cards" << endl;
    Card draw = d.dealCard();
    p.addCard(draw);
    myfile << p.getName() << " draws " << draw << endl;
    checkForBookings(d, p, myfile);
    if(*playersTurn == 1){
        *playersTurn = 2;
    }else{
        *playersTurn = 1;
    }
}

//Function: dealHand
//Inputs: Constant reference to the deck, a player, and the file output stream, and pointer to the players Turn
//Outputs: None
//Users asks for a random card from their hand and opponent answers by either giving the card
//or says go fish making the user draw card.
void takeTurn(Deck &d, Player &user, Player &opponent, ofstream &myfile, int *playersTurn){
    Card card1 = user.chooseCardFromHand();
    myfile << user.getName() << " asks - Do you have a " << card1.rankString(card1.getRank()) << "?" << endl;
    if (opponent.sameRankInHand(card1)) {
        myfile << opponent.getName() << " says - Yes. I have a " << card1.rankString(card1.getRank()) << "." << endl;
        Card matching;
        for(int i = 0; i < 4; i++){
            Card *c = new Card(card1.getRank(), (Card::Suit)i);
            if(card1 != *c && opponent.cardInHand(*c)){
                matching = *c;
            }
            delete(c);
        }
        //Card matching = opponent.removeCardFromHand(card1);
        opponent.removeCardFromHand(matching);
        user.addCard(matching);
        myfile << user.getName() << " books the " << card1 << " and the " << matching << endl;
        user.bookCards(card1, matching);
    } else {
        myfile << opponent.getName() << " says - Go Fish" << endl;
        Card draw = d.dealCard();
        user.addCard(draw);
        myfile << user.getName() << " draws " << draw << endl;
        checkForBookings(d, user, myfile);
        if(*playersTurn == 1){
            *playersTurn = 2;
        }else{
            *playersTurn = 1;
        }
    }
}

//Function: checkForBookings
//Inputs: Constant reference to the deck, a player, and the file output stream
//Outputs: None
//Checks hand for bookings and books card if necessary
void checkForBookings(Deck &d, Player &p, ofstream &myfile){
    Card c1, c2;
    if(p.checkHandForBook(c1,c2)){
        myfile << p.getName() << " books the " << c1 << " and the " << c2 << endl;
        p.bookCards(c1, c2);
    }
}

//Function: checkForBookings
//Inputs: Constant reference to the 2 players, and the file output stream
//Outputs: None
//Writes the bookings to the file and determines the winner and writes it to the file
void findWinner(Player &p1, Player &p2, ofstream &myfile){
    myfile << p1.getName() << "'s bookings are:" << endl << p1.showBooks() << endl;
    myfile << p2.getName() << "'s bookings are:" << endl << p2.showBooks() << endl;
    if(p1.getBookSize() > p2.getBookSize()){
        myfile << p1.getName() << " wins with " << p1.getBookSize()/2 << " bookings!" << endl;
    }
    else if(p1.getBookSize() < p2.getBookSize()){
        myfile << p2.getName() << " wins with " << p2.getBookSize()/2 << " bookings!" << endl;
    }
    else{
        myfile << "It's a tie! Both players have 13 bookings.";
    }
}


