#include "Stage.h"

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
void Stage::MoveEntity(IEntity& entity, Position pos)
{

}

void Stage::RenderAll()
{
	for (auto x  = 0; x < _width; x++)
	{
		for (auto y = 0; y < _height; y++)
		{
		}

	}
}

