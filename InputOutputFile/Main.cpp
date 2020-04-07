#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//A struct is a class with 'public' default accesibility.
//a bag of values too.
//put in stack too.
struct Product
{
	string Name;
	double Price;
	string Notes;
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
	cout << "Enter name: " << endl;
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

	vector<Product> products;
	Product p1 = { "Product1",22, "Notes1" };
	Product p2 = { "Product2",23, "Notes2" };
	Product p3 = { "Product3",24, "Notes3" };

	products.push_back(p1);
	products.push_back(p2);
	products.push_back(p3);

	//save products to products.txt
	ofstream fout;
	fout.open("products.txt");
	for (unsigned int i = 0; i < products.size(); i++)
	{
		fout << products[i].Name << endl << products[i].Price << endl << products[i].Notes << endl;
	}
	fout.close();

	vector<Product> products2;

	ifstream fin;
	fin.open("products.txt");
	while (!fin.eof())
	{
		Product temp;
		getline(fin, temp.Name);
		fin >> temp.Price;
		fin.ignore();

		getline(fin, temp.Notes);

		products2.push_back(temp);
	}
	fin.close();

	cout << "Products Read from File \n";

	for (unsigned int i = 0; i < products2.size(); i++)
	{
		PrintProduct(products2[i]);
	}

	return 0;
}