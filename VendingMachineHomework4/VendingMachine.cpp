#include "VendingMachine.h"
#include <iostream>
#include <string>

using namespace std;
namespace vndm {

	//Homework 4: 
//Continue the vending machine and use structs and vectors instead 
//of arrays.
//use a menu using Enums with the following points:
/*
Add new Product.
Sort Products.
Display Products.
Exit

*/


	void Init()
	{
		MainMenu();
		while (currentSelection!= Exit)
		{
			switch (currentSelection)
			{
			case AddNewProduct:
				InsertProducts();
				break;
			case SortProducts:
				BubbleSortArray();
				break;
			case DisplayProducts:
				PromptProducts();
				break;
			case Exit:
				cout << "jajajaja";
				currentSelection = Exit;
				break;
			default:
				currentSelection = Exit;
				break;
			}
			MainMenu();
		}
	}
	void MainMenu()
	{
		cout << "Hi there! " << endl;
		cout << "Pick an option from the menu:" << endl;
		cout << "1. Add a new product \n";
		cout << "2. Sort the products in Bubble sort \n";
		cout << "3. Display the products \n";
		cout << "4. Exit\n";
		cin >> currentSelection;
		cin.ignore();
		cout << "\n";
	}
	void InsertProducts()
	{
		Product product;
		cout << "Insert the name of the product:\n";
		getline(cin, product.Name);
		cout << "Insert the price of the product:\n";
		cin >> product.Price;
		cin.ignore();
		products.push_back(product);
	};
	void PromptProducts()
	{
		if (products.size() > 0)
		{
			cout << "here's the list of current products: \n";
			for (auto product : products)
			{
				cout << "Product Name: " << product.Name << "\n";
				cout << "Product Price: " << product.Price << "\n";
			}
		}
		else
		{
			cout << "There are not products to show right now! :/\n\n";
		}
	}

}
namespace
{
	void BubbleSortArray()
	{
		int counter = 0;
		if (products.size() <= 0)
		{
			cout << "There are not products to sort\n\n";
			return;
		}

		for (counter = 0; counter < products.size(); counter++)
		{
			if ((counter+1)< products.size())
			if (products[counter].Price > products[counter + 1].Price)
			{
				swap(products[counter], products[counter + 1]);
				////Let's perform a swap.
				//auto tempProduct = products[counter + 1];
				//products[counter + 1] = products[counter];
				//products[counter] = tempProduct;
				counter = -1;
				continue;
			}
			continue;
		}

	}
	void FinishBuy()
	{
		userHasFinishedBuying = true;
	}
	void AskClientMoney()
	{
		cout << "Welcome, Mr. Client, how much money do you have?: " << endl;
		cin >> clientMoney;
	}
}


