#include "Door.h"


Door::Door(bool isOpen, Direction direction)
{
	mIsDoor = true;
	mIsOpen = isOpen;
	mDirection = direction;
}

Door::~Door()
{
}

void Door::AddRoom(Room* room)
{
	if (mRooms.size() < MaxRooms)
	{
		mRooms.push_back(room);
	}
}
