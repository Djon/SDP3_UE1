///////////////////////////////////////////////////////////////////////////
// Workfile : Door.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Header for Door.cpp
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#ifndef DOOR_H
#define DOOR_H

#include <vector>
#include "Side.h"
#include "Room.h"


int const MaxRooms = 2;

class Door :
	public Side
{
public:
	//CTor with parameters
	Door(bool isOpen, Direction direction);

	//virtual destructor
	virtual ~Door();

	//Adds a room to the current door if MaxRooms isn't
	//reached yet
	void AddRoom(Room* room);

private:	
	bool mIsOpen;
	std::vector<Room*> mRooms;
};

#endif