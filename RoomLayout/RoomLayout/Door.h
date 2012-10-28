#ifndef DOOR_H
#define DOOR_H
#include <vector>
#include "Side.h"
#include "Room.h"

int const MaxRooms = 2;

class Door :
	public Side
{
public:
	Door(bool isOpen, Direction direction);
	virtual ~Door();
	bool AddRoom(Room* room);

private:	
	bool mIsOpen;
	std::vector<Room*> mRooms;
};

#endif