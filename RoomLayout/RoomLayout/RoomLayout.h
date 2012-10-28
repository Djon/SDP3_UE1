#ifndef ROOMLAYOUT_H
#define ROOMLAYOUT_H

#include <list>
#include "Object.h"
#include "Room.h"

typedef std::list<Room*> Rooms;
typedef Rooms::const_iterator RoomsItor;

class RoomLayout :
	public Object
{
public:
	RoomLayout();
	virtual ~RoomLayout();
	void Print();
	bool AddRoom(Room* room);

private:
	Rooms mRooms;
	bool mWasDoor;

	void PrintRoom(Room* room, bool WasDoor);
};

#endif