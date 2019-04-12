#include <iostream>
#include <fstream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

Player * switchTurn(Player * p1, Player * p2);

void printPlayerCards(Player player1, Player player2);

string actionMessage(Player const p, int move, Card c);

Player * turnToMove(int playerID, Player * p1, Player * p2);

static const int GOFISH = 0;
static const int ASKS   = 1;
static const int TAKES  = 2;
static const int HAS    = 3;
static const int BOOKS  = 4;

static const int P1 = 0;
static const int P2 = 1;

int main()
{
	srand(time(NULL) + getpid());

	int numCards = 7;									// sets number of cards per hand

	Player player1("John");								// create players
	Player player2("Lucy");

	Deck d;												// create Deck

	d.shuffle();										// shuffle deck

	dealHand(d, player1, numCards);						// deal hand to players
	dealHand(d, player2, numCards);

	Card c1, c2, cardInHand;							// creates cards c1 and c2 for working

	int currentPlayerID = P1;							// set the person who goes first.

	printPlayerCards(player1, player2);

	while (player1.checkHandForBook(c1, c2) == true) {	// checks for pairs in p1's hand
		player1.bookCards(c1, c2);						// and books them if so
		cout << actionMessage(player1, BOOKS, c1) << endl << endl;
	}
	while (player2.checkHandForBook(c1, c2) == true) {	// checks for pairs in p2's hand
		player2.bookCards(c1, c2);						// and books them if so
		cout << actionMessage(player2, BOOKS, c1) << endl << endl;
	}

	while (player1.getBookSize() + player2.getBookSize() != 26) {
		Player * currentPlayer = turnToMove(currentPlayerID, &player1, &player2);
		Player * otherPlayer   = turnToMove((currentPlayerID + 1) % 2, &player1, &player2);

		printPlayerCards(player1, player2);

		cardInHand = currentPlayer->chooseCardFromHand();


		cout << actionMessage(*currentPlayer, ASKS, cardInHand) << endl;
		if (otherPlayer->sameRankInHand(cardInHand)) {
			cout << actionMessage(*otherPlayer, HAS, cardInHand) << endl;

			Card pairCard = otherPlayer->findSimilarCard(cardInHand);
			currentPlayer->addCard(otherPlayer->removeCardFromHand(pairCard));

			currentPlayer->bookCards(cardInHand, pairCard);
			cout << actionMessage(*currentPlayer, BOOKS, cardInHand) << endl << endl;
		} else {
			cout << actionMessage(*otherPlayer, GOFISH, cardInHand) << endl;
			Card drawnCard = d.dealCard();
			currentPlayer->addCard(drawnCard);
			cout << actionMessage(*currentPlayer, TAKES, drawnCard) << endl;
			if (currentPlayer->checkHandForBook(c1, c2)) {
				currentPlayer->bookCards(c1, c2);
				cout << actionMessage(*currentPlayer, BOOKS, c1) << endl << endl;
			}
			currentPlayerID = (currentPlayerID + 1) % 2;
		}
		if (currentPlayer->getHandSize() == 0 && d.size() != 0) {
			currentPlayer->addCard(d.dealCard());
		}
		if (otherPlayer->getHandSize() == 0 && d.size() != 0) {
			otherPlayer->addCard(d.dealCard());
		}
	}
	cout << " ALL CARDS PLAYED " << endl;
	cout << "John has " << player1.getBookSize() << " books." << endl;
	cout << "Lucy has " << player2.getBookSize() << " books." << endl;
	if (player1.getBookSize() > player2.getBookSize()) {
		cout << player1.getName() << " wins!" << endl;
	} else if (player1.getBookSize() < player2.getBookSize()) {
		cout << player2.getName() << " wins!" << endl;
	} else {
		cout << "It's a tie!" << endl;
	}
}														// main

void printPlayerCards(Player player1, Player player2)	// prints out the current hands/books of the players.
{
	cout << player1.getName() << "'s cards: " << player1.showHand() << endl;
	cout << player2.getName() << "'s cards: " << player2.showHand() << endl;
	cout << player1.getName() << "'s books: " << player1.showBooks() << endl;
	cout << player2.getName() << "'s books: " << player2.showBooks() << endl;
	cout << endl;
}

string actionMessage(Player const p, int move, Card c)
{
	string message = p.getName();

	if (move == ASKS) {
		message += " asks - Do you have a ";
		message += c.rankString(c.getRank());
	} else if (move == BOOKS) {
		message += " books the ";
		message += c.rankString(c.getRank());
	} else if (move == HAS) {
		message += " says - Yes, I do have a  ";
		message += c.rankString(c.getRank());
	} else if (move == GOFISH) {
		message += " says - Go Fish!";
	} else if (move == TAKES) {
		message += " draws ";
		message += c.toString();
	}
	return message;
}

void dealHand(Deck &d, Player &p, int numCards)
{
	for (int i = 0; i < numCards; i++)
		p.addCard(d.dealCard());
}

Player * turnToMove(int playerID, Player * p1, Player * p2)
{
	if (playerID == P1) {
		return p1;
	} else {
		return p2;
	}
}
