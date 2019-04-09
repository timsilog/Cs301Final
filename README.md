# Cs301Final

Some linked lists and a queue. All .h files are filled out, but the .cpp files need to be completed! Let me know what you guys think!

## The 'Item' object

The project will revolve around the `Item` object which will simply contain the `name` of an item and its `price`. For example:

```
Item burger = new Item("burger", 3.99);
cout << burger.getName() << endl; // prints "burger"
cout << "$" << burger.getPrice() << endl; // prints "$3.99"
```

This will allow us to create menu items at our own discretion. 

## The 'Order' object

A representation of when you order something at a restaurant. Basically exactly what you'd see on your receipt. An `Order` contains a linked list of `Item`s. It also has an order number so the customer knows when they're up, as well as a subtotal price.

```
Item item1 = Item("burger", 3.99);
Item item2 = Item("fries", 1.99);
Order order;

order.addItem(item1);
order.addItem(item2);
order.printReceipt(); // prints the burgers and fries

```

## The 'OrderQueue' class

This will be the engine that controls everything! The `OrderQueue` will contain a queue (linked list) of `Order` objects which is what the chefs will see so they know what order to fulfill next. Adding an order goes to the back of the queue and fulfilling an order pops it off the front. It will also have the ability to remove items from the center in case a chef finishes an order early!

It will also contain an array of zeros and ones to represent the "order numbers". It will initialize to all zeroes. When an order number is issued, that index will be set to 1. For example if I order a burger and my receipt says I'm order #5, then `orderNumbers[5]` would be set to `1`. Once the order is fulfilled it'll be set back to `0` again. Once the order numbers reach the end, it'll wrap back around to the beginning again. So if the max size is 100, and I'm customer #99, the next customer would be #0 again! Works like that at In n' Out, right?

## The 'Menu' class

This will act as a sort of "database" of `Item`s. The `Menu` class will contain a Vector of `Item`s that will represent our restaurant menu. A vector is simply an array without a fixed size that will allow us to add more elements as we please! The menu will be naturally unsorted and have the ability to spit out `Item`s at will. This will be used to add `Item`s to `Order` objects before the `Order`s are added to the `OrderQueue`.

#### Why a Vector?

Our restaurant menu could be any size! Maybe the folks had a meeting last Monday and decided they wanted to add tacos to our burger menu. Adding elements to a Vector eliminates the need to reallocate the size of an array, the same benefit as a linked list! 
Accessing an element in a Vector is O(1) time. For example if the burger is the 5th element of Vector `v`, we'd find it with `v[4]`. The same benefit as an array! In a linked list finding the burger would be O(n) time where we start at the head and traverse down the list until we find the burger.

#### A natural problem

Removing an element from the center of a Vector poses the issue that it is O(n) time where we remove the element then shift all the rest down. It would be O(1) to remove an item from a linked list. If we decided we didn't want tacos anymore and just burgers we'd need to be able to remove them quickly! To make this O(1) I sort of swap the last element in the vector with the element to be deleted, then pop off the end of the vector. Since removing from the center causes everything to shift down one element and to all receive new indices, I figured doing this "swap" is okay since it only changes the index of 1 element rather than a bunch.