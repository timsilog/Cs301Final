#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item {
    private:
        std::string name;
        double price;

    public:
        Item();
        Item(std::string name, double price);
        void setName(std::string newName);
        void setPrice(double price);
        std::string getName();
        double getPrice();
        void printItem();

        // operator overload function
        bool operator==(Item rhs);
};

#endif