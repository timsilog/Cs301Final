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
        void    addOrder(Order &addMe); //push
        void    removeAllOrders();
        void    printOrders();
        Order*   completeOrder(); //pop
        Order*   completeOrder(int indexToDelete);
        Order   getCurrentOrder(); // front
        Order   getRecentOrder(); // back
        
};

#endif