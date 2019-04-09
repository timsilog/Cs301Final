#include "OrderQueue.h"

// Default constructor
OrderQueue::OrderQueue() {
    // set list to null and maxSize to some default number
    // like 100 and allocate that much space to the array
    // then set all elements of that array to 0
}

// Normal constructor
OrderQueue::OrderQueue(int queueSize) {
    // same as above except use queueSize instead of 100
}

// Destructor
OrderQueue::~OrderQueue() {
    // deallocate the list and the orderNumbers
}

int OrderQueue::issueOrderNumber() {
    // return the next orderNumber in the array
    // set it to 1, and return that index
    // if at end of array, start from beginning again
    // throw if full
}

void OrderQueue::addOrder(Order addMe, bool needsId = false) {
    // give addMe an orderId if it needs one
    // then add it to the back of the queue
}

void OrderQueue::removeAllOrders() {
    // get rid of 'em all!
}

void OrderQueue::removeOrder(Order removeMe) {
    // traverse the list until 'removeMe' is found
}

void OrderQueue::printOrders() {
    // print the queue
}

Item OrderQueue::completeOrder() {
    // pop the front and set its orderNumber to 0
}

Item OrderQueue::completeOrder(int orderNumber) {
    // traverse the list until 'orderNumber' is found
    // and remove it. set its orderNumber to 0
}

Order getCurrentOrder() {
    // return the front
}

Order getRecentOrder() {
    // return the back
}