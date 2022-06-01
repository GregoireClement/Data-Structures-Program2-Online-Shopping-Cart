#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "ShoppingCart.h"
#include "ItemToPurchase.h"

//Default Constructor
ShoppingCart::ShoppingCart()
{
    CustomerName = "none";
    CurrentDate = "January 1, 2016";
}

//Parametrized constructor
ShoppingCart::ShoppingCart(string name, string date)
{
    CustomerName = name;
    CurrentDate = date;
}

//Destructor
ShoppingCart::~ShoppingCart() {}

//Get customer Name function
string ShoppingCart::GetCustomerName() {
    return CustomerName;
}

//get date function
string ShoppingCart::GetDate() {
    return CurrentDate;
}


//Add item function
void ShoppingCart::AddItem(ItemToPurchase item) {
    CartItems.push_back(item);
}
//remove item function
void ShoppingCart::RemoveItem(ItemToPurchase item) {
    int counter = -1;
    for (unsigned int i = 0; i < CartItems.size(); i++) {
        if (CartItems.at(i).GetName() == item.GetName()) {
            CartItems.erase(CartItems.begin() + i);
            counter++;
        }
    }
    if (counter < 0) {
        cout << "Item not found in cart. Nothing removed." << endl;
    }
}

//Modify item function
void ShoppingCart::ModifyItem(ItemToPurchase item) {
    int counter = -1;
    for (unsigned int i = 0; i < CartItems.size(); i++) {
        if (item.GetName() == CartItems.at(i).GetName()) {
            CartItems.at(i).SetQuantity(item.GetQuantity());
            counter++;
        }
    }
    if (counter < 0) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}

//get number of items in cart function
int ShoppingCart::GetNumItemsInCart() {
    return CartItems.size();
}


//Get cost of cart function
int ShoppingCart::GetCostOfCart() {
    int totalCost = 0;
    for (unsigned int i = 0; i < CartItems.size(); i++) {
        totalCost = totalCost + (CartItems.at(i).GetPrice() * CartItems.at(i).GetQuantity());
    }
    return totalCost;
}

// Print description items in cart
void ShoppingCart::PrintDescriptions() {
    cout << CustomerName << "'s Shopping Cart - " << CurrentDate << endl << endl;
    cout << "Item Descriptions" << endl;
    for (unsigned int i = 0; i < CartItems.size();i++) {
        CartItems.at(i).PrintItemDescription();
    }
}

//Print total function
void ShoppingCart::PrintTotal() {
    int totalCost = this->GetCostOfCart();
    int numberOfItems = 0;
    if (totalCost == 0) {
        cout << CustomerName << "'s Shopping Cart -" << CurrentDate << endl;
        cout << "Number of Items: " << CartItems.size() << endl << endl;
        cout << "SHOPPING CART IS EMPTY" << endl << endl;
        cout << "Total: $" << totalCost << endl;
    }
    else {
        cout << CustomerName << "'s Shopping Cart -" << CurrentDate << endl;
        for (unsigned int i = 0; i < CartItems.size();i++) {
            numberOfItems = numberOfItems + (CartItems.at(i).GetQuantity());
        }
        cout << "Number of Items: " << numberOfItems << endl << endl;
        for (unsigned int i = 0; i < CartItems.size(); i++) {
            CartItems.at(i).PrintItemCost();
        }
        cout << endl;
        cout << "Total: $" << totalCost << endl;
    }
}


