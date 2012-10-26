#include <iostream>
#include "RoomLayout.h"
#include <algorithm>

RoomLayout::RoomLayout()
{
}

RoomLayout::~RoomLayout()
{
}

void PrintRoom(Room* r1)
{
	r1->Print();
}

void RoomLayout::Print() 
{
	std::for_each(mRooms.begin(),mRooms.end(),PrintRoom);
}

void RoomLayout::AddRoom(Room* room)
{
	mRooms.push_back(room);
}
