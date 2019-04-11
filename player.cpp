#include "player.h"
#include <string>
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

Card Player::chooseCardFromHand() const
{
	Card c;
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
