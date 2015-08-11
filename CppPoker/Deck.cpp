#include <algorithm>
#include <random>
#include "Deck.h"

Deck::Deck() {
	for (int i = 1; i != 14; ++i) {
		cards.push_back(Card(i, SPADE));
	}
	for (int i = 14; i != 27; ++i) {
		cards.push_back(Card(i-13, HEART));
	}
	for (int i = 27; i != 40; ++i) {
		cards.push_back(Card(i-26, DIAMOND));
	}
	for (int i = 40; i != 53; ++i) {
		cards.push_back(Card(i-39, CLUB));
	}
	shuffle();
}

Card Deck::draw(std::vector<int>::size_type idx) {
	if (idx < 0 || idx >= cards.size()) {
		std::cerr << "Card selection index outside of the deck ";
		return Card(0, SPADE);
	}
	Card select = cards[idx];
	cards.erase(cards.begin() + idx);
	return select;
}

std::vector<int>::size_type Deck::getSize() {
	return cards.size();
}

void Deck::shuffle() {
	auto const seed = std::random_device()();
	auto engine = std::mt19937(seed);
	std::shuffle(std::begin(cards), std::end(cards), engine);
}

std::ostream& operator<< (std::ostream& os, const Deck& d) {
	int cnt = 0;
	auto it = d.cards.begin();
	while (it!=d.cards.end()) {
		os << *it;
		++it;
		++cnt;
		if (cnt == 4) {
			os << std::endl;
			cnt = 0;
		}
	}
	return os;
}