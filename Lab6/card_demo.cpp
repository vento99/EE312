// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void checkForBookings(Deck &d, Player &p);

int main( ) {
    //need to do flow of the game
    int numCards = 7;
    int playersTurn = 1;    //which playersTurn it is

    Player p1("Joe");
    Player p2("Jane");
    
    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;


    Card c1, c2;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(i == 0 && p1.checkHandForBook(c1, c2)){
                cout << p1.getName() << " books the two " << c1.getRank() << "'s" << endl;
                p1.bookCards(c1, c2);
            }
            else if(i == 1 && p2.checkHandForBook(c1, c2)){
                cout << p2.getName() << " books the two " << c1.getRank() << "'s" << endl;
                p2.bookCards(c1, c2);
            }
        }
    }


    while(p1.getBookSize() + p2.getBookSize() != 52){
        //both could have match right off bat...
        if(playersTurn == 1){
            if(p1.getHandSize() < 1){
                cout << p1.getName() << " does not have any cards" << endl;
                Card draw = d.dealCard();
                p1.addCard(draw);
                cout << p1.getName() << " draws " << draw << endl;
            }else{
                Card card1 = p1.chooseCardFromHand();
                cout << p1.getName() << " asks - Do you have a " << card1.getRank() << endl;
                if(p2.sameRankInHand(card1)){
                    cout << p2.getName() << " says - Yes. I have a " << card1.getRank() << endl;
                    Card matching = p2.findRankInHand(card1);
                    p2.removeCardFromHand(matching);
                    p1.addCard(matching);
                    cout << p1.getName() << " books the two " << card1.getRank() << "'s" << endl;
                    p1.bookCards(card1, matching);
                }else{
                    cout << p2.getName() << " says - Go Fish" << endl;
                    Card draw = d.dealCard();
                    p1.addCard(draw);
                    cout << p1.getName() << " draws " << draw << endl;
                    if(p1.checkHandForBook(c1, c2)){
                        cout << p1.getName() << " books the two " << c1.getRank() << "'s" << endl;
                        p1.bookCards(c1, c2);
                    }                }
            }
            cout << endl;
            playersTurn = 2;
        }else{
            if(p2.getHandSize() < 1){
                cout << p2.getName() << " does not have any cards" << endl;
                Card draw = d.dealCard();
                p2.addCard(draw);
                cout << p2.getName() << " draws " << draw << endl;
            }else{
                Card card1 = p2.chooseCardFromHand();
                cout << p2.getName() << " asks - Do you have a " << card1.getRank() << endl;
                if(p1.sameRankInHand(card1)){
                    cout << p1.getName() << " says - Yes. I have a " << card1.getRank() << endl;
                    Card matching = p1.findRankInHand(card1);
                    p1.removeCardFromHand(matching);
                    p2.addCard(matching);
                    cout << p2.getName() << " books the two " << card1.getRank() << "'s" << endl;
                    p2.bookCards(card1, matching);
                }else{
                    cout << p1.getName() << " says - Go Fish" << endl;
                    Card draw = d.dealCard();
                    p2.addCard(draw);
                    cout << p2.getName() << " draws " << draw << endl;
                    if(p2.checkHandForBook(c1, c2)){
                        cout << p2.getName() << " books the two " << c1.getRank() << "'s" << endl;
                        p2.bookCards(c1, c2);
                    }
                }
            }
            cout << endl;
            playersTurn = 1;
        }
    }

    if(p1.getBookSize() > p2.getHandSize()){
        cout << p1.getName() << " Wins!";
    }
    else if(p1.getBookSize() < p2.getBookSize()){
        cout << p2.getName() << " Wins!";
    }
    else{
        cout << "It's a ties";
    }
    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards) {
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

void checkForBookings(Deck &d, Player &p){
}



