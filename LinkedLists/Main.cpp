#include <iostream>
#include "LinkedList.h"
using namespace std;

//Homework 5.
	//Use LinkedLists to allow th user to enter as many numbers as she wants
	//and stop when the user enters 0.
	//and return the average of those numbers and display them on the screen.

struct ItemStruct
{
	ItemStruct* nextItemPointer;
	int Number;
};

void LinkedListExerciseNoOOP()
{
	ItemStruct* items = NULL; //Create an an instance of an array and return its pointer.
	unsigned int itemsCounter = 0;
	while (true)
	{
		cout << "\nWelcome user insert a number or 0 to exit\n";

		ItemStruct item;

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
		ItemStruct* currentItemPointer = &item;

		if (items == NULL)
		{
			items = new ItemStruct[1];
			items[0] = item;
			itemsCounter = 1;
		}
		else
		{
			ItemStruct* temp = items;
			items = new ItemStruct[itemsCounter + 1];

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

int main()
{
	LinkedListExerciseNoOOP();
	Item itemInstance;
	cout << "\n Finishing 'No OOP' Linked List Exercise\n";
	itemInstance.LinkedListExercise();
	cout << "\n Finishing 'No OOP' Linked List Exercise\n";
	return 0;
}