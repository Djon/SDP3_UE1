#include "Wall.h"
#include <iostream>

Wall::Wall(std::string color, Direction direction)
{
	mColor = color;
	mDirection = direction;
	mIsDoor = false;
}

Wall::~Wall()
{
}