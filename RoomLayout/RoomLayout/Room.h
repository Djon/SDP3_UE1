#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include "Object.h"
#include "Side.h"

int const maxWalls = 4;
typedef std::vector<Side*> TVec;
typedef TVec::const_iterator TVecItor;

class Room :
	public Object
{
public:
	Room();
	virtual ~Room();
	void Print();
	bool AddSide(Side* side);

private:
	//Definition: bestimmte Reihenfolge von Himmelsrichtungen: N, W, O, S
	std::vector<Side*> mSides;
};

#endif