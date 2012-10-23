#ifndef ROOM_H
#define ROOM_H
#include "Object.h"
#include "Side.h"

int const SideNumber = 4;

class Room :
	public Object
{
public:
	Room();
	virtual ~Room();
	virtual void Print();

private:
	Side* mSides[SideNumber];
};

#endif

//this file is ok