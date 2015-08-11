#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck {
public:
	Deck();
	Card draw(std::vector<int>::size_type);
	std::vector<int>::size_type getSize();
	void shuffle();
	friend std::ostream& operator<< (std::ostream&, const Deck&);
private:
	std::vector<Card> cards;
};

#endif