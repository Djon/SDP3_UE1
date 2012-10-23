#ifndef ROOM_H
#define ROOM_H
#include <vector>
#include "Object.h"
#include "Side.h"

class Room :
	public Object
{
public:
	Room();
	virtual ~Room();
	virtual void Print();

private:
	std::vector<Side*> mSides;
};

#endif