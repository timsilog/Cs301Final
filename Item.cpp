#include "Item.h"
#include <iostream>

// Constructors
Item::Item() { // Default constructor
	name = " "; // set a generic name and price of $0.00
	price = 0;
}

Item::Item(std::string name, double price) { // normal constructor
	name = name;
	price = price;
}

void Item::setName(std::string newName) {
	name = newName;
}

void Item::setPrice(double newPrice) {
	price = newPrice;
}

std::string Item::getName() {
	return name;
}

double Item::getPrice() {
	return price;
}


// FIX THIS
void Item::printItem() {
	std::cout << " name" << name << "price" << price << std::endl;
}

bool Item::operator==(Item const rhs) {
	if (name == rhs.name && price == rhs.price) {
		return true;
	}
	return false;
}