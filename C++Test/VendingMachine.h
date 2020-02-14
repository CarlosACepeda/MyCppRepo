#pragma once
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <string>

using namespace std;

namespace //Anonymous namespace for private fields declaration
{
	float clientMoney = 0;
	string userchoice;
	bool userHasFinishedBuying;
	int userChosenProduct = -1;
	bool userHasMoneyToPay = true; //By default the user has money to pay.
	string productNames[4];
	float productPrices[4] = {-1};
}

//Declare prototypes. (I'll use also a custom namespace)
namespace vndm
{
	void DisplayWelcomeMessage();
	void InsertProducts();
	void PromptProducts();
	

}
namespace
{
	//Private function to check if the array (Of prices) has been completed.
	bool CheckArrayCompletion(); //?
	void BubbleSortArray();
	void FinishBuy();
	void AskClientMoney();
	bool CheckUserAffordanceForCurrentProduct();
	void BuyProducts();
}

#endif // !VENDINGMACHINE_H


