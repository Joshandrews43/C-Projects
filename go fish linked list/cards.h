//cards.h
//Authors: Your name and your partner's name
//All class declarations go here

#ifndef CARDS_H
#define CARDS_H
#include <string>

class Card{
public:
	Card();
	Card(std::string value_);
	std::string getValue() const { return value; }
	bool operator==(Card& card);
	std::string value;
	Card* next;
};

class Hand{
public:
	Hand();
	Card* getHead() const { return first; };
	void friend searchAndDestroy(Hand& player, Hand& opponent, std::string value);
	std::string friend hasMatch(Hand& playerHand, Hand& opponentHand);
	void printHand() const;
	int count() const;
	void addCard(std::string value_);
	void clearHand();

private:
	Card* first;
	Card* last;
};


#endif