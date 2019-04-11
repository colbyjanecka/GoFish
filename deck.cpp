#include "deck.h"
#include <string>
#include <ctime>
#include <iostream> // Provides cout and cin
#include <cstdlib>

using namespace std;


Deck::Deck()
{
    myIndex = 0;
    int tempIndex = 0;

    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 1; rank < 14; rank++) {
            myCards[tempIndex] = Card(rank, Card::Suit(suit));
            // cout<<myIndex<<". "<<myCards[myIndex].toString()<<endl;
            tempIndex++;
        }
    }
    // for(int j=0; j < SIZE; j++){
    //    cout << myCards[j].toString() << endl;
    // }
}

void Deck::shuffle()
{
    Card temp;

    srand(time(NULL) + getpid());
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

Card Deck::dealCard()
{
    Card temp(0, Card::Suit(0));

    if (size() > 0) {
        temp = myCards[myIndex];
        myIndex++;
    }

    return temp;
}

int Deck::size() const
{
    int remainingCards = SIZE - myIndex;

    return (remainingCards);
}
