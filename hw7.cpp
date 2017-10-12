
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)
const unsigned int dealerMoney = 900;

// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main(){
    Player player(100);
    Player dealer(900);
    
    unsigned int bet = 0;
    int round = 0;
    while(true){
        //increment round number
        round++;
        
        cout << "You have " << player.get_money() << "$. Enter bet: ";
        
        //draw a card
        Card newCard;
        while(true) {
            cin >> bet;
            if(bet <= player.get_money()) {
                //adds card to hand
                player.play_hand(bet, newCard);
                break;
            }
            else{
                cout << "Sorry, you only have " << player.get_money() << "$. Enter bet: ";
            }
        }
        
        cout << "Your cards:\n" << "\t" << newCard.get_spanish_rank() << " de " << newCard.get_spanish_suit() << "\t(" << newCard.get_english_rank() << " of " << newCard.get_english_suit() << ").\n";
        
        cout << "Your total is " << player.get_score() << ". Do you want another card (y/n)?";
        char ans;
        cin >> ans;
        if(ans == 'n'){
            break;
        }
    }
    return 0;
}
