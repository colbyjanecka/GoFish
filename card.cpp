#include "card.h"
#include <string>
using namespace std;

Card::Card()
{
	myRank = 1;
	mySuit = Card::Suit(0);
}

Card::Card(int rankIn, Suit suitIn)
{
	myRank = rankIn;
	mySuit = suitIn;
}

bool Card::sameSuitAs(const Card &c) const
{
	return mySuit == c.mySuit;
}

int Card::getRank() const
{
	return myRank;
}

string Card::suitString(Card::Suit s) const
{
	string suit;

	if (s == spades) {
		suit = 's';
	} else if (s == hearts) {
		suit = 'h';
	} else if (s == diamonds) {
		suit = 'd';
	} else if (s == clubs) {
		suit = 'c';
	}

	return suit;
}

string Card::rankString(int r) const
{
	string array[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	return array[r - 1];
}

string Card::toString() const
{
	return (rankString(myRank) + suitString(mySuit));
}

bool Card::operator == (const Card &rhs) const
{
	return mySuit == rhs.mySuit && myRank == rhs.myRank;
}

bool Card::operator != (const Card &rhs) const
{
	return mySuit != rhs.mySuit || myRank != rhs.myRank;
}

ostream&operator << (ostream& out, const Card& c)
{
	out << c.toString();
	return out;
}
