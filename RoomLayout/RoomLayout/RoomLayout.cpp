#include <iostream>
#include <algorithm>
#include <iterator>
#include "RoomLayout.h"

RoomLayout::RoomLayout()
	: mWasDoor(false)
{
}

RoomLayout::~RoomLayout()
{
	RoomsItor itor = mRooms.begin();

	while (itor != mRooms.end())
	{
		delete (*itor);
		++itor;
	}
}

void RoomLayout::PrintRoom(Room* room, bool WasDoor)
{
	room->Print(WasDoor);
}

void RoomLayout::Print() 
{
	bool WasDoor = false;

	for (std::list<Room*>::const_iterator first = mRooms.begin() ; first!=mRooms.end(); ++first ) 
	{
		PrintRoom(*first, WasDoor);
		WasDoor = (*first)->IsSouthDoor();
	}
}

bool RoomLayout::AddRoom(Room* room)
{
	if (mWasDoor == room->IsNorthDoor() || mRooms.empty())
	{
		mRooms.push_back(room);
		mWasDoor = room->IsSouthDoor();
		return true;
	}
	return false;
}
