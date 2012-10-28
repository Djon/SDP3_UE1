#include <iostream>
#include <algorithm>
#include <iterator>
#include "RoomLayout.h"


RoomLayout::RoomLayout()
{
}

RoomLayout::~RoomLayout()
{
}

void RoomLayout::PrintRoom(Room* room)
{
	room->Print();
}

void RoomLayout::Print() 
{
	for (std::list<Room*>::const_iterator first = mRooms.begin() ; first!=mRooms.end(); ++first ) 
	{
		PrintRoom(*first);
	}
}

void RoomLayout::AddRoom(Room* room)
{
	mRooms.push_back(room);
}
