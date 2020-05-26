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

	virtual char GetCharacter() { return _character; }
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
	virtual char GetCharacter() { return _character; };
	virtual Position& GetPosition() { return _position; };
	virtual void SetPosition(Position& position) { _position = position; };
	virtual void Collide(IEntity& entity) {};

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

	BasicEntity player('Δ');
	stage.SetEntity(player, Position(1, 1));
	char input;

	stage.RenderAll();
	while ((input = _getch()) != 27 /*ESC key */)
	{
		auto pos = player.GetPosition();
		if (input == 'w')
			stage.MoveEntity(player, Position(pos.GetX(), pos.GetY() - 1));
		else if (input =='a')
			stage.MoveEntity(player, Position(pos.GetX()-1, pos.GetY()));
		else if (input =='s')
			stage.MoveEntity(player, Position(pos.GetX(), pos.GetY() + 1));
		else if (input =='d')
			stage.MoveEntity(player, Position(pos.GetX()+1, pos.GetY()));
	}
	cin.get();
	return 0;
}