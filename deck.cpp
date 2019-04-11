#include "deck.h"
#include <string>
using namespace std;


Deck::Deck() {
    myIndex = 0;
    for(Suit = Card::spades; Suit <= Card::clubs; Suit++ ){
        for(int rank = 1; rank <= 14 ; rank++){
            myCards[myIndex] = Card(rank, Suit);
            myIndex++;
        }
    }
}
