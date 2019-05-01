#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H
#include "Order.h"

struct OrderList {
    Order *data;
    OrderList *next;
};

class OrderQueue {
    private:
        OrderList *orders; // front
        OrderList *back; // back
        int latestOrderNumber;
        int maxSize;
        int size;
        int orderNumbers[];

    public:
        OrderQueue();
        OrderQueue(int queueSize);
        ~OrderQueue();
        int     issueOrderNumber();
        int     getSize();
        void    addOrder(Order addMe, bool needsId = false); //push
        void    removeAllOrders();
        void    removeOrder(Order removeMe);
        void    printOrders();
        Item    completeOrder(); //pop
        Item    completeOrder(int orderNumber);
        Order   getCurrentOrder(); // front
        Order   getRecentOrder(); // back
};

#endif