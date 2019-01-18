// PreMadeItem.cpp

#include <string>
#include "PreMadeItem.h"

using namespace std;

string PreMadeItem::composeItem() {
	string s;
	s += "Pre-made Size: " + size + "\n";
	s += "Pre-made Item: " + name + "\n";
	s += "Price: $" + to_string(this->getPrice()).substr(0,4) + "\n";
	return s;
}

double PreMadeItem::getPrice() {
	return this->price;
} 

PreMadeItem::PreMadeItem(string name, string size) : IceCreamItem(size) {
	this->name = name;
	if(size == "small")
		this->price = 4.00;
	else if(size == "medium")
		this->price = 6.00;
	else
		this->price = 7.50;
}

PreMadeItem::~PreMadeItem() {

}
