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
        contents += (*iter).toString() + " ";
    }
    return (contents);
}
