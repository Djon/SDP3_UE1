#ifndef DOOR_H
#define DOOR_H
#include <vector>
#include "Side.h"
#include "Room.h"

class Door :
	public Side
{
public:
	Door(bool isOpen, Direction direction);
	virtual ~Door();
	//virtual void Print();

private:
	bool mIsOpen;
	std::vector<Room*> mRooms;
};

#endif