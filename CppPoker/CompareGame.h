#ifndef COMPAREGAME_H
#define COMPAREGAME_H

#include "Deck.h"

class CompareGame {
public:
	CompareGame(int m = 1000);
	Card playerDraw();
	Card randomDraw();
	std::vector<int>::size_type getDeckSize();
	void play(int m = 0);
private:
	int money;
	Deck deck;
};

#endif