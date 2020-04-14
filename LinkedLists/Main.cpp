#include <iostream>
using namespace std;

//Homework 5.
	//Use LinkedLists to allow th user to enter as many numbers as she wants
	//and stop when the user enters 0.
	//and return the average of those numbers and display them on the screen.

struct Item
{
	Item* nextItemPointer;
	int Number;
};

int main()
{
	Item* items = NULL; //Create an an instance of an array and return its pointer.
	unsigned int itemsCounter = 0;
	while (true)
	{
		cout << "\nWelcome user insert a number or 0 to exit\n";

		Item item;

		int selection = 0;
		cin >> selection;
		cin.ignore(); //Omit enters and whitespaces.
		if (selection == 0)
		{
			break;
		}
		//Let's create a new item.
		item.Number = selection;
		item.nextItemPointer = NULL;
		Item* currentItemPointer = &item;

		if (items == NULL)
		{
			items = new Item[1];
			items[0] = item;
			itemsCounter = 1;
		}
		else
		{
			Item* temp = items;
			items = new Item[itemsCounter + 1];

			for (unsigned int i = 0; i < itemsCounter; i++)
			{
				items[i] = temp[i];
			}
			items[itemsCounter - 1].nextItemPointer = currentItemPointer;
			items[itemsCounter] = item;
			itemsCounter++;
			delete[] temp;
		}
	}
	float result = 0;
	for (unsigned int i=0; i< itemsCounter; i++)
	{
		if (items[i].nextItemPointer != NULL)
			result = items[i].Number + items[i + 1].Number;
	}

	result = result / itemsCounter;

	cout << "The average of the numbers you entered is: " << result << endl;

	//BONUS:
	//Replace the vector<> usage in the last homework and use my own linked list.
	return 0;
}