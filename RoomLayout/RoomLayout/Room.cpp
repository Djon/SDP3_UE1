///////////////////////////////////////////////////////////////////////////
// Workfile : Room.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Implements the class room
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>
#include "Room.h"
#include "Door.h"


Room::Room()
{
}

Room::~Room()
{
	TVecItor itor = mSides.begin();

	while (itor != mSides.end())
	{
		delete (*itor);
		++itor;
	}
}

void Room::PrintWallOrDoorNS(Side* side) const
{
	if (!side->IsDoor())
	{
		std::cout << WallString_N << std::endl;
	}
	else
	{
		std::cout << DoorString_N << std::endl;
	}
}

void Room::PrintWallOrDoorOW(Side* side) const
{
	if (!side->IsDoor())
	{
		std::cout << WallSign;
	}
	else
	{
		std::cout << DoorSign;
	}
}

void Room::PrintTwoWallParts() const
{
	std::cout << WallSign;
	PrintSpaces();
	std::cout << WallSign << std::endl;
}

void Room::PrintSpaces() const
{
	std::cout << SideSpaces;
}

void Room::Print(bool WasDoor) const
{
	try
	{
		//Checks if the room has 4 Sides
		if (mSides.size() != MaxWalls) {
			std::string ex("Sides are missing");
			throw(ex);
		}

		TVecItor itor = mSides.begin();

		//North
		if (!WasDoor)
		{
			PrintWallOrDoorNS(*(itor));
		}
		++itor;

		//West+East
		PrintTwoWallParts();
		PrintWallOrDoorOW((*itor));
		PrintSpaces();
		++itor;
		PrintWallOrDoorOW((*itor));
		std::cout << std::endl;
		PrintTwoWallParts();
		++itor;

		//South
		PrintWallOrDoorNS(*(itor));
	}
	catch (std::string const& ex)
	{
		std::cerr << "Error occured in Room::Print: " << ex << std::endl;
	}
	catch (...)
	{
		std::cerr << "Unknown Error in Room::Print" << std::endl;
	}
}

bool CheckSideOrder(Side* side1, Side* side2)
{
	return (side1->getDirection()) < (side2->getDirection());
}

bool Room::AddSide(Side* side)
{
	try
	{
		//checks if max amount of walls have been reached
		if (mSides.size() >= MaxWalls)
		{
			std::string ex("Max amount of walls already reached");
			throw(ex);
		}
		//only inserts walls which doesn't already exist
		for (TVecItor itor = mSides.begin(); itor != mSides.end(); ++itor)
		{
			if ((*itor)->getDirection() == side->getDirection())
			{
				return false;
			}
		}
		mSides.push_back(side);
		//Sorts the Sides
		std::sort(mSides.begin(),mSides.end(),CheckSideOrder);

		if (side->IsDoor())
		{			
			AddRoomToDoor(side);
		}
		return true;
	}
	catch (std::string const& ex)
	{
		std::cerr << "Error occured in Room::AddSide: " << ex << std::endl;
		return false;
	}
	catch (...)
	{
		std::cerr << "Unknown Error in Room::AddSide" << std::endl;
		return false;
	}
}

bool Room::IsNorthDoor() const
{
	return mSides[0]->IsDoor();
}

bool Room::IsSouthDoor() const
{
	return mSides[MaxWalls-1]->IsDoor();
}

void Room::AddRoomToDoor(Side* side)
{
	Door* door = dynamic_cast<Door*>(side);
	door->AddRoom(this);
}

Side* Room::GetNorthSide() const
{
	return mSides[0];
}

Side* Room::GetSouthSide() const
{
	return mSides[MaxWalls-1];
}

bool Room::IsFull() const
{
	return mSides.size() == MaxWalls;
}