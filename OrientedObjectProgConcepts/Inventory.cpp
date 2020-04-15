#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
	//Do whatever we want in the contructor, for now print a Message.
	std::cout << "Class-- Constructor called \n";

	//Guidelines says that we should initalize members here too.
}
Inventory::~Inventory()
{
	//Release unmanaged resources, if any.
	//For now, print a message.
	std::cout << "Class-- Destructor called \n";

}
int Inventory::GetCount()
{
	return Inventory::_productCount;
}
void Inventory::AddProduct(Product product)
{
	this->_product = &product; //'This' is a keyword to get the Pointer of the instance of the class.
}
void Inventory::SetLocation(std::string location)
{
	this->_location = location;
}