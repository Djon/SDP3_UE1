///////////////////////////////////////////////////////////////////////////
// Workfile : Side.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Base functionality for wall and door
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#include "Side.h"


Side::~Side()
{
}

Direction Side::getDirection() const
{
	return mDirection;
}

bool Side::IsDoor() const
{
	return mIsDoor;
}
