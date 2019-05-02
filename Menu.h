#ifndef MENU_H
#define MENU_H
#include "Item.h"
#include <vector>

class Menu {
    private:
        std::vector<Item> data;
    public:
        void addItem(std::string name, double price);
        void addItem(Item item);
        void removeItem(std::string name);
        void removeItem(Item item);
        void removeItem(int index);
        void adjustItem(int index, std::string newName, double newPrice);
        void swapItems(int index1, int index2);
        void printMenu();
        void loadMenu(std::string inFile);
        void saveMenu();
        int findItem(Item item);
        int getSize();
};

#endif