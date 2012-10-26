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
	virtual void Print();
	void AddRoom(Room*);

private:
	std::list<Room*> mRooms;
};

#endif