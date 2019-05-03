#include "OrderQueue.h"
#include <iostream>
// Default constructor
OrderQueue::OrderQueue() {
	orders = NULL; // front
	back = NULL; // back
    latestOrderNumber=0;
	maxSize = 200;
	size=0;
    currentOrder = 0;
}

// Normal constructor
OrderQueue::OrderQueue(int queueSize) {
	orders = NULL; // front
	back = NULL; // back
	latestOrderNumber = 0;
	maxSize = queueSize;
	size = 0;
    currentOrder = 0;
}

// Destructor
OrderQueue::~OrderQueue() {
	OrderList *temp;

	while (orders) {
		temp = orders;                   // O (n)
		orders = orders->next;
		delete  temp;
	}
    orders = nullptr;
}

int OrderQueue::issueOrderNumber() {
    currentOrder++;
    if (currentOrder > maxSize) {
        currentOrder = 1;
    }
    return currentOrder;
}

int OrderQueue::getSize() {
	return size;
}

// enqueue
void OrderQueue::addOrder(Order &addMe) {
	OrderList* location = new OrderList();

    if (!addMe.getOrderNumber()) {
        addMe.setOrderNumber(issueOrderNumber());
    }
	location->data = addMe;
    location->next = nullptr;
    if (back) {
        back->next = location;
    } else {
        orders = location;
    }
	back = location;
	size++;
}

void OrderQueue::removeAllOrders() {
	OrderList *temp;

	while (orders) {
		temp = orders;                   // O (n)
		orders = orders->next;
		delete  temp;
	}
    orders = nullptr;
    back = nullptr;
    currentOrder = 0;
}


void OrderQueue::printOrders() {
	OrderList* temp = orders;
	while (temp) {
		temp->data.printReceipt();
        std::cout << '\n';
		temp = temp->next;
	}
}

// dequeue
Order* OrderQueue::completeOrder() {
	OrderList *temp;
	Order* order = new Order();
	temp = orders;
	orders = orders->next;
	*order = temp->data;
	delete temp;
    if (!orders) {
        back = nullptr;
    }
	return order;
}

// To remove an order at specific index.
// Throws if index is out of bounds
Order* OrderQueue::completeOrder(int indexToDelete) {
	OrderList *temp;
	OrderList *toDelete;
	Order *toReturn = new Order();
	temp = orders;
	int i = 0;

	if (indexToDelete < 0 || indexToDelete >= size) {
		throw "Index attempting to delete is out of bounds (E.G. < 0 or >= size)";
    }

	if (i == indexToDelete) {
		temp = orders;
		orders = orders->next;
		size--;
		*toReturn = temp->data;
		delete temp;
        if (!orders) {
            back = nullptr;
        }
		return toReturn;
	}
	i++;
	while (temp->next != NULL) {
		if (i == indexToDelete) {
			size--;
            
			toDelete = temp->next;
			*toReturn = toDelete->data;
			temp->next = temp->next->next;
            if (!temp->next) {
                back = temp;
            }
			delete toDelete;
			return toReturn;
		}
		i++;
		temp = temp->next;
	}
    // compiles with warning without return statement,
    // but shouldn't ever get this far
    return toReturn;
}

// front
Order OrderQueue::getCurrentOrder() {
	return orders->data;
}

// back
Order OrderQueue::getRecentOrder() {
	return back->data;
}