#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H
#include "Order.h"

struct OrderList {
    Order data;
    OrderList *next;
};

class OrderQueue {
    private:
        OrderList *orders; // front
        OrderList *back; // back
        int latestOrderNumber;
        int maxSize;
        int size;
        int currentOrder;

    public:
        OrderQueue();
        OrderQueue(int queueSize);
        ~OrderQueue();
        int     issueOrderNumber();
        int     getSize();
        void    addOrder(Order &addMe); // enqueue
        void    removeAllOrders(); // O(n)
        void    printOrders(); // O(n)
        Order*  completeOrder(); // dequeue
        Order*  completeOrder(int indexToDelete); // O(n)
        Order   getCurrentOrder(); // front
        Order   getRecentOrder(); // back
};

#endif