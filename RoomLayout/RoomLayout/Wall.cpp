///////////////////////////////////////////////////////////////////////////
// Workfile : Wall.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Implementation for a wall
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#include <iostream>
#include "Wall.h"


Wall::Wall(std::string color, Direction direction)
{
	mColor = color;
	mDirection = direction;
	mIsDoor = false;
}

Wall::~Wall()
{
}