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
	virtual void Print() = 0;

private:
	Direction mDirection;
};

#endif