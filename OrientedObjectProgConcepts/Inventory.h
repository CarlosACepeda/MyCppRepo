#ifndef INVENTORY_H
#define INVENTORY_H
#include "Product.h"
#include <string>

class Inventory //By default classes and member are private.
{
private: //Reduhdant, just for being specific, members are private by default.
	Product* _product;
	int _productCount;
	std::string _location;
public:
	Inventory(); //Constructor of the class. Get's invoked automatically when making an instance of it.
	~Inventory(); //Destructor of the class. Get's invoked automatically when the scope of the function
	//an instance is being used is finished/or when called specifically. (Never do this)
	//Both contructor and destructor are innecessary, if I don't want I won't write them.

	int GetCount();
	void AddProduct(Product product); //We can use a Pointer but that would be confusing, instead let's pass a copy of the whole object instead
	void SetLocation(std::string location);
};

#endif // !INVENTORY_H
