#include "VendingMachine.h"
#include <iostream>

using namespace std;
namespace vndm {

	void DisplayWelcomeMessage()
	{
		cout << "Hi there! The vending machine is empty, would you like to insert the products " << endl;
		cout << "that you will buy? LOL, yes that sounds dumb, but you must abide..." << endl;
		cin.ignore();
	}
	void InsertProducts()
	{
		for (int position = 0; position <sizeof(productPrices)/4; position++)
		{
			cout << "Insert the name of the " << position + 1 << " product" << endl;
			getline(cin, productNames[position]);
			cout << "Now insert the price of that product" << endl;
			cin >> productPrices[position];
			cin.ignore();
		}
		BubbleSortArray();
	};
	void PromptProducts()
	{
		AskClientMoney();
		if (clientMoney > 0)
		{
			while (userHasFinishedBuying == false)
			{
				if (userHasMoneyToPay)
				{
					cout << "Products" << endl;
					for (int j=0; j < sizeof(productPrices) / 4; j++)
					{
						cout << j+1 << "." << productNames[j] << ", price " << productPrices[j] << endl;
					}
					cout << "Please, enter the number of the product you'd wish to buy!" << endl;
					cin >> userChosenProduct;

					if(userHasFinishedBuying==false)
					BuyProducts();
				}
				else
				{
					//automatically we say that the user has finished buying because she finished it or
					//she doesn't have money to pay anyway, lol.
					FinishBuy();
					cout << "You don't have more money left or you canceled the buy, thanks for coming" << endl;
				}
			}
			cout << "Thanks for buying, now you have " << clientMoney << " left!" << endl;
		}
		else
		{
			cout << "Who are you trying to fool?" << endl;
		}
	}
	
}
namespace
{
	bool CheckArrayCompletion()
	{
		for (double item : productPrices)
		{
			if (item == -1)
				return false;
		}
		return true;
	}
	void BubbleSortArray()
	{
		int counter = 0;
		for (counter = 0; counter < sizeof(productPrices) / 4; counter++)
		{
			if (counter + 1 < sizeof(productPrices) / 4) //If counter + 1 is greater than 3 it'll crash...
				if (productPrices[counter] > productPrices[counter + 1])
				{
					//Let's perform a swap.
					auto tempPrice = productPrices[counter + 1];
					auto tempName = productNames[counter + 1];
					productPrices[counter + 1] = productPrices[counter];
					productPrices[counter] = tempPrice;

					productNames[counter + 1] = productNames[counter];
					productNames[counter] = tempName;
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
	bool CheckUserAffordanceForCurrentProduct()
	{
		if (clientMoney > productPrices[userChosenProduct - 1]){
			userHasMoneyToPay = true;
			return true;
		}
		else {
			userHasMoneyToPay = false;
			cout << "Come back when you have more money, those pennies won't afford our luxuries" << endl;
			return false;
		}
	}
	void BuyProducts()
	{
		if (userChosenProduct != -1)
		{
			//let's check if the client has enough money to buy in the first place.
			if (CheckUserAffordanceForCurrentProduct())
			{
				clientMoney = clientMoney - productPrices[userChosenProduct - 1];
				cout << "Okay Mr. Client, you bought " << productNames[userChosenProduct - 1] << "!" << endl;

				cout << "Your balance is now: " << clientMoney << endl;
				cout << "Do you wish to buy another item? y/n" << endl;
				cin.ignore();
				cin >> userchoice;
				if (userchoice == "y")
				{
					userHasFinishedBuying = false;
				}
				else if (userchoice == "n")
				{
					FinishBuy();
				}
				else
				{
					cout << "woah";
				}
			}
		}
	}

}

