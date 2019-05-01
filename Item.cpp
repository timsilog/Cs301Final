#include "Item.h"

// Constructors
Item::Item() { // Default constructor
    // set a generic name and price of $0.00
}

Item::Item(std::string name, double price) { // normal constructor

}

void Item::setName(std::string newName) {

}

void Item::setPrice(double price) {

}

std::string Item::getName() {

}

double Item::getPrice() {

}

void Item::printItem() {
    
}

bool Item::operator==(Item rhs) {
    if (rhs.getName() == name && rhs.getPrice() == price)
        return true;
    return false;
}