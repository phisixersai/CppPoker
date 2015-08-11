#include "Card.h"

Card::Card(): value(0), suit(SPADE) {}
Card::Card(int v, Suit s) :value(v), suit(s) {}

int Card::getValue() {
	return value;
}

Suit Card::getSuit() {
	return suit;
}

Card Card::operator=(const Card& c2) {
	value = c2.value;
	suit = c2.suit;
	return *this;
}

bool Card::operator<(const Card& c2) {
	if (value == c2.value) return (suit < c2.suit);
	else {
		if (value == 1) {
			return false;
		}
		if (c2.value == 1) {
			return true;
		}
		return (value < c2.value);
	}
}

std::ostream& operator<< (std::ostream& os, const Card& c) {
	os << " [";
	switch (c.suit) {
		case SPADE:
			os << " Spade -";
			break;
		case HEART:
			os << " Heart -";
			break;
		case DIAMOND:
			os << "Diamond-";
			break;
		case CLUB:
			os << " Club  -";
			break;
		default:
			os << "Bug in Card operator << switch case";
	}
	switch (c.value) {
	    case 1:
			os << "A ";
			break;
		case 11:
			os << "J ";
			break;
		case 12:
			os << "Q ";
			break;
		case 13:
			os << "K ";
			break;
		case 10:
			os << "10";
			break;
		default:
			os << c.value << " ";
	}
	os << "] ";
	return os;
}