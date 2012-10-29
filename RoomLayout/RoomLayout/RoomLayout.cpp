#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
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
	try 
	{
		if (!room->IsFull())
		{
			std::string ex("Room is not full");
			throw(ex);
		}
		if (mRooms.empty() || mWasDoor == room->IsNorthDoor())
		{
			mRooms.push_back(room);

			if (mWasDoor)
			{
				Side* CurrentDoor = room->GetNorthSide();
				Side* PrevDoor = prevRoom->GetSouthSide();

				prevRoom->AddRoomToDoor(CurrentDoor);
				room->AddRoomToDoor(PrevDoor);
			}

			mWasDoor = room->IsSouthDoor();
			prevRoom = room;
			return true;
		}
		return false;
	}
	catch (std::string const& ex)
	{
		std::cerr << "Error occured in RoomLayout::AddRoom: " << ex << std::endl;
		return false;
	}
	catch (...)
	{
		std::cerr << "Unknown Error in RoomLayout::AddRoom" << std::endl;
		return false;
	}
}
