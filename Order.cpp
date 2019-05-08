#include "Order.h"
#include<iostream>
#include<string>

// Default constructor
Order::Order() {
	orderNumber = 0; 
	size = 0;
	items = NULL;
	currentItem = NULL;
	subtotal = 0; 
}

// Normal constructor
Order::Order(int orderNum) {
	orderNum = orderNum;
    size = 0;
    items = NULL;
    currentItem = NULL;
    subtotal = 0;
}

// Destructor
Order::~Order() {
    removeAllItems();
}

void Order::addItem(Item addMe) {
	ItemList* location; 
	location = new ItemList;
	location->data = addMe;
	location->next = items;
	items = location;
	size++; 
	subtotal += addMe.getPrice();
}

void Order::removeItem(Item removeMe) {
	ItemList* temp = items;
	ItemList* toDelete; // holder to delete an Item

	if (temp->data == removeMe) {
		size--;
		subtotal -= removeMe.getPrice();
		items = temp->next;
		delete temp;
		return;
	}

	while (temp->next != NULL) {
		if (temp->next->data == removeMe) {
			size--;
			subtotal -= removeMe.getPrice();
			toDelete = temp->next;
			temp->next = temp->next->next;
			delete toDelete;
		}

		temp = temp->next; 
	}
}

void Order::removeAllItems() {
	ItemList *temp;

	while (items) {
		temp = items;                   // O (n)
		items = items->next;
		delete temp;
	}
}

// go back to the beginning for getNextItem()
void Order::resetCurrentItem() {
	currentItem = NULL;
}

void Order::setOrderNumber(int orderId) {
	orderNumber = orderId; 
}

bool Order::containsItem(Item checkMe) {
	ItemList* temp = items;
	
	while (temp->next != NULL) {
		if (temp->next->data == checkMe) {
			temp->next = temp->next->next;
			return true;
		}
	}
	return false;
}

int Order::getOrderNumber() {
	return orderNumber;
}

int Order::getSize() {
	return size;
}

double Order::getSubtotal() {
	return subtotal;
}

void Order::printReceipt() {
	ItemList* temp = items; 
    int i = 0;

    if (orderNumber) {
        std::cout << "Order #" << orderNumber << std::endl;
    } else {
        std::cout << "Current Order:\n";
    }
	while (temp) {
        std::cout << ++i << ". ";
		temp->data.printItem();
		temp = temp->next;
	}
	std::cout << "-----\nSubtotal: $" << subtotal << std::endl;
}

Item Order::getNextItem() {
	currentItem++;
	return currentItem->data; 
}

ItemList* Order::cloneList(ItemList *list) {
    if (!list) {
        return nullptr;
    }
    ItemList *temp = new ItemList();
    temp->data = list->data;
    temp->next = cloneList(list->next);
    return temp;
}

// copies with reset currentItem
Order& Order::operator=(Order const &rhs) {
    if (rhs.size) {
        orderNumber = rhs.orderNumber;
        size = rhs.size;
        currentItem = nullptr;
        subtotal = rhs.subtotal;
        items = cloneList(rhs.items);
    }
    return *this;
}