#ifndef ORDER_H
#define ORDER_H
#include "Item.h"

struct ItemList {
    Item data;
    ItemList *next;
};

class Order {
    private:
        int         orderNumber;
        int         size;
        ItemList    *items; // front of list
        ItemList    *currentItem; // pointer for getNextItem()
        double      subtotal; // sum of all prices

    public:
        Order();
        Order(int orderNum);
        ~Order(); // destructor to deallocate ItemList
        void    addItem(Item addMe);
        void    removeItem(Item removeMe);
        void    removeAllItems();
        void    resetCurrentItem();
        void    setOrderNumber(int orderId);
        bool    containsItem(Item checkMe); // maybe
        int     getOrderNumber();
        int     getSize();
        double  getSubtotal();
        void    printReceipt();
        Item    getNextItem();
};

#endif