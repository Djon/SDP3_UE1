///////////////////////////////////////////////////////////////////////////
// Workfile : Room.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 29.10.2012
// Description : Header for Room.cpp
// Remarks : -
// Revision : 0
///////////////////////////////////////////////////////////////////////////


#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <string>
#include "Object.h"
#include "Side.h"


typedef std::vector<Side*> TVec;
typedef TVec::const_iterator TVecItor;

std::string const WallString_N = "*********";
std::string const DoorString_N = "****D****";
std::string const SideSpaces = "       ";
char const WallSign = '*';
char const DoorSign = 'D';

int const MaxWalls = 4;

class Room :
	public Object
{
public:
	//Default CTor
	Room();

	//virtual destructor
	virtual ~Room();

	//Prints the four sides of the room
	void Print(bool WasDoor) const;

	//Adds a side to the room
	bool AddSide(Side* side);
	//Adds this room to a certain door
	void AddRoomToDoor(Side* door);

	//Checks if the room has reached the max amount of walls
	bool IsFull() const;
	//Checks if the north side is a door
	bool IsNorthDoor() const;
	//Checks if the south side is a door 
	bool IsSouthDoor() const;

	//Returns the north side
	Side* GetNorthSide() const;
	//Returns the south side
	Side* GetSouthSide() const;	

private:
	std::vector<Side*> mSides;

	//Prints a horizontal side
	void PrintWallOrDoorNS(Side* side) const;
	//Prints the sign of a vertical side
	void PrintWallOrDoorOW(Side* side) const;
	//Prints the parts of two parallel walls
	void PrintTwoWallParts() const;
	//Prints the Spaces between two vertical sides
	void PrintSpaces() const;
};

#endif