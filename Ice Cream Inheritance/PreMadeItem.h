// PreMadeItem.h

#ifndef PREMADEITEM_H
#define PREMADEITEM_H

#include <string>
#include "IceCreamItem.h"

class PreMadeItem : public IceCreamItem {
public:
	std::string composeItem();
	double getPrice();
	PreMadeItem(std::string name, std::string size);
	virtual ~PreMadeItem();
protected: 
	std::string name;
	double price;
};

#endif