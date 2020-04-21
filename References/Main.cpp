#include <iostream>
#include <string>

class GoodClass
{
	std::string _names;
public:
	GoodClass(std::string name) : _names(name) //Good classes use initialization lists, so
		//'_names' gets initialized with whatever value is in 'name' param.
	{
		//My code...
	}
};
class BadClass
{
	std::string _name;
public:
	BadClass(std::string name)
	{
		_name = name; //BAD! causes _name to initialize to a default value then Assign it to the value of 'name'.
	}
};

int main()
{
	//Initializers are called before the constructors in classes.

	BadClass("Whoa");
	return 0;
}