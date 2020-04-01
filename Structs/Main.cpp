#include <string>
#include <iostream>
#include <vector>
using namespace std;

//A struct is a class with 'public' default accesibility.
//a bag of values too.
//put in stack too.
struct Product
{
	string Name;
	string Notes;
	double Price;
};

void PrintProduct(Product product)
{
	cout << "Name: " << product.Name << endl;
	cout << "Price: " << product.Price << endl;
	cout << "Notes: " << product.Notes << endl;
}

Product GetProductFromInput()
{
	Product temp;
	cout << "Enter name: "  <<endl;
	getline(cin, temp.Name);
	cout << "Enter Notes: " << endl;
	getline(cin, temp.Notes);
	cout << "Enter Price: " << endl;
	cin >> temp.Price;
	cin.ignore();
	return temp;

}

int main()
{
	Product p1;
	p1.Name = "Product 1";
	p1.Price = 32.32;
	p1.Notes = "These are notes for product 1";

	Product p2 = { "Product 2","Notes for product 2", 31.31 };

	Product myProductsArray[2]; //Can make arrays too!
	vector<Product> products; //dynamically sizable.
	PrintProduct(p1);
	PrintProduct(GetProductFromInput());

	int index = 0;
	while (true)
	{
		cout << "-----------------Product " << index + 1 << " ----------";
		auto product = GetProductFromInput();
		products.push_back(product);

		cout << "Enter another product? [y/n]: ";
		char choice;
		cin >> choice;
		if (choice == 'n')
		{
			break;
		}
		cin.ignore();
		cout << endl;
		index++;
	}

	for (int i = 0; products.size(); i++)
	{
		cout << "-----------------Product " << index + 1 << " ----------";
		PrintProduct(products[index]);
		cout << endl;
	}

	Product mostExpensive = products[0];
	for (int i = 0; products.size(); i++)
	{
		if (products[i].Price > mostExpensive.Price)
		{
			mostExpensive = products[i];
		}
	}
	cout << "---- Most Expensive Product " << mostExpensive.Name << " ----------";

	return 0;
}