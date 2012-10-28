#include "Room.h"
#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include <string>

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

void Room::PrintWallOrDoorNS(Side* side) 
{
	if (side->IsDoor() == false)
	{
		std::cout << WallString_N << std::endl;
	}
	else
	{
		std::cout << DoorString_N << std::endl;
	}
}

void Room::PrintWallOrDoorOW(Side* side) 
{
	if (side->IsDoor() == false)
	{
		std::cout << WallSign;
	}
	else
	{
		std::cout << DoorSign;
	}
}

void Room::PrintTwoWallParts()
{
	std::cout << WallSign;
	PrintSpaces();
	std::cout << WallSign << std::endl;
}

void Room::PrintSpaces()
{
	std::cout << SideSpaces;
}

void Room::Print(bool WasDoor) 
{
	try
	{
		//Checks if the room has 4 Sides
		if (mSides.size() != MaxWalls) {
			throw("Sides are missing");
		}

		TVecItor itor = mSides.begin();

		//N
		if (!WasDoor)
		{
			PrintWallOrDoorNS(*(itor));
		}
		++itor;

		//W+O
		PrintTwoWallParts();
		PrintWallOrDoorOW((*itor));
		PrintSpaces();
		++itor;
		PrintWallOrDoorOW((*itor));
		std::cout << std::endl;
		PrintTwoWallParts();
		++itor;

		//S
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
	//checks if max amount of walls have been reached
	if (mSides.size() < MaxWalls)
	{
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

		return true;
	}
	return false;
}

bool Room::IsNorthDoor()
{
	return mSides[0]->IsDoor();
}

bool Room::IsSouthDoor()
{
	return mSides[MaxWalls-1]->IsDoor();
}