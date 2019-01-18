// CustomItem.h

#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <string>
#include <map>
#include "IceCreamItem.h"

class CustomItem : public IceCreamItem {
public:
	CustomItem(std::string size);
	std::string composeItem();
	double getPrice();
	virtual ~CustomItem();
	void addTopping(std::string topping);
protected: 
	double price;
	std::map <std::string, int> toppings;
};



#endif