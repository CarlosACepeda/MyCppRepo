//Punto de entrada para la aplicación.

#include <iostream>
using namespace std;

int main()
{
	string result;
	cout << "Hello World";
	cin >> result;

	for (int i = 0; i < 9; i++)
	{
		cout << i << "Pollito" <<endl;
	};
	int x = 1;

	cout << "X equals now to: " << x << endl;
	cout << "x++: "<< x++ << endl; //Outputs 1, the reason is that it first grabs the value, then it does the operation.
	cout << "X equals now to: " << x << endl;
	cout << "++x: " << ++x << endl; //Outputs 3; //it makes the operation first then it returns the value.
	cout << "X equals now to: " << x << endl;


	cin >> result;

	cout << "The size of result is " << sizeof(result)
		<< " and the size of X is " << sizeof(x) << endl;

	//Ancient inherited from C octal system:
	//by default c++ interprets numbers starting with 0 as octals.

	cout << " 0173= " << 0173 << endl; //outputs 123.


	//hexadecimal numbers
	cout << "0x7B  = " << 0x7B << endl; //outputs 123 too
	cout << "0x123 = " << 0x123 << endl; //outputs 291.


	//Bitwise operators:
	//~ :NOT, toggles the bit from 1 to 0 and 0 to 1.
	//& :AND each bit of the left - hand argument with that on the right 
	//| :OR each bit of the left - hand argument with that on the right 
	//^ :XOR(exclusive OR) each bit of the left - hand argument with that on the right

	int number6 = 0x6;
	int number = ~number6;
	cout << "This is 6, right? " << number << endl; //outputs -7
	number = 2 | number6;
	cout << "2 or 6 Equals to: " << number << endl; //outputs 6 
	number = 2 ^ number6;
	cout << "2 xor 6 Equals to: " << number << endl; //outputs 4

	//For Demo.
		// input the loop count
	int nLoopCount;    cout << "Enter loop count: ";
	cin  >> nLoopCount;    // count up to the loop count limit
	for (int i = 1; i <= nLoopCount; i++)    
	{        
		cout << "We've finished " << i 
			<< " loops" << endl;   
	}    
	// wait until user is ready before terminating program
	// to allow the user to see the program results    
	cout << "Press Enter to continue..." << endl;
	cin.ignore();
	cin.get(); 

	return 0;

}