#include <iostream>
#include <string>
#include "CustomResizeableArray.h"

using namespace std;



void BadFunction(Product** pointerPointer, bool crash)
{
	if (crash)
	{
		Product product; //..on Stack.
		product.Name = "Name 1";
		*pointerPointer = &product;
		//Popped stack off... now 'product' has been deallocated when function exits.
	}
	
	else
	{
		//The solution is allocate on the Heap instead.
		*pointerPointer = new Product; //Allocate a new 'Product' on the heap and get a pointer to it.
		(**pointerPointer).Name = "Name 2";
	}

}


int main()
{
	Product p;
	p.Name = "ProductName";

	Product* myProductPointer = &p; //(Pointer to 'p')
	Product myProductObjectRetrieved = *myProductPointer; //Asterisk behind gets the object the pointer is pointing to. (Dereferencing)
	Product** myPointerPointer = &myProductPointer; //Asigning the Product Pointer to the Product Pointer Pointer, lol.

	cout << "Product Pointer Address: " << myProductPointer << "\n";
	cout << "Pointer Adress of Product Pointer : " << myPointerPointer << "\n";
	cout << "Product Name Retrieved from Pointer: " << myProductPointer->Name << "\n";
	cout << "Product Name from Product Object retrieved from Pointer: : " << myProductObjectRetrieved.Name << "\n";


	//Heap memory allocation, use the keyword 'new' to retrieve a pointer.
	Product* myHeapAllocatedProduct = new Product;
	myHeapAllocatedProduct->Name = "Allocated product name using a pointer to the Heap";
	cout << "Name from Product allocated on the heap: " << myHeapAllocatedProduct->Name << "\n";
	//IMPORTANT: use 'delete' keyword to avoid memory leaks when allocating on the heap.
	//we don't have a GC to do that for us.
	delete myHeapAllocatedProduct;


	//Invoke a bad function that will make the program crash:
	Product** pp = new Product*; //Create a new Pointer pointing to a Pointer on te HEAP. (keyword 'new')
	cout << "My bad function will crash" << "\n";
	BadFunction(pp,false);

	cout << (**pp).Name;

	//Memory leaks!!, Deallocate the pointer pointer and the pointer the pointer pointer is pointing too.
	delete *pp; //see 'BadFunction()' to see the allocation of '*pp'
	delete pp;

	AddProductNames();

	return 0;
}