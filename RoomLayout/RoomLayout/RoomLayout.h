///////////////////////////////////////////////////////////////////////////
// Workfile : RoomLayout.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Header for RoomLayout.cpp
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#ifndef ROOMLAYOUT_H
#define ROOMLAYOUT_H

#include <list>
#include "Object.h"
#include "Room.h"

typedef std::list<Room*> Rooms;
typedef Rooms::const_iterator RoomsItor;

class RoomLayout :
	public Object
{
public:
	//Default CTor
	RoomLayout();

	//virtual destructor
	virtual ~RoomLayout();

	//Prints the rooms in the layout
	void Print() const;

	//Adds a room to the layout
	bool AddRoom(Room* room);

private:
	Rooms mRooms;
	Room* prevRoom;
	bool mWasDoor;

	//Prints one specific room of the layout
	void PrintRoom(Room* room, bool WasDoor) const;
};

#endif