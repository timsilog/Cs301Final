#include "Menu.h"
#include <string>
#include <iostream>
#include <fstream>

void Menu::addItem(std::string name, double price) {
    Item item = Item(name, price);
    data.push_back(item);
}

void Menu::addItem(Item item) {
    data.push_back(item);
}

// Sets current item to last item, then removes last item
// This avoids the O(n) time required for vector.erase()
// Removes first occurance of 'name' or nothing
void Menu::removeItem(std::string name) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i].getName() == name) {
            data[i] = data[data.size() - 1];
            data.pop_back();
            return;
        }
    }
}

// Removes first occurance of 'item' or nothing
void Menu::removeItem(Item item) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == item) {
            data[i] = data[data.size() - 1];
            data.pop_back();
            return;
        }
    }
}

void Menu::removeItem(int index) {
    if (index >= data.size()) {
        throw "ERROR: Index to remove doesn't exist!\n";
    }
    data[index] = data[data.size() - 1];
    data.pop_back();
}

void Menu::adjustItem(int index, std::string newName, double newPrice) {
    data[index].setName(newName);
    data[index].setPrice(newPrice);
}

// In case someone wants to sort their menu
void Menu::swapItems(int index1, int index2) {
    Item temp;

    if (index1 >= data.size() || index2 >= data.size()) {
        throw "ERROR: One of the provided indexes don't exist!\n";
    }
    temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}

void Menu::printMenu() {
    std::cout << "\nMENU\n";
    for (int i = 0; i < data.size(); i++) {
        std::cout << i + 1 << ". ";
        data[i].printItem();
        std::cout << std::endl;
    }
}

// Adds all items from file to current menu
void Menu::loadMenu(std::string inFile) {
    std::ifstream file;
    std::string line, name;
    double price;

    file.open(inFile);
    if (!file) {
        throw "ERROR: Couldn't open filename: " + inFile + '\n';
    }
    while (file >> name >> price) {
        addItem(name, price);
    }
}

void Menu::saveMenu() {
    std::ofstream file;

    file.open("menuDb.txt");
    for (int i = 0; i < data.size(); i++) {
        file << data[i].getName() << ' ' << data[i].getPrice() << '\n';
    }
}

Item Menu::getItem(int index) {
    if (index < 0 || index >= data.size()) {
        throw "ERROR: Index out of bounds (E.G. < 0 or >= size";
    }

    return data[index];
}

// returns index of item or -1 if it can't find anything
int Menu::findItem(Item item) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == item) {
            return i;
        }
    }
    return -1;
}

int Menu::getSize() {
    return data.size();
}