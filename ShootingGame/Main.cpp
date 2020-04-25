#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void SetCharacter(char ch, int x, int y)
{
	COORD pos= { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
	cout << ch;
}

int main()
{
	SetCharacter('a', 2, 2);
	return 0;
}