#ifndef ROOMLAYOUT_H
#define ROOMLAYOUT_H

#include <list>
#include "Object.h"
#include "Room.h"

class RoomLayout :
	public Object
{
public:
	RoomLayout();
	virtual ~RoomLayout();
	void Print();
	void AddRoom(Room* room);

private:
	std::list<Room*> mRooms;
	//bool mWasDoor;
	void PrintRoom(Room* room);
};

#endif