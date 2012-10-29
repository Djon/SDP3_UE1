///////////////////////////////////////////////////////////////////////////
// Workfile : Side.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Header for Side.cpp
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#ifndef SIDE_H
#define SIDE_H

#include "Direction.h"
#include "Object.h"


class Side :
	public Object
{
public:
	//virtual destructor
	virtual ~Side();

	//Checks if the current object is a door
	bool IsDoor() const;

	//Gets the direction of the current side
	Direction getDirection() const;

protected:
	bool mIsDoor;
	Direction mDirection;
};

#endif