#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Stage.h"

using namespace std;

class BasicTile : public ITile
{
private:
	char _character;
	bool _canEnter;
public: 
	BasicTile(char ch, bool canEnter) : _character(ch), _canEnter(canEnter)
	{
	}

	virtual char GetCharacter() const { return _character; }
	virtual bool CanEnter(IEntity& entity) { return _canEnter; }
	virtual void Enter(IEntity& entity) {}

};

class BasicEntity: public IEntity
{
	char _character;
	Position _position;
public: 
	BasicEntity(char ch): _character(ch), _position(0,0)
	{

	}
	 
	virtual char GetCharacter() const { return _character; }
	virtual const Position& GetPosition() const { return _position; }
	virtual void SetPosition(const Position& position) { _position = position; }
	virtual void Collide(IEntity& entity) {}
	virtual void Update(){}
};
int main()
{
	Stage stage(20, 20);
	BasicTile empty(' ', true);
	BasicTile wall('#', false);

	stage.SetTiles(empty, Position(0, 0), Position(19, 19));
	stage.SetTiles(wall, Position(0, 0), Position(0, 19));
	stage.SetTiles(wall, Position(0, 0), Position(19, 0));
	stage.SetTiles(wall, Position(19, 0), Position(19, 19));
	stage.SetTiles(wall, Position(0, 19), Position(19, 19));
	stage.SetTiles(wall, Position(4, 4), Position(6, 6));

	BasicEntity player('A');
	stage.SetEntity(player, Position(1, 1));
	char input = '\0';

	stage.RenderAll();

	auto lastTime = timeGetTime(); //Import a static library. (precompiled code ready to use)
	while (input != 27 /*ESC key */)
	{
		auto currentElapsed = timeGetTime() - lastTime;
		if (currentElapsed > 33.3)
		{
			lastTime = timeGetTime();
			stage.Update();
		}
		if (_kbhit())
		{
			input = _getch();
			auto pos = player.GetPosition();
			if (input == 'w')
				stage.MoveEntity(player, Position(pos.GetX(), pos.GetY() - 1));
			else if (input == 'a')
				stage.MoveEntity(player, Position(pos.GetX() - 1, pos.GetY()));
			else if (input == 's')
				stage.MoveEntity(player, Position(pos.GetX(), pos.GetY() + 1));
			else if (input == 'd')
				stage.MoveEntity(player, Position(pos.GetX() + 1, pos.GetY()));
		}
	}
	cin.get();

	int a = 20;
	int b = 40;
	//Aditional concepts:
	const int* constPtrtoInt= &a; // a pointer to a constant value.
	//*constPtrtoInt = 20; -->ERROR.
	//constPtrtoInt = &b; --> OK
	int* const constIntPtr = &a; //a constant pointer to a mutable value. (Like references do)
	//*constIntPtr = 40; --->OK
	//constIntPtr = &b; --->ERROR
	const int* const constPtrToConstInt = &b; //a constant pointer to a constant value.
	//*constPtrToConstInt = 20; ---> ERROR.
	//constPtrToConstInt = &a; ----> ERROR.

	//Homework 9: use constants throughout the code of Shooting Game.
	//Also use constant parameter references when possible.
	//constant fields as much as possible too.

	return 0;
}