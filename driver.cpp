#include <iostream>
#include <fstream>
#include "Menu.h"
#include "OrderQueue.h"

using namespace std;

void goToBack(Menu &menu, OrderQueue &orders);
void goToFront(Menu &menu, OrderQueue &orders);
void manageMenu(Menu &menu);
void manageOrders(OrderQueue &orders);

int main(int argc, char **argv) {
    bool done = false;
    ifstream ifile;
    Menu menu;
    OrderQueue orders;
    int option;

    if (argc == 2) {
        try {
            menu.loadMenu(argv[1]);
        } catch (string err) {
            cout << err << endl;
            return -1;
        }
    }
    while (!done) {
        cout << "::ADMIN PANEL::\n"
             << "1. BACK END\n"
             << "2. FRONT END\n"
             << "3. EXIT\n";
        cin >> option;
        switch (option) {
            case 1:
                goToBack(menu, orders);
                break;
            case 2:
                goToFront(menu, orders);
                break;
            case 3:
                done = true;
                break;
            default:
                cout << "Sorry I didn't understand that option!\n";
                break;
        }
    }
}

void startOrder(Menu &menu, OrderQueue &orders) {
    int option;
    bool done = false;

    while (!done) {
        menu.printMenu();

    }
}

void goToFront(Menu &menu, OrderQueue &orders) {
    int option;
    bool done = false;

    while (!done) {
        cout << "::ARTA'S BURGERS POS::"
             << "1. Start a new order\n"
             << "2. See all orders\n"
             << "3. Go back\n";
        cin >> option;
        switch (option) {
            case 1:
                startOrder(menu, orders);
                break;
            case 2:
                orders.printOrders();
                break;
            case 3:
                done = true;
                break;
            default:
                cout << "Sorry I didn't understand that option!\n";
        }
    }
}

void goToBack(Menu &menu, OrderQueue &orders) {
    int option;
    bool done = false;

    while (!done) {
        cout << "::BACK END::\n"
             << "1. Manage Menu\n"
             << "2. Manage Orders\n"
             << "3. Go back\n";
        cin >> option;
        switch (option) {
            case 1:
                manageMenu(menu);
                break;
            case 2:
                manageOrders(orders);
                break;
            case 3:
                done = true;
                break;
            default:
                cout << "Sorry I didn't understand that option!\n";
                break;
        }
    }
}

void manageMenu(Menu &menu) {
    int option, index = -1;
    string name;
    double price;
    bool done = false;

    while (!done) {
        cout << "::MANAGE MENU::\n"
             << "1. See Menu\n"
             << "2. Add Item\n"
             << "3. Remove Item\n"
             << "4. Adjust Item\n"
             << "5. Save Changes\n"
             << "6. Go Back\n";
        cin >> option;
        switch (option) {
            case 1:
                // menu.printMenu();
                cout << menu.getSize();
                break;
            case 2:
                cout << "Enter new item name: ";
                cin >> name;
                cout << "Enter item price: ";
                cin >> price;
                menu.addItem(Item(name, price));
                cout << "Successfully added new item: " << name << ": $" << price << endl;
                break;
            case 3:
                if (!menu.getSize()) {
                    cout << "Error: Menu is empty!\n";
                    break;
                }
                while (index < 0) {
                    cout << "Enter index: ";
                    cin >> index;
                    if (index >= menu.getSize()) {
                        cout << "Error: Invalid index!\n";
                        index = -1;
                    }
                }
                menu.removeItem(index);
                index = -1;
                cout << "Successfully removed item at index [" << index << "]\n";
                break;
            case 4:
                if (!menu.getSize()) {
                    cout << "Error: Menu is empty!\n";
                    break;
                }
                while (index < 0) {
                    cout << "Enter index to be adjusted: ";
                    cin >> index;
                    if (index >= menu.getSize()) {
                        cout << "Error: Invalid index!\n";
                        index = -1;
                    }
                }
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new price: ";
                cin >> price;
                menu.adjustItem(index, name, price);
                index = -1;
                cout << "Successfully edited item at index [" << index << "]\n";
                break;
            case 5:
                menu.saveMenu();
                cout << "Successfully saved changes!\n";
                break;
            case 6:
                done = true;
                break;
            default:
                cout << "Sorry I didn't understand that option!\n";
                break;
        }
    }
}

void manageOrders(OrderQueue &orders) {
    bool done = false;
    int option, index = -1;

    while (!done) {
        cout << "::MANAGE ORDERS::\n"
             << "1. See all orders\n"
             << "2. Remove an order\n"
             << "3. Clear all orders\n"
             << "4. Go back\n";
        cin >> option;
        switch (option) {
            case 1:
                orders.printOrders();
            case 2:
                if (!orders.getSize()) {
                    cout << "Error: OrderQueue is empty!\n";
                    break;
                }
                while (index < 0) {
                    cout << "Enter index: ";
                    cin >> index;
                    if (index >= orders.getSize() || index < 0) {
                        cout << "Error: Invalid index!\n";
                        index = -1;
                    }
                }
                orders.completeOrder(index);
                index = -1;
                cout << "Successfully removed item at index [" << index << "]\n";
                break;
            case 3:
                orders.removeAllOrders();
                cout << "Successfully remove all items from Order List.\n";
                break;
            case 4:
                done = true;
                break;
            default:
                cout << "Sorry I didn't understand that option!\n";
                break;
        }
    }
}