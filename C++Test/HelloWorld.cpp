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
		cout << i;
	};

	int x = 1;
	cout << x++; //Outputs 1;
	cout << ++x; //Outputs 3;

	cin >> result;

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
	cout << "This is 6, right? " << number; //outputs -7

	return 0;

	//DEFINE ALL the OTHER OPERATIONS. TODO
}