#ifndef SHOPPING_CART
#define SHOPPING_CART
#include "ItemToPurchase.h"
#include <vector>
#include<string>
using namespace std;

class ShoppingCart
{
private://private members
	string CustomerName;
	string CurrentDate;
	vector<ItemToPurchase>CartItems;

public://public members
	ShoppingCart(string name, string date);
	ShoppingCart();
	~ShoppingCart();
	void AddItem(ItemToPurchase item);
	void RemoveItem(ItemToPurchase item);
	void ModifyItem(ItemToPurchase item);
	string GetCustomerName();
	string GetDate();
	void SetDate(string date);
	int GetNumItemsInCart();
	int GetCostOfCart();
	void PrintTotal();
	void PrintDescriptions();
};

#endif