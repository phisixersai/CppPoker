#ifndef CARD_H
#define CARD_H

#include <iostream>

enum Suit{CLUB, DIAMOND, HEART, SPADE};

class Card {
public:
	Card();
	Card(int, Suit);
	int getValue();
	Suit getSuit();
	Card operator= (const Card&);
	bool operator< (const Card&);
	friend std::ostream& operator<< (std::ostream&, const Card&);
private:
	int value;
	Suit suit;
};


#endif