#pragma once
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <string>

using namespace std;

namespace //Anonymous namespace for private fields declaration only accesible within the cpp file.
	//Or in this case only on the VendingMachine.cpp
	//or in the cpp file that referenced this header!
	//Though putting anonymous members in the header maybe useless.
	//If this header gets referenced in another cpp file it won't compile LOL
{
	float clientMoney = 0;
	string userchoice;
	bool userHasFinishedBuying;
	int userChosenProduct = -1;
	bool userHasMoneyToPay = true; //By default the user has money to pay.
	string productNames[4];
	float productPrices[4] = {-1};
	//extern bool myVariable ---> prototyping a variable and promising the compiler this variable exists somewhere
	//same with functions I have to provide a implementation of this variable at certain point
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


