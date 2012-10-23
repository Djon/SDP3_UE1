#ifndef WALL_H
#define WALL_H
#include <string>
#include "Side.h"

class Wall :
	public Side
{
public:
	Wall();
	virtual ~Wall();
	virtual void Print();

private:
	std::string mColor;
};

#endif