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

	bool IsDoor();
	Direction getDirection();

protected:
	bool mIsDoor;
	Direction mDirection;
};

#endif