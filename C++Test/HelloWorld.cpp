//Punto de entrada para la aplicación.

#include <iostream>
#include <limits.h> //C header.
#include <string> 
#include <sstream> //Allows several operations with strings.

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
	for (int i = 1; i <= nLoopCount; i++ /*This action always happens at the end of each loop*/)
	{
		cout << "We've finished " << i
			<< " loops" << endl;
	}

	//Arrays. (array type of float)
	//Foreach type there's an array.
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

	//Homework 2:
	//Modify this Vending machine program so the user can insert the 4 products along with its prices,
	//and the products must be shown in ascending order of price.
	//The rest of the program will continue normally.

	float clientMoney = 0;
	string userchoice;
	bool userHasFinishedBuying = false;
	int userchosenProduct = -1;
	bool userhasMoneyToPay = true;


	//(For the homework 2 I've to comment this out because the user is the one who will insert the prices
	//and the names of the products)

	string productsNames[4];
	/*productsNames[0] = "Paper Aircraft";
	productsNames[1] = "Paper Boat";
	productsNames[2] = "Paper Rocket";
	productsNames[3] = "Paper Super Fast Car";*/

	/*productPrices[0] = 200.5f;
	productPrices[1] = 105.6f;
	productPrices[2] = 402.7f;
	productPrices[3] = 105.5f;*/

	string tempProductName;
	float tempProductPrice=0;

	cout << "Hi there! The vending machine is empty, would you like to insert the products "<< endl;
	cout << "that you will buy? LOL, yes that sounds dumb, but you must abide..." << endl;
	cin.ignore();
	for (int i = 0; i < sizeof(productPrices)/4; i++)
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
	for (counter = 0; counter < sizeof(productPrices)/4; counter++)
	{	
		//cout << sizeof(productPrices) / 4 << endl;
		if(counter+1< sizeof(productPrices)/4) //If counter + 1 is greater than 3 it'll crash...		
		if (productPrices[counter] > productPrices[counter + 1])
		{
			//Let's perform a swap.
			auto tempPrice = productPrices[counter + 1];
			auto tempName = productsNames[counter + 1];
			productPrices[counter + 1] = productPrices[counter];
			productPrices[counter] = tempPrice;

			productsNames[counter + 1] = productsNames[counter];
			productsNames[counter] = tempName;
			counter =- 1;
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

	//Demo string with ASCII
	//Now here I show that concatenating strings with integers will cause 'cout' to (in the case of the integers)
	//output the ASCII code for that int, example, 49 equals to 1 in ASCII.
	//In order to do those concats we use a header called sstream (or stringstream) which will help us to print the intended 
	//Values when concatenating.
	//In this example I will ask the age and the name, and concatenate them to form a message.
	//One will output the wrong value for the age (1) (in the case I enter 49) 
	//and the other will output the correct value, 49, by using the stringstream class in the sstream header before using cout.

	int age;
	string name;
	cout << "Enter your age: ";
	cin >> age;

	cout << "Enter your name: ";
	cin >> name;

	string output = name + " - you are  ";
	output += age;
	output += " years old";

	cout << "The result with 'cout' is : " << endl;
	cout << output << endl; //This is the version for cout, will print the Age number in its ASCII equivalent, test 49 and it'll show 1.

	stringstream ss;

	ss << name << " - you are " << age << " years old!";
	output = ss.str(); //This will cause 'age' to be formatted correctly.

	cout << "The result with 'ss' from sstream is : " << endl;
	cout << output << endl; //This is the version with 'age' formatted.

	//stringstream allows us to convert from string to int.

	stringstream ss2;

	string agestring = "42";
	int ageInt;
	ss2 << agestring;
	ss2 >> ageInt;
	cout << "you're " << (ageInt+ 1) << " in a year!" << endl;
	
	//Foreach (kind of(?))
	cout << "For each demo: " << endl;
	int arr[] = { 1,2,3,4 };
	for (int item : arr)
	{
		cout << "Item foreach: " << item << endl;
	};


	// wait until user is ready before terminating program
	// to allow the user to see the program results    
	cout << "Press Enter to continue..." << endl;
	cin.ignore();
	cin.get(); 

	return 0;

}