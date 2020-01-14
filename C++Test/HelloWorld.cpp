//Punto de entrada para la aplicación.

#include <iostream>
#include <limits.h> //C header.

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
	cout << "x++: "<< x++ << endl; //Outputs 1, the reason is that it first grabs the value, then it does the operation.
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
	cin  >> nLoopCount;    // count up to the loop count limit
	for (int i = 1; i <= nLoopCount; i++)    
	{        
		cout << "We've finished " << i 
			<< " loops" << endl;   
	}    

	//Arrays. (array type of double)
	//Foreach tipe there's an array.
	//e.g. int myArray[3]; 
	double productPrices[4]; 

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




	// wait until user is ready before terminating program
	// to allow the user to see the program results    
	cout << "Press Enter to continue..." << endl;
	cin.ignore();
	cin.get(); 

	return 0;

}