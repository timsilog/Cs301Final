#include "Order.h"
#include<iostream>
#include<string>
using namespace std; 

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
	ItemList* temp;
	
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
	// Come up with a fancy way to print all the
	// items, their prices, and the subtotal!
	ItemList* temp; 
	while (temp) {

		temp->data.printItem();
		temp = temp->next;
	}
	cout << "subtotal" << subtotal << endl;
}

Item Order::getNextItem() {
	currentItem++;
	return currentItem->data; 
}