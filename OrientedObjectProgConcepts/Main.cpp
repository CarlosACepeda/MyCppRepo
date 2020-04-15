#include <string>
#include "Inventory.h"

int main()
{
	//Let's create a new instance of the Inventory class on the stack
	//within this scope (Curly braces) to see how the Destructor is also called)
	{
		Inventory inventory;
	}
	//If a call it on the heap I have to release the memory myself.
	//Otherwise I'll have a memory leak
	Inventory* inventory = new Inventory();
	delete inventory;

	//Homework 6:
	//Use classes and OOP concepts and re-do the Homework 5 with Linked Lists.
	//Instead of functions we should use methods, and instead of structs we use classes.

	return 0;
}