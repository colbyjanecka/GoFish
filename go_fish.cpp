#include <iostream>
#include <fstream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

Player * switchTurn(Player * p1, Player * p2);

string actionMessage(Player * p, int move, Card c);
static const int GOFISH = 0;
static const int ASKS   = 1;
static const int TAKES  = 2;
static const int HAS    = 3;
static const int BOOKS  = 4;

int main()
{
	int numCards = 5;				// sets number of cards per hand

	Player player1("John");			// create players
	Player player2("Lucy");

	Deck d;							// create Deck

	d.shuffle();					// shuffle deck

	dealHand(d, player1, numCards);	// deal hand to players
	dealHand(d, player2, numCards);

	cout << player1.getName() << " has : " << player1.showHand() << endl;
	cout << player2.getName() << " has : " << player2.showHand() << endl;
}

void dealHand(Deck &d, Player &p, int numCards)
{
	for (int i = 0; i < numCards; i++)
		p.addCard(d.dealCard());
}

Player * switchTurn(Player * p, Player * p1, Player * p2)
{
	if (p == p1) {
		return p2;
	} else {
		return p1;
	}
}
