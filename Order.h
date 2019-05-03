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
	double      subtotal;
    ItemList*   cloneList(ItemList *list); // O(n)

public:
	Order();
	Order(int orderNum);
	~Order();
	void    addItem(Item addMe);
	void    removeItem(Item removeMe); // O(n)
	void    removeAllItems(); // O(n)
	void    resetCurrentItem();
	void    setOrderNumber(int orderId);
	bool    containsItem(Item checkMe); // O(n)
	int     getOrderNumber();
	int     getSize();
	double  getSubtotal();
	void    printReceipt(); // O(n)
	Item    getNextItem();
    Order&  operator=(Order const &rhs); // O(n)
};

#endif
