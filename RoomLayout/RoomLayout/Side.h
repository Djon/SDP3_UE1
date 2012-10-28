#ifndef SIDE_H
#define SIDE_H

#include "Direction.h"
#include "Object.h"

class Side :
	public Object
{
public:
	Side();
	virtual ~Side();
	Direction getDirection();
	bool IsDoor();

protected:
	bool mIsDoor;
	Direction mDirection;
};

#endif