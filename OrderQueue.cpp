#include "OrderQueue.h"

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
void OrderQueue::addOrder(Order addMe) {
	OrderList* location;
	location = new OrderList;

    if (!addMe.getOrderNumber()) {
        addMe.setOrderNumber(issueOrderNumber());
    }
	location->data = addMe;
	back->next = location ;
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
}


void OrderQueue::printOrders() {
	OrderList* temp;
	while (temp) {
		temp->data.printReceipt();
        // std::cout << "\n";
		temp = temp->next;
	}
}

// dequeue
Order OrderQueue::completeOrder() {
	OrderList *temp;
	Order order;
	temp = orders;
	orders = orders->next;
	order = temp->data;
	delete temp;
	return order;
}

// To remove an order at specific index.
// Throws if index is out of bounds
Order OrderQueue::completeOrder(int indexToDelete) {
	OrderList *temp;
	OrderList *toDelete;
	Order toReturn;
	temp = orders;
	int i = 0;

	if (indexToDelete < 0 || indexToDelete >= size)
		return NULL;

	if (i == indexToDelete) {
		temp = orders;
		orders = orders->next;
		size--;
		toReturn = temp->data;
		delete temp;
		return toReturn;
	}
	i++;
	while (temp->next != NULL) {
		if (i == indexToDelete) {
			size--;

			toDelete = temp->next;
			toReturn = toDelete->data;
			temp->next = temp->next->next;
			delete toDelete;
			return toReturn;
		}
		i++;
		temp = temp->next;
	}
	
}

// front
Order OrderQueue::getCurrentOrder() {
	return orders->data;
}

// back
Order OrderQueue::getRecentOrder() {
	return back->data;
}