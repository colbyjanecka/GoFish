#include <iostream>
#include <fstream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

Player * switchTurn(Player * p1, Player * p2);

int main()
{
    int numCards = 5;

    Player player1("John");
    Player player2("Lucy");

    Deck d;

    dealHand(d, player1, numCards);
    dealHand(d, player2, numCards);

    cout << player1.getName() << " has : " << player1.showHand() << endl;
    cout << player2.getName() << " has : " << player2.showHand() << endl;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i = 0; i < numCards; i++)
        p.addCard(d.dealCard());
}
