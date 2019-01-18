//cards->cpp
//Authors: Your name and your partner's name
//Implementation of the classes defined in cards->h
#include "cards.h"
#include <iostream>
using namespace std;

//cards.cpp
//Authors: Your name and your partner's name
//Implementation of the classes defined in cards.h
#include "cards.h"
#include <iostream>
using namespace std;

Card::Card(){
	value = "NULL";
}

Card::Card(string value_){
	value = value_;
}

bool Card::operator==(Card& card){
	bool flag = true;
	if(card.value != this->value)
		return false;
	return true;
}

Hand::Hand(){
	first = 0;
	last = 0;
}

string hasMatch(Hand& playerHand, Hand& opponentHand){
	Card* opponentCard = opponentHand.first;
	Card* playerCard = playerHand.first;
	while(playerCard){
		//cout << "Base Card: " << playerCard->value << "\n";
		while(opponentCard->next){
			if(playerCard->value == opponentCard->value){
				return playerCard->value;
			}else{
				//cout << "Test: " << opponentCard->value << "\n";
				opponentCard = opponentCard->next;
			}
		}
		//cout << opponentHand.last->value << " " << playerHand.last->value << endl;
		//issue is the opponentHand.last value isnt reached in the while loop. if i change the while loop
		//to opponentCard instead of ->next, i get seg fault. If i hard code, i get error as well. 
		if(opponentCard->value == playerCard->value)
			return playerCard->value;
		opponentCard = opponentHand.first;
		playerCard = playerCard->next;
	}
	//cout << "hasMatch\n";
	return "NULL";
}

void searchAndDestroy(Hand& player, Hand& opponent, string value){
	Card* playerCard = player.first;
	Card* opponentCard = opponent.first;
	Card* temp1 = playerCard->next;
	Card* temp2 = opponentCard->next;

	if(opponentCard->value == value){
		delete opponentCard;
		opponent.first = temp2;
	}
	while(temp2->value != value){
		opponentCard = temp2;
		temp2 = temp2->next;
	}
	if(temp2 == opponent.last){
		opponentCard->next = 0;
		opponent.last = opponentCard;
	}else
		opponentCard->next = temp2->next;
	delete temp2;

	//delete player Card with value
	if(playerCard->value == value){
		delete playerCard;
		player.first = temp1;
	}
	while(temp1->value != value){
		playerCard = temp1;
		temp1 = temp1->next;
	}
	if(temp1 == player.last){
		playerCard->next = 0;
		player.last = playerCard;
	}else
		playerCard->next = temp1->next;
	delete temp1;

	//opponent.printHand();
	//cout << "\n";
	//player.printHand();
}


void Hand::printHand() const{
	Card* temp = first;
	while(temp){
		cout << temp->value << "\n";
		temp = temp->next;
	}
}

int Hand::count() const{
	Card* temp = first;
	int count = 0;
	while(temp){
		count++;
		temp = temp->next;
	}
	return count;
}

void Hand::clearHand(){
	Card* temp;
	while(first){
		temp = first->next;
		delete first;
		first = temp;
	}
	first = 0;
}


void Hand::addCard(string value_){
	if(!first){
		first = new Card;
		//cout << "alloc addCard\n";
		first->value = value_;
		first->next = 0;
		last = first;
	} else{
		last->next = new Card;
		//cout << "alloc addCard\n";
		Card* temp = last->next;
		temp->value = value_;
		temp->next = 0;
		last = temp;
	}
}