#include "Wall.h"
#include <iostream>

Wall::Wall(std::string color, Direction direction)
{
	mColor = color;
	mDirection = direction;
	mIsDoor = false;
}

Wall::~Wall()
{
}

//void Wall::Print() 
//{	
//	if (mDirection == North) 
//	{ 
//		std::cout << "*********" << std::endl;
//	}
//	else if (mDirection == West)
//	{
//		std::cout << "*********" << std::endl;
//	}
//}
