#include <string>
#include <iostream>
#include "CustomResizeableArray.h"
using namespace std;

void AddProductNames()
{

	Product* products = NULL; //Empty array.
	unsigned int productCount = 0;
	while(true)
	{
		std::cout << "\n Insert product name or '' to exit\n";

		Product product;
		getline(cin, product.Name);

		if (product.Name == "")
		{
			break;
		}

		if (products == NULL)
		{
			products = new Product[1]; //Create a new array of 1 slot and return its address to 'products' pointer.
			products[0] = product; //add the product to the first slot of this array.
			productCount = 1; //set product count to 1.
		}
		else
		{
			Product* temp = products; //save the address of the previous created list into another pointer called temp.
			products = new Product[productCount+1]; //Create a new Array that has previous array size +1.
			for (unsigned int i = 0; i < productCount; i++)
			{
				products[i] = temp[i]; //Copy all the elements from the temp array into the new one.
			}
			products[productCount] = product; //Add the new element into the last slot of the new created Array.
			productCount++;
			delete [] temp; //Deallocate the memory created by the array we copied the data from. (or else we have a Memory leak)
		}
	}
	for (unsigned int i = 0; i < productCount; i++)
	{
		cout << "[" << i << "] " << products[i].Name << endl ;
	}
}