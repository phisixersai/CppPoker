#include <random>
#include "CompareGame.h"

CompareGame::CompareGame(int m) {
	money = m;
}

Card CompareGame::playerDraw() {
	int idx = 0;
	std::cout << "Please Enter the Index of the Card You Want to Draw: (1 ~ " << getDeckSize() << ") " << std::endl;
	std::cin >> idx;
	return deck.draw(idx-1);
}

Card CompareGame::randomDraw() {
	auto const seed = std::random_device()();
	auto engine = std::mt19937(seed);
	std::uniform_int_distribution<int> dist(0, deck.getSize()-1);
	int idx = dist(engine);
	return deck.draw(idx);
}

std::vector<int>::size_type CompareGame::getDeckSize() {
	return deck.getSize();
}

void CompareGame::play(int m) {
	std::cout << "===============================================================================" << std::endl;
	Card computer = randomDraw();
	std::cout << "The computer draws :" << computer << std::endl;
	Card player = playerDraw();
	std::cout << "You draws :" << player << std::endl;
	if (computer < player) {
		std::cout << "You Win !!" << std::endl;
	}
	else {
		std::cout << "Sorry, You Lose. You're a Loser." << std::endl;
	}
	std::cout << "===============================================================================" << std::endl;
}