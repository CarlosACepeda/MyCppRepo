#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H
#include <string>
#include <vector>

using namespace std;

namespace //Anonymous namespace for private fields declaration only accesible within the cpp file.
	//Or in this case only on the VendingMachine.cpp
	//or in the cpp file that referenced this header!
	//Though putting anonymous members in the header maybe useless.
	//If this header gets referenced in another cpp file it won't compile LOL
{
	struct Product {
		std::string Name;
		float Price;
	};

	enum Menu
	{
		None,
		AddNewProduct,
		SortProducts,
		DisplayProducts,
		Exit
	};

	int currentSelection = 0;

	float clientMoney = 0;
	string userchoice;
	bool userHasFinishedBuying;
	int userChosenProduct = -1;
	bool userHasMoneyToPay = true; //By default the user has money to pay.
	vector<Product> products;
	//extern bool myVariable ---> prototyping a variable and promising the compiler this variable exists somewhere
	//same with functions I have to provide a implementation of this variable at certain point
}

//Declare prototypes. (I'll use also a custom namespace)
namespace vndm
{
	void Init();
	void MainMenu();
	void InsertProducts();
	void PromptProducts();


}
namespace
{
	void BubbleSortArray();
}

#endif // !VENDINGMACHINE_H
