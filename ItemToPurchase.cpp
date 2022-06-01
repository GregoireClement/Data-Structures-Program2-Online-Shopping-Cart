#include <iostream>
#include <string>
using namespace std;

#include "ItemToPurchase.h"

//Default Constructor
ItemToPurchase::ItemToPurchase()
{
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}

//Parametrized constructor
ItemToPurchase::ItemToPurchase(string name, string description, double price, int quantity)
{
    itemName = name;
    itemDescription = description;
    itemPrice = price;
    itemQuantity = quantity;
}

//Definition of SetName
void ItemToPurchase::SetName(string name) {
    itemName = name;
}
//Definition of GetName
string ItemToPurchase::GetName() {
    return itemName;
}

//Definition of SetPrice
void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}
//Definition of GetPrice
double ItemToPurchase::GetPrice() {
    return itemPrice;
}

//Definition of SetQuantity
void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}
//Definition of GetQuantity
int ItemToPurchase::GetQuantity() {
    return itemQuantity;
}
//Definition of SetDescription
void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}
//Definition of GetDescription
string ItemToPurchase::GetDescription() {
    return itemDescription;
}
//Definition of print item cost
void ItemToPurchase::PrintItemCost() {
    cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity * itemPrice << endl;
}
//definition of print item description
void ItemToPurchase::PrintItemDescription() {
    cout << itemName << ": " << itemDescription << endl;
}

//Destroyer
ItemToPurchase::~ItemToPurchase() {}
