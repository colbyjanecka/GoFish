#include "deck.h"
#include <string>
#include <ctime>
#include <iostream> // Provides cout and cin
#include <cstdlib>

using namespace std;


Deck::Deck()
{
    myIndex = 0;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 1; rank < 14; rank++) {
            myCards[myIndex] = Card(rank, Card::Suit(suit));
            // cout<<myIndex<<". "<<myCards[myIndex].toString()<<endl;
            myIndex++;
        }
    }
    // for(int j=0; j < SIZE; j++){
    //    cout << myCards[j].toString() << endl;
    // }
}

void Deck::shuffle()
{
    Card temp;

    srand(time(NULL));
    for (int i = 0; i < 512; i++) {
        int i1 = rand() % SIZE;
        int i2 = rand() % SIZE;
        temp        = myCards[i1];
        myCards[i1] = myCards[i2];
        myCards[i2] = temp;
    }
    // for(int j =0; j< SIZE; j++){
    //    cout << myCards[j].toString() << endl;
    // }
}
