#include <iostream>
#include "LinkedList.h"
using namespace std;

//Homework 6:
	//Use classes and OOP concepts and re-do the Homework 5 with Linked Lists.
	//Instead of functions we should use methods, and instead of structs we use classes.


void Item::LinkedListExercise()
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
			items[itemsCounter - 1].nextItemPointer = currentItemPointer; //Asign the current pointer to the previous item property 'nextItemPointer'
			//Implicitly the last item won't make this assignment, so it's a easy way to check if we hit the last item on a list when making loops.
			items[itemsCounter] = item;
			itemsCounter++;
			delete[] temp;
		}
	}
	float result = 0;
	for (unsigned int i = 0; i < itemsCounter; i++)
	{
		if (items[i].nextItemPointer != NULL) //To avoid buffer overruns!!
			result = items[i].Number + items[i + 1].Number;
	}

	result = result / itemsCounter;

	cout << "The average of the numbers you entered is: " << result << endl;

}