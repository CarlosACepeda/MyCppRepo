#include "VendingMachine.h"
#include "string.h"
#include <sstream>
#include <iostream>

using namespace std;
using namespace cac;

//Example of an anonymous namespace, this is for declaring private fields and avoiding implementors of this cpp file to access those fields and modify them
// for example by using a 'extern' keyword. (in the context of namespaces) as for classes we use 'private'
namespace {

	float clientMoney = 0;
	string userchoice;
	bool userHasFinishedBuying = false;
	int userchosenProduct = -1;
	bool userhasMoneyToPay = true;
}
//is not really necessary to wrap the implementation inside the namespace, instead we can prefix the members of that namespace (as defined in the header)
//it depends on the design or the choice
//namespace cac {
void cac::VendingMachine() {
	//Homework 1: The vending machine.
		/*
		Ask the user how much money do they have
		There must be at least 4 products.
		The user will select a product from the product list
		The program will inform the user what item they purchased and how much money they have left.
		The program will continue to execute until the user has no money or decides to exit.

		Allowed to use:
		while loops.
		if statements.
		cin/cout.
		arrays.
		any primitive datatype.
		variables.
		*/

		//Homework 2:
		//Modify this Vending machine program so the user can insert the 4 products along with its prices,
		//and the products must be shown in ascending order of price.
		//The rest of the program will continue normally.

	

	//(For the homework 2 I've to comment this out because the user is the one who will insert the prices
	//and the names of the products)

	string productsNames[4];
	/*productsNames[0] = "Paper Aircraft";
	productsNames[1] = "Paper Boat";
	productsNames[2] = "Paper Rocket";
	productsNames[3] = "Paper Super Fast Car";*/

	//Arrays. (array type of float)
//Foreach type there's an array.
//e.g. int myArray[3];
	float productPrices[4];
	/*productPrices[0] = 200.5f;
	productPrices[1] = 105.6f;
	productPrices[2] = 402.7f;
	productPrices[3] = 105.5f;*/

	string tempProductName;
	float tempProductPrice = 0;

	cout << "Hi there! The vending machine is empty, would you like to insert the products " << endl;
	cout << "that you will buy? LOL, yes that sounds dumb, but you must abide..." << endl;
	cin.ignore();
	for (int i = 0; i < sizeof(productPrices) / 4; i++)
	{
		cout << "Insert the name of the " << i + 1 << " product" << endl;
		//cin.ignore();
		getline(cin, productsNames[i]);
		//cin >> productsNames[i];
		cout << "Now insert the price of that product" << endl;
		cin >> productPrices[i];
		cin.ignore();
	}
	//now lets arrange the products by the price in ascending order
	//we will use bubble sort.
	int counter = 0;
	for (counter = 0; counter < sizeof(productPrices) / 4; counter++)
	{
		//cout << sizeof(productPrices) / 4 << endl;
		if (counter + 1 < sizeof(productPrices) / 4) //If counter + 1 is greater than 3 it'll crash...
			if (productPrices[counter] > productPrices[counter + 1])
			{
				//Let's perform a swap.
				auto tempPrice = productPrices[counter + 1];
				auto tempName = productsNames[counter + 1];
				productPrices[counter + 1] = productPrices[counter];
				productPrices[counter] = tempPrice;

				productsNames[counter + 1] = productsNames[counter];
				productsNames[counter] = tempName;
				counter = -1;
				continue;
			}
		continue;
	}

	cout << "Welcome, Mr. Client, how much money do you have?: " << endl;
	cin >> clientMoney;

	if (clientMoney > 0)
	{
		while (userHasFinishedBuying == false)
		{
			if (userhasMoneyToPay)
			{
				cout << "Products" << endl;
				cout << "1." << productsNames[0] << " price: " << productPrices[0] << endl;
				cout << "2." << productsNames[1] << " price: " << productPrices[1] << endl;
				cout << "3." << productsNames[2] << " price: " << productPrices[2] << endl;
				cout << "4." << productsNames[3] << " price: " << productPrices[3] << endl;

				cout << "Please, enter the number of the product you'd wish to buy!" << endl;
				cin >> userchosenProduct;

				if (userchosenProduct != -1)
				{
					//let's check if the client has enough money to buy in the first place.
					if (clientMoney > productPrices[userchosenProduct - 1])
					{
						userhasMoneyToPay = true;
						clientMoney = clientMoney - productPrices[userchosenProduct - 1];
						cout << "Okay Mr. Client, you bought " << productsNames[userchosenProduct - 1] << "!" << endl;

						cout << "Your balance is now: " << clientMoney << endl;
						cout << "Do you wish to buy another item? y/n" << endl;
						cin >> userchoice;
						if (userchoice == "y")
						{
							userHasFinishedBuying = false;
						}
						else if (userchoice == "n")
						{
							userHasFinishedBuying = true;
						}
						else
						{
							cout << "woah";
						}
					}
					else
					{
						userhasMoneyToPay = false;
						cout << "Come back when you have more money, those pennies won't afford our luxuries" << endl;
					}
				}
			}
			else
			{
				//automatically we say that the user has finished buying because she finished it or
				//she doesn't have money to pay anyway, lol.
				userHasFinishedBuying = true;
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
//}