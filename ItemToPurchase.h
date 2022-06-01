#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H
#include <iostream>
#include <string>
using namespace std;

class ItemToPurchase {
private: // private data members
	string itemName;
	string itemDescription;
	double itemPrice;
	int itemQuantity;

public:// public data members
	ItemToPurchase(); // default constructor
	ItemToPurchase(string name, string description, double itemPrice, int itemQuantity);//parametrized constructor
	~ItemToPurchase();

	void SetName(string name);// mutator and accessor for name
	string GetName();

	void SetPrice(double price);//mutator and accessor for price
	double GetPrice();

	void SetQuantity(int quantity);//mutator and accessor for quantity
	int GetQuantity();

	void SetDescription(string description);
	string GetDescription();


	void PrintItemCost();
	void PrintItemDescription();
};

#endif