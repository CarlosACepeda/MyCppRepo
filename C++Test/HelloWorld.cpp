//Punto de entrada para la aplicación.

#include <iostream>
#include <limits.h> //C header.
#include <string> 

using namespace std;

int main()
{
	string result;
	cout << "Hello World" << endl;

	//Limits:
	INT_MAX;
	INT_MIN;
	//etc...

	cout << "Unary addition Demo: ";

	int x = 1;

	cout << "X equals now to: " << x << endl;
	cout << "x++: " << x++ << endl; //Outputs 1, the reason is that it first grabs the value, then it does the operation.
	cout << "X equals now to: " << x << endl;
	cout << "++x: " << ++x << endl; //Outputs 3; //it makes the operation first then it returns the value.
	cout << "X equals now to: " << x << endl;

	cout << "Insert a string here: ";
	cin >> result;

	cout << "Sizeof Demo: (outputs the bytes used by certain datatype or variable datatype, either works)";
	cout << "The size of 'result' is " << sizeof(result)
		<< " and the size of 'x' is " << sizeof(x) << endl;

	//Ancient inherited from C octal system:
	//by default c++ interprets numbers starting with 0 as octals.

	cout << " 0173 (Octal)= " << 0173 << endl; //outputs 123.


	//hexadecimal numbers
	cout << "0x7B  (Hexadecimal) = " << 0x7B << endl; //outputs 123 too
	cout << "0x123 (Hexadecimal) = " << 0x123 << endl; //outputs 291.


	//Bitwise operators:
	//~ :NOT, toggles the bit from 1 to 0 and 0 to 1.
	//& :AND each bit of the left - hand argument with that on the right 
	//| :OR each bit of the left - hand argument with that on the right 
	//^ :XOR(exclusive OR) each bit of the left - hand argument with that on the right

	int number6 = 0x6;
	int number = ~number6;
	cout << "6 (hex) NOT operation applied: " << number << endl; //outputs -7
	number = 2 | number6;
	cout << "2 OR 6 Equals to: " << number << endl; //outputs 6 
	number = 2 ^ number6;
	cout << "2 Exclusive OR (XOR) 6 Equals to: " << number << endl; //outputs 4

	//For Demo.
		// input the loop count
	cout << "For Demo:" << endl;
	int nLoopCount;    cout << "Enter loop count: ";
	cin >> nLoopCount;    // count up to the loop count limit
	for (int i = 1; i <= nLoopCount; i++)
	{
		cout << "We've finished " << i
			<< " loops" << endl;
	}

	//Arrays. (array type of float)
	//Foreach tipe there's an array.
	//e.g. int myArray[3]; 
	float productPrices[4];

	string crashOption = "n";
	cout << "Do you wish to see a While loop demo that crashes the program?, If you do, press 'y' otherwise press 'n'" << endl;
	cin >> crashOption;

	if (crashOption == "y")
	{
		auto index = 0;
		cout << "While Demo:" << endl;
		while (index < 7) //Buffer overrun because productPrices size is 4.
		{
			cout << "Enter price for product " << index << ":" << endl;
			cin >> productPrices[index]; //at the moment we cross the last position (4) it writes to random memory places.
			//basically outofbounds, unlike c# for example, it lets us to run the program and work 'perfectly'
			//in Visual c++ it generates an exception.
			//but in other compilers or platforms it may pass undetected. ;)
			index++;
		}
	}

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

	float clientMoney = 0;
	string userchoice;
	bool userHasFinishedBuying = false;
	int userchosenProduct = -1;
	bool userhasMoneyToPay = true;

	string productsNames[4];
	productsNames[0] = "Paper Aircraft";
	productsNames[1] = "Paper Boat";
	productsNames[2] = "Paper Rocket";
	productsNames[3] = "Paper Super Fast Car";

	productPrices[0] = 200.5f;
	productPrices[1] = 105.6f;
	productPrices[2] = 402.7f;
	productPrices[3] = 105.5f;


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
						userHasFinishedBuying = true; //she does not have more money to buy things.
						cout << "Come back when you have more money, those pennies won't afford our luxuries" << endl;
					}
				}
			}
			else
			{
				//automatically we say that the user has finished buying because she finished it or
				//she doesn't have money to pay anyway, lol.
				userHasFinishedBuying == true; //(For some reason this assignment isn't working LOL.
				//The while loop executes forever, the debugger just skips this, to see this happening, remove the line
				//175: "(userHasFinishedBuying = true; //she does not have more money to buy things.)".
				cout << "You don't have more money left or you canceled the buy, thanks for coming" << endl;

			}
		}
		cout << "Thanks for buying, now you have " << clientMoney << " left!" << endl;
	}
	else
	{
		cout << "Who are you trying to fool?" << endl;
	}


	//Numeric Limits, we're gonna using the limits header.
	cout << "Numeric Limits" << endl;
	cout << "Int: " << endl;
	cout << "Minimum " <<numeric_limits<int>::min() << endl;
	cout << "Maximum " <<numeric_limits<int>::max() << endl;
	
	cout << "Int (unsigned): " << endl;
	cout << "Minimum " <<numeric_limits<unsigned int>::min() << endl;
	cout << "Maximum " <<numeric_limits<unsigned int>::max() << endl;

	cout << "Int: " << endl;
	cout << "Minimum " << (int)numeric_limits<char>::min() << endl;
	cout << "Maximum " << (int)numeric_limits<char>::max() << endl;

	cout << "Char (unsigned): " << endl;
	cout << "Minimum " << (int)numeric_limits<unsigned char>::min() << endl;
	cout << "Maximum " << (int)numeric_limits<unsigned char>::max() << endl;


	cout << "now testing String" << endl;
	string yourName;

	cout << "Enter your name" << endl;
	cin.ignore();
	getline(cin, yourName); // It gets the input from cin and stuffs yourName with its contents.

	cout << "Your name is: " << yourName << endl;

	// wait until user is ready before terminating program
	// to allow the user to see the program results    
	cout << "Press Enter to continue..." << endl;
	cin.ignore();
	cin.get(); 

	return 0;

}