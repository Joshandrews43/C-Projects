// CustomItem.cpp

#include <string>
#include <vector>
#include <map>
#include "CustomItem.h"

using namespace std;

CustomItem::CustomItem(string size) : IceCreamItem(size) {
	if(size == "small")
		this->price = 3.00;
	else if(size == "medium")
		this->price = 5.00;
	else
		this->price = 6.50;
}

string CustomItem::composeItem() {
	string s;
	map<string, int> :: iterator itr;
	s += "Custom Size: " + size + "\n";
	s += "Toppings:\n";
	for(itr = this->toppings.begin(); itr != this->toppings.end(); ++itr){
		s += itr->first + ": " + to_string(itr->second) + " oz\n";
	}
	s += "Price: $" + to_string(this->getPrice()).substr(0,4) + "\n";
	return s;
}

double CustomItem::getPrice(){
	return this->price;
}

CustomItem::~CustomItem() {

}

void CustomItem::addTopping(string topping) {
	this->toppings[topping]++;
	this->price += .40;
}