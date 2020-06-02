#include "Stage.h"
#include <iostream>
#include <Windows.h>

using namespace std;
Stage::Stage(int width, int height) : _width(width), _height(height), _tiles(width*height)
{

}
int Stage::GetWidth()
{
	return _width;
}
int Stage::GetHeight()
{
	return _height;
}
void Stage::SetTile(ITile& tile, Position pos)
{
	_tiles[GetIndexForXY(pos.GetX(), pos.GetY())] = &tile;
}
void Stage::SetTiles(ITile& tile, Position from, Position to)
{
	for (auto x = from.GetX(); x <= to.GetX(); x++)
	{
		for (auto y = from.GetY(); y <= to.GetY(); y++)
		{
			_tiles[GetIndexForXY(x,y)] = &tile;
		}
	}
}
void Stage::SetEntity(IEntity& entity, Position pos)
{
	_entities.push_back(&entity);
	entity.SetPosition(pos);
}
bool Stage::MoveEntity(IEntity& entity, Position pos)
{
	if (pos.GetX() <0 || pos.GetX() >= _width || pos.GetY() <0 || pos.GetY() >=_height) 
		return false;
	
	auto tileToEnter= _tiles[GetIndexForXY(pos.GetX(), pos.GetY())];
	if(!tileToEnter-> CanEnter(entity))
		return false;
	
	auto oldPos= entity.GetPosition();	

	auto oldTile = _tiles[GetIndexForXY(oldPos.GetX(), oldPos.GetY())];
	SetCharacter(oldTile->GetCharacter(), oldPos.GetX(), oldPos.GetY());
	SetCharacter(entity.GetCharacter(), pos.GetX(), pos.GetY());
	entity.SetPosition(pos);
	return true;
}

void Stage::RenderAll()
{
	for (auto x  = 0; x < _width; x++)
	{
		for (auto y = 0; y < _height; y++)
		{
			auto tile= _tiles[GetIndexForXY(x, y)];
			SetCharacter(tile->GetCharacter(), x, y);
		}

	}
	for (auto i = _entities.begin(); i != _entities.end(); i++)
	{
		auto entity = *i;
		auto pos = entity->GetPosition();
		SetCharacter(entity->GetCharacter(), pos.GetX(), pos.GetY());

	}
}
void Stage::Update()
{
	for (auto i = _entities.begin(); i != _entities.end(); i++)
	{
		(*i)->Update();
	}
}
void Stage::SetCharacter(char ch, int x, int y) 
{
	COORD pos= { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
	cout << ch;

}
int Stage::GetIndexForXY(int x, int y)
{
	return _width * x + y;
}

