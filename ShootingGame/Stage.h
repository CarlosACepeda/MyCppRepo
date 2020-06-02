#ifndef STAGE_H
#define STAGE_H

#include "ITile.h"
#include "IEntity.h"
#include "Position.h"
#include <vector>

class Stage
{
	int _width, _height;
	std::vector<ITile*> _tiles;
	std::vector<IEntity*> _entities;



public:
	Stage(int width, int height);
	int GetWidth();
	int GetHeight();
	void SetTile(ITile& tile, Position pos);
	void SetTiles(ITile& tile, Position from, Position to);
	void SetEntity(IEntity& entity, Position pos);
	bool MoveEntity(IEntity& entity, Position pos);
	void Update();

	void RenderAll();

private:
	int GetIndexForXY(int x, int y);
	void SetCharacter(char ch, int x, int y);
};

#endif // !STAGE_H

