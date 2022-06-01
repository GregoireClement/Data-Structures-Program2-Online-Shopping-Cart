#include <iostream>
#include <string>
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <string>
using namespace std;

void printMenu(ShoppingCart cart1) {
    char userInput;
    string itemName;
    string itemDescription;
    double itemPrice;
    int itemQuantity;
    while (userInput != 'q') {
        cout << "MENU" << endl;
        cout << "a - Add item to cart" << endl;
        cout << "d - Remove item from cart" << endl;
        cout << "c - Change item quantity" << endl;
        cout << "i - Output items' descriptions" << endl;
        cout << "o - Output shopping cart" << endl;
        cout << "q - Quit" << endl << endl;
        userInput = ' ';
        while (userInput != 'o' && userInput != 'i' && userInput != 'c' && userInput != 'd' && userInput != 'a' && userInput != 'q') {
            cout << "Choose an option:" << endl;
            cin >> userInput;
        }
        switch (userInput) {
        case 'a': {
            cout << "ADD ITEM TO CART" << endl;
            cin.ignore();
            cout << "Enter the item name:" << endl;
            getline(cin, itemName);
            cout << "Enter the item description:" << endl;
            getline(cin, itemDescription);
            cout << "Enter the item price:" << endl;
            cin >> itemPrice;
            cout << "Enter the item quantity:" << endl << endl;
            cin >> itemQuantity;
            ItemToPurchase item1(itemName, itemDescription, itemPrice, itemQuantity);
            cart1.AddItem(item1);
            break;
        }
        case 'd': {
            cout << "REMOVE ITEM FROM CART" << endl;
            cout << "Enter name of item to remove:" << endl << endl;
            cin.ignore();
            getline(cin, itemName);
            ItemToPurchase item1;
            item1.SetName(itemName);
            cart1.RemoveItem(item1);
            break;
        }
        case 'c': {
            ItemToPurchase item1;
            cout << "CHANGE ITEM QUANTITY" << endl;
            cout << "Enter the item name:" << endl << endl;
            cin.ignore();
            getline(cin, itemName);
            cout << "Enter the new quantity:" << endl;
            cin >> itemQuantity;
            item1.SetName(itemName);
            item1.SetQuantity(itemQuantity);
            cart1.ModifyItem(item1);
            break;
        }
        case'i': {
            cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
            cart1.PrintDescriptions();
            break;
        }
        case'o': {
            cout << "OUTPUT SHOPPING CART" << endl << endl;
            cart1.PrintTotal();
            break;
        }
        case'q':
            break;

        default:
            break;
        }
    }
}

int main()
{
    string CustomerName;
    string CurrentDate;

    cout << "Enter customer's name: " << endl;
    getline(cin, CustomerName);
    cout << "Enter today's date: " << endl << endl;
    getline(cin, CurrentDate);
    ShoppingCart cart1 = ShoppingCart(CustomerName, CurrentDate);
    cout << "Customer name: " << cart1.GetCustomerName() << endl;
    cout << "Today's date: " << cart1.GetDate() << endl;
    printMenu(cart1);
    return 0;
}