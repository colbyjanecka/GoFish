#include "card.h"
#include <string>
using namespace std;

Card::Card() {
    myRank = " ";
    mySuit = " ";
}

Card::Card(int rankIn, Suit suitIn){
    myRank = rankIn;
    mySuit = suitIn;
}

string Card::toString() const {

}