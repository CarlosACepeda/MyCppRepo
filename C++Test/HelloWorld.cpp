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
	return 0;

	//bitwise values.
}