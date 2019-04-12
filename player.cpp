#include "player.h"
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

Player::Player()
{
	myName = " ";
}

void Player::addCard(Card c)
{
	myHand.push_back(c);
}

string Player::showHand() const
{
	string contents;

	vector<Card>::const_iterator iter;
	for (iter = myHand.begin(); iter != myHand.end(); iter++) {
		contents += iter->toString() + " ";
	}
	return (contents);
}

string Player::showBooks() const
{
	string contents;

	vector<Card>::const_iterator iter;
	for (iter = myBook.begin(); iter != myBook.end(); iter++) {
		contents += iter->toString() + " ";
	}
	return (contents);
}

Card Player::chooseCardFromHand() const
{
	int cardToChoose = rand() % getHandSize();

	return (myHand[cardToChoose]);
}

bool Player::cardInHand(Card c) const
{
	vector<Card>::const_iterator iter;
	for (iter = myHand.begin(); iter != myHand.end(); iter++) {
		if (*iter == c) {
			return (true);
		}
	}
	return (false);
}

int Player::getHandSize() const
{
	int count = 0;

	vector<Card>::const_iterator iter;
	for (iter = myHand.begin(); iter != myHand.end(); iter++) {
		count++;
	}
	return (count);
}

int Player::getBookSize() const
{
	return myBook.size() / 2;
}

void Player::bookCards(Card c1, Card c2)
{
	myBook.push_back(c1);
	removeCardFromHand(c1);
	myBook.push_back(c2);
	removeCardFromHand(c2);
}

Card Player::removeCardFromHand(Card c)
{
	vector<Card>::iterator iter;
	Card removedCard;
	for (iter = myHand.begin(); iter != myHand.end(); iter++) {
		if (*iter == c) {
			removedCard = *iter;
			myHand.erase(iter);
			return removedCard;
		}
	}
}

bool Player::checkHandForBook(Card &c1, Card &c2)
{
	vector<Card>::const_iterator iter1;
	vector<Card>::const_iterator iter2;
	for (iter1 = myHand.begin(); iter1 != myHand.end(); iter1++) {
		for (iter2 = myHand.begin(); iter2 != myHand.end(); iter2++) {
			if ((iter1->getRank() == iter2->getRank()) && !(iter1->sameSuitAs(*iter2))) {
				c1 = *iter1;
				c2 = *iter2;
				return (true);
			}
		}
	}
	return (false);
}

bool Player::sameRankInHand(Card c) const
{
	vector<Card>::const_iterator iter;
	for (iter = myHand.begin(); iter != myHand.end(); iter++) {
		if (iter->getRank() == c.getRank()) {
			return (true);
		}
	}
	return (false);
}
