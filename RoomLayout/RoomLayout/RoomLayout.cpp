#include <iostream>
#include <algorithm>
#include "RoomLayout.h"


RoomLayout::RoomLayout()
{
}

RoomLayout::~RoomLayout()
{
}

void RoomLayout::PrintRoom(Room* room)
{
	room->Print(/*mWasDoor*/);
}

void RoomLayout::Print() 
{
	std::for_each(mRooms.begin(), mRooms.end(), PrintRoom);
}

void RoomLayout::AddRoom(Room* room)
{
	mRooms.push_back(room);
}
