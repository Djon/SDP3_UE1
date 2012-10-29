///////////////////////////////////////////////////////////////////////////
// Workfile : Wall.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Header for Wall.cpp
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#ifndef WALL_H
#define WALL_H

#include <string>
#include "Side.h"


class Wall :
	public Side
{
public:
	//CTor with color and direction
	Wall(std::string color, Direction direction);

	//virtual destructor
	virtual ~Wall();

private:
	std::string mColor;
};

#endif