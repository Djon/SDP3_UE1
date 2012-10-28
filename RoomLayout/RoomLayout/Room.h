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
	Room();
	virtual ~Room();
	void Print(bool WasDoor);
	bool AddSide(Side* side);
	bool IsNorthDoor();
	bool IsSouthDoor();

private:
	std::vector<Side*> mSides;

	void PrintWallOrDoorNS(Side* side);
	void PrintWallOrDoorOW(Side* side);
	void PrintTwoWallParts();
	void PrintSpaces();
};

#endif