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
	typedef std::list<Room*> Rooms;
	typedef Rooms::const_iterator RoomsItor;
	std::list<Room*> mRooms;
	void PrintRoom(Room* room);
};

#endif