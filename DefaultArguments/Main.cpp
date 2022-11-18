#include <iostream>
#include <string>
using namespace std;

class ClassA
{
public:
	ClassA(int i)
	{
		cout << "Creating Class A with an int of " << i <<"\n"; 
	}
};

int GetInt(ClassA cls1= ClassA(10), string prompt="number") //If the caller of this method does not provide arguments, 
															//then the ones defined here will be used instead
{
	cout << prompt << ": ";
	int result;
	cin >> result;
	cin.ignore();
	return result;
}

int main()
{
	ClassA whoa(20);

	cout << "before you get int \n";
	//auto age = GetInt(whoa, "hey"); //Provided Argument
	auto age = GetInt(); //Default Argument
	cout << "You are " << age << " years old!";

	return 0;
}