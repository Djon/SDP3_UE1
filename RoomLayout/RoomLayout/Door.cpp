///////////////////////////////////////////////////////////////////////////
// Workfile : Door.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Implemantation for a door, with the possibility to connect
//				 two rooms to it.
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#include "Door.h"


Door::Door(bool isOpen, Direction direction)
{
	mIsDoor = true;
	mIsOpen = isOpen;
	mDirection = direction;
}

Door::~Door()
{
}

void Door::AddRoom(Room* room)
{
	if (mRooms.size() < MaxRooms)
	{
		mRooms.push_back(room);
	}
}
