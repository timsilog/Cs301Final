#include "Order.h"

// Default constructor
Order::Order() {
    // set all numbers to 0 and ItemLists to null
}

// Normal constructor
Order::Order(int orderNum) {
    // same as default constructor except 'orderNum'
}

// Destructor
Order::~Order() {
    // deallocate 'ItemList *items' here
}

void Order::addItem(Item addMe) {
    // increment 'size' and add to 'subtotal'
    // add 'addMe' to list
}

void Order::removeItem(Item removeMe) {
    // traverse list 'items' until 'removeMe' is found
    // then decrement size and subtract from subtotal
    // then remove the item
    // ignore all this if item isn't found
}

void Order::removeAllItems() {
    // same as destructor!
}

void Order::resetCurrentItem() {
    // reset 'currentItem' pointer to null
}

void Order::setOrderNumber(int orderId) {
    // set 'orderNumber' to 'orderId'
}

bool Order::containsItem(Item checkMe) {
    // traverse list and return true if item is found
}

int Order::getOrderNumber() {
    // return the 'orderNumber'
}

int Order::getSize() {
    // return the size
}

double Order::getSubtotal() {
    // return the subtotal
}

void Order::printReceipt() {
    // Come up with a fancy way to print all the
    // items, their prices, and the subtotal!
}

Item Order::getNextItem() {
    // increment 'currentItem' pointer and return the item inside!
}